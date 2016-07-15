#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
long long num [70][70];
bool calc[70][70];
long long f (int i, int j)
{
	if(j<0 || i>j)
		return 0;
	if((i==j) || !i)
		return 1;
	if(!calc[i][j])
	{
		num[i][j] = f(i-1,j-1) + f(i,j-1);
		calc[i][j] = true;
	}
	return num[i][j];
}

int main()
{
	int n,m,t;
	long long ans=0;
	cin>>n>>m>>t;
	FOR(i,4,t)
		ans+=f(i,n)*f(t-i,m);
	cout<<ans<<endl;
}
