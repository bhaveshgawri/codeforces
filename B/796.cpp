//dont use cin instead of scanf here. It will cause TLE.

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, k;
	cin>>n>>m>>k;
	vector<int>holes(4000000, 0);
	int h;
	for (int i=0;i<m;i++){
		scanf("%d", &h);
		holes[h]=1;
	}

	int bone_at = 1;
	for (int i=0;i<k;i++){
		int p, q;
		scanf("%d %d", &p,&q);
		if (holes[bone_at]){
			break;
		}
		if (bone_at==p)
			bone_at=q;
		else if (bone_at==q)
			bone_at=p;
	}
	cout<<bone_at<<endl;
}	