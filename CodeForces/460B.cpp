#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
typedef long long ll;
ll a,b,c;
vector<ll> ans;
ll pw(ll l, ll k)
{
	ll ret = 1;
	FOR(i,0,k)
		ret*=l;
	return ret;
}
ll sd(ll x)
{
	if(!x)
		return 0;
	else
		return (x%10) + sd(x/10);
}
int main()
{
	cin>>a>>b>>c;
	FOR(i,1,82)
	{
		ll x = b*pw(i,a)+c;
		if(x<=1000000000 && x>0 && sd(x) == i)
			ans.push_back(x);
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(ll x : ans)
		cout<<x<<" ";
	cout<<endl;
}
