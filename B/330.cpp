#include <bits/stdc++.h>

using namespace std;

vector<int> constraint(1004, 0);

int main(){
	int n, m, p, q, a_variable;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>p>>q;
		constraint[p]=constraint[q]=1;
	}
	for (int i=1;i<=n;i++)
		if (constraint[i]==0)
			a_variable = i;
	cout<<n-1<<endl;
	for (int i=1;i<=n;i++)
		if (a_variable!=i)
			cout<<a_variable<<" "<<i<<endl;
}