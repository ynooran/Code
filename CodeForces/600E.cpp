#include <iostream>
#include <vector>
#include <map>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int MAX = 100011;
map<int,int> *cs[MAX];
int color[MAX],dom[MAX],n;
vector<int> adj[MAX];
void dfs(int node, int par)
{
	if(adj[node].size() == 1)
	{
		cerr<<node<<endl;
		dom[node] = color[node];
		cs[node] = new map<int,int>();
		cout<<dbug(node)<<(cs[node]->size())<<endl;
		(*cs[node])[color[node]] = 1;
		return;
	}
	int mxc=0,mxi;
	cerr<<"Entering "<<dbug(node)<<endl;
	for(int i : adj[node])
		if(i!=par)
		{
			cerr<<dbug(node)<<dbug(i)<<endl;
			dfs(i,node);
			if(cs[i]->size()>mxc)
			{
				mxi = i;
				mxc = cs[i]->size();
			}	
		}
	cs[node] = cs[mxi];
	for(int i : adj[node])
		if(i != par && i!=mxi)
			for( pair<int,int> j : *cs[i])
			{
				(*cs[node])[j.first] += j.second;
			}
	for(pair<int,int>  i : *cs[node])
	{
		dom[node] = i.first;
		break;
	}
}
int main()
{
	cin>>n;
	FOR(i,0,n)
		cin>>color[i];
	FOR(i,0,n-1)
	{
		int x,y;
		cin>>x>>y;
		adj[--x].push_back(--y);
		adj[y].push_back(x);
	}
	adj[0].push_back(-1);
	dfs(0,-1);
	FOR(i,0,n)
		cout<<dom[i]<<endl;
}
