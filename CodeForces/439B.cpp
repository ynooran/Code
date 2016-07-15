#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
long long n,x,c[100000], ans;
int main()
{
	cin>>n>>x;
	FOR(i,0,n)
		cin>>c[i];
	sort(c,c+n);
	FOR(i,0,n)
	{
		ans+=x*c[i];
		if(x>1)
			x--;
	}
	cout<<ans<<endl;
}

