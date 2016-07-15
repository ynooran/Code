#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
long long ans,n,m,w[100100],d = 1000*1000*1000 + 7;
pair<int,int> p[100100];
int binarySearch ( int a, int b, int x )
{
	if(a==b)
		return a-1;
	int mid = (a+b)/2;
	if(p[mid].first >= x )
		return binarySearch(a,mid,x);
		return binarySearch(mid+1,b,x);
}
int main()
{
	cin>>n>>m;
	w[1] = 1;
	FOR(i,1,m+1)
		cin>>p[i+1].second>>p[i+1].first;
	sort(p,p+m+2);
	FOR(i,1,m+1)
		w[i+1] =w[i] + w[binarySearch(1,m+2,p[i+1].first)] - w[binarySearch(1,m+2,p[i+1].second)],w[i+1]%=d;
	int tmp = binarySearch(1,m+2,n);
	if(p[tmp+1].first < n)
		cout<<0<<endl;
	else
		cout<<(d + w[m+1] - w[tmp])%d<<endl;
}
