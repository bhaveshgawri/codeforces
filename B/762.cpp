#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main(){
	int u,p,b,m;
	cin>>u>>p>>b>>m;
	pair<ll,ll> ans;
	ans.first=ans.second=0;
	vector< pair<ll,string> >v(m);
	for(int i=0;i<m;i++){
		cin>>v[i].first>>v[i].second;	
	}
	sort(v.begin(), v.end(), [](auto &left, auto &right) {
    	return left.first < right.first;
	});
	for (int i=0;i<m;i++){
		if (u>0 && v[i].second == "USB"){
			u--;
			ans.second+=v[i].first;
			ans.first++;
		}
		else if (p>0 && v[i].second == "PS/2"){
			p--;
			ans.second+=v[i].first;
			ans.first++;
		}
		else if(b>0){
			b--;
			ans.second+=v[i].first;
			ans.first++;
		}
	}
	cout<<ans.first<<" "<<ans.second;
}
