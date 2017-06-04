#include <bits/stdc++.h>

using namespace std;

queue<int> q;
vector<int> visited(200004);
vector<int> v(200004);
vector<int> dist(200004, 0);

void bfs(int n){
	while(!q.empty()){
		int idx = q.front();
		q.pop();
		if (idx-1>=0 && visited[idx-1]==0 && v[idx-1]!=0){
			dist[idx-1]=dist[idx]+1;
			q.push(idx-1);
			visited[idx-1]=1;
		}
		if (idx+1<n && visited[idx+1]==0 && v[idx+1]!=0){
			dist[idx+1]=dist[idx]+1;
			q.push(idx+1);
			visited[idx+1]=1;			
		}
	}
}

int main(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>v[i];
		if (v[i]==0)
			q.push(i);
	}
	bfs(n);
	for (int i=0;i<n;i++){
		cout<<dist[i]<<" ";
	}
	cout<<endl;
}