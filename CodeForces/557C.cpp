#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX 110000

using namespace std;

struct leg { int length, energy; };

bool comp (leg a, leg b) { return (a.length <= b.length); }

leg table [MAX];

int fprice [MAX], sum[MAX];
int dic [210];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&table[i].length);
	for(int i=0;i<n;i++)
		scanf("%d",&table[i].energy);
	sum[n] = 0;
	sort(table,table+n,comp);
	for(int i=n-1;i>=0;i--)
		sum[i] = table[i].energy + sum[i+1],printf("%d \n",sum[i]);
	int begin=0,ans = sum[1];
	for(int i=0;i<n;i++)
	if((table[i].length != table[i+1].length ) || (i == n-1))
	{
		int cans = sum[i+1];
		int legsleft = 2*begin -i;
		int index = 0,numindex=1;
		while(legsleft>0)
		{
			if(dic[index]>= numindex)
			{
				legsleft--;
				cans += index;
				numindex++;
			}
			else
			{
				index++;
				numindex = 1;
			}
		}
		for(int j=begin; j<=i;j++)
			dic[table[j].energy]++;
		begin = i+1;
		ans = min ( ans , cans );
	}
	printf("%d \n", ans);
}
