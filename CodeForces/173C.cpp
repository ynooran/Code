#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
int s[501][501],a[501][501],n,m,ans,sum;
int main(){
	ans = -2e9;
	cin>>n>>m;
	FOR(i,0,n)
		FOR(j,0,m){
			cin>>a[i+1][j+1];
			s[i+1][j+1] = s[i+1][j] + s[i][j+1] - s[i][j] + a[i+1][j+1];
		}
	FOR(r,2,n)
		FOR(c,2,m){
			sum = a[r][c];
			int w = 1;
			while(r-w>0 && r+w<=n && c-w>0 && c+w<=m){
				sum = s[r+w][c+w] - s[r+w][c-w-1] - s[r-w-1][c+w] + s[r-w-1][c-w-1] - sum - a[r-w+1][c-w];
				ans = max(ans,sum);
				w++;
			}
		}
	cout<<ans<<endl;
}
