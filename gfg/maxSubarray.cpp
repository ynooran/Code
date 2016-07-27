#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define pf push_front
#define mk make_pair
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		deque<pair<int,int>> st;
		FOR(i,0,n){
			int x;
			cin>>x;
			int minb = i - k + 1;
			if(!st.empty() &&st.back().second<minb)
				st.pop_back();
			while(!st.empty() && x>=st.front().first)
				st.pop_front();
			st.pf(mk(x,i));
			if(i>=k-1)
				cout<<st.back().first<<" ";
		}
		cout<<endl;
	}
}
