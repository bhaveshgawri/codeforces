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


#define trace1(a)           cerr<<#a<<": "<<a<<nl
#define trace2(a, b)        cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<nl
#define trace3(a, b, c)     cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<nl
#define trace4(a, b, c, d)  cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<nl

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

int n;
vi v(504);
vvi cache(504, vi(504, -1));

int calculate(int i, int j){
	if (cache[i][j]!=-1) return cache[i][j];

	if (i>=j) return 1;
	// or
	// if (i>j || i>=n || j>=n) return 0;
	// if (i+1==j) return v[i]==v[j]?1:2;
	// if (i==j) return 1;

	int a1 = inf, a2 = inf;
	if (v[i]==v[j]) 
		a1 = calculate(i+1, j-1);
	for (int k=i;k<j;k++)
		a2 = min(a2, calculate(i, k)+calculate(k+1, j));
	return cache[i][j] = min(a1, a2);
}


void solve(){
    cin>>n;
    for (int i=0;i<n;i++){
    	cin>>v[i];
    }
    int ans = calculate(0, n-1);
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