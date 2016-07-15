#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int a[5100],b[5100];
long long c[5100];
int main()
{
	int n;cin>>n;
	FOR(i,0,n)
	{
		cin>>a[i];
		b[i] = a[i];
	}
	sort(b,b+n);
	FOR(i,0,n)
		FOR(j,0,n)
		{
			int d = b[j] - a[i];
			if(d>0)
				c[j] = min(c[j-1],d+c[j]);
			else
				c[j] -= d;
		}
	long long ans=c[0];
	while(--n)
		if(ans>c[n])
			ans = c[n];
	cout<<ans<<endl;
}
