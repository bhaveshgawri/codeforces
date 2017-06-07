#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int sum=0, variable;
	for (int i=0;i<n;i++){
		cin>>variable;
		sum+=variable;
	}
	int m;
	cin>>m;
	vector<int>t(2*m);
	for (int i=0;i<2*m;i++){
		cin>>t[i];
	}
	int ans=-1;
	int flag=0;
	for (int i=0;i<2*m;i++){
		if (t[i]==sum){
			ans=i;
			flag=1;
			cout<<sum<<endl;
			break;
		}
	}
	if (ans==-1){
		for (int i=0;i<2*m-1;i++){
			if (sum < t[0]){
				flag=1;
				cout<<t[0]<<endl;
				break;
			}
			else if (i%2==0 && t[i]<sum && t[i+1]>sum){
				cout<<sum<<endl;
				flag=1;
				break;
			}
			else if (i%2==1 && t[i]<sum && t[i+1]>sum){
				cout<<t[i+1]<<endl;
				flag=1;
				break;
			}

		}
	}
	if (flag==0){
		cout<<-1<<endl;
	}
}