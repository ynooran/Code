#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define pb push_back
#define mp make_pair
using namespace std;
int32_t main(){
	int n;
	cin>>n;
	int sum=0;
	FOR(i,0,n){
		int x;
		cin>>x;
		sum ^= x;
		if(sum&1)
			cout<<2<<endl;
		else
			cout<<1<<endl;
		sum ^= 1;
	}
}

