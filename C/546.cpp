#include <bits/stdc++.h>

#define limit 5000000

using namespace std;

queue<int> one;
queue<int> two; 

int main(){
	int n, p;
	cin>>n;
	int k1, k2;
	cin>>k1;
	for (int i=0;i<k1;i++){
		cin>>p;
		one.push(p);
	}
	cin>>k2;
	for (int i=0;i<k2;i++){
		cin>>p;
		two.push(p);
	}
	int fir, sec, flag=0, winner=0, ans=0;
	for (int i=1;i<=limit;i++){
		if (one.empty() || two.empty()){
			flag = 1;
			ans = i-1;
			break;
		}
		fir = one.front();
		sec = two.front();
		one.pop();
		two.pop();
		if (fir > sec){
			one.push(sec);
			one.push(fir);
			winner=1;
		}
		else{
			two.push(fir);
			two.push(sec);
			winner=2;	
		}
	}
	if (flag==0 || winner==0){
		cout<<-1<<endl;
	}
	if (flag==1){
		cout<<ans<<" "<<winner<<endl;
	}
}