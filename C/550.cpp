#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	vector<int> v;
	string s;
	cin>>s;
	int l=s.size();
	for (int i=0;i<l;i++){
		int p = s[i] - '0';
		v.push_back(p);
	} 
	if (l==1){
		if (v[0]%8==0)
			cout<<"YES"<<endl<<v[0];
		else
			cout<<"NO";
	}
	else if (l==2){
		if ((v[1]*10+v[0])%8==0)
			cout<<"YES"<<endl<<v[1]*10+v[0];
		else if (v[0]%8==0)
			cout<<"YES"<<endl<<v[0];
		else if (v[1]%8==0)
			cout<<"YES"<<endl<<v[1];
		else 
			cout<<"NO";
	}
	else if (l>=3){
		for (int i=0;i<l;i++)
			for (int j=i+1;j<l;j++)
				for (int k=j+1;k<l;k++){
					if (l>=1&&(v[j]%8==0||v[i]%8==0||v[k]%8==0)){
						cout<<"YES"<<endl;
						if (v[j]%8==0)
							cout<<v[j];
						else if (v[i]%8==0)
							cout<<v[i];
						else if (v[k]%8==0)
							cout<<v[k];
						return 0;
					}
					else if (l>=2&&(10*v[j]+v[k])%8==0||(10*v[i]+v[j])%8==0||(10*v[i]+v[k])%8==0){
						cout<<"YES"<<endl;
						if ((10*v[j]+v[k])%8==0)
							cout<<10*v[j]+v[k];
						else if ((10*v[i]+v[k])%8==0)
							cout<<10*v[i]+v[k];
						else if ((10*v[i]+v[j])%8==0)
							cout<<10*v[i]+v[j];
						return 0;
					}
					else if (l>=3&&(100*v[i]+10*v[j]+v[k])%8==0){
						cout<<"YES"<<endl<<100*v[i]+10*v[j]+v[k];//<<" i"<<v[i]<<" j"<<v[j]<<" k"<<v[k]<<endl;
						return 0;
					}
				}
		cout<<"NO";
	}
}