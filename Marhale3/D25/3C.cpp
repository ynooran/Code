#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define int long long
using namespace std;
const int MAX = 55, M = 1e9 + 7, delta = 55967;
int fac, inv;
int n,k,t;
int pow(int a, int b)
{
	a%=M;
	if(!b)

		return 1;
	if(b&1)
		return (a*pow(a,b-1))%M;
	int r = pow(a,b/2);
	return (r*r)%M;
}
int C(int a, int b)
{
	int ret = 1, inv=1;
	for(int i=b; i>b-a; i--)
	{
		ret*=(i%M);
		ret%=M;
	}
	FOR(i,1,a+1)
	{
		inv*=i;
		inv%=M;
	}
	inv = pow(inv,M-2);
	return (inv*ret)%M;
}
int32_t main()
{
	cin>>n>>t>>k;
	int ans = (C(t,1ll<<n)*C(k-t+1,(1ll<<n)-t))%M;
	cout<<ans%delta<<endl;
}
