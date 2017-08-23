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

	void solve(){
		ll n, m, k;
		cin>>n>>m>>k;
		ll x, s;
		cin>>x>>s;
		vi a(m+1), b(m) , c(k), d(k);
		for (int i=0;i<m;i++){
			cin>>a[i];
		}
		for (int i=0;i<m;i++){
			cin>>b[i];
		}
		for (int i=0;i<k;i++){
			cin>>c[i];
		}
		for (int i=0;i<k;i++){
			cin>>d[i];
		}
		ll ans = n*x;
		for (int i=0;i<k;i++) 
			if (d[i]<=s)
				ans = min(ans, x*(n-c[i]));
		for (int i=0;i<m;i++){
			ll rem_pow = s-b[i];
			if (rem_pow<0) continue;
			if (rem_pow<d[0])
				ans = min(ans, n*a[i]);
			else{
				ll upper = ub(d, rem_pow)-1;
				// if (upper>0)
					// upper--;
				ll rem_pot = n-c[upper];
				ans = min(ans, rem_pot*a[i]);
			}
		}
		cout<<ans<<nl;
	}

	int main(){
		nfs;
		no_step;
		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
		solve();
	}