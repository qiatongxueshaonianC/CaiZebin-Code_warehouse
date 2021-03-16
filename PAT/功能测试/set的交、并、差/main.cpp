/*Description
���ϵ���������ø����ļ���ȥָ���µļ��ϡ���A��B�Ǽ��ϣ������ǵĲ�������ֱ������£�
A��B={x|x��A��x��B}
A��B={x|x��A��x��B}
A-B={x|x��A��x������ B}
SA ={x|x��(A��B)��x ������A}
SB ={x|x��(A��B)��x ������B}
<!--[endif]-->
Input
��һ������һ��������T����ʾ�ܹ���T��������ݡ���T<=200��
Ȼ��������2T�У�ÿһ�ж���n+1�����֣����е�һ��������n(0<=n<=100)����ʾ���к��滹��n���������롣
Output
����ÿ��������ݣ������������������ţ���Case #.NO����
�����������7�У�ÿ�ж���һ�����ϣ�
ǰ2�зֱ��������A��B������5�����ֱ��������A��B�Ĳ�(A u B)����(A n B)����(A �C B)������
�����е�Ԫ���á�{}������������Ԫ��֮���á��� ��������
Sample Input
1
4 1 2 3 1
0
Sample Output
Case# 1:
A = {1, 2, 3}
B = {}
A u B = {1, 2, 3}
A n B = {}
A - B = {1, 2, 3}
SA = {}
SB = {1, 2, 3}
*/
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    set<int>A;
    set<int>B;
    set<int>C1;
    set<int>C2;
    set<int>C3;
    set<int>C4;
    set<int>C5;
    set<int>C6;
 
    set<int>::iterator pos;/// ��������������������setԪ��
    int count=0;
    int A_i,B_i,n,m;
    cin>>n;
    while(n--)
    {
        count++;
        cin>>A_i;
        while(A_i--)///���뼯��A
        {
            cin>>m;
            A.insert(m);
        }
        cin>>B_i;///���뼯��B
        while(B_i--)
        {
            cin>>m;
            B.insert(m);
        }
 
        cout<<"Case# "<<count<<":"<<endl;
 
        cout<<"A = {";
        for(pos=A.begin(); pos!=A.end(); pos++)///������������
        {
            if(pos!=A.begin())cout<<", ";
            cout<<*pos;///�����������ã���������һ�������ָ��
        }
        cout<<"}"<<endl;
 
        cout<<"B = {";
        for(pos=B.begin(); pos!=B.end(); pos++)
        {
            if(pos!=B.begin())cout<<", ";
            cout<<*pos;
        }
        cout<<"}"<<endl;
 //***********�� 
        set_union(A.begin(),A.end(),B.begin(),B.end(),inserter( C1 , C1.begin() ) );    /*ȡ��������*/
        //set_union(A.begin(),A.end(),B.begin(),B.end(),ostream_iterator<int>(cout," "));    /*ȡ��������*/ //����ostream_iterator��ͷ�ļ���iterator
        cout<<"A u B = {";
        for(pos=C1.begin(); pos!=C1.end(); pos++)
        {
            if(pos!=C1.begin())cout<<", ";
            cout<<*pos;
        }
        cout<<"}"<<endl;
 //*******�� 
        set_intersection(A.begin(),A.end(),B.begin(),B.end(),inserter( C2 , C2.begin() ));    /*ȡ��������*/
        cout<<"A n B = {";
        for(pos=C2.begin(); pos!=C2.end(); pos++)
        {
            if(pos!=C2.begin())cout<<", ";
            cout<<*pos;
        }
        cout<<"}"<<endl;
 //********�� 
        set_difference( A.begin(), A.end(),B.begin(), B.end(),inserter( C3, C3.begin() ) );    /*ȡ�����*/
        cout<<"A - B = {";
        for(pos=C3.begin(); pos!=C3.end(); pos++)
        {
            if(pos!=C3.begin())cout<<", ";
            cout<<*pos;
        }
        cout<<"}"<<endl;
 
        set_difference(C1.begin(),C1.end(), A.begin(), A.end(),inserter( C4, C4.begin() ) );/*ȡ�����*/
        cout<<"SA = {";
        for(pos=C4.begin(); pos!=C4.end(); pos++)
        {
            if(pos!=C4.begin())cout<<", ";
            cout<<*pos;
        }
        cout<<"}"<<endl;
 
        set_difference(C1.begin(),C1.end(), B.begin(), B.end(),inserter( C5, C5.begin() ) );/*ȡ�����*/
        cout<<"SB = {";
        for(pos=C5.begin(); pos!=C5.end(); pos++)
        {
            if(pos!=C5.begin())cout<<", ";
            cout<<*pos;
        }
        cout<<"}"<<endl;
 //*******�ԳƲ 
        set_symmetric_difference(A.begin(),A.end(),B.begin(),B.end(),inserter( C6 , C6.begin() ) );///ȡ �ԳƲ����
        cout<<"A �� B = {";
        for(pos=C6.begin(); pos!=C6.end(); pos++)
        {
            if(pos!=C6.begin())cout<<", ";
            cout<<*pos;
        }
        cout<<"}"<<endl;
 
        A.clear();
        B.clear();//�����������㣬�����´�ʹ�û����
        C1.clear();
        C2.clear();
        C3.clear();
        C4.clear();
        C5.clear();
        C6.clear();
    }
}

