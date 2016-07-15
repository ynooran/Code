#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,m,a[100],b[100];
int main()
{
	cin>>n>>m;
	FOR(i,0,n)
		cin>>a[i];
	FOR(i,0,m)
		cin>>b[i];
	int mina = *min_element(a,a+n);
	int maxa = *max_element(a,a+n);
	int minb = *min_element(b,b+m);
	int v = max(2*mina,maxa);
	cout<<(v<minb ? v : -1)<<endl;
}

