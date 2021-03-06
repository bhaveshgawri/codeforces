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
//first element greater or equal to k
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

vvi G(50004);
vi visited(50004);
int dist[50004][504];
ll ans = 0;
int n, k;

void calculate(int node, int parent){
	if (!visited[node]){
		visited[node] = 1;
		dist[node][0] = 1;
		for (int child: G[node]){
			if (child != parent){
				calculate(child, node);
				for (int i=1;i<=k;i++){
					ans += dist[node][i-1]*dist[child][k-i];
				}
				for (int i=1;i<=k;i++){
					dist[node][i] += dist[child][i-1];
				}
			}
		}
	}
}

void solve(){
	cin>>n>>k;
	int a, b;
	for (int i=0;i<n-1;i++){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	calculate(1, 0);
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