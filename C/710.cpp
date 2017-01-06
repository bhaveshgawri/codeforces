
#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a[i][j]=0;
        }
    }
    vector<int> x1, x2;
    for(int i=1; i<=n*n; i++){
        if(i%2==0){
            x2.push_back(i);
        }
        else{
            x1.push_back(i);
        }
    }
    int idx=(n-1)/2, ct=1;
    for(int i=0; i<=n/2; i++){
        int j=idx,k=0;
        while(k<ct){
            a[i][j]=1;
            k++;
            j++;
        }
        idx--;
        ct+=2;
    }
    ct=n-2, idx=1;
    for(int i=1+n/2; i<n; i++){
        int j=idx,k=0;
        while(k<ct){
            a[i][j]=1;
            k++;
            j++;
        }
        idx++;
        ct-=2;
    }
    
    int sz1=x2.size(), sz2=x1.size();
    int l=0,m=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]==0){
                a[i][j]=x2[l++];
            }
            else{
                a[i][j]=x1[m++];
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
