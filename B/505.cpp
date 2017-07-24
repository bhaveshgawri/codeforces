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

vector<vvi> W(104, vvi(104));
vi visited(104, 0);

void dfs(int color, int node){
	if (!visited[node]){
		visited[node]=1;
		for (int i: W[color][node]){
			dfs(color, i);
		}
	}
}

bool isConnected(int color, int a, int b){
	//return true;
	init(visited, 0);
	//cout<<color<<" "<<a<<nl;
	dfs(color, a);
	if (visited[b]==1)
		return true;
	else
		return false;
}

int main(){
	nfs;
	int n, m;
	cin>>n>>m;
	int p, q, c;
	int max_color=1;
	for (int i=0;i<m;i++){
		cin>>p>>q>>c;
		max_color = max(max_color, c);
		W[c][p].pb(q);
		W[c][q].pb(p);
	}
	int queries, a, b;
	cin>>queries;
	while(queries--){
		int ans=0;
		cin>>a>>b;
		for (int i=1;i<=max_color;i++){
			if (isConnected(i, a, b))
				ans++;
		}
		cout<<ans<<nl;
	}
}