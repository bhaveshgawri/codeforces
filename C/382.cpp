#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for (int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	map<int, int> d;
	for (int i=0;i<n-1;i++){
		d[v[i+1]-v[i]]++;
	}
	auto max = d.rbegin();
	auto min = d.begin();
	int uniq = d.size();
	// cout<<min->first<<" "<<max->first<<endl;
	if (uniq == 0){
		cout<<-1<<endl;
	}
	else if (uniq==1){
		vector<int> ans;
		if (v.size()==2){
			if (!((v[0]+v[1])%2)){
				ans.push_back((v[0]+v[1])/2);
			}
		}
		ans.push_back(v[0]-min->first), ans.push_back(v[n-1]+min->first);
		sort(ans.begin(), ans.end());
		ans.resize(distance(ans.begin(), unique(ans.begin(), ans.end())));
		cout<<ans.size()<<endl;
		for (int i: ans)cout<<i<<" ";cout<<endl;
	}
	else if (uniq==2){
		if (min->second >= max->second && max->second == 1){
			int flag = 0;
			for (int i=0;i<n-1;i++){
				if (v[i+1]-v[i] == max->first && v[i]+2*min->first==v[i+1]){
					cout<<1<<endl;
					cout<<v[i]+min->first<<endl;						
					flag = 1;
					break;
				}
			}
			if (!flag)cout<<0<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	else{
		cout<<0<<endl;
	}
}