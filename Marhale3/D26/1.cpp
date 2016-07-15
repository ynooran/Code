#include <iostream>
#include <map>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define int long long
using namespace std;
const int M = 1e9 + 7, N = 65, K = 2e16;
int n, k;
map<pair<int,int>,int> mp;
int ans (int pw, int pc)
{
	if(!pc)
		return 0;
	int &mem = mp[make_pair(pw,pc)];
	if(mem)
		return mem;
	int ret =  1ll<<(pw-1);
	pc--;
	if(pc>ret-1)
	{
		ret += ans(pw-1,pc/2) + ans(pw-1, pc-pc/2) + 1;
		mem = ret%M;
		return mem;
	}
	ret += ans(pw-1,pc);
	mem = ret%M;
	return mem;
}
int32_t main()
{
	cin>>n>>k;
	cout<<ans(n,k-1)<<endl;
}
