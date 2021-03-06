#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int sum[110000], M[110000];

int main ()
{
	int n;
	cin>>n;
	M[0] = sum[0] = 0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&sum[i]);
		sum[i] += sum[i-1];
		M[i] = min(M[i-1],sum[i]);
	}
	int answer = sum[n];
	for(int i=0; i<=n; i++)
		answer = max (answer, 2*(sum[i] - M[i]) - sum[n]);
	cout<<answer<<endl;

}

