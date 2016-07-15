#include <iostream>
#include <vector>
#include<algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
struct p
{
	int a,b;
	int s;
};
bool comp (p i, p j)
{
	return i.s>j.s;
}
vector<p> v;
bool b[1000];
int c[1000];
int main()
{
	int n;cin>>n;
	FOR(i,1,2*n+1)
		FOR(j,1,i)
		{
			int m;cin>>m;
			p tmp;
			tmp.a=i;
			tmp.b=j;
			tmp.s=m;
			v.push_back(tmp);
		}
	sort(v.begin(),v.end(),comp);
	for(const p a : v)
	{
		int x = a.a;
		int y = a.b;
		if(b[x]||b[y])
			continue;
		c[x] = y;
		c[y] = x;
		b[x]=b[y]=1;
	}
	FOR(i,1,2*n+1)
		cout<<c[i]<<" ";		
}
