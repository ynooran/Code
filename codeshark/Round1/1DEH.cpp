#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define int long long
using namespace std;
const int MAX = 2e6, M = 12251;
int phi[MAX], A, ans;
int32_t main()
{
	cin>>A;
	FOR(i,1,A+1)
	{
		phi[i] +=i;
		for(int j=2*i;j<=A;j+=i)
			phi[j]-=phi[i];
	}
	FOR(i,2,A+1)
		ans+=(phi[i]*phi[i])%M,ans%=M;
	cout<<ans<<endl;
}
