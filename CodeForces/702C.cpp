#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
using namespace std;
const int MAX = 1e5+10;
ll a[MAX],b[MAX],n,m;
bool good (ll r){
	int ind = 0;
	FOR(i,0,n){
		while(abs(a[i]-b[ind])>r){
			ind++;
			if(ind==m)
				return false;
		}
	}
	return true;
}

int main(){
	cin>>n>>m;
	FOR(i,0,n)
		cin>>a[i];
	FOR(i,0,m)
		cin>>b[i];
	ll lo = -1, hi = 1e18+10;
	while(hi-lo>1ll){
		ll m = lo + (hi-lo)/2;
		(good(m) ? hi : lo) = m;
	}
	cout<<hi<<endl;
}
