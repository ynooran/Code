#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,d[100],a,b,ans;
int main()
{
	cin>>n;
	FOR(i,1,n)
		cin>>d[i];
	cin>>a>>b;
	while(a<b)
		ans += d[a++];
	cout<<ans<<endl;
}

