#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include"orderFile.h"
//��ʦ�����
class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι���
	Teacher(int empId, string name, string pwd);
	//�˵�����
	virtual void operMenu();//�̳и���
	//�鿴����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void vaildOrder();
	//ְ����
	int m_EmpId;
};