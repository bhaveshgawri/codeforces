#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main(){
	int n;
	cin>>n;
	string s;
	int ans =0;
	for (int i=0;i<n;i++){
		cin>>s;
		if (s=="Tetrahedron")
			ans+=4;
		else if (s=="Cube")
			ans+=6;
		else if (s=="Octahedron")
			ans+=8;
		else if (s=="Dodecahedron")
			ans+=12;
		else
			ans+=20;
	}
	cout<<ans;
}