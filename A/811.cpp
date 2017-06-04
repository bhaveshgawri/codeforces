#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b;
	cin>>a>>b;
	int i=1;
	while(1){
		a-=i;
		if (a<0){
			cout<<"Vladik"<<endl;
			break;
		}
		i++;
		b-=(i);
		if (b<0){
			cout<<"Valera"<<endl;
			break;
		}
		i++;
	}	
}