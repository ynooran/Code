#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;
int n,q,str[N],cnt[4*N],seg[4*N];
void build(int v = 1, int s = 0, int e = n){
	if(e-s==1){
		seg[v] = str[s];
		cnt[v] = 1;
		return;
	}
	int mid = (s+e)/2, l = 2*v, r = 2*v+1;
	build(l,s,mid), build(r,mid,e);
	seg[v] = __gcd(seg[l], seg[r]);
	if(seg[v] == seg[l])
		cnt[v] += cnt[l];
	if(seg[v] == seg[r])
		cnt[v] += cnt[r];
}
pii get(int L, int R, int v = 1, int s = 0, int e = n){
	if(L<=s && e<= R)
		return { seg[v], cnt[v] };
	if(R<=s || e<=L)
		return {0,0};
	int mid = (s+e)/2, l = 2*v, r = 2*v+1;
	pii ret1 = get(L,R,l,s,mid),
	    ret2 = get(L,R,r,mid,e);
	pii ret = { __gcd(ret1.first,ret2.first), 0 };
	if(ret.first == ret1.first)
		ret.second += ret1.second;
	if(ret.first == ret2.first)
		ret.second += ret2.second;
	return ret;
}
int main(){
	cin>>n;
	for(int i = 0; i<n; i++)
		cin>>str[i];
	build();
	cin>>q;
	while(q--){
		int l, r;
	       	cin>>l>>r; l--;
		cout<<(r-l) - get(l,r).second<<endl;
	}
}
