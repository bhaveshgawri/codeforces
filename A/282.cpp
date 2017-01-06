#include<iostream>

using namespace std;

int main(){
    int t,x=0;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if (s=="++X") ++x;
        else if (s=="X++") x++;
        else if (s=="--X") --x;
        else if (s=="X--") x--;
    }
    cout<<x;
    return 0;
}
