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
#define nfs        ios_base::sync_with_stdio(false);cin.tie(NULL)

#define Max(a, b, c)   max(a, max(b, c))
#define Min(a, b, c)   min(a, min(b, c))
#define mxe(a)        *max_element(all(a))
#define mne(a)        *min_element(all(a))

#define lb(x, k)   lower_bound(all(x), k)-x.begin()
#define ub(x, k)   upper_bound(all(x), k)-x.begin()

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

vl x, y;
map<II, ll> xy;

int main(){
	nfs;
	ll n, p, q;
	cin>>n;
	for (ll i=0;i<n;i++){
		cin>>p>>q;
		x.pb(p);
		y.pb(q);
		xy[{p, q}]++;
	}
	sort(all(x));
	sort(all(y));
	ll ans, final_ans=0;
	for (ll i=0;i<n;){
		ll u = ub(x, x[i]), l = lb(x, x[i]);
		ans = u-l;
		final_ans += (ans*(ans-1))/2;
		ll check=x[i];
		i++;
		while(i<n && x[i]==check) i++;
		//cout<<l<<" "<<u<<nl;
	}
	//cout<<nl;
	for (ll i=0;i<n;){
		ll u = ub(y, y[i]), l = lb(y, y[i]);
		ans = u-l;
		final_ans += (ans*(ans-1))/2;
		ll check=y[i];
		i++;
		while(i<n && y[i]==check) i++;
		//cout<<l<<" "<<u<<nl;
	}
	int dec=0;
	for (auto i: xy){
		final_ans-=(i.ss*(i.ss-1))/2;
	}
	cout<<final_ans<<nl;
}