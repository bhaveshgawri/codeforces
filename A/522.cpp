#include <bits/stdc++.h>

using namespace std;

map <string, int> m;

int main(){
	int n, ans=0;
	m["polycarp"]=1;
	cin>>n;
	string child, _, parent;
	for (int i=0;i<n;i++){
		cin>>child>>_>>parent;
		for (int i=0;i<child.size();i++)
			if (child[i]<=90 && child[i]>=65)
				child[i]+=32;
		for (int i=0;i<parent.size();i++)
			if (parent[i]<=90 && parent[i]>=65)
				parent[i]+=32;
		m[child]=m[parent]+1;
		ans = max(ans, m[child]);
	}
	cout<<ans<<endl;
}