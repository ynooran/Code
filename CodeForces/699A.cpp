#include <iostream>
#include <algorithm>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define int long long
#define pb push_back
using namespace std;
const int MAX = 1e18;
int ans = MAX;
string s;
int a[200001];
int32_t main(){
	int n;
	cin>>n;
	cin>>s;
	FOR(i,0,n)
		cin>>a[i];
	FOR(i,0,n-1)
		if(s[i] == 'R' && s[i+1] =='L')
			ans = min(ans, a[i+1]-a[i]);
	if(ans == MAX)
		cout<<-1<<endl;
	else
		cout<<(ans/2)<<endl;
}
