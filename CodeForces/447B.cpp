#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
string s;
long long k, c[26], m;
long long ans()
{
	long long ret = 0;
	FOR(i,0,s.size())
		ret+=(i+1)*c[s[i]-'a'];
	return ret;
}
int main()
{
	cin>>s>>k;
	FOR(i,0,26)
	{
		cin>>c[i];
		if(c[i]>c[m])
			m = i;
	}
	FOR(i,0,k)
		s+=(char)(m+'a');
	cout<<ans()<<endl;
}

