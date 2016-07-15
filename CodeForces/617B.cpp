#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n;
vector<int> ones;
int main()
{
	cin>>n;
	FOR(i,0,n)
	{
		int tmp;
		cin>>tmp;
		if(tmp)
			ones.push_back(i);
	}
	if(ones.empty())
		cout<<0<<endl;
	else
	{
		long long p = 1;
		FOR(i,1,ones.size())
			p *= ones[i]-ones[i-1];
		cout<<p<<endl;
	}
}

