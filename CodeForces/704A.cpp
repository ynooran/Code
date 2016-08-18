#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define pb push_back
#define mk make_pair
using namespace std;
const int N = 3e5 + 10;
vector<int> app[N], adds;
int ans, ci[N],li;
int32_t main(){
	int n,q;
	cin>>n>>q;
	int i = 1;
	while(q--){
		int t,x;
		cin>>t>>x;
		if(t == 1){
			ans++;
			adds.pb(x);
			app[x].pb(i++);
		}
		else if(t == 2){
			while(ci[x]<app[x].size())
				ans--,ci[x]++;
		}
		else{
			while(li<adds.size() && li<x){
				int cap = adds[li];
				if(ci[cap]<app[cap].size() && li+1 == app[cap][ci[cap]]){
					ci[cap]++;
					ans--;
				}
				li++;
			}
		}
		cout<<ans<<endl;
	}
}
