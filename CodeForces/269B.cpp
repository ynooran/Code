#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
const int N = 1e5;
int n, m, sz, dp[N];
double a;
int main(){
	cin>>n>>m;
	FOR(i,0,n){
		int x;
		cin>>x>>a;
		int ind = upper_bound(dp,dp+sz,x) - dp;
		if(ind==sz)
			sz++;
		dp[ind] = x;
	}
	cout<<n-sz<<endl;
}
