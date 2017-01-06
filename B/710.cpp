#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int num;
    cin >> num;
    long long int sum;
    long long int idx=0,temp;
    int a1[num];
    for(int i=0; i<num; i++){
        cin >> a1[i];
        if(i!=0){
            sum+=a1[i];
        }
    }
    sort(a1,a1+num);
    long long int lo=1, hi=num-1, min=sum, ans=0;

    while(hi>=0 && idx<num-1){
        temp=a1[idx+1]-a1[idx];
        sum=abs(sum-(hi*temp)+lo*temp);
        if(min>sum){
            min=sum;
            ans=a1[idx+1];
        }
        //cout << s << endl;
        lo++;
        hi--;
        idx++;
    }
    cout << ans << endl;
    return 0;
}
