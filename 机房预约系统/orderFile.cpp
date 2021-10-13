#include"orderFile.h"
//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	string data;//日期
	string interval;//时间段
	string stuName;//学生姓名
	string stuId;//学生编号
	string roomId;//机房编号
	string status;//预约状态

	this->m_Size= 0; //记录条数
	while (ifs >> data && ifs >> interval && ifs >>
		stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		//cout << data << endl;

	}
	//data:1
	string key;
	string value;
	map<string, string>m;
	int pos = data.find(":");//4
	if (pos != -1)
	{
		key = data.substr(0, pos);
		value = data.substr(pos + 1, data.size() - pos - 1);
		m.insert(make_pair(key, value));
	}
	pos = interval.find(":");
	if (pos != -1)
	{
		key = interval.substr(0, pos);
		value = interval.substr(pos + 1, interval.size() - pos - 1);
		m.insert(make_pair(key, value));
	}

	pos = stuId.find(":");
	if (pos != -1)
	{
		key = stuId.substr(0, pos);
		value = stuId.substr(pos + 1, stuId.size() - pos - 1);
		m.insert(make_pair(key, value));
	}

	pos = stuName.find(":");
	if (pos != -1)
	{
		key = stuName.substr(0, pos);
		value = stuName.substr(pos + 1, stuName.size() - pos - 1);
		m.insert(make_pair(key, value));
	}


	pos = roomId.find(":");
	if (pos != -1)
	{
		key = roomId.substr(0, pos);
		value = roomId.substr(pos + 1, roomId.size() - pos - 1);
		m.insert(make_pair(key, value));
	}



	pos = status.find(":");
	if (pos != -1)
	{
		key = status.substr(0, pos);
		value = status.substr(pos + 1, status.size() - pos - 1);
		m.insert(make_pair(key, value));
	}
	//将小map容器放入到大的map容器
	this->m_orderData.insert(make_pair(this->m_Size, m));
	this->m_Size++;

	//cout << "key=" << key << endl;
	//cout << "value=" << value << endl;


ifs.close();
//测试最大的map容器
for (map<int, map<string, string>>::iterator it = m_orderData.begin();it != m_orderData.end();it++)
{
	cout <<"条数为："<< "key=" << it->first << "value=" << endl;
	for (map<string, string>::iterator mit = (*it).second.begin();mit != it->second.end();mit++)
	{
		cout << " key=" << mit->first << endl;
        cout << " value=" <<mit->second << endl;
	}
}
}
//更新预约记录
void OrderFile::UpdataOrder() 
{
	if (this->m_Size == 0)
	{
		return; //预约记录0条，直接return
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}

	ofs.close();
}