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

vvi R(404);
vvi T(404);
vi visited(404, 0);
vi dist(404);
int conn[404][404];

void bfs(int n, char c){
	init(visited, 0);
	init(dist, -1);
	queue<int> q;
	q.push(1);
	visited[1]=1;
	dist[1]=0;
	int flag=0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		if (c=='r')
			for(int i: R[node]){
				if (visited[i]==0){
					q.push(i);
					visited[i]=1;
					dist[i]=dist[node]+1;
					if (i == n){
						flag=1;
						break;
					}
				}
			}
		else
			for(int i: T[node]){
				if (visited[i]==0){
					q.push(i);
					visited[i]=1;
					dist[i]=dist[node]+1;
					if (i == n){
						flag=1;
						break;
					}
				}
			}
		if (flag==1)
			break;
	}
}

int main(){
	nfs;
	int n, m, p, q;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>p>>q;
		R[p].pb(q);
		R[q].pb(p);
		conn[p][q]=conn[q][p]=1;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (conn[i][j]==0){
				T[i].pb(j);
			}
		}
	}
	int p1, p2, ans;
	bfs(n, 'r');
	p1=dist[n];
	bfs(n, 't');
	p2=dist[n];
	ans = max(p1, p2);
	if (ans>1)
		cout<<ans<<nl;
	else
		cout<<-1<<nl;
}