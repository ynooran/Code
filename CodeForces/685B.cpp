#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 300 * 1000;
int n, q, par[MAX+1], sz[MAX + 1];
vector<int> c[MAX + 1];
vector<pair<int, int> > *st[MAX +1];
void dfs(int x)
{
	sz[x] = 1;
	if(c[x].empty())
		st[x] = new vector<pair<int, int> >;
	int mx = 0;
	for(int k : c[x])
	{
		dfs(k);
		sz[x] += st[k]->back().first;
		if(st[k]->back().first>mx)
		{
			mx = st[k]->back().first;
			st[x] = st[k];
		}
	}
	st[x]->push_back(make_pair(sz[x], x));
}
int main()
{
	cin>>n>>q;
	for(int i=2; i<=n; i++)
	{
		cin>>par[i];
		c[par[i]].push_back(i);
	}
	dfs(1);
	while(q--)
	{
		int x;
		cin>>x;
		cout<<upper_bound(st[x]->begin(),st[x]->end(),make_pair(sz[x]/2,MAX))->second<<endl;
	}
}
