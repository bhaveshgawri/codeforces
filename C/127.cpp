//code doesn't work correctly on codeforces compiler for test #8(due to ll) but
//works fine on other compilers like on hackerrank, on gcc 6.3 on local machine

#include <bits/stdc++.h>

#define ll      long long int

#define nl         "\n"
#define pb         push_back
#define ppb        pop_back
#define pf         push_front
#define ppf        pop_front
#define sz(x)      x.size()
#define all(x)     x.begin(), x.end()
#define Sort(x)    sort(all(x))
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
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int Max1 = 1e5 + 4;
const int Max2 = 2e5 + 4;
const int Mod = 1e9 + 7;

int main(){
	nfs;
	vl one, two;
	ll t1, t2, x1, x2, t0;
	cin>>t1>>t2>>x1>>x2>>t0;
	if (t1==t0 && t2==t0){
		ll minn = min(x1, x2);
		cout<<minn<<" "<<minn<<nl;
		return 0;
	}
	else if (t1==t0){
		cout<<x1<<" "<<0<<nl;
		return 0;
	}
	else if (t2==t0){
		cout<<0<<" "<<x2<<nl;
		return 0;
	}
	double ratio = double(t2-t0)/(t0-t1);
	ll max_2 = max(x2, (ll)ratio*x1);
	double variable=DBL_MAX;
	ll index;
	//cout<<dot(5)<<ratio<<nl;
	for (ll i=1;i<=max_2;i++){
		if (i*ratio>x1)
			break;
		ll r = i*ratio;
		double opti = double(t1*r+t2*i)/(i+r);
		//cout<<i*ratio<<" "<<i<<" "<<opti<<nl;
		two.pb(i);
		one.pb(ratio*i);
		if (opti<=variable){
			variable=opti;
			index=i;
		}
	}
	cout<<one[index-1]<<" "<<two[index-1]<<nl;
}