#include<iostream>
#include<algorithm>
#define FOR(i,a,b) for(int i = a; i<b; i++)
using namespace std;
bool is[1000010];
int main ()
{
	int n,ans=0,tmp=0;
	cin>>n;
	FOR(i,0,n)
	{
		char a;
		int x;
		cin>>a>>x;
		if(a == '+')
		{
			is[x] = true;
			tmp++;
		}
		else 
		{
			if(is[x])
				tmp--;
			else
				ans = max(ans,tmp)+1;
			is[x] = false;
		}
		ans = max(ans,tmp);
	}
	cout<<ans<<endl;
}
