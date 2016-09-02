#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
const int N = 600006, A = 313, MOD =  1110111110111;
int n, m, base[N];
set<int> S;
string t;
int get_hash(string &s){
	int ret = 0;
	FOR(i,0,s.size()){
		ret += s[i]*base[i];
		ret %= MOD;
	}
	return ret;
}
int32_t main(){
	base[0] = 1;
	FOR(i,1,N)
		base[i] = base[i-1]*A % MOD;
	cin>>n>>m;
	while(n--){
		cin>>t;
		S.insert(get_hash(t));
	}
	while(m--){
		bool ok = 0;
		cin>>t;
		int h = get_hash(t);
		FOR(i,0,t.size())
			FOR(j,'a','d')
				if(j != t[i])
					ok |= S.count((h+(j-t[i])*base[i]+4*MOD)%MOD);
		cout<<(ok ? "YES":"NO")<<endl;
	}
}
