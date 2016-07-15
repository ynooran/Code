#include <iostream>
#include<algorithm>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define int long long
using namespace std;
const int N = 1111151, M = 12251;
int phn, ans;
vector<int> d;
int pow(int a, int b)
{
	if(!b)
		return 1;
	if(b&1)
		return (a*pow(a,b-1))%N;
	int p = pow(a,b/2);
	return (p*p)%N;
}
int calc(int p)
{
	FOR(i,0,d.size())
		if(pow(p,d[i])==1)
			return d[i];
}
int phi(int x)
{
	int ret=x;
	for(int i=2; i*i<=x; i++)
		if(x%i==0)
		{
			ret/=i;
			ret*=i-1;
			while(x%i==0)
				x/=i;
		}
	if(x>1)
		ret = (ret/x)*(x-1);
	return ret;
}
int32_t main()
{
	phn = phi(N);
	for(int i = 1; i*i<=phn; i++)
		if(phn%i==0)
		{
			d.push_back(i);
			if(i*i != phn)
				d.push_back(phn/i);
		}
	sort(d.begin(),d.end());
	FOR(i,1,N)
		ans += calc(i),ans%=M;
	cout<<ans<<endl;
}
