#include <iostream>
#include <vector>
#include <algorithm>

#define INF 9999999
 
using namespace std;

//iterative
int main(){
	int n;
	vector<int> v(3);
	cin>>n>>v[0]>>v[1]>>v[2];
	vector<int> pieces(4004, -1*INF);
	pieces[0]=0,pieces[v[0]]=1,pieces[v[1]]=1,pieces[v[2]]=1;
	for (int total_len=1;total_len<=n;total_len++){
		for (int j=0;j<3;j++){
			if (v[j] > total_len)
				continue;
			pieces[total_len] = max(pieces[total_len] , pieces[total_len - v[j]]+1);
		}
	}
	cout<<pieces[n];
}