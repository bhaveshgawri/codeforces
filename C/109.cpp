#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int i, flag = 0, m=n/4;
	for (i=0;i<=m;i++){
		if (i) n-=4;
		if (!(n%7) || !n){
			flag = 1;
			break;
		}
	}
	if (!flag)cout<<-1<<endl;
	else{
		while(i--)
			cout<<4;
		for (int j=0;j<n/7;j++)
			cout<<7;
		cout<<endl;
	}
}