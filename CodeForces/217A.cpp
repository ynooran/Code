#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
vector <int> adj[2200];
bool seen[2200];
void dfs( int i)
{
	if(seen[i])
		return;
	seen[i] = true;
	for( auto a : adj[i])
		dfs(a);
}
int main()
{
	int n,ans=0;
	cin>>n;
	FOR(i,2001,n+2001)
	{
		int t1,t2;
		cin>>t1>>t2;
		adj[i].push_back(t1);
		adj[i].push_back(t2+1000);
		adj[t1].push_back(i);
		adj[t2+1000].push_back(i);
	}
	FOR(i,2001,n+2001)
		if(!seen[i])
		{
			ans++;
			dfs(i);
		}
	cout<<ans-1<<endl;
}
