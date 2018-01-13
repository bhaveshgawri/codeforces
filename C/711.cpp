#include <bits/stdc++.h>

#define gc         getchar
#define pc         putchar
// #define gc         getchar_unlocked
// #define pc         putchar_unlocked

#define ll         long long
#define nl         "\n"
#define pb         push_back
#define ppb        pop_back
#define pf         push_front
#define ppf        pop_front
#define sz(x)      x.size()
#define all(x)     x.begin(), x.end()
#define init(x, k) fill(all(x), k)
#define dot(x)     fixed<<setprecision(x) 
#define nfs        ios_base::sync_with_stdio(false)
#define no_step    cin.tie(NULL)

#define Max(a, b, c)   max(a, max(b, c))
#define Min(a, b, c)   min(a, min(b, c))
#define mxe(a)        *max_element(all(a))
#define mne(a)        *min_element(all(a))

#define lb(x, k)   lower_bound(all(x), k)-x.begin()
//first element greater or equal to k
#define ub(x, k)   upper_bound(all(x), k)-x.begin()
//first element greater than k

// fast i/o for integers
#define in2(a, b)        in(a), in(b)
#define in3(a, b, c)     in2(a, b), in(c)
#define in4(a, b, c, d)  in3(a, b, c), in(d)
#define out2(a, b)       out(a), out(b)
#define out3(a, b, c)    out2(a, b), out(c)
#define out4(a, b, c, d) out3(a, b, c), out(d)

template <typename T> bool in(T &n){
    n = 0;
    bool got = false, negative = false;
    char c = gc();
    while( c < '0' || c > '9'){if (c == '-') negative = true; c = gc();}
    while(c >= '0' && c <= '9'){got = true; n = n*10 + c-48; c = gc();}
    if(negative) n = ~(n-1);
    return got;
}
template <typename T> void out(T n, char seperator = ' '){
    if(n<0){pc('-'); n = -n;}
    if(!n) {pc('0'); pc(seperator); return;}
    char buff[22]; 
    int len = 0;
    while(n) buff[len++] = n%10+48,n/=10;
    for(int i=len-1;i>=0;i--) pc(buff[i]);
    pc(seperator);
}

#define inf      INT_MAX
#define INF      LLONG_MAX

#define ff       first
#define ss       second

using namespace  std;

typedef pair<int, int> ii;
typedef pair<ll, ll> II;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MOD = 1e9 + 7;
const int MAX = 1e5 + 4;

ll n, m, k;
vl c(104);
vvl cost(104);
const ll MAXX = 1e14;
vector<vvl> cache(104, vvl(104, vl(104, -1)));

ll calculate(ll pos, ll prev_color, ll beauty){
    if (beauty > k) return MAXX;
    if (pos > n+1) return 0;
    if (pos == n+1 && beauty != k) return MAXX;
    if (pos == n+1 && beauty == k) return 0;
    if (cache[pos][prev_color][beauty]!=-1) return cache[pos][prev_color][beauty];
    if (c[pos]!=0)
        if (prev_color!=c[pos]) return calculate(pos+1, c[pos], beauty+1); 
        else return calculate(pos+1, prev_color, beauty);
    ll ans = MAXX;
    for (ll i=1;i<=m;i++){
        ll a1=MAXX, a2=MAXX, curr_color=i;
        if (prev_color==curr_color) a1 = cost[pos][i-1] + calculate(pos+1, i, beauty);
        else a2 = cost[pos][i-1] + calculate(pos+1, i, beauty+1);
        ans = Min(ans, a1, a2);
    }
    return cache[pos][prev_color][beauty] = ans;
}

void solve(){
    cin>>n>>m>>k;
    ll a;
    for (ll i=1;i<=n;i++) cin>>c[i];
    for (ll i=1;i<=n;i++){
        for (ll j=0;j<m;j++){
            cin>>a;
            cost[i].pb(a);
        }
    }
    ll ans = calculate(1, 0, 0);
    if (ans>=MAXX)ans=-1;
    cout<<ans<<nl;
}

int main(){
    nfs;
    no_step;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}