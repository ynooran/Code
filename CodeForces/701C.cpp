#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define mk make_pair
typedef long long ll;
using namespace std;
map<char,int> mp;
set<char> st;
int n,nv, ans;
string S;
int main(){
	ans = 2e8;
	cin>>n>>S;
	for(auto c : S)
		st.insert(c);
	nv = st.size();
	int cnv = 0;
	int e = 0;
	FOR(i,0,n){
		if(i){
			mp[S[i-1]]--;
			if(!mp[S[i-1]])
				cnv--;
		}
		while(e<n && cnv<nv){
			if(!mp[S[e]])
				cnv++;
			mp[S[e++]]++;
		}
		if(cnv == nv)
			ans = min(ans,e-i);
	}
	cout<<ans<<endl;
}
