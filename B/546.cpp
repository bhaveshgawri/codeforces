#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	int ans=0;
	for (int i=0;i<n;i++){
		cin>>v[i];
	}
	vector<int> count(5000, 0);
	for (int i=0;i<n;i++){
		count[v[i]]++;
	}
	for (int i=0;i<3001;i++){
		if (count[i]>1){
			for (int j=i;j<=3001;j++){
				if (count[j]==0){
					ans += (j-i);
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
}