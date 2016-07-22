#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i=a; i<b; i++)
typedef long long ll;
using namespace std;
const ll N = 1e5;
ll n,m,h[N],p[N];
bool good(ll t){
	ll pind = 0;
	FOR(i,0,n){
		ll d = max(h[i] - p[pind],0ll);
		if(d>t)
			return false;
		ll mm = max(t-2*d, (t-d)/2);
		pind = upper_bound(p,p+m,h[i] + mm) - p;
		if(pind == m)
			return true;
	}
	return false;
}
int main(){
	cin>>n>>m;
	FOR(i,0,n)
		cin>>h[i];
	FOR(i,0,m)
		cin>>p[i];
	ll l = -1, h = 2e10;
	while(h-l>1){
		ll m = h+l>>1;
		(good(m) ? h : l) = m;
	}
	cout<<h<<endl;
}
