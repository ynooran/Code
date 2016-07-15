#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
long long n,x,ans;
int main()
{
	cin>>n>>x;
	while(n--)
	{
		char tmpc;
		int tmpi;
		cin>>tmpc>>tmpi;
		if(tmpc == '+')
			x+=tmpi;
		else if(x>=tmpi)
			x-=tmpi;
		else
			ans++;

	}
	cout<<x<<" "<<ans<<endl;
}

