/*Description
集合的运算就是用给定的集合去指定新的集合。设A和B是集合，则它们的并差交补集分别定义如下：
A∪B={x|x∈A∨x∈B}
A∩B={x|x∈A∧x∈B}
A-B={x|x∈A∧x不属于 B}
SA ={x|x∈(A∪B)∧x 不属于A}
SB ={x|x∈(A∪B)∧x 不属于B}
<!--[endif]-->
Input
第一行输入一个正整数T，表示总共有T组测试数据。（T<=200）
然后下面有2T行，每一行都有n+1个数字，其中第一个数字是n(0<=n<=100)，表示该行后面还有n个数字输入。
Output
对于每组测试数据，首先输出测试数据序号，”Case #.NO”，
接下来输出共7行，每行都是一个集合，
前2行分别输出集合A、B，接下5行来分别输出集合A、B的并(A u B)、交(A n B)、差(A – B)、补。
集合中的元素用“{}”扩起来，且元素之间用“， ”隔开。
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
 
    set<int>::iterator pos;/// 定义迭代器，作用是输出set元素
    int count=0;
    int A_i,B_i,n,m;
    cin>>n;
    while(n--)
    {
        count++;
        cin>>A_i;
        while(A_i--)///输入集合A
        {
            cin>>m;
            A.insert(m);
        }
        cin>>B_i;///输入集合B
        while(B_i--)
        {
            cin>>m;
            B.insert(m);
        }
 
        cout<<"Case# "<<count<<":"<<endl;
 
        cout<<"A = {";
        for(pos=A.begin(); pos!=A.end(); pos++)///迭代器的作用
        {
            if(pos!=A.begin())cout<<", ";
            cout<<*pos;///迭代器的作用，迭代器是一种特殊的指针
        }
        cout<<"}"<<endl;
 
        cout<<"B = {";
        for(pos=B.begin(); pos!=B.end(); pos++)
        {
            if(pos!=B.begin())cout<<", ";
            cout<<*pos;
        }
        cout<<"}"<<endl;
 //***********并 
        set_union(A.begin(),A.end(),B.begin(),B.end(),inserter( C1 , C1.begin() ) );    /*取并集运算*/
        //set_union(A.begin(),A.end(),B.begin(),B.end(),ostream_iterator<int>(cout," "));    /*取并集运算*/ //其中ostream_iterator的头文件是iterator
        cout<<"A u B = {";
        for(pos=C1.begin(); pos!=C1.end(); pos++)
        {
            if(pos!=C1.begin())cout<<", ";
            cout<<*pos;
        }
        cout<<"}"<<endl;
 //*******交 
        set_intersection(A.begin(),A.end(),B.begin(),B.end(),inserter( C2 , C2.begin() ));    /*取交集运算*/
        cout<<"A n B = {";
        for(pos=C2.begin(); pos!=C2.end(); pos++)
        {
            if(pos!=C2.begin())cout<<", ";
            cout<<*pos;
        }
        cout<<"}"<<endl;
 //********差 
        set_difference( A.begin(), A.end(),B.begin(), B.end(),inserter( C3, C3.begin() ) );    /*取差集运算*/
        cout<<"A - B = {";
        for(pos=C3.begin(); pos!=C3.end(); pos++)
        {
            if(pos!=C3.begin())cout<<", ";
            cout<<*pos;
        }
        cout<<"}"<<endl;
 
        set_difference(C1.begin(),C1.end(), A.begin(), A.end(),inserter( C4, C4.begin() ) );/*取差集运算*/
        cout<<"SA = {";
        for(pos=C4.begin(); pos!=C4.end(); pos++)
        {
            if(pos!=C4.begin())cout<<", ";
            cout<<*pos;
        }
        cout<<"}"<<endl;
 
        set_difference(C1.begin(),C1.end(), B.begin(), B.end(),inserter( C5, C5.begin() ) );/*取差集运算*/
        cout<<"SB = {";
        for(pos=C5.begin(); pos!=C5.end(); pos++)
        {
            if(pos!=C5.begin())cout<<", ";
            cout<<*pos;
        }
        cout<<"}"<<endl;
 //*******对称差集 
        set_symmetric_difference(A.begin(),A.end(),B.begin(),B.end(),inserter( C6 , C6.begin() ) );///取 对称差集运算
        cout<<"A ⊕ B = {";
        for(pos=C6.begin(); pos!=C6.end(); pos++)
        {
            if(pos!=C6.begin())cout<<", ";
            cout<<*pos;
        }
        cout<<"}"<<endl;
 
        A.clear();
        B.clear();//各个集合清零，否则下次使用会出错
        C1.clear();
        C2.clear();
        C3.clear();
        C4.clear();
        C5.clear();
        C6.clear();
    }
}

