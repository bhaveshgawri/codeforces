#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define ff first
#define ss second

int main(){
	int n, m;
	cin>>n>>m;
	vector<ii> v(n);
	if (m!=0 && n!=0){
		cout<<min(m+1, n+1)<<endl;
		ii pt;
		if (m<n)pt={0, m};
		else pt={n, 0};
		for (int i=0;i<=min(m, n);i++){
			if (m<n)
				cout<<pt.ff+i<<" "<<pt.ss-i<<endl;
			else
				cout<<pt.ff-i<<" "<<pt.ss+i<<endl;
		}
	}
	else{
		cout<<1<<endl;
		if (m==0)cout<<n<<" "<<0<<endl;
		else cout<<0<<" "<<m<<endl;
	}
}
