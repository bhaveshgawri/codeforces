#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector <int> v(n);
	for (int i=0;i<n;i++){
		cin>>v[i];
	}
	int count[n][n]={0};
	int ans = 0,count_one=0,count_zero=0,flag=0;
	for (int i=0;i<n;i++){
		if (v[i]==0)
			count_zero++;
		else 
			count_one++;
	}
	if (count_one==n){
		cout<<n-1;
	}
	else{
		for (int i=0;i<n;i++){
			count_zero = 0;
			count_one = 0;
			for (int j=i;j<n;j++){
				if (v[j]==0)
					count_zero++;
				else 
					count_one++;
				
				count[i][j] = max(count_zero,count_one);
				
				for(int k=0;k<i;k++)
					if (v[k]==1)
						count[i][j]++;
				if (j<n)
					for (int k=j+1;k<n;k++)
						if (v[k]==1)
							count[i][j]++;

				if (ans < count[i][j])
					ans = count[i][j];
				//cout<<i<<" "<<j<<" "<<count_zero<<" " <<count_one<<" "<<ans<<endl;
			}
		}
		cout<<ans;
	}
}