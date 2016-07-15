#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
int happiness[9][9], dir[4][2] = { {0,-1} , {1,0} , {0,1}, {-1,0}};
int x,y;
const int delta = 10091;
int main()
{
	FOR(i,1,delta)
	{
		happiness[x][y]++;
		int ind = happiness[x][y] % 4;
		x+=dir[ind][0];
		y+=dir[ind][1];
		x = (x+9)%9;
		y =(y+9)%9;
	}
	long long ans = 1;
	FOR(i,0,9)
		FOR(j,0,9)
		{
			ans*=happiness[j][i];
			ans%=delta;
		}
	cout<<ans<<endl;
}
