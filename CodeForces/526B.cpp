#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int edges[10000];
int main()
{
	int n,ans=0;cin>>n;
	FOR(i,2,pow(2,n+1))
		cin>>edges[i];
	for(int i=pow(2,n)-1;i;i--)
	{
		int l = edges[2*i];
		int r = edges[2*i+1];
		ans+=abs(l-r);
		edges[i]+=max(l,r);
	}
	cout<<ans<<endl;
}

