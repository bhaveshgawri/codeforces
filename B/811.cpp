#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	vector<int> page_at(n+1);
	for (int i=1;i<=n;i++){
		cin>>page_at[i];
	}
	for (int i=0;i<m;i++){
		int l, r, x, count=0;
		cin>>l>>r>>x;
		if (x<l || x>r){
			cout<<"No"<<endl;
			continue;
		}
		for (int j=l;j<=r;j++){
			if (page_at[j]<page_at[x])
				count++;
		}
		if (page_at[l+count]==page_at[x]){
			cout<<"Yes"<<endl;
		}
		else
			cout<<"No"<<endl;
	}	
}