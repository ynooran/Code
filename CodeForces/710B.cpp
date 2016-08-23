#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
const int N = 4e5;
int n,a[N];
int main(){
	cin>>n;
	FOR(i,0,n)
		cin>>a[i];
	sort(a,a+n);
	cout<<a[n-1>>1]<<endl;
}
