#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> v(m);
	for (int i=0;i<m;i++){
		cin>>v[i];
	}

	sort(v.begin(),v.end());
	int min = v[n-1]-v[0],i=0;
	//cout<<min;
	while(true){
		if (n+i == m)break;
		i++;
		int p = v[n-1+i]-v[i];
		if (min>p)min=p;
	}
	cout<<min;
}