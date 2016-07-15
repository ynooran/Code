#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
long long n, s, ans;
int main()
{
	cin>>n;
	FOR(i,0,n)
	{
		int tmp;
		cin>>tmp;
		ans+=abs(tmp-s);
		s+=(tmp-s);
	}
	cout<<ans<<endl;
}

