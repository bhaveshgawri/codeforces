#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<string> v(n);
	vector<string> c(n);
	for (int i=0;i<n;i++){
		cin>>v[i];
		c[i]=v[i];
		sort(c[i].begin(), c[i].end());
	}
	for (int i=0;i<n-1;i++){
		if (c[i]!=c[i+1]){
			cout<<-1<<endl;
			return 0;
		}
	}
	for (int i=0;i<n;i++){
		c[i]=v[i];
	}
	int ans = INT_MAX;
	string match = v[0];
	for (int p=0;p<match.length();p++){
		//cout<<match<<endl;
		int temp_ans = 0;
		for (int i=0;i<n;i++){
			int count = 0;
			//cout<<v[i]<<endl;
			while(v[i]!=match){
				char temp = v[i][0];
				for (int j=0;j<v[i].length()-1;j++){
					v[i][j]=v[i][j+1];
				} 
				v[i][v[i].length()-1] = temp;
				count++;
			}
			temp_ans += count;
		}
		//cout<<temp_ans<<endl;
		char temp = match[0];
		for (int j=0;j<match.length()-1;j++){
			match[j]=match[j+1];
		} 
		match[match.length()-1] = temp;
		ans = min(ans, temp_ans);
		for (int i=0;i<n;i++){
			v[i]=c[i];
		}
	}
	cout<<ans<<endl;
}