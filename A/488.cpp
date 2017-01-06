#include <iostream>
#include <cmath>

using namespace std;

int main(){
	long long int s,p;
	cin>>s;
	for (long long int i=s+1;true;i++){
		p=abs(i);		
		while(p){
			if (p%10==8){cout<<i-s;return 0;}
			p/=10;
		}	
	}	
	return 0;
}
