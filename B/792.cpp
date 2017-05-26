#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin>>n>>k;
	vector<int> v(k);
	set<int>nums;
	for (int i=1;i<=n;i++){
		nums.insert(i);
	}
	for (int i=0;i<k;i++){
		cin>>v[i];
	}
	set<int>::iterator leader = nums.begin();
	for (int i=0;i<k;i++){
		int to_incr = v[i];
		to_incr%=(nums.size());
		for (int j=0;j<to_incr;j++){
			leader++;
			if (leader==nums.end())
				leader = nums.begin();
		}
		cout<<*(leader)<<" ";
		leader = nums.erase(leader);
		if (leader==nums.end())
			leader=nums.begin();
	}

}