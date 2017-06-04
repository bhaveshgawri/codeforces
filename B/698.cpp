#include <bits/stdc++.h>

using namespace std;


int parent[200004];

int root(int i){
	while(i!=parent[i]){
		parent[i]=parent[parent[i]];
		i=parent[i];
	}
	return i;
}

int main(){
	int n;
	cin>>n;
	int par_bk[200004];
	set<int> bigs;
	int big;
	for (int i=1;i<=n;i++){
		cin>>parent[i];
		par_bk[i]=parent[i];
		if (i==parent[i])
			big = i;
	}
	if (big==0){
		big=root(1);
	}
	//cout<<big<<endl;
	for (int i=1;i<=n;i++){
		bigs.insert(root(i));
	}
	/*for (auto i: bigs){
		cout<<i<<" ";
	}
	cout<<endl;*/
	int count=0;
	for (int i: bigs){
		int temp = par_bk[i];
		par_bk[i]=big;
		if (temp!=par_bk[i])
			count++;
	}
	cout<<count<<endl;
	for (int i=1;i<=n;i++){
		cout<<par_bk[i]<<" ";
	}
	cout<<endl;
}