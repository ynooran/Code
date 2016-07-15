#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
string s;
int main()
{
	cin>>s;
	int i;
	for(i=0;i<s.size() && s[i]=='1';i++);
	if(i==s.size())
		FOR(j,0,s.size()-1)
			cout<<s[j];
	else
		FOR(j,0,s.size())
			if(j!=i)
				cout<<s[j];
	cout<<endl;
}

