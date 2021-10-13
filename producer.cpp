#include<iostream>
#include<fstream>
#include<iomanip>
#include"Producer.h"
#include"process.h"
using std::string;
using std::list;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::setw;


void Producer::headerShow()
{
	cout << "�� ��\t��ϵ�绰\t��ϵ��ַ\n";
}

Producer::Producer()
{
	name[0] = '\0';
	phone[0] = address[0] = '\0';
}

bool Producer::setName(string newName)
{
	memcpy(name, newName.c_str(), PRODUCER_NAME_SIZE);
	return true;
}

bool Producer::setPhone(string newPhone)
{
	memcpy(phone, newPhone.c_str(), PRODUCER_PHONE_SIZE);
	return true;
}

bool Producer::setAddress(string newAddress)
{
	memcpy(address, newAddress.c_str(), PRODUCER_ADDRESS_SIZE);
	return true;
}

bool Producer::isName(string newName)
{
	if (newName == name)
	{
		return true;
	}
	return false;
}

istream& operator>>(std::istream& is, Producer& t)
{
	is >> t.name >> t.phone >> t.address;
	return is;
}

ostream& operator<<(std::ostream& os, const Producer& t)
{
	os.setf(ios::left);
	os << setw(8) << t.name << setw(16) << t.phone
		<< t.address;
	return os;
}

bool addProducer(const string fileName)
{
	Producer newProducer;
	ofstream fp(fileName, ios::app);
	int flag = 1;
	do {
		Producer::headerShow();
		cin >> newProducer;
		fp << newProducer << endl;
		cout << "�Ƿ������ӣ���1����0����\n";
		cin >> flag;
	} while (flag == 1);
	fp.close();
	return true;
}

bool searchProducer(const string fileName)
{
	list<Producer> producerList;
	readListFromFile(producerList, fileName);
	list<Producer> newList;
	string nameToFind;
	int flag = 1;
	do
	{
		cout << "��������Ҫ��ѯ�Ľ���������\n";
		cin >> nameToFind;
		newList = searchFromList(producerList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "û��" << nameToFind << "����Ϣ\n";
		}
		else
		{
			Producer::headerShow();
			traverseList(newList);
		}
		cout << "�Ƿ������ѯ������������Ϣ����1����0����\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool alterProducer(const string fileName)
{
	list<Producer> producerList;
	readListFromFile(producerList, fileName);
	list<Producer> newList;
	string nameToFind;
	int flag = 1, choice = 0;
	do
	{
		cout << "��������Ҫ�޸ĵĽ���������\n";
		cin >> nameToFind;
		newList = searchFromList(producerList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "û��" << nameToFind << "����Ϣ\n";
		}
		else
		{
			Producer::headerShow();
			traverseList(newList);
			cout << "��ѡ����Ҫ�޸ĵĽ����̣��������£���1��ʼ��ȡ����0��:\n";
			int count = 1;
			cin >> choice;
			for (auto curr = producerList.begin(); curr != producerList.end(); curr++)
			{
				if (curr->isName(nameToFind))
				{
					if (count == choice)
					{
						int type = 0;
						cout << "��ѡ����Ҫ�޸���Ϣ�����:\n";
						cout << "(1.����\t2.��ϵ�绰\t3.��ϵ��ַ)\n";
						cin >> type;
						if (type >= 4 || type <= 0)
						{
							cout << "��Ч����\n";
						}
						else
						{
							string newContent;
							cout << "�������µ�����:\n";
							cin >> newContent;
							alterProducerFromList(curr, newContent, choice);
							listToFile(producerList, fileName);
							cout << "�޸ĳɹ�\n";
							break;
						}
					}
					count++;
				}
			}
		}
		cout << "�Ƿ�����޸���������Ա��Ϣ����1����0����\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool deleteProducer(const string fileName)
{
	list<Producer> producerList;
	readListFromFile(producerList, fileName);
	list<Producer> newList;
	string nameToFind;
	int flag = 1, choice = 0;
	do
	{
		cout << "��������Ҫɾ���Ľ���������\n";
		cin >> nameToFind;
		newList = searchFromList(producerList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "û��" << nameToFind << "����Ϣ\n";
		}
		else
		{
			Producer::headerShow();
			traverseList(newList);
			cout << "��ѡ����Ҫɾ���Ľ����̣��������£���1��ʼ��ȡ����0��:\n";
			cin >> choice;
			if (deleteFromList(producerList, nameToFind, choice))
			{
				listToFile(producerList, fileName);
				cout << "ɾ���ɹ�" << endl;
			}
		}
		cout << "�Ƿ����ɾ��������������Ϣ����1����0����\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool traverseProducer(const string fileName)
{
	list<Producer> producerList;
	readListFromFile(producerList, fileName);
	Producer::headerShow();
	traverseList(producerList);
	cout << "���»س�������";
	cin.get();
	cin.get();
	return true;
}

bool alterProducerFromList(list<Producer>::iterator curr, string newContent, int choice)
{
	switch (choice)
	{
	case 1:
		curr->setName(newContent);
		break;
	case 2:
		curr->setPhone(newContent);
		break;
	case 3:
		curr->setAddress(newContent);
		break;
	default:return false;
	}
	return true;
}