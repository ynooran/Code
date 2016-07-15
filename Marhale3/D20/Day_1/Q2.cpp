#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int delta = 10133;
int a[7];
bool good ()
{
	bool ret = 1;
	FOR(i,0,2)
		ret&=(a[i]==a[i+1]);
	FOR(i,4,6)
		ret&=(a[i]==a[i+1]);
	if(ret) return 1;
	ret = 1;
	FOR(i,0,2)
		ret&=(a[i]==a[i+1]);
	FOR(i,3,5)
		ret&=(a[i]==a[i+1]);
	if(ret) return 1;
	ret = 1;
	FOR(i,1,3)
		ret&=(a[i]==a[i+1]);
	FOR(i,4,6)
		ret&=(a[i]==a[i+1]);
	if(ret) return 1;
	ret = 1;
	FOR(i,4,6)
		ret&=(a[i]==a[i+1]);
	if(ret && a[0]==a[1] && a[2]==a[3])
		return 1;
	ret = 1;
	FOR(i,2,4)
		ret&=(a[i]==a[i+1]);
	if(ret&& a[0]==a[1] && a[5]==a[6])
		return 1;
	ret = 1;
	FOR(i,0,2)
		ret&=(a[i]==a[i+1]);
	if(ret&& a[3]==a[4] && a[5]==a[6])
		return 1;
	ret = 1;
	FOR(i,0,3)
		ret&=(a[2*i]==a[2*i+2]);
	FOR(i,0,2)
		ret&=(a[2*i+1]==a[2*i+3]);
	if(ret) return 1;
	return 0;
}
int main()
{
	int ans = 0;
	FOR(i,1000000,7801390)
	{
		int x = i;
		FOR(i,0,7)
		{
			a[6-i] = x%10;
			x/=10;
		}

		if(good())
			ans++;
		ans%=delta;
	}
	cout<<((ans*ans)%delta)<<endl;
}
