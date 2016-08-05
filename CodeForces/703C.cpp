#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define pb push_back
#define mk make_pair
typedef long long ll;
using namespace std;
int n,w,v,u;
pair<int,int> a[10001];
int main(){
	cin>>n>>w>>v>>u;
	FOR(i,0,n){
		int x, y;
		cin>>x>>y;
		a[i] = mk(y,x);
	}
	bool flag = true;
	for(int i=0;flag && i<n; i++){
		double y = a[i].first;
		double x = a[i].second;
		double t = x/v;
		if(t*u<y)
			flag = false;
	}
	cout.precision(10);
	cout<<fixed;
	if(flag)
		cout<<1.0*w/u<<endl;
	else{
		sort(a,a+n);
		double cur = 0, t = 0;
		FOR(i,0,n){
			double d1 = a[i].first - cur,
       				tt = max(d1/u,1.0*a[i].second/v - t);
			t += tt;
			cur = a[i].first;
		}
		t += 1.0*(w-cur)/u;
		cout<<t<<endl;
	}
}
