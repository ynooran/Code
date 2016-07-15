#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,d,a[101];
int main()
{
	cin>>n>>d;
	FOR(i,1,d+1)
		FOR(j,0,n)
		{
			char tmp;
			cin>>tmp;
			if(tmp=='0')
				a[i]++;
		}
	int ans=0,tans=0;
	FOR(i,1,d+1)
	{
		if(a[i])
			tans++;
		else
		{
			ans = max(tans,ans);
			tans=0;
		}
	}
	cout<<max(ans,tans)<<endl;
}
