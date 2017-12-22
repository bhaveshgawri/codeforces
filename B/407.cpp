#include <bits/stdc++.h>

#define ll      long long int

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
//first element not less than (i.e. greater or equal to) k
#define ub(x, k)   upper_bound(all(x), k)-x.begin()
//first element greater than k

#define inf      INT_MAX
#define INF      LLONG_MAX

#define ff    first
#define ss    second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ll, ll> II;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int Max1 = 1e5 + 4;
const int Max2 = 2e5 + 4;
const int Mod = 1e9 + 7;

vl visited(1004, 0);
vl cache(1004, -1);
vl v(1004);
ll dest;

void calculate(ll n){
	ll ans = 0;
	if (dest+1==n){
		return;
	}
	if (!visited[n]){
		visited[n] = 1;
		ll temp_ans = 1 + cache[n] - cache[v[n]];
		temp_ans += Mod;
		temp_ans %= Mod;
		cache[n+1] = 1 + cache[n] + temp_ans;
		cache[n+1] += Mod;
		cache[n+1] %= Mod;
		// cout<<n<<" "<<cache[n]<<nl;
		calculate(n+1);
	}
}

void solve(){
	ll n;
	cin>>n;
	dest = n+1;
	for (ll i=1;i<=n;i++){
		cin>>v[i];
	}
	cache[1]=0;
	calculate(1);
	cout<<cache[n+1]<<nl;
}

int main(){
	nfs;
	no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}