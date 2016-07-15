#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
typedef long long ll;
ll n, ans;
ll twoPow(int x)
{
	if(!x)
		return 1;
	return 2*twoPow(x-1);
}
bool good(int x)
{
	if(!x)
		return true;
	if(x%10>1)
		return false;
	return good(x/10);
}
int numDigits(int x)
{
	if(!x)
		return 0;
	return 1 + numDigits(x/10);
}
int main()
{
	cin>>n;
	int t = 2;
	while(t-1<=n)
		t*=10;
	t/=10;
	ans = twoPow(numDigits(t)) - 1;
	FOR(i,t*5,n+1)
		if(good(i))
			ans++;
	cout<<ans<<endl;
}
