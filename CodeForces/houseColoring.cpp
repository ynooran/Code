#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 100000;

int street [MAX][3],dp [MAX][3];

int main ()
{
	int n;
	cin>>n;
	dp [0][0] = dp [0][1] = dp [0][2] = 0;

	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)
			scanf("%d",&street[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)
			dp[i][j] = min(dp[i-1][(j+1)%3] , dp[i-1][(j+2)%3]) + street[i][j];
	int answer=dp[n][0];
	for(int i=1;i<3;i++)
		if(answer > dp[n][i])
			answer = dp[n][i];
	cout<<answer<<endl;

}

