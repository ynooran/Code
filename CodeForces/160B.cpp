#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,a[2][100];
bool ans()
{
	if(a[0][0] > a[1][0])
	{
		FOR(i,1,n)
			if(a[0][i]<=a[1][i])
				return false;
	}
	else
		FOR(i,0,n)
			if(a[0][i]>=a[1][i])
				return false;
	return true;
}
int main()
{
	cin>>n;
	FOR(i,0,2)
		FOR(j,0,n)
		{
			char tmp;
			cin>>tmp;
			a[i][j] = tmp - '0';
		}
	sort(a[0], a[0] + n);
	sort(a[1], a[1] + n);
	cout<<( ans() ? "YES":"NO")<<endl;
}
