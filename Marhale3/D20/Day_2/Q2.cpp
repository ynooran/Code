#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int delta = 10267;
bool stopped[3];
pair<int,int> p[3],moves[9];
int dist (pair<int,int> a, pair<int,int> b)
{
	return abs(a.first-b.first) + abs(a.second-b.second);
}
pair<int,int> sum (pair<int,int> a, pair<int,int> b)
{
	return make_pair(a.first+b.first,a.second+b.second);
}
int main()
{
	p[0] = make_pair(1024,2010);
	p[1] = make_pair(-1381,138);
	p[2] = make_pair(1,2010);
	FOR(i,-1,2)
	FOR(j,-1,2)
	{
		int ind = 3*(i+1) + j + 1;
		moves[ind] . first = i;
		moves[ind] . second = j;
	}
	long long s = 0;
	while(!stopped[0] || !stopped[1] || !stopped[2])
	{
		FOR(i,0,3)
			cerr<<p[i].first<<" "<<p[i].second<<" "<<endl;

		pair<int,int> cmove[3];
		FOR(i,0,3)
		{
			if(stopped[i])
				continue;
			int d  = dist(p[i],p[(i+1)%3]);
			FOR(j,0,9)
			if(d>= dist(sum(p[i],moves[j]),p[(i+1)%3]))
			{
				d = dist(sum(p[i],moves[j]),p[(i+1)%3]);
				cmove[i] = moves[j];
				if(!d){
					stopped[i] = true;
					cmove[i] = make_pair(0,0);
					cerr<<"stopped \n\n\n\n\n\n\n\n\n\n"<<i<<endl;
				}
			}
		}
		s++;
		FOR(i,0,3)
			p[i]= sum(p[i],cmove[i]);
	}
	s--;
	s= (((s*s)%delta)*s)%delta;
	s = (s*s)%delta;
	cerr<<s<<endl;
}
