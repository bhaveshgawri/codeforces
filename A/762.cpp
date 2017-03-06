#include <iostream>
#include <set>

#define ll long long

using namespace std;

int main(){
	ll a,b;
	cin>>a>>b;
	ll i=1;
	set<ll> s;
	while(i*i<=a){
		if (a%i==0){
			s.insert(i);
			s.insert(a/i);		
		}
		i++;
		//cout<<i<<" ";
	}
	i=1;
	for (auto it = s.begin();it!=s.end();it++){
		if (i==b){
			cout<<*(it);
			return 0;
		}
		i++;
	}
	cout<<-1;

}
