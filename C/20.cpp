#include <bits/stdc++.h>

#define pb push_back
#define ii pair<int, int>
#define f first
#define s second
#define nfs ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

vector<vector<pair<int, int> > >D(100004);
vector<int> visited(100004);
vector<long long int> distance_(100004, LLONG_MAX);
vector<int> path(100004);

void dfs(int node){
	if (!visited[node]){
		visited[node]=1;
		for (auto i: D[node]){
			dfs(i.s);
		}
	}
}

void dijkstra(int node){
	fill(visited.begin(), visited.end(), 0);
	priority_queue<ii, vector<ii>, greater<ii> > q;
	distance_[1]=0;
	q.push({0, 1});
	while(!q.empty()){
		pair<int, int> p = q.top();
		q.pop();
		int d = p.f;
		int v = p.s;
		if (d<=distance_[v]){
			for (auto i: D[v]){
				int v_dash = i.s;
				int weight = i.f;
				if (distance_[v_dash] > distance_[v]+weight){
					distance_[v_dash] = distance_[v]+weight;
					path[v_dash] = v;
					q.push({distance_[v_dash], v_dash});
				}
			}
		}
	}
}

int main(){
	nfs;
	int n, m, p, q, w;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>p>>q>>w;
		D[p].pb({w, q});
		D[q].pb({w, p});
	}
	dfs(1);
	if (visited[n]==0){
		cout<<-1<<endl;
	}
	else{
		dijkstra(1);
		vector<int>ans;
		ans.pb(n);
		for (int i=n;i!=1;i=path[i]){
			ans.pb(path[i]);
		}
		reverse(ans.begin(), ans.end());
		for (int i: ans)
			cout<<i<<" ";
		cout<<endl;
	}
}