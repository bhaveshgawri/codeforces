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

typedef struct node{
	int beauty;
	int weight;
}node;

int n, m, w;
vector<int> beauties(1004);
vector<int> weights(1004);
vector<int> parent(1004);
map<int, vi> links;
vector<vector<node>> v(1004);
vvi cache(1004, vi(1004, -1));

int root(int i){
	while(i!=parent[i]){
		parent[i] = parent[parent[i]];
		i = parent[i];
	}
	return i;
}

void union_(int x, int y){
	int rootx = root(x);
	int rooty = root(y);
	parent[rootx] = rooty;
}

void preprocess(){
	int p, q;
	for (int i=0;i<m;i++){
		cin>>p>>q;
		union_(p, q);
	}
	for (int i=1;i<=n;i++){
		links[parent[root(i)]].pb(i);
	}
	for (int i=1;i<=n;i++){
		node N;
		N.beauty = beauties[i];
		N.weight = weights[i];
		v[parent[root(i)]].pb(N);
	}
	for (auto i: links){
		if ((i.second).size()>=2){
			int w_tot=0, b_tot=0;
			for (int j=0;j<(i.second).size();j++){
				w_tot += weights[(i.second)[j]];
				b_tot += beauties[(i.second)[j]];
			}
			node n;
			n.beauty = b_tot;
			n.weight = w_tot;
			v[i.first].pb(n);
		}
	}
}

int calculate(int k, int w){
	int ans = 0;
	if (k == n+1)return 0;
	if (cache[k][w]!=-1)return cache[k][w];
	ans = max(ans, calculate(k+1, w));
	for (auto i: v[k]){
		if (w-i.weight>=0)
			ans = max(ans, i.beauty+calculate(k+1, w-i.weight));
	}
	return cache[k][w]=ans;
}

void solve(){
	cin>>n>>m>>w;
	for (int i=1;i<=n;i++){
		parent[i]=i;
	}
	for (int i=1;i<=n;i++){
		cin>>weights[i];
	}
	for (int i=1;i<=n;i++){
		cin>>beauties[i];
	}
	preprocess();
	int ans = calculate(1, w);
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