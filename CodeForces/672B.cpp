#include <iostream>
#include <set>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n;
set<char> s;
int main()
{
	int n;
	cin>>n;
	if(n>26)
		cout<<-1<<endl;
	else
	{
		FOR(i,0,n)
		{
			char tmp;
			cin>>tmp;
			s.insert(tmp);
		}
		cout<<n-s.size()<<endl;
	}
}
