#include<bits/stdc++.h>
using namespace std;
int N,M,TOL; 
int X[]={1,-1,0,0,1,1,-1,-1};
int Y[]={0,0,-1,1,1,-1,1,-1};
vector<vector<double>> G;
bool judge(double u,int x,int y,int xx,int yy){
	if(G.size()<=xx||G[x].size()<=yy) return true;
	if(fabs(G[x][y]-G[xx][yy])<=TOL) return false;
	return true;
}
int main() {
	scanf("%d%d%d",&M,&N,&TOL);
	G.resize(N);
	fill(G.begin(),G.end(),vector<double>(M));
	unordered_map<double,int> mp;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%lf",&G[i][j]);
			mp[G[i][j]]++;
		}
	}
	vector<pair<pair<int,int>,double>> Ans;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			bool flag=true;
			for(int k=0;k<8;k++){
				int xx=i+X[k];
				int yy=j+Y[k];
				if(xx<0||yy<0) continue;
				if(judge(G[i][j],i,j,xx,yy)==false){
					flag=false;
					break;
				}
			}
			if(flag&&mp[G[i][j]]==1)
				Ans.push_back({{j+1,i+1},G[i][j]});
		}
	}
	if(Ans.size()>1)
		puts("Not Unique");
	else if(Ans.size()==0)
		puts("Not Exist");
	else for(auto I:Ans)
		printf("(%d, %d): %.0lf\n",I.first.first,I.first.second,I.second);
	return 0;
}
/*
8 6 200
0 	 0 	  0 	   0	    0 	     0 	      0        0
65280 	 65280    65280    16711479 65280    65280    65280    65280
16711479 65280    65280    65280    16711680 65280    65280    65280
65280 	 65280    65280    65280    65280    65280    165280   165280
65280 	 65280 	  16777015 65280    65280    165280   65480    165280
16777215 16777215 16777215 16777215 16777215 16777215 16777215 16777215

4 5 2
0 0 0 0
0 0 3 0
0 0 0 0
0 5 0 0
0 0 0 0

3 3 5
1 2 3
3 4 5
5 6 7
*/
