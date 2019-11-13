//两个字符串A,B 将B插入A中判断插入的方式中有几个是回文的 
#include <iostream>
using namespace std;
int counthuwen(string &a,string &b)
{
    string c=a;
    int count=0,tmp=1;
    for(int i=0;i<a.size()+1;i++)
    {
        c.insert(i,b);
        int len=c.size();
        for(int j=0;j<len/2;j++)
        {
            if(c[j]==c[len-j-1]) tmp=1;
            else
            {
                tmp=0;
                break;
            }
        }
        count+=tmp;
        c=a;
    }
    return count;
}
int main()
{
    string a,b;
    cin>>a;
    cin>>b;
    cout<<counthuwen(a,b);
    return 0;
}
