#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int x)
{
  if (x < 2) return false;
  for(int i=2; i<= sqrt(x); i++) {
    if ((x%i) == 0) return false;
  }
  return true;
}

int main(){
	int n;
	cin>>n;
	if (n==1){
		cout<<3;
	}
	else if (n==2){
		cout<<4;
	}
	else{
		if (n%2==1){
			cout<<1;
		}
		else{
			for (int i=1;i<=1000;i++){
				if (!isPrime(n*i+1)){
					cout<<i;
					break;
				}
			}
		}

	}
}