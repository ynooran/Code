#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define dbug(x) #x<<" = "<<(x)<<" "
using namespace std;
const int N = 4.1e5;
int lazy[4*2*N], n;
vector<int> ax;
vector<pair<int,int>> P;
set<int> S;
void shift(int v){
	if(!lazy[v])
		return;
	lazy[2*v] = lazy[2*v+1] = lazy[v];
	lazy[v] = 0;
}
void upd(int L, int R, int id, int v = 1, int s = 0, int e = ax.size()){
	if(L <= s && e <= R){
		lazy[v] = id;
		return;
	}
	if(R <= s || e <= L)
		return;
	int mid = (s+e)/2;
	shift(v);
	upd(L,R,id,2*v,s,mid);
	upd(L,R,id,2*v+1,mid,e);
}
void fillS(int v = 1, int s = 0, int e = ax.size()){
	if(lazy[v]){
		S.insert(lazy[v]);
		return;
	}
	if(e-s==1)
		return;
	int mid = (s+e)/2;
	fillS(2*v,s,mid), fillS(2*v+1,mid,e);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ax.clear();
		P.clear();
		S.clear();
		memset(lazy,0,sizeof(lazy));
		FOR(i,0,n){
			int l, r;
			cin>>l>>r;
			P.pb({l, r});
			ax.pb(l), ax.pb(r);
		}
		sort(ax.begin(),ax.end());
		ax.resize(unique(ax.begin(),ax.end()) - ax.begin());
		FOR(i,0,n){
			int l = lower_bound(ax.begin(),ax.end(),P[i].first) - ax.begin();
			int r = upper_bound(ax.begin(),ax.end(),P[i].second) - ax.begin();
			upd(l,r,i+1);
		}
		fillS();
		cout<<S.size()<<endl;
	}
}
