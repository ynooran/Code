#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int a,p,ans;
int main()
{
	int n;cin>>n;
	int tmp=110;
	FOR(i,0,n){
		cin>>a>>p;
		if(tmp>p)
			tmp=p;
		ans += a* tmp;
	}
	cout<<ans<<endl;
}
