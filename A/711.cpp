#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int n,flag;
	cin>>n;
	char v[n][5];
	for (int i=0;i<n;i++){
		for (int j=0;j<5;j++){
			cin>>v[i][j];
		}
	}
	//cout<<v[1][4];
	for (int i=0;i<n;i++){
		flag=0;
		for (int j=0;j<4;j++){
			if (v[i][j]=='O' && v[i][j+1]=='O'){
				v[i][j]='+';
				v[i][j+1]='+';
				flag=1;
				break;
			}
		}
		if (flag==1)break;
	}
	if (flag==1){cout<<"YES"<<endl;
		for (int i=0;i<n;i++){
			for (int j=0;j<5;j++){
				cout<<v[i][j];
			}
			cout<<endl;
		}
	}
	
	else cout<<"NO";
}
