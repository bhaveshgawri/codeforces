#include <bits/stdc++.h>

using namespace std;

vector< vector<int> >visited(304, vector<int>(304, 0));

pair<int, int> dfs(int r, int c, int rows, int cols, int count){
	stack<pair<int, int> > s;
	int row, col;
	s.push({r, c});
	visited[r][c]=1;
	cout<<count+1<<" ";
	while(!s.empty()){
		pair<int, int> p = s.top();
		row = p.first;
		col = p.second;
		s.pop();
		cout<<row<<" "<<col<<" ";
		if (visited[row][col+1]==0 && col+1<=cols && count>0){
			s.push({row, col+1});
			count--;
			visited[row][col+1]=1;
			continue;
		}
		if (visited[row][col-1]==0 && col-1>=1 && count>0){
			s.push({row, col-1});
			count--;
			visited[row][col-1]=1;
			continue;
		}
		if (visited[row+1][col]==0 && row+1<=rows && count>0){
			s.push({row+1, col});
			count--;
			visited[row+1][col]=1;
			continue;
		}
	}
	return {row, col};
}

int main(){
	int n, m, k;
	cin>>n>>m>>k;
	pair<int, int> start = {1, 1};
	start = dfs(1, 1, n, m, n*m-2*(k-1)-1);
	for (int i=0;i<k-1;i++){
		cout<<endl;
		if (visited[start.first][start.second+1]==0 && start.second+1<=m)
			start = dfs(start.first, start.second+1, n, m, 1);
		else if (visited[start.first][start.second-1]==0 && start.second-1>=1)
			start = dfs(start.first, start.second-1, n, m, 1);
		else
			start = dfs(start.first+1, start.second, n, m, 1);
	}
	cout<<endl;
}