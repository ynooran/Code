#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
const int delta = 10133;
const int r[4] = {7,13,21,30};
long double pdraw(int a, int b){
	return (50.0-abs(a-b))/(double)100;
}
long double pwin (int a, int b){
	long double ta = a;
	long double tb = b;
	return ((tb*(1.0-pdraw(a,b)))/(ta + tb));
}
long double f (int x)
{
	long double p=1;
	int score[4];
	FOR(i,0,4) score[i] = 0;
	FOR(i,0,4)
		FOR(j,i+1,4)
		{
			if(x%3 == 0)
			{
				p*=pdraw(r[i],r[j]);
				score[i]+=1;
				score[j]+=1;
			}
			else if(x%3 == 1)
			{
				p*=pwin(r[i],r[j]);
				score[i]+=3;
			}
			else
			{
				p*=pwin(r[j],r[i]);
				score[j]+= 3;
			}
			x/=3;
		}
	int tmp = 0;
	FOR(i,0,2)
	{
		if(score[i]<score[2])
			tmp++;
	}
	if(score[3]<=score[2])
		tmp++;
	if(tmp>1)
		return p;
	return 0;
}
int main()
{
	long double ans=0;
	FOR(i,0,729)//3^6
	{
		ans+=f(i);
	}
	ans*= delta;
	ans*=delta;
	cout<<(long long)ans<<endl;	
}
