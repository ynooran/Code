#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
int dens[100];
long long cando;
int c,d,v;
int main(){
	int t;
	cin>>t;
	FOR(j,1,t+1){
		cin>>c>>d>>v;
		FOR(i,0,d)
			cin>>dens[i];
		int dind=0, ext = cando = 0;
		while(cando<v){
			if(dind<d && dens[dind]<=cando+1)
				cando += 1ll*c*dens[dind++];
			else{
				ext++;
				cando += c*(cando+1);
			}
		}
		printf("Case #%d: %d\n", j, ext);
	}
}
