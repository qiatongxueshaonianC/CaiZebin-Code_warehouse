#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
typedef long long ll;
ll dp[maxn][3];
//	dp[i][j]=dp[i-1][j-1]+dp[i-1][j]
int main(){
	std::ios::sync_with_stdio(false);
	dp[0][0]=dp[0][1]=1;dp[0][2]=0;
	string s;
	cin>>s;
	for(int i=1;i<s.size();i++){
		for(int j=0;j<=2;j++){
			if(i+1==j){dp[i][j]=1;continue;}  //ȫɾ 
			if(j==0){dp[i][j]=1;continue;}		//��ɾ 
			dp[i][j]=dp[i-1][j-1]+dp[i-1][j];	//ɾi�Ͳ�ɾi���������
			for(int pos=i-1;pos>=0&&(i-pos)<=j;pos--){	//��֤pos��pos+1�������ܹ���j�ĸ��Ƿ�Χ֮�� 
				if(s[pos]==s[i]){ //posλ��ʼ������posλ����i-1λȫ��ɾ����ʣ�µľ���pos-1λ֮ǰ����
									//��ʣ�£�j-��i-pos)��λ�ÿ���ɾ�� 
					dp[i][j]-=(pos==0)?1:dp[pos-1][j-(i-pos)];
					break;
				} 
			} 
		}
	}
	cout<<dp[s.size()-1][2]+dp[s.size()-1][1]+1;
	return 0;
}
/*
ababcc

����s[i]������ɾ�����ɸ���ĸ��ɾ��s[i]����ɾ�����ɸ���ĸ �ⲿ���ظ��ˣ����磺
abcdefaaaa->abcdefaaa��ɾ�����һ����->abcdefaa(��һ����ɾ��iǰ���һ����
abcdefaaaa->abcdefaaaa��ûɾ���һ����->abcdefaa��ɾ�˵����ڶ���������a��
������������ظ��� 
*/
