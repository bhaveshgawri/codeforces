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

vi visited(Max1);
vvi v(Max1);
vi _main(Max1);
vi q;
int flag=0;

void dfs(int node){
	visited[node]=1;
	for (int i: v[node]){
		if (visited[i]==1)
			flag=1;
		if (visited[i]==0)
			dfs(i);
	}
	visited[node]=-1;
	q.pb(node);
}

int main(){
	nfs;
	int n, k, p, qt;
	cin>>n>>k;
	for (int i=0;i<k;i++){
		cin>>_main[i];
	}
	for (int i=1;i<=n;i++){
		cin>>p;
		while(p--){
			cin>>qt;
			v[i].pb(qt);
		}
	}
	for (int i=0;i<k;i++)
		if (!visited[_main[i]])
			dfs(_main[i]);
	if (flag)
		cout<<-1<<nl;
	else{
		cout<<sz(q)<<nl;
		for (int i: q)
			cout<<i<<" ";
		cout<<nl;
	}
}