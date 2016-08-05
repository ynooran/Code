#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define pb push_back
#define mk make_pair
typedef long long ll;
using namespace std;
int n, sa, sb;
int main(){
	cin>>n;
	FOR(i,0,n){
		int a, b;
		cin>>a>>b;
		if(a>b)
			sa++;
		else if(a<b)
			sb++;
	}
	if(sa>sb)
		cout<<"Mishka"<<endl;
	else if(sa<sb)
		cout<<"Chris"<<endl;
	else
		cout<<"Friendship is magic!^^"<<endl;
}
