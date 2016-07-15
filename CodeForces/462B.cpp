#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
long long n, k, a[26],ans;
int main()
{
	cin>>n>>k;
	FOR(i,0,n)
	{
		char t;
		cin>>t;
		a[t-'A']++;
	}
	sort(a,a+26,greater<long long>());
	FOR(i,0,26)
	{
		if(a[i]>k)
		{
			ans+=k*k;
			break;
		}
		ans += a[i]*a[i];
		k -=a[i];
	}
	cout<<ans<<endl;
}
