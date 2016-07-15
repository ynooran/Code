#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

#define FOR(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int badges[6100];

int main()
{
	int n,ans=0,i=0;
	cin>>n;
	FOR(i,0,n)
	{
		int tmp;
		cin>>tmp;
		badges[tmp]++;
	}
	while(n)
	{
		n-=badges[i];
		int x = badges[i]-1;
		if(x>0)
		{
			badges[i+1]+=x;
			n+=x;
			ans+=x;
		}
		i++;
	}
	cout<<ans<<endl;
}
