#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;
//��ݳ������(����ֻ��Ҫͷ�ļ�)
class Identity
{
public:
	//�����˵�  ���麯��
	virtual void operMenu() = 0;//�̳и���


	int m_Id;
	//�û���
	string m_Name;
	//����
	string m_Pwd;
};

