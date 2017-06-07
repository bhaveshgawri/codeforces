#include <bits/stdc++.h>

#define pb push_back

using namespace std;

vector<vector<int> >cthu(104);
vector<int> visited(104, 0);

void dfs(int node){
	if (!visited[node]){
		visited[node]=1;
		for (auto i: cthu[node]){
			dfs(i);
		}
	}
}

int main(){
	int n, m, p, q;
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>p>>q;
		cthu[q].pb(p);
		cthu[p].pb(q);
	}
	int components=0;
	for (int i=1;i<=n;i++){
		if (!visited[i]){
			components++;
			dfs(i);
		}
	}
	if (components==1 && n==m){
		cout<<"FHTAGN!"<<endl;
	}
	else
		cout<<"NO"<<endl;
}