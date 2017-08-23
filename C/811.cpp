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
	vi v(n+1);
	vi start(5004, -1), end(5004, -1);
	for (int i=1;i<=n;i++){
		cin>>v[i];
		if (start[v[i]]==-1){
			start[v[i]]=i;
		}
	}
	for (int i=n;i>0;i--){
		if (end[v[i]]==-1){
			end[v[i]]=i;
		}
	}
	vi ans(5004, 0);
	for (int i=1;i<=n;i++){
		int lo = i;
		int xor_=0;
		ans[i] = ans[i-1];
		for (int j=i;j>0;j--){
			if (end[v[j]]>i){
				break;
			}
			else{
				if (start[v[j]]<lo)
					lo = start[v[j]];
				if (j==end[v[j]])
					xor_ ^= v[j];
				if (j==lo)
					ans[i] = max(ans[i], ans[j-1]+xor_);
			}
		}
	}
	cout<<ans[n]<<nl;
}

int main(){
	nfs;
	no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}