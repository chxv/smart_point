/*************************************************************************
	> File Name: shared_ptr.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月25日 星期三 14时10分06秒
 ************************************************************************/
#ifndef _SHARED_PTR_CPP
#define _SHARED_PTR_CPP
#include "share_p.h"

//默认初始化一个空的shared_ptr
template <class T>
shared_ptr<T>::shared_ptr()
{
    ptr=nullptr;
    cntp=nullptr;
    //cur_test1=test1;
}

//指针-构造一个shared_ptr指向元素来管理其内存
template <class T>
shared_ptr<T>::shared_ptr(T *p)
{
    ptr=p;
    cntp=new count;
    assert(p);
    ++(cntp->cnt);
    std::cerr<<"T*"<<cntp->cnt<<std::endl;
    //++test1;
    //cur_test1=test1;
}
//shared_ptr对象-重载构造
template <class T>
shared_ptr<T>::shared_ptr(const shared_ptr<T> &lhs_p)
{
    ptr=lhs_p.ptr;
    cntp=lhs_p.cntp;
    ++(cntp->cnt);
    std::cerr<<"拷贝构造"<<cntp->cnt<<std::endl;
    //++test1;
}    
/*/元素对象-重载构造4.0
template<class T>
shared_ptr<T>::shared_ptr(const T& lhs)
{
    ptr=new T(lhs);
    assert(ptr);
    cntp=new count;
    assert(cntp);
    ++(cntp->cnt);
    //++test1;
}

*/


//destructor 析构--智能指针的灵魂
template<class T>
shared_ptr<T>::~shared_ptr()
{
    
    //当指针数目为0
    //std::cerr<<"this is destuctor";
    //if(cntp==nullptr)
    //    std::cerr<<this->cur_test1<<"cao!!!!\n";
    if(cntp!=nullptr&&!--(cntp->cnt))
    {
        if(ptr!=nullptr)
        {
            //std::cerr<<this->cntp->cnt<<"接下来删除pta\n";
            delete ptr;
            ptr=nullptr;
        }
        if(cntp!=nullptr)
        {
            //std::cerr<<"接下来删除cntp\n";
            delete cntp;
        }
        
        std::cerr<<"我删除了一个\n";
    }
    else 
        std::cerr<<"析构，但不删除\n";
    //--test1;
}
//重载解引用时，以对象作为返回值，直接返回目标对象即可
template<class T>
T &shared_ptr<T>::operator *()
{
    return *ptr;
}

//重载->，以指针作为返回值
//若返回值为指针，自动解引用，直至取得非指针的对象为止
//再直接返回->后的对象成员
//注意->是一元操作符
template<class T>
T* shared_ptr<T>::operator -> ()
{
    return ptr;
}

//重载=，避免在赋值时错误的调用构造
template<class T>
bool shared_ptr<T>::operator =(T* p)
{
    ptr = p;
    cntp = new count;
    ++cntp->cnt;

}

template<class T>
bool shared_ptr<T>::unique()
{
    return (cntp->cnt==1)?true:false;
}


//返回当前对象保存的指针
template <class T>
T* shared_ptr<T>::get()
{
    return ptr;
}

template<class T>
size_t shared_ptr<T>::use_count()
{
    return static_cast<size_t>(cntp->cnt);
}
/*
 *
 *
 *****************************************************
 *以下为类外函数
 *****************************************************
 *
 *
 *
 */

//make_shared函数

template <class T>
shared_ptr<T> make_shared()
{
    shared_ptr<T> sp;
    return sp;
}

    

template<class T>
shared_ptr<T> make_shared(const T& lhs)
{
    T *p=new T(lhs);
    shared_ptr<T> sp(p);
    return sp;
}




#endif
