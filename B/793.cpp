//this code is just a dfs-> this code gives wrong ans -> need to correct

#include <iostream>
#include <vector>

using namespace std;

int visited[1005][1005]={0};
int flag = 0;

void dfs(vector<vector<char> >& city, char last_dir, int x, int y, int a, int b, int count, int n, int m){
	cout<<x<<" "<<y<<" "<<a<<" "<<b<<" "<<count<<" "<<n<<" "<<m<<endl;
	visited[x][y]=1;
	if (x==a && y==b && count<=2){
		cout<<"YES"<<endl;
		flag = 1;
		return;
	}
	//cout<<city[x+1][y]<<" "<<city[x][y+1];
	//cout<<(city[x][y+1]!='*');
	if(y+1<m && city[x][y+1]!='*' && visited[x][y+1]==0){
		if (last_dir=='v')
			count++;
		last_dir='h';
		dfs(city, last_dir, x, y+1, a, b, count, n, m);	
	}
	if (x+1<n && city[x+1][y]!='*' && visited[x+1][y]==0){
		if (last_dir=='h')
			count++;
		last_dir='v';
		dfs(city, last_dir, x+1, y, a, b, count, n, m);
	}
	if (y-1>=0 && city[x][y-1]!='*' && visited[x][y-1]==0){
		if (last_dir=='v')
			count++;
		last_dir='h';
		dfs(city, last_dir, x, y-1, a, b, count, n, m);
	}
	if (x-1>=0 && city[x-1][y]!='*' && visited[x-1][y]==0){
		if (last_dir=='h')
			count++;
		last_dir='v';
		dfs(city, last_dir, x-1, y, a, b, count, n, m);
	}
}	

int main(){
	int rows, cols;
	cin>>rows>>cols;
	int s_row, s_col, e_row, e_col;
	vector< vector<char> > city(rows, vector<char>(cols)); 
	for (int i=0;i<rows;i++){
		for (int j=0;j<cols;j++){
			cin>>city[i][j];
			if (city[i][j]=='S'){
				s_row= i;
				s_col = j;
			}
			else if (city[i][j]=='T'){
				e_row = i;
				e_col = j;
			}
		}
	}
	int count = 0;
	char last_dir = 'h';//h->hor and v->ver
	//cout<<start.first<<start.second<<end.first<<end.second;
	dfs(city, last_dir, s_row, s_col, e_row, e_col, count, rows, cols);
	if (flag==0)
		cout<<"NO"<<endl;
}