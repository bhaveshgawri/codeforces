#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n, f;
	cin>>n>>f;
	int k, l;
	vector<int>v;
	long long int ans = 0;
	for (int i=0;i<n;i++){
		cin>>k>>l;
		ans+=min(k,l);
		if (l>k)
			v.push_back(min(k ,l-k));
	}
	sort(v.rbegin(), v.rend());
	for (int i=0;i<f&&i<v.size();i++){
		ans+=v[i];
	}
	cout<<ans<<endl;
}