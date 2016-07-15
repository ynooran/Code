#include <iostream>
#include <set>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define all(x) x.begin(), x.end()
using namespace std;
const int MAX = 10001;
string s;
set<string> dp[MAX][2];
int main()
{
	cin>>s;
	FOR(i,6,s.size())
	{
		string d1, d2, s1, s2;
		FOR(j,i-2,i+1)
			s1+=s[j];
		for(int j = i-5; j>=3 && j<i-2; j++)
			s2+=s[j];
		FOR(j,i-1,i+1)
			d1+=s[j];
		for(int j= i-3; j>=3 && j<i-1; j++)
			d2+=s[j];
		dp[i][0] = dp[i-2][1];
		dp[i][1] = dp[i-3][0];
		if(i>6)
			dp[i][1].insert(s1);
		dp[i][0].insert(d1);
		if(d1 != d2)
			dp[i][0].insert(all(dp[i-2][0]));
		if(s2 != s1)
			dp[i][1].insert(all(dp[i-3][1]));
	}
	dp[s.size()-1][0].insert(all(dp[s.size()-1][1]));
	cout<<dp[s.size()-1][0].size()<<endl;
	for(auto x : dp[s.size()-1][0])
		cout<<x<<endl;
}
