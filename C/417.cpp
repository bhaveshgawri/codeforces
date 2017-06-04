#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin>>n>>k;
	int value = n%2==0?n/2-1:n/2;
	if (k>value){
		cout<<-1<<endl;
	}
	else{
		cout<<n*k<<endl;
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<i+1+k;j++){
				cout<<i<<" "<<(j%n==0?n:j%n)<<endl;
			}
		}
	}
}