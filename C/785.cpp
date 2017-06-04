#include <iostream>
#include <cmath>

#define ll long long	

using namespace std;

int main(){
	ll n,m;
	cin>>n>>m;
	if(m>=n){
		cout<<n;
		return 0;
	}
	double ans = (-3.0+sqrt(9.0+8.0*(n-m-1)))/2.0;
	if(floor(ans)!=ans){
		ans++;	
	}
	cout<<(ll)(ans+m+1);
}