#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

#define FOR(i,a,b) for(int i=a; i<b; i++)

const int delta = 1e9 + 7;

char forest [500][500];
int dp[300][500][500];
int n,m;
int dDiagnal;

using namespace std;

void fillMiddle()
{
	if((n+m)%2)
	{
		FOR(x1,0,m)
			FOR(x2,0,m)
			{
				int y1 =  dDiagnal - x1;
				int y2 = dDiagnal - x2 +1;
				if((y1<0) || (y2<0))
					continue;
				if( abs(x1-x2)+abs(y1-y2) == 1  && forest[x1][y1] == forest[x2][y2]) 
					dp[0][x1][x2] = 1;
			}		
	}
	else
	{
		FOR(x,0,m)
		{
			int y = dDiagnal -x;
			if(y<0)
				continue;
			dp[0][x][x] = 1;
		}
	}
}

int numPalindrome (int x1,int y1,int x2,int y2)
{
    if(x1>x2 || y1>y2)
        return 0;
	if(forest[x1][y1] != forest[x2][y2])
		return 0;
	return		 dp[distance-1][x1+1][x2-1]
			+ dp[distance-1][x1+1][x2]
			+ dp[distance-1][x1][x2-1]
			+ dp[distance-1][x1][x2];
}

void fillDiagnal (int distance)
{
	FOR(x1,0,m)
		FOR(x2,0,m)
		{
			int a = &dp[distance][x1][x2];
			int d = dDiagnal - distance;
			int y1 = d - x1;
			int y2 = n+m-2 - d -x1;
			if((y1<0) || (y2<0) || x1>x2 || y1>y2 || forest[x1][y1] != forest[x2][y2]){
				a=0;continue;}
			a 	=  dp[distance-1][x1+1][x2-1]
					+ dp[distance-1][x1+1][x2]
					+ dp[distance-1][x1][x2-1]
					+ dp[distance-1][x1][x2];
		}
}

int main()
{
	cin>>n>>m;
	FOR(i,0,n)
		FOR(j,0,m)
			scanf("%c",&forest[i][j]);
	int dDiagnal = (n+m-2)/2;
	fillMiddle();
	FOR(i,1,(n+m)/2)
		fillDiagnal(i);
	cout<<dp[(n+m-2)/2][0][m-1];
}
