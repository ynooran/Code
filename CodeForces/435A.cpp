#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,m,a[100], ans, rem;
int main()
{
	cin>>n>>m;
	FOR(i,0,n)
		cin>>a[i];
	FOR(i,0,n)
	{
		if(rem<a[i])
		{
			rem = m;
			ans++;
		}
		rem -= a[i];
	}
	cout<<ans<<endl;
}

