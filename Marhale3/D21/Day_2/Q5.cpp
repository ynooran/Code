#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int maze[8][8];
void show()
{
	FOR(i,1,7)
	{
		FOR(j,1,7)
			cout<<maze[i][j]<<  " ";
		cout<<endl;
	}
	cout<<endl;
}
bool good (int cell, int code)
{
	int x = cell/6 + 1;
	int y = cell%6 + 1;
	FOR(i,0,3)
		FOR(j,0,3)
		{
			if(i==1 && j==1)
				continue;
			if(maze[x+i-1][y+j-1] == code)
				return false;
		}
	return true;
}
int ans (int x)
{
	if(x == 36)
	{
		show();
		return 1;
	}
	int& cell = maze[x/6 + 1][x%6 + 1];
	if(cell)
		return ans(++x);
	int tmp = 0;
	FOR(i,1,5)
		if(good(x,i))
		{
			cell = i;
			tmp+= ans(x+1);
			cell = 0;
		}
	return tmp;
}
int main()
{
	maze[1][3] = 3;
	maze[2][1] = 1;
	maze[2][6] = 2;
	maze[5][2] = 4;
	maze[6][4] = 4;
	cout<<ans(0)<<endl;
}
