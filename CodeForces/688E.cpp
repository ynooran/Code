#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,k,c[501];
bool dp[501][501][501];
int main()
{
	cin>>n>>k;
	FOR(i,1,n)
		cin>>c[i];
	FOR(i,0,n)
		dp[i][0][0] = true;
	FOR(i,1,n)
		FOR(j,0,k)
			FOR(l,0,j)
			{
				dp[i][l][j] = dp[i-1][l][j];
				if(j>=c[i])
					dp[i][l][j] |= dp[i-1][l][j-c[i]];
				if(l>=c[i])
					dp[i][l][j] |= dp[i-1][l-c[i]][j-c[i]];
			}
	vector<int> ans;
	FOR(i,0,k+1)
		if(dp[n][i][k])
			ans.push_back(i);
	cout<<ans.size()<<endl;
	for(int x : ans)
			cout<<x<<" ";
	cout<<endl;
}
