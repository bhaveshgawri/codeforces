#include <bits/stdc++.h>
using namespace std;

string s;
int n, p;

int compute(int start, int end){
	int l=0, r=0, ans=0;
	for (int i = start;i<=end;i++){
		int x = n-i+1;
		if (s[i-1] != s[x-1]){	
			int minn = min(abs(s[x-1]-s[i-1]), abs(26-abs(s[x-1]-s[i-1])));
			ans += minn;
			if (l==0) l=i;
			r=i;
		}
	}
	if (l>0)ans += min(abs(p-l), abs(p-r))+r-l;
	return ans;
}

int main(){
	cin>>n>>p;
	cin>>s;
	if (p<=n/2)cout<<compute(1, n/2);
	else cout<<compute(n/2+1, n);
}
