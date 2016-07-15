#include<iostream>
using namespace std;
struct cell{ int maxcorn;string path;cell(){maxcorn=0;path="";};};
int corn[110][110];
cell dp [110][110];
int main(){
		int m,n;
		scanf("%d%d",&m,&n);
		for(int i=m-1;i>=0;i--)
			for(int j=0;j<n;j++)
				cin>>corn[i][j];
		for(int i=0;i<m;i++)					
			for(int j=0;j<n;j++)
			{
				int addition = 0;
				string extra = "";
				if(i)
					addition = dp[i-1][j].maxcorn, extra = dp[i-1][j].path +  "F";
				if(j)
					if(addition <= dp[i][j-1].maxcorn)
						addition = dp[i][j-1].maxcorn, extra = dp[i][j-1].path + "R";
				dp[i][j].maxcorn = addition + corn[i][j];
				dp[i][j].path  = extra;
			}
		cout<<dp[m-1][n-1].path<<endl;
}
