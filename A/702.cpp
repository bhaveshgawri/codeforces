#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n,count=1;
	cin>>n;
	vector<int> v(n);
	vector<int> c;
	for (int i=0;i<n;i++){
		cin>>v[i];
		//cout<<v[i];
	}
	for (int i=0;i<n-1;i++){
		if (v[i]<v[i+1])count++;
		else if (v[i]>v[i+1] || v[i]==v[i+1]){
			//i=count;
			c.push_back(count);
			count=1;
		}
	}
	c.push_back(count);
	cout<<*max_element(c.begin(),c.end())<<endl;
}
