#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n,s;
	cin>>n;
	vector <int> v(n);
	for (int i=0;i<n;i++){
		cin>>v[i];
	}
	int count=1;
	sort (v.begin(),v.end());
	//cout<<v.front()<<" "<<v.back();
	if (v.front()==v.back()){cout<<"pYES";return 0;}
	//cout<<m<<endl;
	for (int i=0;i<n-1;i++){
		if (v[i]!=v[i+1]){
			count++;//cout<<count<<endl;
			if (count==2) s=i+1;
			//cout<<v[i]<<endl<<endl;
			if (count>3){cout<<"pNO";return 0;}
		}	
	}
	int m=v[0];
	int n2=v[s];
	int o=v.back();
	cout<<m<< " "<< n2<<" " <<o<<" "<<endl;
	if ((n2==o && m%2==0 && o%2==0)||(n2==o && m%2==1 && o%2==1)){cout<<"cYES";return 0;}
	int p = n2-m;
	int q = o-n2;
	//cout<<m<< " "<< n2<<" " <<o<<" "<<p<<" " <<q<<" "<<endl;
	if (p==q) cout<<"YES";
	else cout<<"NO";
}
