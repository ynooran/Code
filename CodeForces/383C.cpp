#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
using namespace std;
const int N = 2.1e5;
int n,q,t,a[N],st[N],en[N],h[N],seg[4*N];
vector<int> adj[N];
void dfs(int v, int par = -1){
	st[v] = t++;
	for(int u : adj[v])
		if(u != par){
			h[u] = h[v] + 1;
			dfs(u,v);
		}
	en[v] = t;
}
int get( int p, int v = 1, int s = 0, int e = n){
	if(e-s==1)
		return seg[v];
	int mid = (s+e)/2;
	if(p<mid)
		return seg[v] + get(p, 2*v, s, mid);
	else
		return seg[v] + get(p, 2*v+1, mid, e);
		
}
void upd( int L, int R, int val, int v = 1, int s = 0, int e = n){
	if(L<=s && e<=R){
		seg[v] += val;
		return;
	}
	if(R<=s || e<=L)
		return;
	int mid = s+e>>1;
	upd(L,R,val,v<<1,s,mid), upd(L,R,val,v<<1^1,mid,e);
}
int main(){
	cin>>n>>q;
	FOR(i,0,n)
		cin>>a[i];
	FOR(i,0,n-1){
		int a, b;
		cin>>a>>b; a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0);
	FOR(i,0,n)
		upd(st[i],st[i]+1,(h[i]%2 ? -1 : 1)*a[i]);
	while(q--){
		int op,v;
		scanf("%d%d",&op,&v); v--;
		if(op == 1){
			int val;
			scanf("%d",&val);
			upd(st[v],en[v],(h[v]%2 ? -1: 1)*val);
		}
		else
			printf("%d\n",(h[v]%2 ? -1 : 1)*get(st[v]));
	}
}
