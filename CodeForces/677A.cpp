#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,h,ans;
int main()
{
	cin>>n>>h;
	while(n--)
	{
		int tmp;
		cin>>tmp;
		ans++;
		if(tmp>h)
			ans++;
	}
	cout<<ans<<endl;
}

