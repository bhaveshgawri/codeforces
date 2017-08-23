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

vvi J(Max1);
vector<double> prob(Max1);
vi visited(Max1);
vi dist(Max1);
vi leaf;

void dfs(int node){
	if (visited[node]==0){
		if (J[node].size()==1 && node!=1){
			leaf.pb(node);
		}
		visited[node] = 1;
		for (int i: J[node]){	
			if (visited[i]==0){
				if (node==1)
					prob[i] = prob[node]*(1.0/(J[node].size()));
				else
					prob[i] = prob[node]*(1.0/(J[node].size()-1));
				dist[i] = dist[node] + 1;
				dfs(i);
			}
		}
	}
}

void solve(){
	int n, p, q;
	cin>>n;
	for (int i=0;i<n-1;i++){
		cin>>p>>q;
		J[p].pb(q);
		J[q].pb(p);
	}
	prob[1] = 1.0;
	dist[1] = 0;
	dfs(1);
	if (n==1)leaf.pb(1);
	double ans = 0.0;
	for (int i: leaf){
		// cout<<prob[i]<<" ";;
		ans += dist[i]*prob[i];
	}
	cout<<dot(7)<<ans<<nl;
}

int main(){
	nfs;
	no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}