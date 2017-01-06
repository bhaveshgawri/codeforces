#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(){
	int n,day,w=0,p;
	cin>>n;
	vector<int> v(n);
	for (int i=0;i<n;i++){
		cin >> v[i];
	}
	sort(v.begin(),v.end());
	cin>>day;
	vector<int> c(day);
	for (int i=0;i<day;i++){
		cin >> c[i];
	}
	for(int i=0; i<day; i++){
		int m=c[i];
		int idx=(int)(upper_bound(v.begin(), v.end(), m)-v.begin());
		cout << idx << endl;
	}
}
