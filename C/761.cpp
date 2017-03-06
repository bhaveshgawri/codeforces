#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int sym=999,ch=999,num=999;
	vector<string> v(n);
	vector<pair<int,pair<int,int> > >c(n);
	for (int i=0;i<n;i++){
		cin>>v[i];
		c[i].first = c[i].second.second = c[i].second.first=99999;
	}
	for(int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (v[i][j]>='0'&&v[i][j]<='9'){
				if (j<num){
					c[i].first = j;
					num=j;
				}
			}
			else if (v[i][j]=='*'||v[i][j]=='&'||v[i][j]=='#'){
				if (j<sym){
					c[i].second.first = j;
					sym = j;
				}
			}
			else if (v[i][j]>='a'&&v[i][j]<='z'){
				if (j<ch){
					c[i].second.second = j;
					ch=j;
				}
			}
		}
	}
	int ans = 99999;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			for (int k=0;k<n;k++){
				int sum = (c[i].first+c[j].second.first+c[k].second.second);
				ans = min(ans,sum);
			}
		}
	}
	if (ans!=99999)
		cout<<ans;
}
