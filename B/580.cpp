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

int main(){
	nfs;
	no_step;
	ll n, d, p, q;
	cin>>n>>d;
	vector<pair<ll, ll>> v;
	for (int i=0;i<n;i++){
		cin>>p>>q;
		v.pb({p, q});
	}
	sort(all(v));
	for (int i=1;i<n;i++){
		v[i].ss += v[i-1].ss;
	}
	ll ans = -INF;
	for (int i=0;i<n;i++){
		ll k = v[i].ff + d;
		ll l = lower_bound(all(v), pair<ll, ll>(k, 0)) - v.begin();
		ll sum = v[l-1].ss - ((i-1)>=0?v[i-1].ss:0);
		//cout<<i<<" "<<l<<" "<<sum<<nl;
		ans = max(ans, sum);
	}

	cout<<ans<<nl;
}