#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
using namespace std;
const int L = 1e5 + 10;
int comp[L];
vector<pair<char,int> > st;
int32_t main(){
	string S;
	cin>>S;
	FOR(i,0,S.size()+1)
		comp[i] = i;
	FOR(i,0,S.size())
		if(isupper(S[i]))
				st.pb(mp(S[i],i));
		else
		{
			if(!st.empty() && st.back().first == S[i] - 'a' + 'A')
			{
				comp[i+1] = comp[st.back().second];
				st.pop_back();
			}
			else
				st.clear();
		}
	int q;
	cin>>q;
	while(q--)
	{
		int l, r;
		cin>>l>>r;
		cout<<(comp[l-1] == comp[r]);
	}
	cout<<endl;
}
