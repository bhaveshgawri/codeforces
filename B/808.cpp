#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
	int k, n;
	cin>>n>>k;
	vector<int> input(n);
	long long initial_sum = 0;
	for (int i=0;i<n;i++){
		cin>>input[i];
		if (i<k){
			initial_sum+=input[i];
		}
	}
	double average_sum=0.0;
	for (int i=0;i<n-k;i++){
		average_sum+=initial_sum;
		initial_sum = initial_sum - input[i] + input[k+i];
	}
	average_sum+=initial_sum;
	if (n!=1)
		printf("%.10f\n", double(average_sum)/(n-k+1));
	else
		printf("%.10f\n", double(average_sum));
}