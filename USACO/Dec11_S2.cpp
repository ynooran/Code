#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int edge[101][101],par[101],dist[101],n,m,ans,original;
bool seen[101];
int dijkstra()
{
	memset(dist,127,sizeof(dist));
	memset(seen,0,sizeof(seen));
	memset(par,0,sizeof(par));
	dist[1] = 0;
	FOR(i,1,n+1)
	if(!seen[i])
	{
		seen[i] = true;
		FOR(j,1,n+1)
		if(!seen[j]&&edge[i][j])
		dist[j] = min(dist[j],edge[i][j] + dist[i]),par[j] = i;
	}
	return dist[n];
}

int main()
{
	cin>>n>>m;
	while(m--)
	{
		int a,b,w;
		cin>>a>>b>>w;
		edge[a][b] = edge[b][a] = w;
	}
	ans = original = dijkstra();
	vector <int> path;
	for(int i = n; i ; i=par[i])
		path.push_back(i);
	FOR(i,0,path.size()-1)
	{
		int a = path[i];
		int b = path[i+1];
		edge[a][b]*=2;
		edge[b][a]*=2;
		ans = max(ans,dijkstra());
		edge[a][b]/=2;
		edge[b][a]/=2;
	}
	cout<<(ans - original)<<endl;
}
