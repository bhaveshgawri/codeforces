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

#define sh short
typedef vector<sh> vsh;
typedef vector<vsh> vvsh;

int n, w, h, l;
vi parent(5004, -1);
vvsh cache(5004, vsh(5004, -1));
vector<pair<ii, int>>v;

sh calculate(int idx, int prev){
	if (idx == l) return 0;
	if (cache[idx][prev] != -1) return cache[idx][prev];
	int ans, a1=-inf, a2=-inf;
	if (v[idx].ff.ff > v[prev].ff.ff && v[idx].ff.ss > v[prev].ff.ss) 
		a1 = 1 + calculate(idx+1, idx);
	a2 = calculate(idx+1, prev);
	if (a1 > a2) parent[prev] = idx;
	ans = max(a1, a2);
	return cache[idx][prev] = ans;
}

void solve(){
	cin>>n>>w>>h;
	int x, y;
	for (int i=0;i<n;i++){
		cin>>x>>y;
		if (x>w && y>h) v.pb({{x, y}, i+1});
	}
	v.pb({{-1, -1}, 0});
	sort(all(v));
	l = v.size();
	cout<<calculate(1, 0)<<nl;
	int i = 0;
	while(parent[i]!=-1){
		cout<<v[parent[i]].ss<<" ";
		i=parent[i];
	}
}

int main(){
    nfs;
    no_step;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}