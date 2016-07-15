#include <iostream>
#define FOR(a,b,c) for(int a=b; a<c; a++)
using namespace std;
const int delta = 10133;
int numBits(int x)
{
	int ret = 1;
	while(x/2)
	{
		x/=2;
		ret++;
	}
	return ret;
}
int main()
{
	int ans = 1;
	int b = 1;
	FOR(i,2,1390)
	{
		int nbits = numBits(i);
		for(int j = nbits; j>=0;j--)
		{
			int tmp = (1<<j) - 1;
			int obits = nbits-j;
			if((b&tmp) == (i>>(obits)))
			{
				ans+=(obits);
				b = (b<<(obits)) | (i&((1<<obits)-1));
				break;
			}

		}
	}
	cout<<((ans*1389)%delta)<<endl;
}
