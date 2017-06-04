#include <bits/stdc++.h>

using namespace std;

vector< vector<char> > M(504, vector<char>(504, 0));
vector< vector<bool> > visited(504, vector<bool>(504, 0));
vector< vector<bool> > convert(504, vector<bool> (504, 1));

void bfs(pair<int, int> point, int rows, int cols, int count){
	queue<pair<int, int> > q;
	q.push(point);
	visited[point.first][point.second]=1;
	convert[point.first][point.second]=0;
	count--;
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		if (M[p.first+1][p.second]=='.' && visited[p.first+1][p.second]==0
			&& p.first+1<=rows && count>0){
			q.push({p.first+1, p.second});
			count--;
			convert[p.first+1][p.second]=0;
			visited[p.first+1][p.second]=1;
		}
		if (M[p.first-1][p.second]=='.' && visited[p.first-1][p.second]==0
			&& p.first-1>=1 && count>0){
			q.push({p.first-1, p.second});
			count--;
			convert[p.first-1][p.second]=0;
			visited[p.first-1][p.second]=1;
		}
		if (M[p.first][p.second+1]=='.' && visited[p.first][p.second+1]==0
			&& p.second+1<=cols && count>0){
			q.push({p.first, p.second+1});
			count--;
			convert[p.first][p.second+1]=0;
			visited[p.first][p.second+1]=1;
		}
		if (M[p.first][p.second-1]=='.' && visited[p.first][p.second-1]==0
			&& p.second-1>=1 && count>0){
			q.push({p.first, p.second-1});
			count--;
			convert[p.first][p.second-1]=0;
			visited[p.first][p.second-1]=1;
		}

	}
}

int main(){
	int n, m, k, flag=0, count_dot=0;
	cin>>n>>m>>k;
	pair<int, int> start;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>M[i][j];
			if (M[i][j]=='.')
				count_dot++;
			if (flag==0 && M[i][j]=='.'){
				start={i, j};
				flag=1;
			}
		}
	}
	bfs(start, n, m, count_dot-k);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (convert[i][j]==1 && M[i][j]!='#'){
				M[i][j]='X';
			}
			cout<<M[i][j];
		}
		cout<<endl;
	}
}