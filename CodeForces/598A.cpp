#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int t;
long long log ( long long x )
{
	if(x == 1 )
		return 1;
	long long ret = log(x/2)*2;
	return ret;
}
int main()
{
	cin>>t;
	while(t--)
	{
		long long n,ans;
		cin>>n;
		ans = n*(n+1);
		ans /= 2;
		ans -= 4*log(n) - 2;
		cout<<ans<<endl;
	}


}
