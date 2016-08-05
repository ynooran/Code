#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define pb push_back
#define mk make_pair
typedef long long ll;
using namespace std;
const int N = 1e5+10;
ll n,k, c[N], sum;
bool cap[N];
ll ans;
int main(){
	cin>>n>>k;
	FOR(i,0,n){
		cin>>c[i];
		sum += c[i];
	}
	FOR(i,0,k){
		int x;
		cin>>x;
		x--;
		sum -= c[x];
		ans += c[x] * sum;
		cap[x] = true;
	}
	FOR(i,0,n)
		if(!cap[(i+1)%n] && !cap[i])
			ans += c[(i+1)%n]*c[i];
	cout<<ans<<endl;
}
