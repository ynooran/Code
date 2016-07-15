#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int d[110000],n,m;
vector<int> h[110000];
int dfs ( int node, int par )
{
	if(d[node])
		d[node] += d[par];
	if(d[node]>m)
		return 0;
	if(h[node].size() == 1 && node!=1)
		return 1;
	int ans = 0;
	for( int y : h[node])
	{
		if(y == par)
			continue;
		ans+=dfs(y,node);
	}
	return ans;
}
int main()
{
	cin>>n>>m;
	FOR(i,0,n)
		cin>>d[i+1];
	FOR(i,1,n)
	{
		int x,y;
		cin>>x>>y;
		h[x].push_back(y);
		h[y].push_back(x);
	}
	cout<<dfs(1,0)<<endl;
}
