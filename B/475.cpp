#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int> > W(500);
vector<int> visited(500,0);
int n, m, count_=0; 

int dfs(int vertex){
	if (visited[vertex] == 0){
		visited[vertex] = 1;
		count_+=1;
		//cout<<"count_"<<count_<<endl;
		for (auto it = W[vertex].begin();it!=W[vertex].end();it++){
			//cout<<"*it"<<*it<<endl;
			dfs(*it);
		}
	}
	return count_;
}


void initialize(){
	cin>>n>>m;
	string hor, ver;
	cin>>hor>>ver;
	int i=1;
	for (int j=0; j<n; j++){	
		for (i; (i%m!=0 && i<=m*n); i++){
			//cout<<i<<endl;
			if (hor[j] == '>'){
				W[i].push_back(i+1);
				//cout<<i<<"--"<<i+1<<endl;
			}
			else if (hor[j] == '<'){
				W[i+1].push_back(i);
				//cout<<i+1<<"--"<<i<<endl;
			}
		}
		i++;
	}
	i=1;
	for (int j=0; j<m; j++){
		for(i;i<=m*n; i+=m){
			//cout<<i<<endl;
			if(ver[j] == 'v' && i+m <= m*n){ //with m*n as total intersections (i+m)th intersection should exist to be appended into the W
				W[i].push_back(i+m);
				//cout<<i<<"--"<<i+m<<endl;
			}
			else if (ver[j] == '^' && i+m <= m*n){
				W[i+m].push_back(i);
				//cout<<i+m<<"--"<<i<<endl;
			}
		}
		i=(i%m)+1;
	}
}

int main(){
	initialize();
	vector<int> check(500);	
	for (int i=1;i<=n*m;i++){
		check[i] = dfs(i);
		visited.clear();
		visited.assign(500,0);
		count_= 0;
		//cout<<"check"<<i<<" = "<<check[i]<<endl;
	}
	int flag = 0;
	for (int i=1;i<=m*n;i++){
		if (check[i] != m*n){
			cout<<"NO"<<endl;
			flag = 1;
			break;
		}
	}
	if (flag == 0){
		cout<<"YES"<<endl;
	}
}