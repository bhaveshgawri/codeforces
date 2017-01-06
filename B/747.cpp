#include <iostream>
#include <string>

using namespace std;

#define max_(a,b) a>=b?a:b

int main(){
	int l;
	cin>>l;
	string s;
	cin>>s;
	int A=0,T=0,C=0,G=0,Q=0;
	for (int i=0;i<l;i++){
		if(s[i]=='A')A++;
		else if(s[i]=='T')T++;
		else if(s[i]=='G')G++;
		else if(s[i]=='C')C++;
	}
	Q = -(A+T+G+C)+l;
	//cout<<Q<<" "<<A<<" "<<C<<" "<<G<<" "<<T<<" "<<endl;
	int p=max_(G,C);
	int c=max_(A,T);
	//cout<<p<<endl;
	int max = max_(c,p);
	//cout<<max<<endl;
	if(l%4==0 && max<=l/4){
		for (int i=0;i<l;i++){
			if (A == l/4){
					break;
			}
			if (s[i]=='?'){
				s[i]='A';
				A++;
				
			}
		}
		for (int i=0;i<l;i++){
			if (T==l/4){
					break;
				}
			if (s[i]=='?'){
				s[i]='T';
				T++;
			}
		}
		for (int i=0;i<l;i++){
			if (G == l/4){
					break;
			}
			if (s[i]=='?'){
				s[i]='G';
				G++;
			}
		}
		for (int i=0;i<l;i++){
			if (C==l/4){
				break;
			}
			if (s[i]=='?'){
				s[i]='C';
				C++;
			}
		}
		cout<<s;
	}
	else cout<<"===";
}

