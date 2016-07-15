#include <iostream>
#include <map>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
map <string, int> m;
int main()
{
	int n;cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		if(m[s]++)
			cout<<s<<m[s]-1<<endl;
		else
			cout<<"OK\n";
	}
}
