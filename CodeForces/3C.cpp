#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int ans;
char a[3][3];
bool win(char x)
{
	FOR(i,0,3)
		if(a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][2] == x)
			return true;
	FOR(i,0,3)
		if(a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[2][i] == x)
			return true;
	if(a[0][0]==a[1][1] && a[1][1] == a[2][2] && a[2][2] == x)
		return true;
	FOR(i,0,3)
		if(a[2-i][i] !=x)
			return false;
	return true;
}
int num(char x)
{
	int ret=0;
	FOR(i,0,3)
		FOR(j,0,3)
			if(x==a[i][j])
				ret++;
	return ret;
}
bool good()
{
	if(win('0') && win('X'))
		return false;
	if(win('0') && num('X')>num('0'))
		return false;
	if(win('X') && num('X') <=num('0'))
		return false;
	if(num('X') - num('0') >1 || num('X')-num('0')<0)
		return false;
	return true;
}
int main()
{
	FOR(i,0,3)
		FOR(j,0,3)
			cin>>a[i][j];
	if(!good())
		cout<<"illegal"<<endl;
	else
	{
		if(win('0'))
			cout<<"the second player won"<<endl;
		else if(win('X'))
			cout<<"the first player won"<<endl;
		else if(num('X') == num('0'))
			cout<<"first"<<endl;
		else if(num('X') == 5)
			cout<<"draw"<<endl;
		else
			cout<<"second"<<endl;
	}
}
