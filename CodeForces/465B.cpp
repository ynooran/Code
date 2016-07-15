#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n, ans;
vector<int> ones;
int main()
{
	cin>>n;
	FOR(i,0,n)
	{
		int tmp;
		cin>>tmp;
		if(tmp)
		{
			if(ones.empty())
				ones.push_back(i-1);
			ones.push_back(i);
		}
	}
	FOR(i,1,ones.size())
	{
		if(ones[i]-ones[i-1] == 1)
			ans++;
		else
			ans+=2;
	}
	cout<<ans<<endl;
}
