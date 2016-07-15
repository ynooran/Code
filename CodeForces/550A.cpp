#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


int main ()
{
	string s;
	vector <int> ab,ba;
	bool answer = false;
	cin>>s;
	for(int i=0; i<s.size()-1; i++)
		if(s[i] == 'A' && s[i+1] == 'B')
			ab.push_back(i);

	for(int i=0; i<s.size()-1; i++)
		if(s[i] == 'B' && s[i+1] == 'A')
			ba.push_back(i);
	for(int i=0; i<ab.size() && !answer; i++)
		for(int j=0; j<ba.size() && !answer; j++)
			if(ba[j]!=ab[i]+1 && ba[j] !=ab[i]-1)
				answer = true;
	if(answer)
		cout<<"YES"<<endl;
	else 
		cout<<"NO"<<endl;
}


