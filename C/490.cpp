#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int a, b;
    cin>>a>>b;
    int l = s.length();
    vector<int> left, right;
    int dig=0;
    for (int i=0;i<l;i++){
        dig = (dig*10 + s[i]-'0') % a;
        if (dig == 0)left.push_back(i);       
    }
    dig = 0;
    int k = 1;
    for (int i=l-1;i>=0;i--){
        dig = (dig + k*(s[i]-'0')) % b;
        k = (k*10) % b;
        if (dig==0)right.push_back(i);
    }
    reverse(right.begin(), right.end());
    int index=-1;
    for (int i=0;i<left.size();i++){
        if (binary_search(right.begin(), right.end(), left[i]+1)  && left[i]!=l-1 && s[left[i]+1]!='0'){
            index = left[i];
            break;
        }
    }
    if (index == -1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        for (int i=0;i<=index;i++){
            cout<<s[i];
        }
        cout<<"\n";
        for (int i=index+1;i<l;i++){
            cout<<s[i];
        }
        cout<<endl;
    }
}
