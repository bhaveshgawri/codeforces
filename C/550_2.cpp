#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<int> v;
    string s;
    cin>>s;
    int ls=s.size();
    v.push_back(0);
    v.push_back(0);
    for (int i=0;i<ls;i++){
        int p = s[i] - '0';
        v.push_back(p);
    }
    int lv = v.size();
    for ( int i=0 ; i < lv ; i++)
        for ( int j = i+1 ; j < lv ; j++ )
            for ( int k = j+1 ; k < lv ; k++)
                if ( (v[k] + (v[j]*10) + (v[i]*100)) % 8 == 0){
                    cout << "YES" <<endl <<  (v[k] + (v[j]*10) + (v[i]*100));
                    return 0 ;
                }
    cout << "NO";
    return 0;
}