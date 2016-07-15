#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define int long long
using namespace std;
const int delta = 1e9 + 7, MAX = 2e5, N = 2000;
int fac[MAX+1],ifac[MAX+1],dp[N+2], h, w, n;
pair<int,int> A[N+1];
int pow(int a, int b)
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
	int ret = (fac[b]*ifac[a])%delta;
	return (ret*ifac[b-a])%delta;
}
int32_t main()
{
	fac[0] = ifac[0] = 1;
	FOR(i,1,MAX+1)
	{
		fac[i] = (i*fac[i-1])%delta;
		ifac[i] = pow(fac[i],delta-2);
	}
	cin>>h>>w>>n;
	FOR(i,0,n)
		cin>>A[i].first>>A[i].second;
	A[n].first = h, A[n].second = w,n++;
	sort(A,A+n);
	FOR(i,0,n)
	{
		dp[i] = C(A[i].first-1,A[i].first+A[i].second-2);
		FOR(j,0,i)
			if(A[j].first<=A[i].first && A[j].second<=A[i].second)
			{
				int dx = A[i].first - A[j].first,
				    dy = A[i].second - A[j].second;
				dp[i] -= (dp[j]*C(dx,dx+dy))%delta;
				if(dp[i]<0)
					dp[i]+=delta;
			}
	}
	cout<<dp[n-1]<<endl;
}
