#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int m,n,p;
	long long int max=0,min=0;
	cin>>n>>m;
	p=n;
	vector<int> v(m);
	vector<int> c(m);
	for (int i=0;i<m;i++){
		cin>>v[i];
		c[i]=v[i];
	}
	sort(v.begin(),v.end());
	sort(c.begin(),c.end());
	
	for (int i=m-1;i>=0;i--){
		//cout<<max<<endl;
		max+=v[i];
		v[i]--;
		sort(v.begin(),v.end());
		/*for (int i=0;i<m;i++){
			cout<<v[i]<<" ";
		}*/
		p--;
		//cout<<endl<<p<<endl;
		if(p==0)break;
		i++;
	}    
	p=n;
	int q=0;
	while(p--){
		min+=c[q];
		c[q]--;
		if(c[q]==0){
			q++;
		}
	}
	cout<<max<<" "<<min;
}
