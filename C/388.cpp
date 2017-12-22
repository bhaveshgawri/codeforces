#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for (int i=0;i<n;i++){
		cin>>v[i];
	}
	int ans = 1;
	sort(v.begin(), v.end());
	for (int i=0;i<n-1;i++){
		int idx = i;
		while(i<n-1 && v[i+1]==v[i])i++;
		int boxes = (i-idx+1)/(v[idx]+1);
		ans = max(ans, boxes);
	}
	cout<<ans<<endl;
}