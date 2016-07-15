#include <iostream>
#include <set>
#include <bitset>
#include<vector>
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define dbug(x) #x<<": "<<x<<' '
#define int long long
using namespace std;
const int delta = 10567;
bitset<16> q;
vector<int> t(8);
set<vector<int> > S;
int32_t main()
{
	FOR(i,0,1<<16)
	{
		q = i;
		FOR(j,0,8)
			t[j] = 0;
		FOR(j,0,4)
			FOR(l,0,4)
				if(q[j*4+l])
					t[j]++, t[l+4]++;
		S.insert(t);		
	}
	int ans = S.size()%delta;
	FOR(i,0,2)
	{
		ans*=ans;
		ans%=delta;
	}
	cout<<ans<<endl;
}
