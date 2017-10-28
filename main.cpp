/*************************************************************************
	> File Name: main.cpp
	> Author:xander
	> Mail: xanderchen98@gmail.com
	> Created Time: 2017年10月24日 星期二 22时21分11秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include "share_p.h"
#include "share_p.cpp"
using namespace std;
int main()
{
    string *strp=new string("hello world");
    string str;
    vector<int> *vp=new vector<int>;
    vector<int> v;
    shared_ptr<int> i0;
    shared_ptr<int> i1(make_shared<int>(15));
    shared_ptr<string> s0;
    shared_ptr<string> s1(make_shared<string>("hah"));
    shared_ptr<vector<int>> v0;
    shared_ptr<vector<int>> v1(vp);
    shared_ptr<vector<int>> v2(make_shared<vector<int>>(v));
    shared_ptr<vector<int>> v3(v2);   

    v1->push_back(666);

    cout<<"i1:"<<*i1<<endl
        <<"s1:"<<*s1<<endl
        <<"v1:"<<(*v1)[0]<<endl;
    v2=v1;
    v2->push_back(77);
    cout<<"v2:"<<(*v2)[0]<<(*v2)[1]<<endl;
    return 0;
}
