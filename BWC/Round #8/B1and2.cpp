#include <iostream>
#include <algorithm>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const long long delta = 781817;
const long long MAX = 1e17;
long long log( long long x)
{
	if(x==1)
		return 0;
	else
		return 1 + log(x/2);
}
long long twoPow(long long x)
{
	if(!x)
		return 1;
	if(x%2)
		return (2*twoPow(x-1))%delta;
	else
	{
		long long tmp = twoPow(x/2);
		tmp = tmp*tmp;
		return tmp%delta;
	}
}
int main()
{
	long long times = log(MAX+1);
	long long ans=0;
	FOR(i,0,times)
	{
		ans+=twoPow(2*i);
		ans%=delta;
	}
	long long rem = MAX - twoPow(times) + 1;
	rem%=delta;
	rem*=rem;
	rem%=delta;
	ans = (ans+rem)%delta;
	cout<<ans<<endl;
}
