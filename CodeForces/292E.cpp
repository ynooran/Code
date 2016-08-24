#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
const int N = 1e5+10;
int n,m,a[N],b[N],seg[4*N];
vector<pair<int,int>> qs;
void upd(int L, int R, int val, int v = 1, int s = 0, int e = n){
	if(L<=s && e<=R){
		seg[v] = val;
		return;
	}
	if(R<=s || e<=L)
		return;
	int mid = (s+e)/2;
	upd(L,R,val,2*v,s,mid),upd(L,R,val,2*v+1,mid,e);
}
int gets(int p, int v=1, int s=0, int e=n){
	int ret = seg[v];
	if(e-s==1)
		return ret;
	int mid = (s+e)/2;
	if(p<mid)
		ret = max(ret, gets(p,2*v,s,mid));
	else
	       ret = max(ret, gets(p,2*v+1,mid,e));
	return ret;
}
int get(int p){
	int ind = gets(p);
	if(ind<0)
		return b[p];
	return a[qs[ind].first + p - qs[ind].second];
}
int main(){
	cin>>n>>m;
	FOR(i,0,n)
		cin>>a[i];
	FOR(i,0,n)
		cin>>b[i];
	memset(seg,-1,sizeof(seg));
	FOR(i,0,m){
		int op;
		cin>>op;
		if(op==1){
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k); x--; y--;
			upd(y,y+k,qs.size());
			qs.push_back({x, y});
		}
		else{
			int x;
			cin>>x; x--;
			printf("%d\n",get(x));
		}
	}
}
