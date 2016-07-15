#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int a,ans;
bool bad (int x)
{
	while(x)
	{
		if((x%10) == 8 || (x%10) == -8)
			return false;
		x/=10;
	}
	return true;
}
int main()
{
	cin>>a;
	a++;
	ans++;
	while(bad(a))
		a++,ans++;
	cout<<ans<<endl;
}

