#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
string s,t;
int k;
bool flag;
int main()
{
	cin>>s>>k;
	if(s.size()%k==0)
	{
		t = s;
		int sz = s.size()/k;
		FOR(i,0,k)
			reverse(t.begin()+i*sz,t.begin()+(i+1)*sz);
		flag = (s==t);
	}
	cout<<(flag ? "YES":"NO")<<endl;
}
