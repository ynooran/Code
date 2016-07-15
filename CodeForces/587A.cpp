#include <iostream>
#include <cstdio>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int MAX = 20000001;
int n;
int w[MAX];
int main()
{
	cin>>n;
	long long ans=0;
	int tmp;
	FOR(i,0,n)
	{
		scanf("%d",&tmp);
		w[tmp]++;
	}
	FOR(i,0,MAX)
	{
		w[i+1] += w[i]/2;
		ans+=(w[i]%2);
	}
	cout<<ans<<endl;
}
