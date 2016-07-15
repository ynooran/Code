#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
vector <int> s[8];
bool ans;
void dfs ( int x, int y, int d)
{
	if(ans || x<0 || y<0 || x>7 || y>7)
		return;
	if(binary_search(s[x].begin(),s[x].end(),y-d) || binary_search(s[x].begin(),s[x].end(),y-d+1))
		return;
	if(d==8 || (x==7 && y==0))
		ans  = true;
	FOR(i,-1,2)
		FOR(j,-1,2)
			dfs(x+i,y+j,d+1);
}

int main()
{
	FOR(i,0,8)
		FOR(j,0,8)
		{
			char tmp;
			cin>>tmp;
			if(tmp == 'S')
				s[j].push_back(i);
		}
	dfs(0,7,0);
	cout<<(ans?"WIN":"LOSE")<<endl;
}
