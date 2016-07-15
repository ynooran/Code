#include <iostream>
#include <vector>
#include <fstream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define mk make_pair
using namespace std;
int ans,n,m;
bool lit[101][101],seen[101][101];
vector<pair<int,int> > keys[101][101];
void dfs(int a, int b)
{
	if(!(a && b && (n+1-b) && (n+1-a)) || seen[a][b])
		return;
	seen[a][b] = true;
	if(!lit[a][b])
		return;
	for(auto x : keys[a][b])
		if(!lit[x.first][x.second])
		{
			ans++;
			lit[x.first][x.second] = true;
			if(seen[x.first][x.second])
			{
				seen[x.first][x.second]=false;
				dfs(x.first,x.second);
			}
		}
	dfs(a+1,b),dfs(a-1,b),dfs(a,b+1),dfs(a,b-1);
}
int main()
{
	ifstream fin("lightson.in");
	ofstream fout("lightson.out");
	fin>>n>>m;
	FOR(i,0,m)
	{
		int a,b,c,d;
		fin>>a>>b>>c>>d;
		keys[a][b].push_back(mk(c,d));
	}
	lit[1][1] = ans = 1;
	dfs(1,1);
	fout<<ans<<endl;
}
