#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int a[3][2];
bool ans()
{
	FOR(k,0,2)
		FOR(j,0,2)
			FOR(i,0,2)
				if(a[0][k^1]>=max(a[1][i^1],a[2][j^1]) && a[0][k]>=a[1][i] + a[2][j])
					return true;
	return false;
}
int main()
{
	FOR(j,0,3)
		FOR(i,0,2)
			cin>>a[j][i];
	cout<<(ans() == true ? "YES" : "NO")<<endl;
}
