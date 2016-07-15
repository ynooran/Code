#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
const int delta = 10267;
const int N = 1000001;
pair<double,int> list[N];
int E[N];
void fill(int x)
{
	int tx = x;
	for(int i=2;i*i<=x;i++)
	if(x%i == 0)
	{
		int l = 1,m = 1;
		while(tx%i==0)
		{
			m*=i;
			tx/=i;
			l+=m;
		}
		E[x] = E[tx]*l;
		return;
	}
	E[x] = x+1;
	return;
}
int main()
{
	E[1] = 1;
	FOR(i,2,N)
		fill(i);
	FOR(i,0,N)
		list[i] = make_pair((((double)E[i]-i)/i), i);
	sort(list,list+N,greater<pair<double,int> >());
	long long tmp = list[12].second;
	tmp = tmp*tmp*tmp + tmp*tmp;
	tmp%=delta;
	cout<<tmp<<endl;
}
