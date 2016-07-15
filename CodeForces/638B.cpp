#include <iostream>
#include <map>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
int n;
map<char,char> child,par;
string s;
bool seen1[26],seen2[26];
void dfs(char x)
{
	while(par.count(x))
	{
		x = par[x];
	}
	while(true)
	{
		seen2[x-'a'] = true;
		cout<<x;
		if(!child.count(x))
			break;
		x = child[x];
	}
}
int main()
{
	cin>>n;
	while(n--)
	{
		cin>>s;
		FOR(i,1,s.size())
			child[s[i-1]] = s[i],par[s[i]] = s[i-1];
		for(char x : s)
			seen1[x-'a'] = true;
	}
	for(char i = 'a'; i<='z'; i++)
		if(!seen2[i-'a']&&seen1[i-'a'])
			dfs(i);
}
