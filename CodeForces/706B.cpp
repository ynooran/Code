#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define pb push_back
#define mk make_pair
#define int long long
using namespace std;
const int N = 1e5+10;
int n,x[N];
int32_t main(){
	cin>>n;
	FOR(i,0,n)
		cin>>x[i];
	sort(x,x+n);
	int q;
	cin>>q;
	while(q--){
		int m;
		cin>>m;
		int ind = upper_bound(x,x+n,m) - x;
		cout<<ind<<endl;
	}
}
