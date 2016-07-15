#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
typedef long long ll;
const int MAX = 1e6, delta = 10427;
ll m1, m2, inv2, ans;
ll twoPow(int x)
{
	if(!x)
		return 1;
	ll ret = twoPow(x/2);
	ret*=ret;
	if(x%2)
		ret*=2;
	ret%=delta;
	return ret;
}
int main()
{
	inv2 = twoPow(delta-2);
	FOR(i,0,MAX+1)
	{
		ll sz = twoPow(MAX-i);
		ll low, high;
		high = twoPow(MAX)-1;
		low = high-sz+1;
		high%=delta;
		low%=delta;
		ll tans = sz*(low+high)*inv2;
		tans%=delta;
		m1+=tans;
		m1%=delta;
	}
	FOR(i,0,MAX+1)
	{
		ll d = twoPow(i), sz = twoPow(MAX-i);
		ll an = twoPow(MAX)-1, a1 = an - (sz-1)*d;
		while(a1<0)
			a1+=delta;
		a1%=delta;
		ll tans = (a1+an)*sz*inv2;
		tans%=delta;
		m2+=tans;
		m2%=delta;
	}
	ans = (m1*m2)%delta;
	ans*=ans;
	cout<<ans%delta<<endl;
}
