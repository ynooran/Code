#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define pb push_back
#define mp make_pair
using namespace std;
int32_t main(){
	int n;
	cin>>n;
	n--;
	cout<<"I hate ";
	FOR(i,0,n){
		if(i&1)
			cout<<"that I hate ";
		else
			cout<<"that I love ";
	}
	cout<<"it"<<endl;
}

