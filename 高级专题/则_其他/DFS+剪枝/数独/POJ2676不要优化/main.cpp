#include<iostream>
#include<cstring>
using namespace std;
const int maxn=10;
struct Point{
	int x,y;
}p[100];
int ans[maxn][maxn];
bool row[maxn][maxn],col[maxn][maxn],cube[maxn][maxn][maxn];
void DFS(int idx,bool& flag){
	if(flag)	return;
	if(idx==-1){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++)
				cout<<ans[i][j];
			cout<<endl;
		}
		flag=true;
		return;
	}
	for(int i=1;i<=9&&!flag;i++){
		int x=p[idx].x;
		int y=p[idx].y;
		if(row[x][i]==false&&col[y][i]==false&&cube[x/3][y/3][i]==false){
			row[x][i]=col[y][i]=cube[x/3][y/3][i]=true;
			ans[x][y]=i;
			DFS(idx-1,flag);
			row[x][i]=col[y][i]=cube[x/3][y/3][i]=false;
			ans[x][y]=0;
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		memset(row,false,sizeof(row));
		memset(col,false,sizeof(col));
		memset(cube,false,sizeof(cube));
		char c;
		int np=0;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cin>>c;
				int tp=c-'0';
				if(tp!=0){
					row[i][tp]=col[j][tp]=cube[i/3][j/3][tp]=true;
					ans[i][j]=tp;
					continue;
				}
				p[np].x=i;
				p[np++].y=j;
			}
			cin.ignore();
		}
		bool flag=false;
		DFS(np-1,flag);
	}
	return 0;
}
/*
2
103000509
002109400
000704000
300502006
060000050
700803004
000401000
009205800
804000107
*/
