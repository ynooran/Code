#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int delta = 11471, MAX = 100, K = 100;
int dp[MAX+1][MAX+1];
int main()
{
	FOR(i,1,MAX+1)
		dp[1][i] = 1;
	FOR(i,2,MAX+1)
		FOR(j,1,K+1)
			FOR(l,j,K+1)
				FOR(d,j,K+1)
					if(__gcd(d,l) == j){
						dp[i][j] += dp[i-1][d];
						dp[i][j] %= delta;
					}
	cout<<dp[100][1]<<endl;
}

