#include<iostream>

using namespace std;

int main(){
        int b,c,t,n,count=0;
        string a;
        cin>>t;
        while(t--){
                cin>>a;
                count=a.size();
                if (count>10){
                        cout<<a[0]<<count-2<<a[count-1]<<endl;
                }
                else{
                        cout<<a<<endl;
                }
        }
return 0;        
}
