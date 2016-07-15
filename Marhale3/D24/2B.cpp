#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
const int MAX = 20000, delta = 10427;
int h[MAX+1], ans, l[MAX+1], M;
int main()
{
	h[1] = 123;
	h[2] = 456;
	FOR(i,3,MAX+1)
		h[i] = (h[i-1] + h[i-2])%1234 + 1;
	FOR(i,1,MAX+1)
	{
		M++;
		int j = l[h[i]];
		if(j)
		{
			while(j<i)
			{
				if(h[j]>h[i])
					break;
				j++;
			}
			if(j==i)
				M--;
		}
		l[h[i]] = i;
	}
	cout<<M<<endl;
	ans = 1;
	FOR(i,0,4)
	{
		ans*=M;
		ans%=delta;
	}
	cout<<ans<<endl;
}
