#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
int a[10010],n;
long ans,s;
int main()
{
	cin>>n;
	FOR(i,0,n)
	{
		cin>>a[i];
		s+= a[i];
	}
	s/=n;
	FOR(i,0,n)
		if(a[i]<s)
			ans+=(s-a[i]);
	cout<<ans<<endl;
}
