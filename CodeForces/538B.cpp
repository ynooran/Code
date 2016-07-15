#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n, a[7], m;
int main()
{
	cin>>n;
	for(int i=0; n; i++)
	{
		a[i] = n%10;
		m = max(a[i],m);
		n/=10;
	}
	cout<<m<<endl;
	FOR(i,1,m+1)
	{
		int x = 1,ans=0;
		FOR(j,0,7)
		{
			if(a[j]>=i)
				ans+=x;
			x*=10;
		}
		cout<<ans<<" ";
	}
	cout<<endl;
}
