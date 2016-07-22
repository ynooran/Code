#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
using namespace std;
vector<char> V;
int32_t main(){
	string S;
	cin>>S;
	for(char c : S)
		if(!V.empty() && V.back() == c)
			V.pop_back();
		else
			V.pb(c);
	cout<<(V.empty() ? "YES":"NO")<<endl;
}
