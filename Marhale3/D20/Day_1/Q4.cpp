#include <iostream>
#include <bitset>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int delta = 10133;
bitset<60> circle;
int w (int x)
{
	int cur = x-1;
	if(circle[cur])
		circle.reset();
	circle[cur] = 1;
	for(int i=0;i<x;)
	{
		cur++;
		cur%=60;
		if(cur+1 == x && !i)
		{
			circle[cur] = 1;
			return x;
		}
		if(!circle[cur])
			i++;
	}
	return w(cur+1);
}
int main()
{
	int T=1;
	FOR(i,1,61)
	{
		T*=w(i);
		T%=delta;
	}
	cout<<T<<endl;
}
