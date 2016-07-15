#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
string s;
int main()
{
	cin>>s;
	FOR(i,1,s.size())
		if(s[i] == s[i-1])
			for(s[i]='a';s[i] == s[i-1] || s[i]==s[i+1]; s[i]++);
	cout<<s<<endl;
}
