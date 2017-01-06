#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector< pair<int,int> > v(n);
	int left=0,right=0;
	for (int i=0;i<n;i++){
		cin>>v[i].first>>v[i].second;
		left+=v[i].first;
		right+=v[i].second;
	}
	int beauty = abs(left-right),ans=0;
	for (int i=0;i<n;i++){
		if (beauty < abs((left-right) - 2*(v[i].first-v[i].second))){
			beauty = abs((left-right) - 2*(v[i].first-v[i].second));
			ans = i+1;
		}
	}
	cout<<ans;
}