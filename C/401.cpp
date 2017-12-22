#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	if (n>m+1 || (m>n && 2*n+2<m)) cout<<-1<<endl;
	else if (m==n) for (int i=0;i<n;i++)cout<<10;
	else{
		string b="", c="";
		int count = 1;
		int lim = m+n;
		for (int i=0;i<lim;i++){
			if (m==0 || n==0) break;
			if (count%3==0) b+="0", n--;
			else b+="1", m--;
			count++;
		}
		if (m!=0 && n==0){
			while(m>0) b+="1", m--;
			c=b;
		}
		else if (m==0 && n!=0){
			c="0", n--;
			for (int i=0;i<b.length()-1;i++){
				c+=b[i];
				if (b[i]=='1' && b[i+1]=='1' && n>0) c+='0', n--;
			}
			c+=b[b.length()-1];
			if (n>0) c+='0';
		}
		cout<<c<<endl;
	}
	
}
