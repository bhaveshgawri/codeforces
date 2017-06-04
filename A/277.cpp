#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > E(104);
vector<int> parent(104);
set<int> unique_;

void initialize(int n){
	for (int i=1;i<=n;i++){
		parent[i]=i;
	}
}

int root(int i){
	while(parent[i]!=i){
		i = parent[i];
		parent[i] = parent[parent[i]];
		//cout<<"i: "<<i<<" parent[i]: "<<parent[i]<<endl;
	}
	return i;
}

void union_(int x, int y){
	int rootx = root(x);
	int rooty = root(y);
	parent[rootx] = rooty;
}

int main(){
	int n, m, flag_=0;
	cin>>n>>m;
	int k, l;
	for (int i=1;i<=n;i++){
		cin>>k;
		if (k!=0)
			flag_=1;
		while(k--){
			cin>>l;
			E[i].push_back(l);
		}
	}
	initialize(n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (i!=j){
				for (int ii: E[i]){
					int flag=0;
					for (int jj: E[j]){
						if (ii==jj){
							union_(i, j);
							flag=1;
							break;
						}
					}
					if (flag==1)
						break;
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		unique_.insert(root(i));
	} 
	//for (int i: unique_){
	//	cout<<i<<" ";
	//}
	//for (int i=1;i<n;i++){
	//	cout<<i<<" "<<parent[i]<<" "<<root(i)<<endl;
	//}
	if (flag_==1)
		cout<<unique_.size()-1<<endl;
	else
		cout<<unique_.size()<<endl;
}