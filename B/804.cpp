#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MOD 1000000007;

using namespace std;

int main(){
	string s;
	cin>>s;
	int len = s.length();
	vector<int> initial(len);
	int b_count=0;
	for (int i=len-1;i>=0;i--){
		if (s[i]=='a')
			initial[i]=b_count;
		if (s[i]=='b'){
			initial[i]=b_count;
			b_count++;
		}
	}
	reverse(s.begin(),s.end());
	reverse(initial.begin(), initial.end());
	vector<int> bs(len, 0);
	int prev_sum=0;
	for (int i=0,k=1;i<len;i++){
		if (s[i]=='a'){
			bs[k] = initial[i]+prev_sum;
			bs[k] = bs[k]%MOD;
			prev_sum+=bs[k];
			prev_sum=prev_sum%MOD
			k++;
		}
	}
	int ans=0;
	for (int i=0;i<len;i++){
		ans+=bs[i];
		ans=ans%MOD;
	}
	cout<<ans;
}