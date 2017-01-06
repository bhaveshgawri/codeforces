#include <iostream>
#include <vector>

using namespace std;

int main(){
	long long int n,p,q,sum=0,sumo=0,sumr=0,sumc=0,sumd1=0,sumd2=0;
	cin>>n;
	if (n==1){cout<<"1";return 0;}
	long long int v[n][n],sumR[n],sumC[n];
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cin>>v[i][j];
			if (v[i][j]==0){
				p=i;
				q=j;
			}
		}
	}
	if (p==0){
		for (int j=0;j<n;j++){
			sumo+=v[0][j];
			sum+=v[1][j];
		}
	}
	else {
		for (int j=0;j<n;j++){
			sumo+=v[p][j];
			sum+=v[0][j];
		}
	}
	v[p][q]=sum-sumo;
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sumr+=v[i][j];
			sumc+=v[j][i];
		}
		sumR[i]=sumr;
		sumC[i]=sumc;
		sumr=0;
		sumc=0;
		sumd1+=v[i][i];
		sumd2+=v[n-i-1][i];
	}
	if (sumd1!=sumd2){cout<<"-1";return 0;}
	int flag=0;
	for (int i=0;i<n;i++){
		if ((sumd1!=sumC[i]) || (sumd1!=sumR[i])){
			flag=1;
			break;
		}
	}
	if (flag==1){cout<<"-1";return 0;}
	else if (v[p][q]<=0) {cout<<"-1";return 0;}
	else cout<<v[p][q];
}
