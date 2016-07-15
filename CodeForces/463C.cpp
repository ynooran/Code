#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
long long n, a[2000][2000], s[2][5000], ans[2][3];
int main()
{
	cin>>n;
	FOR(i,0,n)
		FOR(j,0,n)
		{
			scanf("%d",&a[i][j]);
			s[0][i+j]+=a[i][j];
			s[1][n+i-j]+=a[i][j];
		}
	FOR(i,0,n)
		FOR(j,0,n)
			if(s[0][i+j] + s[1][n-j+i] - a[i][j] >= ans[(i+j)&1][2])
			{
				ans[(i+j)&1][2] = s[0][i+j] + s[1][n-j+i] - a[i][j];
				ans[(i+j)&1][1] = j;
				ans[(i+j)&1][0] = i;
			}
	cout<<ans[0][2]+ans[1][2]<<endl;
	FOR(i,0,2)
		FOR(j,0,2)
			cout<<ans[i][j]+1<<" ";
	cout<<endl;
}
