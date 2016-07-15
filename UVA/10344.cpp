#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
bool ans;
int nums[5],perm[5],ops[4];
bool seen[5];
int f(int x, int y, int o)
{
	switch(o)
	{
		case 0: return x-y;
		case 1: return x+y;
		case 2: return x*y;
	}
}
void checkp()
{
	FOR(i,0,81)
	{
		int num = i;
		int tmp = perm[0];
		FOR(j,0,4)
		{
			tmp = f(tmp,perm[j+1],num%3);
			num/=3;
		}
		if(tmp==23)
			ans = true;
	}
}
void check(int ind)
{
	if(ind==5)
		checkp();
	if(ans || ind==5)
		return;
	FOR(i,0,5)
	if(!seen[i])
	{
		perm[ind]  = nums[i];
		seen[i] = true;
		check(ind+1);
		seen[i] = false;
	}
}
int main()
{
	while(1)
	{
		FOR(i,0,5)
			cin>>nums[i];
		if(!nums[0])
			break;
		check(0);
		if(ans)
			cout<<"Possible"<<endl;
		else
			cout<<"Impossible"<<endl;
		ans=0;
	}
}
