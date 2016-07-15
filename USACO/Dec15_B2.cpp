#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int road[101];
int main()
{
	int ans=0;
	ifstream fin("speeding.in");
	ofstream fout("speeding.out");
	int n,m;
	fin>>n>>m;
	int a=1,b=0;
	while(n--)
	{
		int w;
		fin>>b>>w;
		FOR(j,a,b+a)
			road[j] = w;
		a +=b;
	}
	a = 1;
	b = 0;
	while(m--)
	{
		int w;
		fin>>b>>w;
		FOR(j,a,b+a)
			if(road[j]<w)
				ans = max(ans,w-road[j]);
		a+=b;
	}
	fout<<ans<<endl;
}
