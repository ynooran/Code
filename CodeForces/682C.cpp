#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
const int MAX = 1e5+1;
int n, ans, a[MAX], cnt[MAX], dist[MAX];
vector<pair<int,int> > adj[MAX];
void dfs1(int v, int p)
{
	for(auto edge : adj[v])
		if(edge.first == p)
			continue;
		else
			dfs1(edge.first, v);
	cnt[p] += 1 + cnt[v];
}
void dfs2(int v, int p)
{
	for(auto edge : adj[v])
		if(edge.first == p)
			continue;
		else
		{
			dist[edge.first] = max(0, dist[v] + edge.second);
			if(dist[edge.first] > a[edge.first])
				ans += cnt[edge.first] + 1;
			else
				dfs2(edge.first, v);
		}
}
int main()
{
	cin>>n;
	FOR(i,0,n)
		cin>>a[i+1];
	FOR(i,2,n+1)
	{
		int u,p;
		cin>>u>>p;
		adj[i].push_back(make_pair(u,p));
		adj[u].push_back(make_pair(i,p));
	}
	dfs1(1,0);
	dfs2(1,0);
	cout<<ans<<endl;
}
