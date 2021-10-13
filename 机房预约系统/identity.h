#pragma once//防止头文件重复包含
#include<iostream>
using namespace std;
//身份抽象基类(基类只需要头文件)
class Identity
{
public:
	//操作菜单  纯虚函数
	virtual void operMenu() = 0;//继承父类


	int m_Id;
	//用户名
	string m_Name;
	//密码
	string m_Pwd;
};

