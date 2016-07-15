#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
typedef long long ll;
const int MAX = 20000, MAXH = 10000, delta = 10427;
ll h[MAX+1], ans, l[MAX+1], M;
ll pow(ll a, ll b)
{
	if(!b)
		return 1;
	int ret = pow(a,b/2);
	ret = ret*ret;
	if(b&1)
		ret*=a;
	ret%=delta;
	return ret;
}
int main()
{
	ans = 20000*pow(10000,20000)
	FOR(d,1,MAX)
		FOR(h,1,MAXH+1)
		{
			ll tans = 1;

		}
	cout<<ans<<endl;
}
