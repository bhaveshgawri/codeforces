#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    string s;
    char p;
    while(scanf("%c",&p)==1){
	if((p!='a')&&(p!='A')&&(p!='e')&&(p!='E')&&(p!='i')&&(p!='I')&&(p!='o')&&(p!='O')&&(p!='u')&&(p!='U')&&(p!='y')&&(p!='Y')){
	   s.push_back('.');    
           s.push_back((char)tolower(p));
        }
    }
        s.erase(s.length()-2);
	cout<<s;
    return 0;
}
