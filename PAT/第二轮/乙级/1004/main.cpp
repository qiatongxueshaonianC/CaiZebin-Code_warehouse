#include<bits/stdc++.h>
using namespace std; 
struct stu{
	string name,id;
	int score;
	stu(char a[],char b[],int c):name(a),id(b),score(c){
	/*	name=a;
		id=b;
		score=c;*/
	}
};
int main() {
	int n,score;
	char a[11],b[11];
	scanf("%d",&n);
	scanf("%s%s%d",&a,&b,&score);
	stu mi(a,b,score);
	stu ma(a,b,score);
	for(int i=1;i<n;i++){
		scanf("%s%s%d",&a,&b,&score);
		if(score>ma.score){
			ma.name=a;
			ma.id=b;
			ma.score=score;
		}else if(score<mi.score){
			mi.name=a;
			mi.id=b;
			mi.score=score;
		}
	}
	printf("%s %s\n",ma.name.c_str(),ma.id.c_str());
	printf("%s %s\n",mi.name.c_str(),mi.id.c_str());
	return 0;
}
/*
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
*/
