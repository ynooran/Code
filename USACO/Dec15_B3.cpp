#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
vector<int> sick[51][101];
bitset<51> is,maybe,milk[51];
int main()
{
	is.flip();
	ifstream fin("badmilk.in");
	ofstream fout("badmilk.out");
	int n,m,d,s;
	fin>>n>>m>>d>>s;
	FOR(i,0,d)
	{
		int p,m,t;
		fin>>p>>m>>t;
		sick[p][t].push_back(m);
		milk[m][p] = true;
	}
	FOR(i,0,s)
	{
		maybe.reset();
		int p,t;
		fin>>p>>t;
		FOR(j,1,t)
			for(auto x : sick[p][j])
				maybe[x] = true;
		is&=maybe;
	}int ans=0;
	FOR(i,1,m+1)
		if(is[i])
			ans = max(ans,(int)milk[i].count());
	fout<<ans<<endl;
}
