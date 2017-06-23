#include <bits/stdc++.h>

#define ll      long long int
#define u64     unsigned long long int

#define nl         "\n"
#define pb         push_back
#define ppb        pop_back
#define pf         push_front
#define ppf        pop_front
#define sz(x)      x.size()
#define all(x)     x.begin(), x.end()
#define init(x, k) fill(all(x), k)
#define dot(x)     fixed<<setprecision(x) 
#define nfs        ios_base::sync_with_stdio(false);cin.tie(NULL)

#define _max(a, b, c)   max(a, max(b, c))
#define _min(a, b, c)   min(a, min(b, c))
#define mxe(a)          *max_element(all(a))
#define mne(a)          *min_element(all(a))

#define lb(x, k) lower_bound(all(x), k)-x.begin()
#define ub(x, k) upper_bound(all(x), k)-x.begin()

#define inf      INT_MAX
#define minf     INT_MIN
#define INF      LLONG_MAX
#define MINF     LLONG_MIN

#define f    first
#define s    second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ll, ll> II;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MAX = 1e5 + 4;
const int MOD = 1e9 + 7;

char H[14][14];
vvi visited(14, vi(14, 0));
int count_=0;

void dfs(ii start, char dir, int rows, int cols, int circle){
	int x = start.f, y=start.s;
	if (dir=='D' && (x+1>rows || (x+1<=rows&&(visited[x+1][y]==1 || H[x+1][y]=='*')))){
		dir='L';
		if (circle<4)
			circle++, dfs(start, dir, rows, cols, circle);
	}
	else if (dir=='L' && (y-1<1 || (y-1>=1&&(visited[x][y-1]==1 || H[x][y-1]=='*')))){
		dir='U';
		if (circle<4)
			circle++, dfs(start, dir, rows, cols, circle);
	}
	else if (dir=='U' && (x-1<1 || (x-1>=1&&(visited[x-1][y]==1 || H[x-1][y]=='*')))){
		dir='R';
		if (circle<4)
			circle++, dfs(start, dir, rows, cols, circle);
	}
	else if (dir=='R' && (y+1>cols || (y+1<=cols&&(visited[x][y+1]==1 || H[x][y+1]=='*')))){
		dir='D';
		if (circle<4)
			circle++, dfs(start, dir, rows, cols, circle);
	}
	if (dir=='D' && x+1<=rows && visited[x+1][y]==0 && H[x+1][y]=='.'){
		visited[x+1][y]=1;
		count_++;
		circle=0;
		dfs({x+1, y}, 'D', rows, cols, circle);
	}
	else if (dir=='L' && y-1>=1 && visited[x][y-1]==0 && H[x][y-1]=='.'){
		visited[x][y-1]=1;
		count_++;
		circle=0;
		dfs({x, y-1}, 'L', rows, cols, circle);
	}
	else if (dir=='U' && x-1>=1 && visited[x-1][y]==0 && H[x-1][y]=='.'){
		visited[x-1][y]=1;
		count_++;
		circle=0;
		dfs({x-1, y}, 'U', rows, cols, circle);
	}
	else if (dir=='R' && y+1<=cols && visited[x][y+1]==0 && H[x][y+1]=='.'){
		visited[x][y+1]=1;
		count_++;
		circle=0;
		dfs({x, y+1}, 'R', rows, cols, circle);
	}
}

int main(){
	nfs;
	int n, m;
	cin>>n>>m;
	ii start;
	char dir;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>H[i][j];
			if (H[i][j]!='*'&&H[i][j]!='.')
				start.f=i, start.s=j, dir=H[i][j];
		}
	}
	count_=0;
	int circle=0;
	//cout<<start.f<<start.s<<dir<<nl;
	visited[start.f][start.s]=1;
	dfs(start, dir, n, m, circle);
	cout<<count_<<nl;
}