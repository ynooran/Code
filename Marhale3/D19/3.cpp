#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
const int delta = 10243;
int choose[70][70];
bool solved[70][70];
int solve (int i, int j)
{
	if(j<0 || j<i)
		return 0;
	if(i==j || !i)
		return 1;
	if(!solved[i][j])
	{
		choose[i][j] = (solve(i-1,j-1) + solve(i,j-1))%delta;
		solved[i][j] = true;
	}
	return choose[i][j];
}
int main()
{
	cout<<solve(33,66)<<endl;
}
