#include <bits/stdc++.h>
using namespace std;
int a[101],b[101],c[101],d,i;
void shuru(int a[])
{
    string s;
    cin>>s;              //�����ַ���
    a[0]=s.length();      //a[0]�����ַ����ĳ���
    for (i=1;i<=a[0];i++)
        a[i]=s[a[0]-i]-'0';   //���ַ���ת��Ϊ����a�������򴢴棬ģ����ʽ����
}
void shuchu(int a[])// ����������Ĵ𰸣���ע������Ϊ0�����
{
    int i;
    if (a[0]==0) {cout<<"0"<<endl;return;}
    for (i=a[0];i>0;i--) cout<<a[i];
    cout<<endl;
    return;
}
int bijiao(int a[],int b[])//�Ƚ�a��b�Ĵ�С��ϵ����a>b��Ϊ1����a<b��Ϊ-1����a=b��Ϊ0
{
    int i;
    if (a[0]>b[0]) return 1;  //��a��λ������b����a>b
    if (a[0]<b[0]) return -1;  //��a��λ��С��b����a<b
    for (i=a[0];i>0;i--){if (a[i]>b[i]) return 1;if (a[i]<b[i]) return -1;} //�Ӹ�λ����λ���αȽϣ��ҳ���С��ϵ
    return 0;
}
void jian(int a[],int b[])  //a�������������������Ϊ��������
{
    int pd;
    int i;
    pd=bijiao(a,b);            //���ú����Ƚ�ab��С
    if (pd==0) {a[0]=0;return;}  //���
    if (pd==1)
    {
        for (i=1;i<=a[0];i++)
        {
            if (a[i]<b[i]) {a[i+1]--;a[i]+=10;}   //������������һλ��һλ
            if (a[i]>=b[i])  a[i]-=b[i];
        }
        while((a[a[0]]==0)&&(a[0]>0)) a[0]--;
        return;
    }
}
void numcpy(int p[],int q[],int det) //����p���鵽q�����det��ʼ�ĵط�
{
    for (int i=1;i<=p[0];i++) q[i+det-1]=p[i];//���������ƣ�ʹ���������Ҷ˶��룬�β�q���鴢�����ƺ�Ľ��
    q[0]=p[0]+det-1;
}
void chugao(int a[],int b[],int c[])
{
    int i,tmp[101];
    c[0]=a[0]-b[0]+1;
    for (i=c[0];i>0;i--)
    {
        memset(tmp,0,sizeof(tmp));     //tmp��������
        numcpy(b,tmp,i);               //������b���ƺ��Ƹ�tmp���飬ע����i���Ƴ���λ��
        while (bijiao(a,tmp)>=0){c[i]++;jian(a,tmp);}   //����ģ�������������
    }
    while((c[c[0]]==0)&&(c[0]>0)) c[0]--;   // �������λ��0
}
int main()//������
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    shuru(a);shuru(b);
    chugao(a,b,c);
    shuchu(c);
    shuchu(a);
    return 0;
}

