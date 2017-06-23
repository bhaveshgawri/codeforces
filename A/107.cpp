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

vvii N(1004);
vi visited(1004, 0);
vi tank, tap;
vi idegree(1004, 0);
vi odegree(1004, 0);

int dfs(int house, int& tap){
	int len=inf;
	if (!visited[house]){
		visited[house]=1;
		for (auto conn: N[house]){
			len = min(conn.ss, dfs(conn.ff, tap));
		}
	}
	if (len==inf){
		tap=house;
	}
	return len;
}


int main(){
	nfs;
	int n, p, a, b, d;
	cin>>n>>p;
	for (int i=0;i<p;i++){
		cin>>a>>b>>d;
		N[a].pb({b, d});
		idegree[b]=1;
		odegree[a]=1;
	}
	for (int i=1;i<=n;i++){
		if (idegree[i]==1 && odegree[i]==0){
			tap.pb(i);
		}
		else if (idegree[i]==0 && odegree[i]==1){
			tank.pb(i);
		}
	}
	cout<<tank.size()<<nl;
	for (int i: tank){
		if (!visited[i]){
			int tap;
			cout<<i<<" "<<tap<<" "<<dfs(i, tap)<<nl;
		}
	}

}