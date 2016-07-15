#include <iostream>
#include <bitset>
#define FOR(a,b,c) for(int a=b; a<c; a++)
using namespace std;
bitset<1390> l1,l2;
const int delta = 10133;
int main()
{
	l2[0] = 1;
	l2[1] = 1;
	for(int i=2;i*i<1390;i++)
	if(!l2[i])
	for(int j=i*i;j<1390;j+=i)
	l2[j] = 1;
	int ans = 0;
	while(l1!=l2)
	{
		l1 = l2;
		FOR(i,1,1389)
		if(!l2[i] && l2[i+1])
		{
			swap(l2[i],l2[i+1]);
			i++;
		}
		ans++;
		ans%=delta;
	}
	ans--;
	cout<<(ans*(1+ans*(1+ans)%delta)%delta)<<endl;
}
