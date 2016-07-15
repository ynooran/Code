#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;

int main()
{
	int n,s=-1;cin>>n;
	int ans=0,a=0;
	while(n--)
	{
		int tmp;cin>>tmp;
		if(tmp>=s)
			a++;
		else
		{
			ans = max(ans , a);
			a=1;
		}
		s = tmp;
	}
	if(a>ans)
		ans=a;
	cout<<ans<<endl;
}

