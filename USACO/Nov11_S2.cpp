#include <iostream>
#include <map>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
const int MAX = 50010;
pair <int,int> c[MAX];
map <int,int> s;
int main()
{
	int n;
	cin>>n;
	FOR(i,0,n)
	{
		cin>>c[i].first>>c[i].second;
		s[c[i].second] = 0;
	}
	sort(c,c+n);
	int j=-1;
	int seen=0;
	while(seen<s.size())
	{
		int tmp = c[++j].second;
		if(!s[tmp]++)
			seen++;
	}
	int ans = c[j].first - c[0].first;
	FOR(i,0,n)
	{
		int tmp = c[i].second;
		s[tmp]--;
		while(!s[tmp] && n-j)
			s[c[++j].second]++;
		if(j==n)
			break;
		int d = c[j].first - c[i+1].first;
		ans = min(ans,d);
	}
	cout<<ans<<endl;
}
