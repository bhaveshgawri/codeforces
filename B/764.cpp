#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v(n+1);
	for (int i=1;i<=n;i++){
		cin>>v[i];
	}
	if (n%2==1)
		for (int i=1;i<=n;i++){
			if (i!=n){
				if (i%2==0){
					cout<<v[i]<<" ";
				}
				else{
					cout<<v[n-i+1]<<" ";
				}
			}
			else{
				if (i%2==0){
					cout<<v[i];
				}
				else{
					cout<<v[n-i+1];
				}	
			}
		}	
	else{
		for(int i=1;i<=n/2;i++){
			if(i!=n){
				if (i%2==0){
					cout<<v[i]<<" ";
				}
				else{
					cout<<v[n-i+1]<<" ";
				}
			}
			else{
				if (i%2==0){
					cout<<v[i];
				}
				else{
					cout<<v[n-i+1];
				}
			}
		}
		for(int i=n/2+1;i<=n;i++){
			if(i!=n){
				if (i%2==1){
					cout<<v[i]<<" ";
				}
				else{
					cout<<v[n-i+1]<<" ";
				}
			}
			else{
				if (i%2==1){
					cout<<v[i];
				}
				else{
					cout<<v[n-i+1];
				}
			}
		}
	}
		
}