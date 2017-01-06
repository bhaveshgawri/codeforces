#include <iostream>

using namespace std;

#define MIN(a,b) a>b?b:a
#define MIN3(a,b,c) MIN(MIN(a,b),c)
#define MAX(a,b) a>b?a:b
#define MAX3(a,b,c) MAX(MAX(a,b),c)


int main(){
	int x,y,ans=0;
	cin>>x>>y;
	int f=y,s=y,t=y;
	int ftemp,stemp,ttemp;
	while(true){
		f=MIN(x,s+t-1);
		ftemp=f;
		stemp=s;
		ttemp=t;
		f=MIN3(ftemp,stemp,ttemp);
		t=MAX3(ftemp,stemp,ttemp);
		s=ftemp+stemp+ttemp-f-t;
		ans++;
		if (f==x || ftemp + stemp + ttemp == 3*y)break; 
	}
	cout<<ans;
}
