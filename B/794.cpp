#include <cmath>
#include <cstdio>

using namespace std;

int main(){
	int n, h;
	scanf("%d %d", &n,&h);
	double h1 = double(h)/sqrt(n);
	for (int i=1;i<n;i++){
		printf("%.52lf ", sqrt(i)*h1);
	}
}