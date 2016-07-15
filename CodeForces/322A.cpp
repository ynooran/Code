#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,m;
int main()
{
	cin>>n>>m;
	cout<<n+m-1<<endl;
	FOR(i,1,n+1)
		cout<<i<<" "<<1<<endl;
	FOR(i,2,m+1)
		cout<<1<<" "<<i<<endl;
}

