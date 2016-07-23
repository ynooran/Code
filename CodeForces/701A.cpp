#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define pb push_back
#define mk make_pair
typedef long long ll;
using namespace std;
const int N = 100;
int n;
pair<int,int> a[N];
int main(){
	cin>>n;
	FOR(i,0,n){
		int t;
		cin>>t;
		a[i] = (mk(t,i));
	}
	sort(a,a+n);
	FOR(i,0,n/2)
		cout<<a[i].second+1<<" "<<a[n-1-i].second+1<<endl;
}

