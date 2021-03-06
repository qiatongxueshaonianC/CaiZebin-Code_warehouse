#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int maxn=10;
struct Point{
	int x,y;
}p[100];
int ans[maxn][maxn];
bool row[maxn][maxn],col[maxn][maxn],cube[maxn][maxn][maxn]; 
string s;
void DFS(int idx,bool& flag){
	if(flag)	return;
	if(idx==-1){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++)
				cout<<ans[i][j];
		}
		cout<<endl;
		flag=true;
		return;
	}
	for(int i=1;i<=9&&!flag;i++){
		int x=p[idx].x,y=p[idx].y;
		bool& r=row[x][i],&c=col[y][i],&cb=cube[x/3][y/3][i];
		if(!r&&!c&&!cb){
			r=c=cb=true;
			ans[x][y]=i;
			DFS(idx-1,flag);
			r=c=cb=false;
			ans[x][y]=0;
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	while(cin>>s&&s[0]!='e'){
		memset(row,false,sizeof(row));
		memset(col,false,sizeof(col));
		memset(cube,false,sizeof(cube));
		int np=0;
		char c;
		for(int i=0;i<81;i++){
			c=s[i];
			int x=i/9,y=i%9;
			if(isdigit(c)&&c!='0'){
				int tp=c-'0';
				ans[x][y]=tp;
				row[x][tp]=col[y][tp]=cube[x/3][y/3][tp]=true;
			}
			else{
				p[np].x=x;
				p[np].y=y;np++;
			}
		}
		bool flag=false;
		DFS(np-1,flag);
	}
	return 0;
}
/*
103000509002109400000704000300502006060000050700803004000401000009205800804000107
.2738..1..1...6735.......293.5692.8...........6.1745.364.......9518...7..8..6534.
......52..8.4......3...9...5.1...6..2..7........3.....6...1..........7.4.......3.
end
*/
