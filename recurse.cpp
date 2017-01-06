#include <iostream>

using namespace std;

//calculate the recursion depth 

void recurse(int count){
	cout<<count<<endl;
	recurse(count+1);
}

int main(){
	int count=0;
	recurse(count);
}