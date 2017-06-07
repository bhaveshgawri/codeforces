#include <iostream>

using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	int x=0, y=0;
	for (int i=1;i<=100004;i++){
		if ((x>=0 && y>0) || (x>0 && y>=0)){
			break;
		}
		x = n-i*m;
		y= 2*i*m-n;
	}
	if (x<0 || y<0)
		cout<<-1<<endl;
	else
		cout<<x+y<<endl;
}