#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define int long long
using namespace std;
const int MAX = 1e6 + 10, M = 55967;
int n, dpb[MAX], ans;
int tpow(int b)
{
	if(!b)
		return 1;
	if(b&1)
		return (2*tpow(b-1))%M;
	int ret = tpow(b/2);
	return (ret*ret)%M;
}
int32_t main()
{
	cin>>n;
	dpb[0] = 1;
	FOR(i,1,n+1)
	{
		int tans;
		dpb[i] = tpow(i*(n-1)-1);
		dpb[i] += (dpb[i-1] * (tpow(n-2)-1));
		dpb[i] %= M;
		tans = tpow(i*(n-1)) - dpb[i];
		if(tans<0)
			tans+=M;
		int rhs = max((n-i)*(n-1) - 1, 0ll);
		tans *= tpow(rhs);
		ans = (ans + tans)%M;
	}
	cout<<ans<<endl;
}
