#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define int long long
using namespace std;
int col[5],row[5], cnt2, ans, n, mp[10][10];
unordered_set< int > S;
void bt(int i,int j)
{
	if(i==n)
	{
		if(cnt2){
			int p = 0;
			FOR(z,0,5)
				p = p * 11 + row[z];
			FOR(z,0,5)
				p = p * 11 + col[z];

			S.insert(p);
			ans++;
		}
		return;
	}
	FOR(k,0,3)
	{
		mp[i][j] = k;
		col[j] += k;
		row[i] += k;
		if(k==2)
			cnt2 ++;
		if((!i || row[i]<=row[i-1]) && (i!=n-1 || j==0 || col[j-1]>=col[j]))
		{
			if(j+1<n)
				bt(i,j+1);
			else
				bt(i+1,0);
		}
		if(k==2)
			cnt2--;
		mp[i][j] = 0;
		col[j] -=k;
		row[i] -= k;
	}
}
int32_t main()
{
	cin>>n;
	bt(0,0);
	cout<<ans<<endl;
	cout<<S.size()<<endl;
}
