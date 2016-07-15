#include<iostream>
#include<algorithm>
#define FOR(i,a,b) for(int i = a; i<b; i++)
using namespace std;
int sequence[210000],n,k;
long long structure[3][210000];
int binarySearch(int i,int j,int x)
{
	if(i>=j)
		return n;
	int a = (i + j)/2;
	int b = structure[0][a];
	if(b == x)
		return a;
	if (x<b)
		return binarySearch(i,a,x);
	return binarySearch(a+1,j,x);
}
	
int main ()
{
	long long answer=0;
	cin>>n>>k;
	FOR(i,0,n)
	{
		cin>>sequence[i];
		structure[0][i] = sequence [i];
	}
	sort(structure[0],structure[0] + n);
	FOR(i,0,n)
	{
		int l = binarySearch(0,n,sequence[i]);
		answer += structure[2][l];
		int a = sequence [i] / k;
		long long b = (long long)sequence[i] * (long long)k;
		if((a*k == sequence[i])&&(b<1000000001)&&(b>-1000000001))
			structure[2][binarySearch(0,n,b)]+= structure[1][binarySearch(0,n,a)];
		structure[1][l]++;
	}
	cout<<answer<<endl;
}
