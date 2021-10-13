#include"manager.h"
Manager::Manager()
{

}
//有参构造
Manager::Manager(string name, string pwd)
{
	//初始化
	this->m_Name = name;
	this->m_Pwd = pwd;
	//初始化容器 获取到所有文件中老师、学生信息
	this->initVector();

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "机房的数量为：" << vCom.size() << endl;

}
void printStudent(Student &s)
{
	cout << "学号：" << s.m_Id << "姓名：" << s.m_Name << "密码：" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "职工号：" << t.m_EmpId << "姓名：" << t.m_Name << "密码：" << t.m_Pwd << endl;
}
//菜单界面
void Manager::operMenu()
{
	cout << "======================  欢迎来到传智播客机房预约系统  ====================="
		<< endl;
	cout << endl << "请输入您的身份" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.学生代表           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.老    师           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.管 理 员           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.退    出           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "输入您的选择: " << endl;
}
//添加账号
void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;
	string fileName;//操作文件名
	string tip;//提示id号
	ofstream ofs;//文件操作对象
	int select = 0;
	cin >> select;//接受用户的选项
	if (select == 1)
	{
		//添加的是学生
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
	}
	//利用追加的方式写文件
	ofs.open(fileName, ios::out | ios::app);
	int id;//学号或者职工号
	string name;//姓名
	int pwd;
	cout << tip << endl;
	cin >> id;

	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;
	//向文件中添加数据
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
	ofs.close();
	//调用初始化容器的接口，重新获取文件中的数据
	this->initVector();
}
//查看账号
void Manager::showPerson()
{
	cout << "请选择查看的内容：" << endl;
	cout << "1.查看所有的学生" << endl;
	cout << "2.查看所有的老师" << endl;
	int select = 0;//接受用户的选择
	cin >> select;
	if (select == 1)
	{
		//查看学生
		cout << "所有的学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);

	}
	else
	{
		//查看老师
		cout << "所有老师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}
//查看机房信息
void Manager::showComputer()
{
	cout << "机房的信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin();it != vCom.end();it++)
	{
		cout << "机房编号：" << it->m_ComId << "机房的最大容量：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
//清空所有预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);//trunc检测文件如果存在，先删除干净
	ofs.close();
	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

//初始化容器
void Manager::initVector()
{
	//确保容器是清空状态
	vStu.clear();
	vTea.clear();
	//读取信息 学生、老师
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if(ifs.is_open())
	{
		cout << "文件读取失败！" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量为：" << vStu.size() << endl;
	ifs.close();
	//读取信息 老师
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前老师数量为：" << vTea.size() << endl;
	ifs.close();

}