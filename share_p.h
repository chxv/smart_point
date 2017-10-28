/*************************************************************************
	> File Name: shared_ptr.h
	> Author: 
	> Mail: 
	> Created Time: 2017年10月25日 星期三 14时09分47秒
 ************************************************************************/

#ifndef _SHARED_PTR_H
#define _SHARED_PTR_H

#include <assert.h>
#include <iostream>
class count
{
public:
    int cnt;
    count()
    {
        cnt=0;
    }
};

//预声明make_shared 函数以便稍后声明为友元
//声明class shared_ptr是因为make_shared 的返回值为shared_ptr
template<class T>
class shared_ptr;

template<class type>
shared_ptr<type> make_shared(const type& lhs);

template<class T>
shared_ptr<T> make_shared();

template<class T>
class shared_ptr
{
private:
    //static int test1;
    //int cur_test1;
    T *ptr;
    count *cntp;
public:
    shared_ptr();       //构造
    explicit shared_ptr(T *p);   //构造重载
    shared_ptr(const shared_ptr<T>& lhs_p);
    //explicit shared_ptr(const T& lhs); //要必须使用make_shared
    
    //不支持在使用=时自动调用构造
    //避免多余的析构

    ~shared_ptr();      //析构

    T &operator* ();//重载*解引用运算符
    T* operator -> ();//重载->箭头运算符
    bool operator = (T*); //重载=

    bool unique();  //判断当前是否只有一个shared_ptr指向目标对象
    T *get();       //返回保存的指针
    size_t use_count();     //返回与之共享指针的数目

    friend shared_ptr<T> make_shared<T>();
    friend shared_ptr<T> make_shared<T>(const T& lhs);
};
//template<class T>
//int shared_ptr<T>::test1=0;

#endif
