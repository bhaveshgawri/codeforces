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

vi color(Max1);
vvi graph(Max1);
vi cardinality(Max1);

int main(){
	nfs;
	int n, m, p, q;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>color[i];
	}
	for (int i=0;i<m;i++){
		cin>>p>>q;
		graph[p].pb(q);
		graph[q].pb(p);
	}
	set<int> ans;
	vector<set<int> > vs(Max1);
	for (int i=1;i<=n;i++){
		for (int j: graph[i]){
			if (color[i]!=color[j]){
				vs[color[i]].insert(color[j]);
			}
		}
	}
	int maxx=-1;
	for (int i=1;i<Max1;i++){
		if (int(vs[color[i]].size())>maxx){
			maxx=int(vs[color[i]].size());
		}
	}
	for (int i=1;i<Max1;i++){
		int sszz = vs[color[i]].size();
		if (maxx==sszz){
			if (color[i]!=0)
				ans.insert(color[i]);
		}
	}
	cout<<*ans.begin()<<nl;
}