#include <iostream>
#include<vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
vector<int> v;
const int MAX = 210000;
int n,k,x;
int suf[MAX],pref[MAX];
int main()
{
	ios::sync_with_stdio(false);
	int largest=0;
	long long xk=1,ans=0;
	cin>>n>>k>>x;
	FOR(i,0,k)
		xk*=x;
	v.push_back(0);
	FOR(i,0,n)
	{
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
		suf[i+1] = suf[i] | tmp;
		if(largest<tmp)
			largest = tmp;
	}
	for(int i=n;i>=0;i--)
		pref[i] = pref[i+1] | v[i];
	for(int i=1; i<v.size(); i++)
		ans = max( ans , suf[i-1] | v[i]*xk | pref[i+1]);
	cout<<ans<<endl;
}
