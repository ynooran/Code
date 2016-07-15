// In the name of Allah
#include <iostream>
#include <bitset>
#include<vector>
#include<map>
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
using namespace std;
const int delta = 10567;
bitset<7> b;
vector<bitset<7> > cols;
map<vector<int>, int> S;
vector<int> t (7), r(7);
int32_t main()
{
	FOR(i,0,7)
	{
		b[i] = 1;
		FOR(j,i+1,7)
		{
			b[j] = 1;
			FOR(l,j+1,7)
			{
				b[l] = 1;
				cols.push_back(b);
				b[l] = 0;
			}
			b[j] = 0;
		}
		b[i] = 0;
	}
	FOR(i,0,7)
		t[i] = 0;
	S[t] = 1;
	FOR(i,0,7)
	{
		map<vector<int>, int> tmp;
		for(auto a : S)
		{
			t = r =  a.first;
			for(auto x : cols)
			{
				bool flag = true;
				FOR(i,0,7)
					if(x[i])
					{
						t[i]++;
						if(t[i]>3)
							flag = false;
					}
				if(flag)
					tmp[t] += S[r],tmp[t]%=delta;
				FOR(i,0,7)
					if(x[i])
						t[i]--;
			}
		}
		S = tmp;
	}
	for(auto a : S)
	{
		for(auto b : a.first)
			cout<<b<<" ";
		cout<<a.second<<endl;
	}
}
