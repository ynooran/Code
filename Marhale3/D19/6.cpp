#include <iostream>
#include <bitset>
#include <unordered_set>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
const int delta = 10243;
bitset<6> b;
int s[6];
int f ()
{
	unordered_set<int> set;
	FOR(i,0,1<<6)
	{
		b = i;
		int n=0;
		FOR(j,0,6)
		if(b[j])
			n+=s[j];
		set.insert(n);
	}
	return set.size();
}		
int main()
{

	int ans=0;
	
	for(s[0]=10;s[0]<26;++s[0])
	for(s[1]=s[0];s[1]<26;++s[1])
	for(s[2]=s[1];s[2]<26;++s[2])
	for(s[3]=s[2];s[3]<26;++s[3])
	for(s[4]=s[3];s[4]<26;++s[4])
	for(s[5]=s[4];s[5]<26;++s[5])
	if(s[0]+s[1]+s[2]+s[3]+s[4]+s[5] == 100)
	{
		ans = max(ans,f());
	}
	cout<<((ans*ans*ans)%delta)<<endl;
}
