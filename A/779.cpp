#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin>>n;
	int A[n], B[n], counta[6],countb[6];
	for (int i=1;i<=5;i++){
		counta[i]=countb[i]=0;
	}

	for (int i=0;i<n;i++){
		cin>>A[i];
		counta[A[i]]++;
	}


	for (int i=0;i<n;i++){
		cin>>B[i];
		countb[B[i]]++;
	}

	int ans = 0;
	for (int i=1;i<=5;i++){
		if (counta[i]%2!=countb[i]%2){
			cout<<-1<<endl;
			return 0;
		}
		ans += abs(counta[i]-countb[i]);
	}
	cout<<ans/4<<endl;
}