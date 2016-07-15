#include <iostream>
#include <set>
#define FOR(i,a,b) for(int i=a; i<b ;i++)
#define int long long
using namespace std;
const int N = 1234, M = 12251;
int ans;
int calc(int p)
{
		set<int> q;
		int rem = p;
		while(!q.count(rem))
		{
			q.insert(rem);
			rem = (rem*p)%N;
		}
		return q.size();
}
int32_t main()
{
	FOR(i,1,N)
		ans += calc(i),ans%=M;
	cout<<ans<<endl;
}
