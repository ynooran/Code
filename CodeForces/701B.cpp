#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define pb push_back
#define mk make_pair
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
ll n,m,ans;
bool c[N], r[N];
int main(){
	cin>>n>>m;
	ans = n*n;
	int numR, numC;
	numR = numC = n;
	FOR(i,0,m)
	{
		int x, y;
		cin>>x>>y;
		if(!r[x] && !c[y]){
			numR --;
			numC --;
			ans -= numR + numC + 1;
			r[x] = c[y] = true;
		}
		else if(!r[x]){
			numR--;
			ans -= numC;
			r[x] = true;
		}
		else if(!c[y]){
			numC--;
			ans -= numR;
			c[y] = true;
		}
		cout<<ans<<endl;
	}
}
