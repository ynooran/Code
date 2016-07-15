#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
pair<int,int> a[1000];
int cnt[10001];
int main()
{
	int n;
	cin>>n;
	FOR(i,0,n)
	{
		int tmp;
		cin>>tmp;
		a[i] = make_pair(cnt[tmp],tmp);
		cnt[tmp]++;
	}
	sort(a,a+n);
	int ans=0;
	FOR(i,1,n)
	{
		if(a[i].second>a[i-1].second)
			ans++;
	}
	cout<<ans<<endl;
}
