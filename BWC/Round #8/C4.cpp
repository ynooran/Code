#include <iostream>
#include <algorithm>
#include <cassert>
#define FOR(i,a,b) for(long long i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int delta = 781817;
long long T[60], ans;
long long child (long long x, int g, int i){
	assert(g+i<60);
	return x + T[g+i];
}
void dfs(long long x, int d, int g){
	if(d>19)
		return;
	ans += x;
	FOR(i,1,4)
		dfs(child(x,g,i),d+1,g+i);
}
int main(){
	T[0] = 1;
	T[1] = 1;
	T[2] = 2;
	FOR(i,3,60)
		T[i] = T[i-1] + T[i-2] + T[i-3],T[i] %= delta;
	assert(T[59]<1e18);
	dfs(1,1,0);
	cout<<ans%delta<<endl;
}
