#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int delta = 781817;
long long T[63], S[63], ans;
long long par (long long x)
{
	int ind = lower_bound(S,S+63,x) - S;
	return x-T[ind];
}
void calc(long long x)
{
	if(!x)
		return;
	ans += x;
	ans%=delta;
	calc(par(x));
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
	calc(1e16);
	cout<<ans<<endl;
}
