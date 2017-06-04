#include <bits/stdc++.h>

using namespace std;

vector<int> parent(504);
set<pair<int, int> >roots;

void initialize(){
	for (int i=1;i<=n;i++){
		parent[i]=i;
	}
}

int root(int i){
	while(i!=parent){
		parent[i]=parent[parent[i]];
		i=parent[i];
	}
	return i;
}

void union_(int x ,int y){
	int rootx = root(x);
	int rooty = root(y);
	parent[rootx] = rooty;
}

int main(){
	int n, m, p, q;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>p>>q;
		union_(p, q);
	}
	for (int i=1;i<=n;i++){
		roots.insert(root(i));
	}
	int flag=0;
	for (auto i: roots){
		int count=0;
		for (int j=1;j<=n;j++){
			if (i==root(j)){
				count++;
			}
		}
		if (count>3){
			flag=1;
		}
	}
	if (flag==1){
		cout<<-1<<endl;
		return 0;
	}

	for (auto it: roots){
		for (int j=1;j<=n;j++){
			if (i==root(j))
		}
	}

}