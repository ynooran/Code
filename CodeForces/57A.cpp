#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,x[2],y[2];
int main()
{
	int ans;
	cin>>n>>x[0]>>y[0]>>x[1]>>y[1];
	if(x[0] == n || x[0] == 0)
	{
		if(x[1] == n || x[1]==0)
		{
			if(x[0]==x[1])
				ans = abs(y[0] - y[1]);
			else
				ans = min(y[0]+y[1],2*n-y[0]-y[1]) + n;
		}
		else
		{
			ans = abs(x[0]-x[1]) + abs(y[0]-y[1]);
		}
	}
	else
	{
		if(x[1] == n || x[1]==0)
		{
			ans = abs(x[0] - x[1]) + abs(y[0]-y[1]);
		}
		else
		{
			if(y[1]==y[0])
				ans = abs(x[0] - x[1]);
			else
				ans = min(x[0]+x[1],2*n-x[0]-x[1]) + n;

		}
		
	}
	cout<<ans<<endl;
}
