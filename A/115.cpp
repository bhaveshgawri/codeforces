#include <bits/stdc++.h>

using namespace std;

vector<vector<int> >G(2004);
vector<int> level_(2004);


void dfs(int i, int level){
	level_[i] = level;
	for (int j: G[i])
		dfs(j, level_[i]+1);
}

int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		int p;
		cin>>p;
		if (p==-1)
			p=0;
		G[p].push_back(i);
	}
	for (int i: G[0])
		dfs(i, 1);
	cout<<*max_element(level_.begin(), level_.end())<<endl;
}