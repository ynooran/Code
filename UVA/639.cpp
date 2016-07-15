#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n;
bool b[4][4],nb[4][4];
int ans(int ind)
{
	if(ind == n*n)
		return 0;
	int x=ind/n;
	int y=ind%n;
	bool px =true,py=true;
	FOR(i,0,x)
	if(b[i][y])
		px = true;
	else if(nb[i][y])
		px = false;
	FOR(i,0,y)
	if(b[x][i])
		py=true;
	else if(nb[x][i])
		py = false;
	int ret= ans(ind+1);
	if(!b[x][y] && px && py)
	{
		nb[x][y] = true;
		ret=max(ret,ans(ind+1)+1);
		nb[x][y] = false;
	}
	return ret;
}
int main()
{
	while(1)
	{
		cin>>n;
		if(!n)
			break;
		FOR(i,0,n)
		FOR(j,0,n)
		{
			char tmp;cin>>tmp;
			if(tmp=='.') b[i][j]=false;
			else b[i][j] = true;
		}
		cout<<ans(0)<<endl;
	}
}
