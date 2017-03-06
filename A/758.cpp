#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int v[n];
	for (int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	int max=v[0];
	for(int i=1;i<n;i++){
		if (v[i]>max)
			max=v[i];
	}
	//printf("%d\n",max);
	int ans=0;
	for (int i=0;i<n;i++){
		ans+=(max-v[i]);
	}
	printf("%d\n",ans);
}