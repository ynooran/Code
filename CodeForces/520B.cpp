#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int a[21000],n,m;
bool b[21000];
int ans(int x)
{
	if(x==n)
		return 0;
	if(b[x] || !x)
		return 10000000;
	b[x] = true;
	if(!a[x])
		a[x] = (x>n ? ans(x-1):min(ans(x-1),ans(x*2)))+1;
	b[x] = false;
	return a[x];
}

int main()
{
	cin>>m>>n;
	cout<<ans(m)<<endl;
}
