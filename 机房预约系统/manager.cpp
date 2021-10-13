#include"manager.h"
Manager::Manager()
{

}
//�вι���
Manager::Manager(string name, string pwd)
{
	//��ʼ��
	this->m_Name = name;
	this->m_Pwd = pwd;
	//��ʼ������ ��ȡ�������ļ�����ʦ��ѧ����Ϣ
	this->initVector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "����������Ϊ��" << vCom.size() << endl;

}
void printStudent(Student &s)
{
	cout << "ѧ�ţ�" << s.m_Id << "������" << s.m_Name << "���룺" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "ְ���ţ�" << t.m_EmpId << "������" << t.m_Name << "���룺" << t.m_Pwd << endl;
}
//�˵�����
void Manager::operMenu()
{
	cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  ====================="
		<< endl;
	cout << endl << "�������������" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.ѧ������           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.��    ʦ           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.�� �� Ա           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.��    ��           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "��������ѡ��: " << endl;
}
//����˺�
void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;
	string fileName;//�����ļ���
	string tip;//��ʾid��
	ofstream ofs;//�ļ���������
	int select = 0;
	cin >> select;//�����û���ѡ��
	if (select == 1)
	{
		//��ӵ���ѧ��
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
	}
	//����׷�ӵķ�ʽд�ļ�
	ofs.open(fileName, ios::out | ios::app);
	int id;//ѧ�Ż���ְ����
	string name;//����
	int pwd;
	cout << tip << endl;
	cin >> id;

	cout << "������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;
	//���ļ����������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
	ofs.close();
	//���ó�ʼ�������Ľӿڣ����»�ȡ�ļ��е�����
	this->initVector();
}
//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴�����ݣ�" << endl;
	cout << "1.�鿴���е�ѧ��" << endl;
	cout << "2.�鿴���е���ʦ" << endl;
	int select = 0;//�����û���ѡ��
	cin >> select;
	if (select == 1)
	{
		//�鿴ѧ��
		cout << "���е�ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);

	}
	else
	{
		//�鿴��ʦ
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}
//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "��������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin();it != vCom.end();it++)
	{
		cout << "������ţ�" << it->m_ComId << "���������������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
//�������ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);//trunc����ļ�������ڣ���ɾ���ɾ�
	ofs.close();
	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::initVector()
{
	//ȷ�����������״̬
	vStu.clear();
	vTea.clear();
	//��ȡ��Ϣ ѧ������ʦ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if(ifs.is_open())
	{
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();
	//��ȡ��Ϣ ��ʦ
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();

}