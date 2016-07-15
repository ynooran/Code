#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
int n,m,a[500][500], rec[500][2][26], dp[500][26][26], tp[500][26][26][2], flag[500][2], c1, c2, ans;
void show(){
	for(int i=n-1;i>=0;i--){
		flag[i][0] = c1;
		flag[i][1] = c2;
		c1 = tp[i][c1][c2][0];
		c2 = tp[i][flag[i][0]][c2][1];
	}
	FOR(i,0,n){
		FOR(j,0,m)
			cout<<(char)(flag[i][j%2]+'a');
		cout<<endl;
	}
}
int main(){
	cin>>n>>m;
	FOR(i,0,n)
		FOR(j,0,m){
			char tmp;
			cin>>tmp;
			a[i][j] = tmp - 'a';
		}
	FOR(i,0,n)
		FOR(c,0,26)
			FOR(j,0,m)
				if(a[i][j]!=c)
					rec[i][j%2][c]++;
	FOR(a,0,26)
		FOR(b,0,26)
		dp[0][a][b] = rec[0][0][a] + rec[0][1][b];
	FOR(i,1,n)
		FOR(a,0,26)
			FOR(b,0,26){
				dp[i][a][b] = 2e9;
				FOR(c,0,26)
					FOR(d,0,26)
						if(c!=d && a!=c && b!=d && dp[i][a][b]>dp[i-1][c][d]){
							dp[i][a][b] = dp[i-1][c][d];
							tp[i][a][b][0] = c;
							tp[i][a][b][1] = d;
						}
				dp[i][a][b] += rec[i][0][a] + rec[i][1][b];
			}
	ans = 2e9;
	FOR(a,0,26)
		FOR(b,0,26)
			if(a!=b && ans>dp[n-1][a][b]){
				ans = dp[n-1][a][b];
				c1 = a;
				c2 = b;
			}
	cout<<ans<<endl;
	show();
}
