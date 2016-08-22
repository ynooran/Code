#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define int long long
#define dbug(x) #x<<": "<<x<<' '
typedef long long ll;
using namespace std;
const int N = 1e5+10;
int n;
string a[N],ra[N];
int dp[N][2],c[N];
int32_t main(){
	cin>>n;
	FOR(i,0,n)
		dp[i][0] = dp[i][1] = 1e18;
	FOR(i,0,n)
		cin>>c[i];
	FOR(i,0,n)
		cin>>ra[i];
	FOR(i,0,n){
		a[i] = ra[i];
		reverse(ra[i].begin(),ra[i].end());
	}
	dp[0][0] = 0;
	dp[0][1] = c[0];
	FOR(i,1,n){
		if(a[i]>=a[i-1])
			dp[i][0] = min(dp[i][0],dp[i-1][0]);
		if(a[i]>=ra[i-1])
			dp[i][0] = min(dp[i][0],dp[i-1][1]);
		if(ra[i]>=a[i-1])
			dp[i][1] = min(dp[i][1],c[i] + dp[i-1][0]);
		if(ra[i]>=ra[i-1])
			dp[i][1] = min(dp[i][1],c[i] + dp[i-1][1]);
	}
	int ans = min(dp[n-1][0],dp[n-1][1]);
	if(ans<1e18)
		cout<<ans<<endl;
	else
		cout<<-1<<endl;
}
