#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
long long n,a,b,c,d,ans;
int main()
{
	cin>>n>>a>>b>>c;
	d = b-c;
	if(a<=d || n<=c)
		ans = n/a;
	else
	{
		ans+=(n-c)/d;
		n-=((n-c)/d)*d;
		ans+=n/a;
	}
	cout<<ans<<endl;
}

