#include <iostream>
#include <utility>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int MAX=4100;
bool adj[MAX][MAX];
int degree[MAX];
vector < pair<int,int> > edges;
int main()
{
	int n,m;cin>>n>>m;
	int ans = 10000;
	FOR(i,0,m)
	{
		int x,y;cin>>x>>y;
		adj[x][y]=adj[y][x]=true;
		edges.push_back(make_pair(x,y));
		degree[x]++,degree[y]++;
	}
	while(!edges.empty())
	{
		pair<int,int> a = edges.back();
		edges.pop_back();
		const int& x=a.first,y=a.second;
		FOR(i,1,n+1)
		{
			int num = degree[x] + degree[y] -6;
			if(i==x || i==y)
				continue;
			else if(adj[i][x] && adj[i][y])
				ans = min(ans, num+degree[i]);
		}
	}
	if(ans == 10000)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;

}
