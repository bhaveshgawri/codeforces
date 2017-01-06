#include <iostream>
#include <vector>
#include <cmath>

#define ll long long int


using namespace std;


ll search(ll k, ll midx, ll mid, ll p){ 
	if (k > midx){
		p=p/2;
		search(k,midx+p,--mid,p);
	}
	else if (k<midx){
		p=p/2;
		search(k,midx-p,--mid,p);
	}
	else
		return mid;
}


int main(){
	ll n,k;
	cin>>n>>k;
	ll len = ((ll)pow(2,n))-1;
	ll ans = search(k,(len+1)/2,n,(len+1)/2);
	cout << ans;

}