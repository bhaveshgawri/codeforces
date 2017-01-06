#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n,b,d,count=0;
	long long int sum=0;
	cin>>n>>b>>d;
	vector<int> v(n);
	for (int i=0;i<n;i++){
		int p;
		cin>>p;
		if (p<=b) sum+=p;
		if (sum>d) {
		    count++;
		    sum=0;
		}
	}
	cout<<count;
}
