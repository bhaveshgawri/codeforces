#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > G(100005);
vector<int> visited(100005, 0);
vector<int> color1, color2;
vector<int> color(100005);

void dfs(int node, int parent_color){
	if (!visited[node]){
		visited[node]=1;
		if (parent_color==1)
			color[node]=2;
		else if (parent_color==2)
			color[node]=1;
		for (auto it = G[node].begin(); it!=G[node].end();++it){
			dfs(*it, color[node]);
		}
	}
}

bool test(int n){
	for (int i=1;i<=n;i++){
		for (int j : G[i]){
			if (color[i]==color[j])
				return 0;
		}
	}
	return 1;
}

void print(int n){
	if (test(n)){
		for (int i=1;i<=n;i++){
			if (color[i]==1)
				color1.push_back(i);
			else if (color[i]==2)
				color2.push_back(i);
		}
		if (color1.size()==0 || color2.size()==0){
			cout<<-1<<endl;
			return;
		}
		cout<<color1.size()<<endl;
		for (auto it = color1.begin();it!=color1.end();++it){
			cout<<*it<<" ";
		}
		cout<<endl<<color2.size()<<endl;
		for (auto it = color2.begin();it!=color2.end();++it){
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	else
		cout<<-1<<endl;
}


int main(){
	int n, m;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int p, q;
		cin>>p>>q;
		G[p].push_back(q);
		G[q].push_back(p);
	}
	for (int i=0;i<n;i++){
		if (!visited[i]){
			dfs(i, 2);
		}
	}
	print(n);
}