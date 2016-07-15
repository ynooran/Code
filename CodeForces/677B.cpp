#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int MAX = 100000;
int n,h,k,a[MAX],ans,full;
int main()
{
	cin>>n>>h>>k;
	FOR(i,0,n)
		cin>>a[i];
	FOR(i,0,n)
	{
		cerr<<dbug(full)<<dbug(ans)<<i<<endl;
		if(a[i]+full<=h)
		{
			full+=a[i];
			continue;
		}
		i--;
		while(full+a[i]>h)
			full = 
	}
	while(full)
	{
		full = max(0,full-k);
		ans++;
	}
	cout<<ans<<endl;
}
