#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	vector<pair<int, int> >v(n);
	vector<int> c(n);
	for (int i=0;i<n;i++){
		cin>>v[i].first;
		v[i].second=0;
		if (v[i].first%2==0)
			c[i]=v[i].first/2;
		else
			c[i]=v[i].first/2+1;
		m-=c[i];
	}
	if (m<0){
		cout<<-1<<endl;
		return 0;
	}
	for (int i=0;i<n;i++){
		int min=999999;
		int min_idx;
		for (int j=0;j<n;j++){
			if (v[j].first<min && v[j].second==0){
				min=v[j].first;
				min_idx=j;
			}
		}
		v[min_idx].second=1;
		//cout<<v[min_idx].first<<endl;
		for (int j=0;j<n;j++){
			//cout<<m<<" ";
			if (v[j].first>min){
				if(c[j]<c[min_idx]){
					if (m>=c[min_idx]-c[j]+1){
						c[j]+=(c[min_idx]-c[j]+1);
						m-=(c[min_idx]-c[j]+1);
					}
					else{
						cout<<-1<<endl;
						return 0;
					}
				}
			}
		}
	}
	while(m){
		int max=-1;
		int max_index;
		for (int i=0;i<n;i++){
			if (v[i].first>max && v[i].first!=c[i]){
				max=v[i].first;
				max_index=i;
			}
		}
		if (m>=v[max_index].first-c[max_index]){
			m-=(v[max_index].first-c[max_index]);
			c[max_index]+=(v[max_index].first-c[max_index]);
		}
		else{
			c[max_index]+=m;
			m=0;
		}
	}
	for (int i=0;i<n;i++){
		cout<<c[i]<<" ";
	}
	cout<<endl;
}