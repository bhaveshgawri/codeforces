#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, t, flag=0;
	cin>>n>>t;
	vector <int> v(n-1);
	for (int i=1;i<n;i++){
		cin>>v[i];
	}
	for (int i=1;i<n*n + n;){
		if (i==t){
			cout<<"YES";
			flag=1;
			break;
		}
		else if (i>t){
			cout<<"NO";
			return 0;
		}
		i=i+v[i];
	}
	if (flag == 0){
		cout<<"NO";
	}
	return 0;
}