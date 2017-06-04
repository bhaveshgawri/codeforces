#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int main(){
	int n, m, p, q;
	cin>>n>>m;
	vector< vector<int> >N(n+1);
	for (int i=1;i<=m;i++){
		cin>>p>>q;
		N[p].pb(q);
		N[q].pb(p);
	}
	int countn=0,count1=0,count2=0;
	for (auto i: N){
		if (i.size()==1)
			count1++;
		else if (i.size()==2)
			count2++;
		else if (i.size()==n-1)
			countn++;
	}
	if (count1==2 && count2==n-2){
		cout<<"bus topology"<<endl;
	}
	else if (count1==n-1 && countn==1){
		cout<<"star topology"<<endl;
	}
	else if (count2==n){
		cout<<"ring topology"<<endl;
	}
	else{
		cout<<"unknown topology"<<endl;
	}
}