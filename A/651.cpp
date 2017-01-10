#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	
	int count=0;
	while(true){
		if (a<=0||b<=0||(a==1&&b==1))
			break;
		if (a<b){
			a++;
			b-=2;
		}
		else{
			b++;
			a-=2;
		}
		count++;
	}
	cout<<count;
}