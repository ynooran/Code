#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n, a[3];
int main()
{
	cin>>n;
	while(n--)
		FOR(j,0,3)
		{
			int tmp;
			cin>>tmp;
			a[j]+=tmp;
		}
	cout<<(a[0] | a[1] | a[2] ? "NO" : "YES")<<endl;
}

