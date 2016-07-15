#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n, a[101], ans, ones;
int main()
{
	cin>>n;
	FOR(i,1,n+1)
	{
		bool tmp;
		cin>>tmp;
		if(tmp)
			ones++,a[i] = - 1;
		else
			a[i] = 1;
	}
	int max_end = ans = a[1];
	FOR(i,2,n+1)
	{
		max_end = max(max_end + a[i], a[i]);
		ans = max(ans,max_end);
	}
	cout<<ans+ones<<endl;
}
