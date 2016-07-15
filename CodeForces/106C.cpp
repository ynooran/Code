#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

#define FOR(i,a,b) for(int i=a; i<b; i++)

int n,m,c0,d0,a[12],b[12],c[12],d[12],dp[12][1100];

using namespace std;

void fill (const int x,const int ni)
{
	int &answer = dp[x][ni];
	FOR(i,0,1100)
	{
		int dressing = i*b[x];
		int dough = i*c[x];
		int price = i*d[x];
		if( (dressing > a[x]) || (dough > ni) )
			break;
		answer = max(answer,dp[x-1][ni - dough] + price);
	}
}	

int main()
{
	cin>>n>>m>>c[1]>>d[1];m++;
	b[1] = 0;
	a[1] = 1;
	FOR(i,2,m+1)
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	FOR(i,1,m+1)
		FOR(j,1,n+1)
			fill(i,j);
	cout<<dp[m][n]<<endl;
}
