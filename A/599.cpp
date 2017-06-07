#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int a, b, c;
	cin>>a>>b>>c;
	cout<<min(a+b+c, min(2*a+2*b, min(2*b+2*c, 2*a+2*c)))<<endl;
}