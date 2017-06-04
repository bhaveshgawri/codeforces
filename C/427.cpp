#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define M 1000000007

vector<int> cost(100004);
vector<vector<int> > C(100004);
vector<vector<int> > C_new(100004);
stack<int> S;
vector<int> visited(100004);
vector<vector<int> > compo(100004);

void dfs(int node){
	if (!visited[node]){
		visited[node]=1;
		for (auto i: C[node])
			dfs(i);
		S.push(node);
	}
}

void rev_list(int n){
	for (int i=1;i<=n;i++){
		for (auto j: C[i]){
			C_new[j].pb(i);
		}
	}
}

void dfs2(int i, int index){
	if (!visited[i]){
		visited[i]=1;
		compo[index].pb(i);
		for (int j: C_new[i])
			dfs2(j, index);
	}
}

int re_dfs(int n){
	fill(visited.begin(), visited.end(), 0);
	int components=0;
	while(!S.empty()){
		int source = S.top();
		S.pop();
		if (!visited[source]){
			components++;
			dfs2(source, components);
		}
	}
	/*for (int i=1;i<=components;i++){
		cout<<i<<": ";
		for (int j: compo[i]){
			cout<<j<<" ";
		}
		cout<<endl;
	}*/
	return components;
}

int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>cost[i];
	}
	int m, p, q;
	cin>>m;
	for (int i=0;i<m;i++){
		cin>>p>>q;
		C[p].pb(q);
	}
	
	//	<kosaraju's algo>
	for (int i=1;i<=n;i++)
		if (!visited[i])
			dfs(i);
	rev_list(n);
	int components = re_dfs(n);
	//	</kosaraju's algo>

	long long int min_cost=0, count=0, ways=1;
	for (int i=1;i<=components;i++){
		long long int min=LLONG_MAX;
		for (int j: compo[i]){
			if (cost[j]<min)
				min = cost[j];
		}
		for (int j: compo[i]){
			if (cost[j]==min)
				count++;
		}
		min_cost+=min;
		ways=((ways%M)*(count%M))%M;
		count=0;
	}
	cout<<min_cost<<" "<<ways<<endl;
}