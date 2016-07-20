#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
const int MAX = 2e3;
int c[MAX],r[MAX],a[MAX][MAX],w;
int main(){
	int n,m;
	cin>>n>>m;
	FOR(i,0,n)
		FOR(j,0,m)
		{
			char tmp;
			cin>>tmp;
			if(tmp=='*')
				w += a[i][j] = 1;
			r[i]+=a[i][j],c[j]+=a[i][j];
		}
	FOR(i,0,n)
		FOR(j,0,m)
			if(r[i] + c[j] - a[i][j] == w)
				return !(cout<<"YES\n"<<i+1<<" "<<j+1<<endl);
	cout<<"NO"<<endl;
}
