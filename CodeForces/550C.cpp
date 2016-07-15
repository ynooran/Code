#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
string s;
bool flag;
int ans;
int main()
{
	cin>>s;
	FOR(i,0,s.size())
		if((s[i]-'0')%8==0)
			flag = true,ans=s[i]-'0';

	FOR(i,0,s.size())
		FOR(j,i+1,s.size())
		{
			int tmp = 10*(s[i]-'0') + (s[j]-'0');
			if(tmp%8==0)
				flag = true,ans=tmp;
		}
	FOR(i,0,s.size())
		FOR(j,i+1,s.size())
			FOR(l,j+1,s.size())
			{
				int tmp = 100*(s[i]-'0') + 10*(s[j]-'0') + (s[l]-'0');
				if(tmp%8==0)
					flag = true,ans=tmp;
			}
	cout<<(flag ? "YES":"NO")<<endl;
	if(flag)
		cout<<ans<<endl;
}
