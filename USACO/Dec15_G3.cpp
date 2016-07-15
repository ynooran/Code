#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#define iibi pair<pair<int,int>,pair<bool,int> >
#define f first
#define s second
#define mk make_pair
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int dist[1001][1001][2][5];
int a[1001][1001];
int n,m;
queue<iibi> Q;
iibi adj[4];
int sadj;
void make (iibi node)
{
	sadj=0;
	int nx,ny,ndir;
	bool nsmell  = node.s.f;
	nx = node.f.f;
	ny = node.f.s;
	ndir = node.s.s;
	if(a[nx][ny] == 1 || ndir==4)
	{
		FOR(i,0,4)
		{
			int ddir;
			switch(i)
			{
				case 0: nx++;
					break;
				case 1: nx--;ny++;
					break;
				case 2: ny--;nx--;
					break;
				case 3: nx++;ny--;
			}
			if(nx>=0 && ny>=0 && nx<m && ny<n)
			{
				sadj++;
				adj[sadj-1] = mk(mk(nx,ny),mk(nsmell,i));
			}
		}

	}
	if(a[nx][ny] == 2)
	{
		FOR(i,0,4)
		{
			switch(i)
			{
				case 0: nx++;
					break;
				case 1: nx--;ny++;
					break;
				case 2: ny--;nx--;
					break;
				case 3: nx++;ny--;
			}
			if(nx>=0 && ny>=0 && nx<m && ny<n)
			{
				sadj++;
				adj[sadj-1] = mk(mk(nx,ny),mk(1,i));
			}
		}

	}
	if(a[nx][ny] == 3 && nsmell)
	{
		FOR(i,0,4)
		{
			switch(i)
			{
				case 0: nx++;
					break;
				case 1: nx--;ny++;
					break;
				case 2: ny--;nx--;
					break;
				case 3: nx++;ny--;
			}
			if(nx>=0 && ny>=0 && nx<m && ny<n)
			{
				sadj++;
				adj[sadj-1] = mk(mk(nx,ny),mk(nsmell,i));
			}
		}

	}
	if(a[nx][ny] == 4)
	{
		int dx=0,dy=0;
		switch(ndir)
		{
			case 0: dx=1;
				break;
			case 1: dy=1;
				break;
			case 2: dx=-1;
				break;
			case 3: dy=-1;
		}
		if(a[nx+dx][ny+dy]==0 || a[nx+dx][ny+dy]==3)
			adj[0] = mk(mk(nx,ny),mk(0,4));
		else
			adj[0] = mk(mk(nx+dx,ny+dy),mk(0,ndir));
		sadj = 1;
	}

}

int main()
{
	ifstream fin("dream.in");
	ofstream fout("dream.out");
	cin>>n>>m;
	FOR(i,0,n)
		FOR(j,0,m)
		cin>>a[i][j];
	memset(dist,-1,sizeof(dist));
	dist[0][0][0][0] = 0;
	Q.push(mk(mk(0,0),mk(0,0)));
	while(!Q.empty())
	{
		iibi cur = Q.front();
		Q.pop();
		make(cur);
		FOR(i,0,sadj)
		{
			iibi x = adj[i];
			int& tmp = dist[x.f.f][x.f.s][x.s.f][x.s.s];
			if(tmp>=0)
				continue;
			tmp = dist[cur.f.f][cur.f.s][cur.s.f][cur.s.s] + 1;
			if(x.s.s == 4)
				tmp--;
			Q.push(x);
		}
	}
	int ans = 100000000;
	FOR(i,0,2)
	FOR(j,0,5)
	FOR(l,0,n)
	FOR(k,0,m)
	{
		if(!k)
			cout<<endl;
	cout<<dist[k][l][i][j]<<" ";}
}
