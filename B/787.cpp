#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	int count=0;
	int group_freq[10004];
	for (int i=0;i<m;i++){
		cin>>group_freq[0];
		for (int j=1;j<=group_freq[0];j++){
			cin>>group_freq[j];
		}
		int group_array[10004]={0};
		for (int j=1;j<=group_freq[0];j++){
			if (group_freq[j]>0){
				group_array[group_freq[j]]=1;
			}
		}
		int match=0;
		for (int j=1;j<=group_freq[0];j++){
			if (group_freq[j]<0){
				if (group_array[abs(group_freq[j])]!=1){
					continue;
				}
				else{
					match=1;
				}
			}
		}
		count+=match;
	}
	if (count==m)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
}