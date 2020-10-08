#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
typedef pair<int, int> pi;
typedef pair<pi, int> ppi;
//const int M = 100;
const int M = 1000000007;
#define PI 3.14159265358979
#define inf M-100
int n = 7, m, k, dots = 0, cou = 0, yes = 0, r, wt;
//vector<vector<int>> g;
vector<string> v;
//int vis[20], lev[20], par[20], color[20];
int dmonst[10][10], da[10][10];
int vis[10][10], lev[10][10];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int isval(int x, int y)
{
	return x >= 0 && y >= 0 && x < n && y < m && 
		!vis[x][y] && v[x][y] != '#';
}

void bfs1(int x, int y)
{
	queue<pi> q;
	q.push({x, y});
	vis[x][y] = 1;
	if(lev[x][y] < dmonst[x][y])
		dmonst[x][y] = lev[x][y];
	while(!q.empty())
	{
		auto ele = q.front();
		q.pop();
		int x = ele.first, y = ele.second;
		vis[x][y] = 1;
		if(lev[x][y] < dmonst[x][y])
			dmonst[x][y] = lev[x][y];
		for(int i = 0; i < 4; i++)
		{
			if(isval(x + dx[i], y + dy[i]))
			{
				lev[x + dx[i]][y + dy[i]] = lev[x][y] + 1;
				vis[x + dx[i]][y + dy[i]] = 1;
				q.push({x + dx[i], y + dy[i]});
			}
		}

	}
}

int isval2(int x, int y)
{
	return x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && v[x][y] == '.';
}

void bfs(int x, int y)
{
	queue<pi> q;
	q.push({x, y});
	vis[x][y] = 1;
	da[x][y] = 0;
	while(!q.empty())
	{
		auto ele = q.front();
		q.pop();
		int x = ele.first, y = ele.second;
		vis[x][y] = 1;
		for(int i = 0; i < 4; i++)
		{
			if(isval2(x + dx[i], y + dy[i]))
			{
				da[x + dx[i]][y + dy[i]] = da[x][y] + 1;
				vis[x + dx[i]][y + dy[i]] = 1;
				q.push({x + dx[i], y + dy[i]});
				
			}
		}

	}
}

int main()
{
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("op2.txt", "w", stdout);
#endif

	// 	TRICK IS TO DO 2 BFSs(ONE FOR ALL THE MONSTERS), STORE MINIMUM DIST FOR 
	// ANY OF THE MONSTERS TO COME TO THAT CELLL
	// THEN DO SECOND BFS FOR 'A'. THEN COMPARE IF THERE EXISTS ANY EDGE CELL WHOSE DIST
	// FROM 'A' IS LESSER THAN FROM ANY MONSTERS
	// IF IT IS THEN THAT CELL IS THE REACHABLE ONE(THE ANSWER), BUT TO OBTAIN
	// SEQUENCE OF STEPS, WE'LL HAVE TO BACKTRACK (WITH THE HELP OF OUR 2D LEVELS MATRICES)

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll  sal = 0, ii, jj, cnt= 0, x, y, ans = 0, l, r;
	ll i, lim,  p,mn = INT_MAX, mx = INT_MIN,j,sum = 0, a, b;
	cin >> n >> m;
	v.resize(n);
	for(i = 0; i < n; i++)
		cin >> v[i];

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			dmonst[i][j] = 100;
			da[i][j] = 100;
		}
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			memset(vis, 0, sizeof(vis));

			if(v[i][j] == 'M')
			{
				memset(lev, 0, sizeof(lev));
				bfs1(i, j);
			}
			if(v[i][j] == 'A')
				bfs(i, j);
		}

	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			//cout << dmonst[i][j] << "  ";
			cout << da[i][j] << "  ";
		}
		cout << endl;
	}

	int f = 0;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{

			if(i == 0 || j == 0 || i == n-1 || j == m-1)
			{
				if(v[i][j] != '#' && da[i][j] < dmonst[i][j])
				{
					f = 1;
					cout << "YESSSSSSSS" << " " << i << " " << j <<  endl;
				}
			}
		}
	}
	if(!f)
		cout << "NOOOOOO";

}
