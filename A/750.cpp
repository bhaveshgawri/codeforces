#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int rem = (240 - k);
	int i=0,count=0;
	while(true){
		i++;
		count++;
		rem-=i*5;
		if (count == n || rem-5*(i+1)<0)
			break;
	}
	cout<<count;
}