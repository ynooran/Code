#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define max(a,b) a>b ? a:b
using namespace std;
const int MAX = 100010;
typedef long long ll;
ll odd[MAX],Left[MAX],Right[MAX],a[MAX],ANS,pointer;
int main()
{
	int n;cin>>n;
	FOR(i,1,n)
		cin>>a[i];
	FOR(i,1,n+1)
	{
		if(i-1)
			odd[i] = odd[i-1] + a[i-1] - !(a[i-1]%2);
		if(a[i-1]==1)
			Left[i]=0;
		else
			Left[i] = Left[i-1] + a[i-1]-(a[i-1]%2);
	}
	for(int i = n; i>=1; i--)
		if(a[i]<=1)
			Right[i] = 0;
		else
			Right[i] = Right[i+1] + a[i]-(a[i]%2);
	FOR(i,1,n+1)
	{
		ll ans = Right[i];
		ll t = odd[i] - odd[pointer] + Left[pointer];
		ll s = Left[i];
		if(s>t)
		{
			pointer = i;
			ans +=s;
		}
		else
			ans+=t;
		ANS = max(ANS, ans);
	}
	cout<<ANS<<endl;
}
