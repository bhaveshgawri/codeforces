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
	int n, m;
	cin>>n>>m;
	int t[n+1][m+1];
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cin>>t[i][j];
		}
	}
	ll ans = 0;
	for (int i=0;i<n;i++){
		int count0 = 0, count1=0;
		for (int j=0;j<m;j++){
			if (t[i][j]==1)count1++;
			else count0++;
		}
		ans += ((ll)(1ll<<count1) -1 -count1);
		ans += ((ll)(1ll<<count0) -1 -count0);
	}
	for (int i=0;i<m;i++){
		int count0 = 0, count1=0;
		for (int j=0;j<n;j++){
			if (t[j][i]==1)count1++;
			else count0++;
		}
		ans += ((ll)(1ll<<count1) -1 -count1);
		ans += ((ll)(1ll<<count0) -1 -count0);
	}
	ans += m*n;
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