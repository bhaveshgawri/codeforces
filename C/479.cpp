#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<pair<int, int>> v(n);
	for (int i=0;i<n;i++){
		cin>>v[i].first>>v[i].second;
	}
	sort(v.begin(), v.end());
	int maxx = -1;
	for (auto i: v){
		if (i.second >= maxx) maxx = i.second;
		else maxx = i.first;
	}
	cout<<maxx<<endl;
}
