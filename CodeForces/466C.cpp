#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long int sum[500100],tmp;

int main()
{
	int n,a1=0;
	long long ans=0;
	cin>>n;
	cin>>sum[0];
	for(int i=1; i<n; i++)
		cin>>tmp,sum[i] = sum[i-1] + tmp;
	tmp = sum[n-1]/3;
	if(3*tmp == sum[n-1])
	{
		for(int i=0; i<n-1; i++)
		{
			if(sum[i] == 2*tmp)
				ans+=a1;
			if(sum[i] == tmp)
				a1++;
		}
	}
	cout<<ans<<endl;	
}

