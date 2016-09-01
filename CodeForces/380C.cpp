#include <bits/stdc++.h>
using namespace std;
const int N = 1.1e6;
int n,q,o[4*N],c[4*N],seg[4*N];
string s;
void build(int v = 1, int xl = 0, int xr = n){
	if(xr - xl == 1){
		if(s[xl] == '(')
			o[v] = 1;
		else
			c[v] = 1;
		return;
	}
	int mid = (xl+xr)/2, l = 2*v, r = 2*v+1;
	build(l,xl,mid), build(r,mid,xr);
	int mm = min(o[l],c[r]);
	seg[v] = seg[l] + seg[r] + 2*mm;
	o[v] = o[l] + o[r] - mm;
	c[v] = c[l] + c[r] - mm;
}
pair<int, pair<int,int>> get(int L,int R,int v = 1,int xl = 0,int xr = n){
	if(L<=xl && xr<=R)
		return {seg[v], {o[v], c[v]}};
	if(R<=xl || xr<=L)
		return {0,{0,0}};
	int mid = (xr+xl)/2, l = 2*v, r = 2*v+1;
	auto a = get(L,R,l,xl,mid),
	     b = get(L,R,r,mid,xr);
	int mm = min(a.second.first,b.second.second);
	int T = a.first + b.first + 2*mm,
	    O = a.second.first + b.second.first - mm,
	    C = a.second.second + b.second.second - mm;
	return {T, {O, C}};
}
int main(){
	cin>>s;
	n = s.size();
	build();
	cin>>q;
	while(q--){
		int l, r;
		cin>>l>>r; l--;
		cout<<get(l,r).first<<endl;
	}
}
