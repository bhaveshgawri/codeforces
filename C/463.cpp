#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n;
    cin>>n;
    long long int a[n][n], b[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%lld", &a[i][j]);
            //cin>>a[i][j];
            b[i][j]=0;
        }
    }
    for (int i=0;i<n;i++){
        ll sum=0;
        for (int j=0;j<n-i;j++){
            sum += a[i+j][j];
        }
        for (int j=0;j<n-i;j++){
            b[i+j][j] = sum;
        }
        if (i>0){
            sum = 0;
            for (int j=0;j<n-i;j++){
                sum += a[j][i+j];
            }
            for (int j=0;j<n-i;j++){
                b[j][i+j] = sum;
            }
        }
    }
    for (int i=0;i<n;i++){
        ll sum = 0;
        for (int j=i;j>=0;j--){
            sum += a[i-j][j];
        }
        for (int j=i;j>=0;j--){
            b[i-j][j] += sum;
        }
        if (i>0){
            sum = 0;
            for (int j=0;i+j<n;j++){
                sum += a[j+i][n-j-1];
            }
            for (int j=0;i+j<n;j++){
                b[j+i][n-j-1] += sum;
            }
        }
    }
    ll max1 = -1, max2=-1, x1,x2,y1,y2;
    ll sum1=0, sum2=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            b[i][j] -= a[i][j];
            if (b[i][j]>max1){
                max1 = b[i][j];
                x1=i, y1=j;
                sum1=max1;
            }
        }
    }
    int parity=0;
    if ((x1+y1)%2==1)parity = 1;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if ((((i+j)&1 && !parity) || (!((i+j)&1) && parity)) && b[i][j]>max2){
	           	max2=b[i][j];
	            x2=i, y2=j;
	            sum2=max2;
            }
        }
    }
    cout<<(ll)(sum1+sum2)<<endl<<x1+1<<" "<<y1+1<<" "<<x2+1<<" "<<y2+1<<endl;
}
