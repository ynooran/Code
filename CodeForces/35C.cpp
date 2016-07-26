#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define mk make_pair
typedef long long ll;
using namespace std;
queue<pair<int,int>> Q;
bool marked[2001][2001];
int n,m,k,x,y, dx[] = { -1, 0, 1, 0}, dy[] = {0,-1,0,1};
int main(){
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>n>>m>>k;
	FOR(i,0,k){
		fin>>x>>y;
		Q.push(mk(x,y));
		marked[x][y] = true;
	}
	while(!Q.empty()){
		x = Q.front().first, y = Q.front().second;
		Q.pop();
		FOR(i,0,4){
			int tx = x + dx[i];
			int ty = y + dy[i];
			if(tx && ty && tx<=n && ty<=m && !marked[tx][ty]){
				marked[tx][ty] = true;
				Q.push(mk(tx,ty));
			}
		}
	}
	fout<<x<<" "<<y<<endl;
}
