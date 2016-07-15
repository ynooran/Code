#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int sum[100011][4],n,q;
int main()
{
	ifstream fin("bcount.in");
	ofstream fout("bcount.out");
	fin>>n>>q;
	FOR(i,1,n+1)
	{
		int tmp;
		fin>>tmp;
		FOR(j,1,4)
			sum[i][j] = sum[i-1][j];
		sum[i][tmp]++;
	}
	FOR(i,0,q)
	{
		int a,b;
		fin>>a>>b;
		FOR(j,1,4)
		{
			fout<<sum[b][j]-sum[a-1][j];
			if(j<3)
				fout<<" ";
		}
		if(i!=q)
		fout<<endl;
	}
}
