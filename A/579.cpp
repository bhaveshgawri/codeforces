#include <iostream>
#include <vector>

using namespace std;

int main(){
	int x,count=0;
	cin>>x;
	while(x>0){
		if (x%2!=0){
			x-=1;
			count++;
		}
		else{
			x/=2;
		}
	}	
	cout<<count;
}
