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
	int n;
	cin>>n;
	vi ans;
	if (n%2==0){
		if ((n/2)%2==0){
			cout<<0<<nl;
			// cout<<n/2<<" ";
			for (int i=1;i<=n/2;i++){
				if (i%2==1)ans.pb(i);
			}
			for (int i=n/2+1;i<=n;i++){
				if (i%2==0)ans.pb(i);
			}
		}
		else{
			cout<<1<<nl;
			for (int i=1;i<=n/2;i++){
				if (i%2==1)ans.pb(i);
			}
			for (int i=n/2+2;i<=n;i++){
				if (i%2==0)ans.pb(i);
			}
		}
	}
	else{
		ans.pb(3);
		int end = (n-3)/2;
		if (((n-1)/2)%2==0){
			cout<<1<<nl;
			for (int i=4;i<4+end;i++){
				if (i%2==0)ans.pb(i);
			}
			for (int i=5+end;i<=n;i++){
				if (i%2==1)ans.pb(i);
			}
		}
		else{
			cout<<0<<nl;
			for (int i=4;i<4+end;i++){
				if (i%2==0)ans.pb(i);
			}
			for (int i=4+end;i<=n;i++){
				if (i%2==1)ans.pb(i);
			}
		}
	}
	cout<<ans.size()<<" ";
	for (int i: ans)cout<<i<<" ";
}

int main(){
	nfs;
	no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}