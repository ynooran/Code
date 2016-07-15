#include <iostream>
#include <algorithm>
#include <vector>
#define FOR(i,a,b) for(long long i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int delta = 781817, MAX = 1e6;
long long T[63], S[63], ans;
vector<long long> children[MAX + 1];
long long par (long long x)
{
	int ind = lower_bound(S,S+63,x) - S;
	return x-T[ind];
}
bool goodPar(long long x)
{
	FOR(i,0,3)
		if(__gcd(x,children[x][i]) > 1)
			return false;
	return true;
}
int main()
{
	T[0] = 1;
	T[1] = 1;
	T[2] = 2;
	S[0] = 1;
	S[1] = 2;
	S[2] = 4;
	FOR(i,3,63)
		T[i] = T[i-1] + T[i-2] + T[i-3];
	FOR(i,1,63)
		S[i] = T[i] + S[i-1];
	FOR(i,1,6e6)
	{
		long long tmp = par(i);
		if(tmp<=MAX)
			children[tmp].push_back(i);
	}
	FOR(i,1,MAX)
		if(goodPar(i))
		{
			ans += i;
			ans %= delta;
		}
	cout<<ans<<endl;
}
