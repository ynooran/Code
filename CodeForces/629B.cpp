#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,a[5000],b[5000];
bool male[5000];
int main()
{
	cin>>n;
	FOR(i,0,n)
	{
		char tmp;
		cin>>tmp;
		if(tmp=='M')
			male[i] = true;
		cin>>a[i]>>b[i];
	}
	int ans=0;
	FOR(i,1,367)
	{
		int ms=0,fms=0;
		FOR(j,0,n)
		{
			if(a[j]<=i && i<=b[j])
			{
				if(male[j])
					ms++;
				else
					fms++;
			}
		}
		ans = max(ans, 2*min(ms,fms));
	}
	cout<<ans<<endl;
}
