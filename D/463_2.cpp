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

int mat[1001][1001];
int seq[7][1001];
vvi v(1001);
vi dist(1001);
int ans = -inf;
vi visited(1001);

void dfs(int node){
	if (!visited[node]){
		visited[node]=1;
		for (int i: v[node]){
			dfs(i);
			dist[node] = max(dist[node], dist[i]+1);
		}
		dist[node]=max(dist[node], 1);
		ans=max(ans, dist[node]);
	}
}

int main(){
	nfs;
	int n, k;
	cin>>n>>k;
	for (int i=1;i<=k;i++){
		for (int j=0;j<n;j++){
			cin>>seq[i][j];
		}
	}
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			mat[seq[1][i]][seq[1][j]] = 1;
		}
	}
	for (int i=2;i<=k;i++){
		for (int j=0;j<n;j++){
			for (int jj=0;jj<j+1;jj++){
				mat[seq[i][j]][seq[i][jj]] = 0;
			}
			for (int jj=j+1;jj<n;jj++){
				mat[seq[i][j]][seq[i][jj]] &= 1;
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (mat[i][j]==1){
				v[i].pb(j);
			}
		}
	}
	for (int i=1;i<=n;i++){
		if (visited[i]==0){
			dfs(i);
		}
	}
	cout<<ans<<nl;
}