#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int a[3];
int main()
{
	int n;cin>>n;
	FOR(i,0,n)
	{
		int x;scanf("%d",&x);
		a[x-1]++;
	}
	cout<<n-max(max(a[0],a[1]),a[2])<<endl;
}
