#include <iostream>
#include <algorithm>
#include <set>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n, m, ans;
set<string> S;
int main()
{
	cin>>n>>m;
	FOR(i,0,n)
	{
		string t;
		cin>>t;
		S.insert(t);
	}
	FOR(i,0,m)
	{
		ans = 0;
		string t;
		cin>>t;
		FOR(j,0,t.size())
			FOR(l,0,3)
				if(t[j] != 'a' + l)
				{
					char tmp = t[j];
					t[j] = 'a' + l;
					ans |= S.count(t);
					t[j] = tmp;
				}
		cout<<(ans ? "YES":"NO")<<endl;
	}
}
