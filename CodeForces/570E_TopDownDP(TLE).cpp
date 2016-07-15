#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

#define FOR(i,a,b) for(int i=a; i<b; i++)

const int delta = 1e9 + 7;

char forest [500][500];
int dp[500][500][500];
bool cal[500][500][500];
int n,m;

using namespace std;

int numPalindrome (int x1,int y1,int x2)
{
	if(cal[x1][y1][x2])
		return dp[x1][y1][x2];	
    int y2 = (n+m) - (x1 + y1 + x2 + 2);
    if(x1>x2 || y1>y2)
        return 0;
	if(forest[x1][y1] != forest[x2][y2])
		return 0;
	int d = (x2+y2) - (x1+y1);
	if((d==1) || (!d))
		return 1;
	dp[x1][y1][x2] = numPalindrome(x1+1,y1,x2-1)
			+ numPalindrome (x1+1,y1,x2)
			+ numPalindrome(x1,y1+1,x2-1)
			+ numPalindrome(x1,y1+1,x2);
	cal[x1][y1][x2] = true;
	return dp[x1][y1][x2];
}

int main()
{
	cin>>n>>m;
	FOR(i,0,n)
		FOR(j,0,m)
			cin>>forest[i][j];
	cout<<numPalindrome(0,0,n-1)<<endl;
}
