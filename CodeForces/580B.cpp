#include <iostream>
#include<algorithm>
#include<cstdio>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
struct f
{ int m,s;};
bool comp (f a, f b) { return a.m<b.m;}
f pals[110000];
int main()
{
	int n,d;cin>>n>>d;
	FOR(i,0,n)
		scanf("%d%d",&pals[i].m,&pals[i].s);
	sort(pals,pals + n, comp);
	long long ans=0,t=0;
	int e=0;
	FOR(i,0,n)
	{
		if(i)
			t -= pals[i-1].s;
		while(e<n && pals[e].m < pals[i].m + d)
			t+=pals[e++].s;
		ans = max(ans, t);
		if(!(n-e))
			break;
	}
	cout<<ans<<endl;
}
