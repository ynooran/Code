#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

#define FOR(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int dp[1100][1100][2], zeroPlace[2];

const int MAX = 1000000001;

int numPrime (int a, int b)
{
	if(a%b)
		return 0;
	return numPrime(a/b, b) + 1;
}

void displayString(int x, int y, int prime)
{
	if(x==1 && y==1)
		return;
	if(dp[x-1][y][prime] < dp[x][y-1][prime])
	{
		displayString(x-1,y,prime);
		cout<<"D";
		return;
	}
	displayString(x,y-1,prime);
	cout<<"R";
}

int main()
{
	bool flag = false;
	int n;
	cin>>n;
	FOR(i,2,n+1)
		FOR(j,0,2)
			dp[i][0][j] = dp[0][i][j] = MAX;
	FOR(i,1,n+1)
		FOR(j,1,n+1)
		{
			int tmp;
			scanf("%d",&tmp);
			if(!tmp)
				flag = true, tmp = 10,zeroPlace[0] = i, zeroPlace[1] = j;
			dp[i][j][0] = min(dp[i][j-1][0],dp[i-1][j][0]) + numPrime(tmp,2);
			dp[i][j][1] = min(dp[i][j-1][1],dp[i-1][j][1]) + numPrime(tmp,5);
		}
	int answer = min(dp[n][n][0],dp[n][n][1]);
	if(flag && answer)
	{
		cout<<"1"<<endl;
		FOR(i,1,zeroPlace[0])
			printf("D");
		FOR(i,1,zeroPlace[1])
			printf("R");
		FOR(i,zeroPlace[0],n)
			printf("D");
		FOR(i,zeroPlace[1],n)
			printf("R");
	}
	else
	{
		cout<<answer<<endl;
		if(answer == dp[n][n][0])
			displayString(n,n,0);
		else
			displayString(n,n,1);
	}
}
