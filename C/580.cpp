#include <bits/stdc++.h>

using namespace std;

vector<int> cats(100004);
vector<vector<int> > G(100004);
vector<int> visited(100004, 0);

bool isLeaf(int node){
	return G[node].size()==1;
} 

int bfs(int node, int max){
	queue<int> q;
	fill(visited.begin(), visited.end(), 0);
	int ans = 0;
	if (cats[node]<=max){
		q.push(node);
		visited[node]=1;
	}
	while(!q.empty()){
		int the_node = q.front();
		q.pop();
		for (int i: G[the_node]){
			if (visited[i]==0){
				visited[i]=1;
				if (cats[i]<=max){
					q.push(i);
					if (isLeaf(i)){
						ans++;
					}
				}
			}
		}
	}
	return ans;
}

void initialize_cats(int node){
	queue<int> q;
	fill(visited.begin(), visited.end(), 0);
	q.push(node);
	visited[node]=1;
	while(!q.empty()){
		int the_node = q.front();
		q.pop();
		for (int i: G[the_node]){
			if (visited[i]==0){
				visited[i]=1;
				if (cats[i]!=0){
					cats[i]+=cats[the_node];
				}
				q.push(i);
			}
		}
	}
	/*if (!visited[node]){
		visited[node]=1;
		for (auto it=G[node].begin();it!=G[node].end();++it){
			if (!visited[(*it)]){
				initialize_cats(*it);
				if (cats[(*it)]!=0){
					cats[(*it)]=cats[node]+1;
				}
			}
		}
	}*/
}

int main(){
	int n, m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>cats[i];
	}
	int p, q;
	for (int i=1;i<n;i++){
		cin>>p>>q;
		G[p].push_back(q);
		G[q].push_back(p);
	}
	initialize_cats(1);
	cout<<bfs(1, m)<<endl;
}