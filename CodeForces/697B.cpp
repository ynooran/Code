#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define int long long
using namespace std;
int a;
string b;
string rb;
string pw;
int rpw;
string ans;
int32_t main()
{
	cin>>a>>b;
	ans = to_string(a);
	int ind = 0;
	while(b[++ind] != 'e')
		rb+=b[ind];
	pw = b.substr(ind+1,b.size()-ind-1);
	rpw = stoi(pw);
	FOR(i,0,rpw)
	{
		if(i<rb.size())
			ans+=rb[i];
		else
			ans+='0';
	}
	bool flag = false;
	FOR(i,rpw,rb.size())
		if(rb[i] > '0')
		{
			flag = true;
			break;
		}
	if(rpw<rb.size()&&flag)
	{
		ans+='.';
		FOR(i,rpw,rb.size())
				ans+=rb[i];
	}
	cout<<ans<<endl;
}
