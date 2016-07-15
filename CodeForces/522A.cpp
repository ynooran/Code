#include <iostream>
#include <map>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n, ans;
string s,t;
map<string,int> M;
int main()
{
	M["POLYCARP"] = 1;
	cin>>n;
	FOR(i,0,n)
	{
		cin>>s;
		cin>>t;
		cin>>t;
		FOR(j,0,s.size())
			if(s[j]>'Z')
				s[j] -= 32;
		FOR(j,0,t.size())
			if(t[j]>'Z')
				t[j]-=32;
		M[s] = M[t] + 1;
		ans = max(ans,M[s]);
	}
	cout<<ans<<endl;
}
