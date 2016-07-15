#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define int long long
using namespace std;
const int delta = 10567;
int fac[5001],inv[5001];
int pow (int a, int b)
{
	if(!b)
		return 1;
	if(b&1)
		return (a*pow(a,b-1))%delta;
	int ret = pow(a,b/2);
	return (ret*ret)%delta;
}
int C (int a, int b)
{
	int ret = (fac[b] * inv[a])%delta;
	return (ret*inv[b-a])%delta;;
}
int32_t main()
{
	fac[0] = inv[0] = 1;
	FOR(i,1,5001)
	{
		fac[i] = (i*fac[i-1])%delta;
		inv[i] = pow(fac[i],delta-2);
	}
	int ans = 1;
	FOR(n,1,5000)
		ans += C(n/2 + 1, n+1),ans%=delta;
	cout<<ans<<endl;
}
