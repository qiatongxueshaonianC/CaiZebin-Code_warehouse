#include<bits/stdc++.h>
using namespace std; 
const int inf=0x3fffffff;
unordered_map<int,bool> harsh;
vector<char> A;
bool checked[256];
int main() {
	string s,in;
	int n;
	scanf("%d%*c",&n);
	getline(cin,in);
	for(int i=0;i<in.size();i++){
		int k=1;
		while(in[i]==in[i+1]){
			k++;
			i++;
		}
		if(k%n!=0&&harsh.find(in[i])==harsh.end()) harsh[in[i]]=true;  //ȷ���������İ��� 
	}
	for(int i=0;i<in.size();i++){
		if(harsh.find(in[i])==harsh.end()&&checked[in[i]]==false){   //������ ����δ����A�� 
			A.push_back(in[i]);
			checked[in[i]]=true;
		}
	}
	for(auto i:A){
		printf("%c%s",i,i==*(--A.end())?"\n":"");
		string temp,r;
		temp=temp+i;
		r.insert(r.size(),n,i);
		in=regex_replace(in,regex(r),temp);
	}
	printf("%s\n",in.c_str());
	return 0;
}
/*
3
caseee1___thiiis___iiisss___a___teeeeeeeeeeeeeeeeeesst
3
caseee1__thiiis_iiisss_a_teeeest  //������������������ڲ������ĵļ�Ϊ�����İ�ť   2019/11/30/0��10����
3
caseee1__thiiis_iiisss_a_teeeeest
10
caseee1__thiiis_iiisss_a_teeeeeest
*/
