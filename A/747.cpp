#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>v(n);
	int j=0;
	for (int i=1;i<=n;i++){
		if (n%i==0){
			v[j]=i;
			j++;
		}
	}
	if (j%2==0){
		cout<<v[(j-1)/2]<<" "<<v[((j-1)/2)+1];
	}
	else cout<<v[j/2]<<" "<<v[j/2];

}