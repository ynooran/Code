#include <iostream>
#include <bitset>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int delta = 10243;
bitset<25> w;
int dp[5][5];
bool okay(int num)
{
	w = num;
	if(!(w[0]&&w[24]))
		return 0;
	dp[0][0]=1;
	FOR(i,0,5)
	FOR(j,0,5)
	{
		if(i||j)
		dp[i][j]=0;
		if(j && w[i*5+j-1])
			dp[i][j]+=dp[i][j-1];
		if(i && w[i*5+j-5])
			dp[i][j]+=dp[i-1][j];
	}
	if(dp[4][4]==1)
		return 1;
	return 0;
}
int pow(int base, int exp) {
	int ret=1;
	while(exp)
	{
		if(exp&1)
			ret*=base;
		exp>>=1;
		base*=base;
	}
	return ret;
}
int main()
{
	int ans=0;
	int MAX = pow(2,25);
	FOR(i,0,MAX)
	{
		if(okay(i))
		{
			ans++;
			ans%=delta;
		}
	}
	cout<<ans<<endl;
}
