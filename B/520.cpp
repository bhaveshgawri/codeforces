#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector< vector<int> >W(10004);
int v[10004] = {0};
int dist[10004] = {0};

int main(){
	int n,m;
	cin>>n>>m;
	for (int i=1;i<5002;i++){
		W[i].push_back(2*i);
		W[i].push_back(i-1);
	}
	for (int i=5002;i<10004;i++){
		W[i].push_back(i-1);
	}
	int start = n;
	queue<int> Q;
	Q.push(start);
	v[start] = 1;
	while(!Q.empty()){
		int i = Q.front();
		Q.pop();
		for (auto it = W[i].begin();it != W[i].end(); ++it){
			
			if (v[*it] == 0){
			//cout<< *it <<" ";
				Q.push(*it);
				v[*it] = 1;
				dist[*it] = dist[i] + 1;
				if (*it == m){
					cout<<dist[*it];
					return 0;
				}
			}	
		}
	}
}

