#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int a1,a2,ans;
int main()
{
	cin>>a1>>a2;
	while(a1>0 && a2>0)
	{
		if(a1>a2)
		{
			a1-=2;
			a2++;
		}
		else
		{
			a2-=2;
			a1++;
		}
		if(a1>=0 && a2>=0)
			ans++;
	}
	cout<<ans<<endl;
}
