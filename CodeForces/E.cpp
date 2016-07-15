#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define int long long
using namespace std;
int M = 1000000009;
int pow(int a, int b,int mod)
{
	a%=mod;
	if(!b)
		return 1;
	if(b&1)
		return (a*pow(a,b-1,mod))%mod;
	int p = pow(a,b/2,mod);
	return (p*p)%mod;
}
int32_t main()
{
	int k;
	cin>>k;
	int p=1;
	bool odd = true;
	FOR(i,0,k)
	{
		unsigned int tmp;
		cin>>tmp;
		if((tmp&1) == 0)
			odd = false;
		tmp%=M-1;
		p*=tmp;
		p%=M-1;
	}
	p = ((p-1)+(M-1))%(M-1);
	int kol = pow(2,p,M);
	int middle = kol;
	if(!odd)
		middle += 1;
	else
	{
		middle-=1;
		if(middle<0)
			middle+=M;
	}
	middle *= pow(3,M-2,M);
	middle %= M;
	cout<<middle<<"/"<<kol<<endl;
}
