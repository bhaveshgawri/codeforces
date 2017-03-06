#include <iostream>

#define ll long long

using namespace std;

int main(){
	ll n,k,p;
	cin>>n>>k;
	p=n;
	int count=0, digits=0;
	while(p){
		int dig = p%10;
		p/=10;
		if (dig == 0)
			k--;
		else
			count++;
		if (k==0){
			cout<<count<<endl;
			return 0;
		}
	}
	if (n==0)
		digits=1;
	else
		while (n){
			n/=10;
			digits++;
		}
	cout<<digits-1<<endl;
}