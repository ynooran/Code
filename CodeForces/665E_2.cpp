#include <iostream>
using namespace std;
const int N = 1E6, LOG = 30, V = N*LOG;
int n, k, tsz, pref, ai, child[V][2], cnt[V];
long long ans;
void calc(int x){
	int v = 0, cur = 0;
	for(int i = LOG-1; i>=0; i--){
		int b = (x >> i) & 1;
		if((cur | (1 << i)) >= k){
			ans += cnt[child[v][!b]];
			v = child[v][b];
		} else {
			v = child[v][!b];
			cur |= (1 << i);
		}
		if(!v)
			break;
	}
}
void add(int x){
	int v = 0;
	for(int i = LOG-1; i>=0; i--){
		int b = (x >> i)&1;
		if(!child[v][b])
			child[v][b] = ++tsz;
		v = child[v][b];
		cnt[v]++;
	}
}
int main(){
	cin>>n>>k;
	add(0);
	for(int i=0; i<n; i++){
		scanf("%d",&ai);
		pref ^= ai;
		calc(pref);
		add(pref);
	}
	cout<<ans<<endl;
}
