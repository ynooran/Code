#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int MAX = 5000001;
bool full1[MAX];
bool full2[MAX];
bool full( int i, bool x[])
{
	if(i<0 || i>=MAX)
		return false;
	return x[i];
}
int main()
{
	ifstream fin("feast.in");
	ofstream fout("feast.out");
	int T,A,B;
	fin>>T>>A>>B;
	full1[0] = true;
	FOR(i,1,T+1)
		full1[i] = full(i-A,full1) || full(i-B,full1);
	FOR(i,0,T+1)
		full2[i] = full1[i] || full(2*i,full1) || full(2*i+1,full1);
	FOR(i,1,T+1)
		full2[i] |= full(i-A,full2) || full(i-B,full2);
	int ans=T+1;
	while(!full2[--ans]);
	fout<<ans<<endl;
}
