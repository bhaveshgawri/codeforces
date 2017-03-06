#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	vector<int> v(a),c(a);
	vector<int> dv(2*a),dc(2*a);
	for(int i=0;i<a;i++){
		cin>>v[i];
	}
	for (int i=0;i<a-1;i++){
		dv[i]=v[i+1]-v[i];
	}
	dv[a-1]=dv[0]+b-v[a-1];
	for (int i=a;i<2*a;i++){
		dv[i] = dv[i-a];
	}
	for (int i=0;i<a;i++){
		cin>>c[i];
	}
	for (int i=0;i<a-1;i++){
		dc[i]=c[i+1]-c[i];
	}
	dc[a-1]=dc[0]+b-c[a-1];
	for (int i=a;i<2*a;i++){
		dc[i] = dc[i-a];
	}
	int flag=0;
	for (int j=0;j<a-1;j++){
		flag=0;
		if (dv[0]==dc[j]){
			for(int k=j;k<j+a-1;k++){
				if(dv[k]!=dc[k]){
					cout<<"NO";
					return 0;
				}
			}
		}
		else
			flag=1;

	}
	if (flag==0)
		cout<<"YES";
	else if (flag==1)
		cout<<"NO";
}