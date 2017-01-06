#include <iostream>

using namespace std;

int main(){
	int n,a,b;
	cin>>n>>a>>b;
	char v[n+1];
	for (int i=1;i<=n;i++){
		cin>>v[i];
	}
	int cost=0;
	if (v[a]==v[b]){
		cout<<0;
		return 0;
	}
	else{
		if (a<b){
			while(v[a]!=v[b]){
				a++;
				if (v[a-1]!=v[a])
					cost++;
			}
		}
		else{
			while(v[a]!=v[b]){
				a--;
				if (v[a+1]!=v[a])
					cost++;
			}
		}
	}
	cout<<cost;


}
