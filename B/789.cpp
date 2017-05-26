#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main(){
	int b, q, l, m;
	cin>>b>>q>>l>>m;
	vector<int> bad(m);
	for (int i=0;i<m;i++){
		cin>>bad[i];
	}
	sort(bad.begin(), bad.end());

	if (abs(b)>l)
		cout<<0<<endl;	
	else if (q==1){
		if (!binary_search(bad.begin(), bad.end(), b))
			cout<<"inf"<<endl;
		else
			cout<<0<<endl;
	}
	else if (q==0 || b==0){
		if (binary_search(bad.begin(), bad.end(), 0) && !binary_search(bad.begin(), bad.end(), b))
			cout<<1<<endl;
		else if (binary_search(bad.begin(), bad.end(), 0) && binary_search(bad.begin(), bad.end(), b))
			cout<<0<<endl;
		else if (!binary_search(bad.begin(), bad.end(), 0))
			cout<<"inf"<<endl;
	}
	else if (q==-1){
		if (binary_search(bad.begin(), bad.end(), b) && binary_search(bad.begin(), bad.end(), -1*b))
			cout<<0<<endl;
		else
			cout<<"inf"<<endl;
	}
	else{
		ll first_number = b;
		ll the_number = first_number;
		ll count = 0;
		while (abs(the_number)<=l){
			if (!binary_search(bad.begin(), bad.end(), the_number))
				count++;
			the_number*=q;
		}
			cout<<count<<endl;
	}
}