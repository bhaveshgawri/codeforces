#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define f first
#define s second

int main(){
	int n,k;
	cin>>n>>k;
	int sum=0;
	vector< pair<int, pair<int, int> > >p(n);
	for (int i=0;i<n;i++){
		cin>>p[i].s.f;
	}
	for (int i=0;i<n;i++){
		cin>>p[i].s.s;
		p[i].f=p[i].s.f-p[i].s.s;
	}
	sort(p.begin(),p.end());
	for (int i=0;i<k;i++){
		sum+=p[i].s.f;
	}
	for (int i=k;i<n;i++){
		sum += p[i].f<0?p[i].s.f:p[i].s.s;
	}
	cout<<sum<<endl;
}