//runtime error on a testcase;

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define	PB	push_back
#define	MP	make_pair

using namespace std;

int main(){
	int n;
	cin>>n;
	vector< pair<int, pair<int, int> > > input(n);
	set<int> one, two, three;
	for (int i=0;i<n;i++){
		cin>>input[i].first;
	}
	for (int i=0;i<n;i++){
		cin>>input[i].second.first;
	}
	for (int i=0;i<n;i++){
		cin>>input[i].second.second;
	}
	for (int i=0;i<n;i++){
		if (input[i].second.first==1 || input[i].second.second==1){
			one.insert(input[i].first);
		}
		if (input[i].second.first==2 || input[i].second.second==2){
			two.insert(input[i].first);
		}
		if (input[i].second.first==3 || input[i].second.second==3){
			three.insert(input[i].first);
		}
	}
	int m;
	cin>>m;
	vector<int> buyer(m);
	for (int i=0;i<m;i++){
		cin>>buyer[i];	
	}
	set<int>::iterator to_remove;
	int came_from;
	for (int i=0;i<m;i++){
		if (buyer[i]==1){
			if (one.size()>0){     
				cout<<*(one.begin())<<" ";
				to_remove = one.begin();
				came_from = 1;
			}
			else{
				cout<<-1<<" ";
				continue;
			}
		}
		else if (buyer[i]==2){
			if (two.size()>0){
				cout<<*(two.begin())<<" ";
				to_remove = two.begin();
				came_from = 2;
			}
			else{
				cout<<-1<<" ";
				continue;
			}
		}
		else if (buyer[i]==3){
			if (three.size()>0){
				cout<<*(three.begin())<<" ";
				to_remove = three.begin();
				came_from = 3;
			}
			else{
				cout<<-1<<" ";
				continue;
			}
		}
		if (came_from==1){
			one.erase(to_remove);
			auto sec = two.find(*to_remove);
			if (sec!=two.end()){
				two.erase(sec);
			}
			auto thi = three.find(*to_remove);
			if (thi!=three.end()){
				three.erase(thi);
			}
		}
		else if(came_from==2){
			two.erase(to_remove);
			auto fir = one.find(*to_remove);
			if (fir!=one.end()){
				one.erase(fir);
			}
			auto thi = three.find(*to_remove);
			if (thi!=three.end()){
				three.erase(thi);
			}
		}
		else if (came_from==3){
			three.erase(to_remove);
			auto fir = one.find(*to_remove);
			if (fir!=one.end()){
				one.erase(fir);
			}
			auto sec = two.find(*to_remove);
			if (sec!=two.end()){
				two.erase(sec);
			}
		}
	}
}