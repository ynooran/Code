#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define pb push_back
#define mk make_pair
typedef long long ll;
using namespace std;
long double l,v1,v2,k;
int n;
bool good(long double t)
{
	long double tl = t, hg = 0;
	int nl  = n;
	while(nl)
	{
		long double x = max((tl*v1*v2-v2*(l-hg))/(v1-v2),0.0l);
		if(x>l-hg)
			return false;
		nl = max(0.0l,nl-k);
		if(!nl)
			return 1;
		long double tk = x/v2;
		hg += tk*v1;
		long double xl = x - tk*v1;
		long double ttk = (xl)/(v1+v2);
		tk += ttk;
		hg += ttk*v1;
		tl -= tk;
		if(tl<0)
			return false;
	}
	return true;
}
int main(){
	cin>>n>>l>>v1>>v2>>k;
	cout<<fixed<<setprecision(10);
	long double lo = 0, hi = 1e9+1;
	FOR(i,0,800)
	{
		long double m = lo + (hi-lo)/2;
		if(good(m))
			hi = m;
		else
			lo = m;
	}
	cout<<hi<<endl;
}
