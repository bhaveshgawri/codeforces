#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long int

using namespace std;

int main(){	
	ll n,l,r,i,k;
	cin>>n>>l>>r;
	if (n==0){
		cout<<0<<endl;
		return 0;
	}
	ll m=n,count=0;
	vector<ll> binary;
	while(m > 0){
		binary.push_back(m%2);
		m=m/2ll;
	}
	int lo=0, hi=binary.size()-1;
	while(lo<hi){
		swap(binary[lo],binary[hi]);
		hi--;
		lo++;
	}
	for(i=l; i<=r; i++){
		ll power;
		for(power=0; power<=50; power++){
			ll num=pow(2ll,power);
			k=i/num;
			k++;
			if(k%2 == 0){
				ll tmp=binary[power];
				if(tmp == 1)
					count++;
				break;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}