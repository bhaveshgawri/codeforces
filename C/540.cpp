#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

vector<vector<char> > I(504, vector<char>(504));
vector<vector<int> > visited(504, vector<int>(504, 0));
int dfs1_flag=0;
int dfs2_flag=0;

void dfs1(vector<pair<int, int> >&e_neigh, pair<int, int> start, pair<int, int> end, int rows, int cols, int count, int var){
	//cout<<start.f<<" "<<start.s<<endl;
	for (auto i: e_neigh){
		if (i==start){
			//cout<<i.f<<" "<<i.s<<endl;
			(count)++;
			//cout<<"count"<<count<<endl;	
		}
	}
	if (start.s+1<=cols && visited[start.f][start.s+1]==0 && I[start.f][start.s+1]=='.'){
		visited[start.f][start.s+1]=1;
		dfs1(e_neigh, {start.f, start.s+1}, end, rows, cols, count, var);
	}
	if (start.s-1>=1 && visited[start.f][start.s-1]==0 && I[start.f][start.s-1]=='.'){
		visited[start.f][start.s-1]=1;
		dfs1(e_neigh, {start.f, start.s-1}, end, rows, cols, count, var);
	}
	if (start.f+1<=rows && visited[start.f+1][start.s]==0 && I[start.f+1][start.s]=='.'){
		visited[start.f+1][start.s]=1;
		dfs1(e_neigh, {start.f+1, start.s}, end, rows, cols, count, var);
	}
	if (start.f-1>=1 && visited[start.f-1][start.s]==0 && I[start.f-1][start.s]=='.'){
		visited[start.f-1][start.s]=1;
		dfs1(e_neigh, {start.f-1, start.s}, end, rows, cols, count, var);
	}
	if ((count)>=1 && var==0){
		dfs1_flag=1;
	}
	/*if ((count)>=2 && var==1){
		dfs1_flag=1;
	}*/	
}

void dfs2(pair<int, int> start, pair<int, int> end, int rows, int cols, int count){
	if (start==end && count>=2){
		cout<<"YES"<<endl;
		dfs2_flag=1;
	}
	else if (start==end && count<2){
		cout<<"NO"<<endl;
		dfs2_flag=1;
	}
	if (start.s+1<=cols && visited[start.f][start.s+1]==0 && I[start.f][start.s+1]=='.'){
		visited[start.f][start.s+1]=1;
		dfs2({start.f, start.s+1}, end, rows, cols, count);
	}
	if (start.s-1>=1 && visited[start.f][start.s-1]==0 && I[start.f][start.s-1]=='.'){
		visited[start.f][start.s-1]=1;
		dfs2({start.f, start.s-1}, end, rows, cols, count);
	}
	if (start.f+1<=rows && visited[start.f+1][start.s]==0 && I[start.f+1][start.s]=='.'){
		visited[start.f+1][start.s]=1;
		dfs2({start.f+1, start.s}, end, rows, cols, count);
	}
	if (start.f-1>=1 && visited[start.f-1][start.s]==0 && I[start.f-1][start.s]=='.'){
		visited[start.f-1][start.s]=1;
		dfs2({start.f-1, start.s}, end, rows, cols, count);
	}
}

int main(){
	int n, m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>I[i][j];
		}
	}
	int sx, sy, ex, ey;
	cin>>sx>>sy>>ex>>ey;
	pair<int, int> start = {sx, sy};
	pair<int, int> end = {ex, ey};
	if (I[ex][ey]=='X'){
		vector<pair<int, int> >e_neigh;
		
		if (I[ex][ey-1]=='.' && ey-1>=1)
			e_neigh.push_back({ex, ey-1});
		if (I[ex+1][ey]=='.' && ex+1<=n)
			e_neigh.push_back({ex+1, ey});
		if (I[ex][ey+1]=='.' && ey+1<=m)
			e_neigh.push_back({ex, ey+1});
		if (I[ex-1][ey]=='.' && ex-1>=1)
			e_neigh.push_back({ex-1, ey});
		/*for (auto i: e_neigh){
			cout<<i.f<<" "<<i.s<<endl;
		}
		cout<<endl;
		*/
		int count=0, var=0;
		if (start==end){
			var=1;
		}
		if (var==1)
			if (e_neigh.size()>=1)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		else{
			if (abs(start.f-end.f)==1 || abs(start.s=end.s)==1)
				cout<<"YES"<<endl;
			else{
				dfs1(e_neigh, start, end, n, m, count, var);
				if (dfs1_flag==0)
					cout<<"NO"<<endl;
				else
					cout<<"YES"<<endl;
			}
		}
	}
	else{
		int e_neigh=0;
		if (I[ex][ey-1]=='.' && ey-1>=1)
			e_neigh++;
		if (I[ex+1][ey]=='.' && ex+1<=n)
			e_neigh++;
		if (I[ex][ey+1]=='.' && ey+1<=m)
			e_neigh++;
		if (I[ex-1][ey]=='.' && ex-1>=1)
			e_neigh++;
		dfs2(start, end, n, m, e_neigh);
		if (dfs2_flag==0)
			cout<<"NO"<<endl;
		return 0;
	}
}