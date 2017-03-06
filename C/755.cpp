#include <iostream>
#include <vector>

using namespace std;

int root(int* id, int p){
	while(id[p]!=p){
		id[p]=id[id[p]];
		p=id[p];
	}
	return p;
}


void union_(int* id, int x, int y){
	int rootx = root(id, x);
	int rooty = root(id, y);
	id[rootx] = rooty;
} 

int main(){
	int n;
	cin>>n;
	vector<int>v(n+1);
	int id[n+1];
	for (int i=1;i<=n;i++)id[i]=i;
	for (int i=1;i<=n;i++){
		cin>>v[i];
		//cout<<v[i]<<"p";
		union_(id,i,v[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(i==id[i]){
			ans++;
		}
	}
	cout<<ans;
}