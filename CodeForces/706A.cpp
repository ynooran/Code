#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define pb push_back
#define mk make_pair
typedef long long ll;
using namespace std;
long double x,y, ans;
int main(){
	ans = 1e10;
	cin>>x>>y;
	int n;
	cin>>n;
	while(n--){
		long double a, b,v;
		cin>>a>>b>>v;
		a = abs(a-x);
		b = abs(b-y);
		long double d = a*a + b*b;
		ans = min(ans,sqrt(d)/v);
	}
	cout<<fixed<<setprecision(10);
	cout<<ans<<endl;
}

