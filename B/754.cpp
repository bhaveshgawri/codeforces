#include <iostream>

using namespace std;

int main(){
	char v[8][8];
	for (int i=2;i<6;i++){
		for (int j=2;j<6;j++){
			cin>>v[i][j];
		}
	}
	for (int i=2;i<6;i++){
		for (int j=2;j<6;j++){
			if (v[i][j]=='x'){
				if (
					//horiz
					   v[i][j-1]=='.'&&v[i][j-2]=='x' || v[i][j-1]=='x'&&v[i][j-2]=='.'
					|| v[i][j+1]=='.'&&v[i][j+2]=='x' || v[i][j+1]=='x'&&v[i][j+2]=='.'
					|| v[i][j-1]=='.'&& v[i][j+1]=='x' || v[i][j-1]=='x'&& v[i][j+1]=='.'
					//verti
					||v[i-1][j]=='.'&&v[i-2][j]=='x' || v[i-1][j]=='x'&&v[i-2][j]=='.'
					|| v[i+1][j]=='.'&&v[i+2][j]=='x' || v[i+1][j]=='x'&&v[i+2][j]=='.'
					|| v[i-1][j]=='.'&& v[i+1][j]=='x' || v[i-1][j]=='x'&& v[i+1][j]=='.'
					//diagon 1 
					|| v[i+1][j+1]=='.'&&v[i+2][j+2]=='x' || v[i+1][j+1]=='x'&&v[i+2][j+2]=='.'
					|| v[i-1][j-1]=='.'&&v[i-2][j-2]=='x' || v[i-1][j-1]=='x'&&v[i-2][j-2]=='.'
					|| v[i-1][j-1]=='.'&&v[i+1][j+1]=='x' || v[i-1][j-1]=='x'&&v[i+1][j+1]=='.'
					//diagon 2
					|| v[i-1][j+1]=='.'&&v[i-2][j+2]=='x' || v[i-1][j+1]=='x'&&v[i-2][j+2]=='.'
					|| v[i+1][j-1]=='.'&&v[i+2][j-2]=='x' || v[i+1][j-1]=='x'&&v[i+2][j-2]=='.'
					|| v[i+1][j-1]=='.'&&v[i-1][j+1]=='x' || v[i+1][j-1]=='x'&&v[i-1][j+1]=='.' 
					){
					cout<<"YES";
					return 0;
				} 
			}
		}
	}
	cout<<"NO";
}