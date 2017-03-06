#include <iostream>

using namespace std;

int main(){
	int m,d;
	cin>>m>>d;
	int ans=4;
	if (m==1||m==3||m==5||m==7||m==8||m==10||m==12){
		if(d==6||d==7)ans+=2;
		else ans+=1;
	}
	else if (m==4||m==6||m==9||m==11){
		if(d==7)ans+=2;
		else ans+=1;
	}
	else if (m==2){
		if (d==1) ans=ans;
		else ans+=1;
	}
	cout<<ans;
}