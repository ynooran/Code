#include <bits/stdc++.h>
using namespace std;
const int N = 1.1e5, SQ = 350;
int n,q,p[N], nm[N], lnds[N];
void recalc(int x){
	int cap = min((x+1)*SQ,n);
	for(int i = cap - 1; i>=x*SQ; i--){
		nm[i] = 1;
		lnds[i] = p[i] + i;
		if(lnds[i] < cap && lnds[lnds[i]] < cap){
			nm[i] += nm[lnds[i]];
			lnds[i] = lnds[lnds[i]];
		}
	}
}
void get(int x){
	int nmv;
	for(nmv = 0; lnds[x]<n; x=lnds[x])
		nmv += nm[x];
	printf("%d %d\n",x+1,nm[x]+nmv);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i = 0; i<n; i++)
		scanf("%d",p+i);
	for(int i = 0; i<SQ; i++)
		recalc(i);
	while(q--){
		int op,a;
		scanf("%d%d",&op,&a); a--;
		if(op)
			get(a);
		else{
			scanf("%d",p+a);
			recalc(a/SQ);
		}
	}
}
