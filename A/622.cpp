#include <iostream>

int main(){
    long long int n,m,i=1;
    std::cin>>n;
    m=n;
    while(n-i>0){
        n=n-i;
        i++;
    }
    std::cout<<n;
}
