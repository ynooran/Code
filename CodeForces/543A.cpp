#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int dp [510][510][510];
int a[510];

int main()
{
	int n,m,b,mod;
	cin>>n>>m>>b>>mod;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int numLines=0;numLines<=m;numLines++)
		for(int numBugs=0;numBugs<=b;numBugs++)
			for(int numCoders=0;numCoders<=n;numCoders++)
			{
				int value = 0;
				if(!numLines)
					value = 1;
				else if(numCoders)
				{
					if(numBugs>=a[numCoders])
						value+= dp[numLines-1][numBugs-a[numCoders]][numCoders];
					value += dp[numLines][numBugs][numCoders-1];
				}
				dp[numLines][numBugs][numCoders] = value%mod;
			}
	cout<<dp[m][b][n]<<endl;
}

