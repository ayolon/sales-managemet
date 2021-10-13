#include<iostream>
#include<fstream>
#include<iomanip>
#include<list>
#include<string>
#include"salesman.h"
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

void Salesman::headerShow()
{
	cout << "�� ��\t\t�� ��\t�Ա�\t��ϵ�绰\t��ϵ��ַ\t\t\t����������\t��ְʱ��\n";
}

Salesman::Salesman()
{
	code[0] = name[0] = '\0';
	gender[0] = birthDate[0] = '\0';
	phone[0] = address[0] = '\0';
	employeeDate[0] = '\0';
}

bool Salesman::setCode(string newCode)
{
	memcpy(code, newCode.c_str(), SALESMAN_CODE_SIZE);
	return true;
}

bool Salesman::setName(string newName)
{
	memcpy(name, newName.c_str(), SALESMAN_NAME_SIZE);
	return true;
}

bool Salesman::setGender(string newGender)
{
	memcpy(gender, newGender.c_str(), SALESMAN_GENDER_SIZE);
	return true;
}

bool Salesman::setBirthDate(string newBirthDate)
{
	memcpy(birthDate, newBirthDate.c_str(), SALESMAN_DATE_SIZE);
	return true;
}

bool Salesman::setPhone(string newPhone)
{
	memcpy(phone, newPhone.c_str(), SALESMAN_PHONE_SIZE);
	return true;
}

bool Salesman::setAddress(string newAddress)
{
	memcpy(address, newAddress.c_str(), SALESMAN_ADDRESS_SIZE);
	return true;
}

bool Salesman::setEmployeeDate(string newEmployeeDate)
{
	memcpy(employeeDate, newEmployeeDate.c_str(), SALESMAN_DATE_SIZE);
	return true;
}

bool Salesman::isName(string newName)
{
	if (newName == name)
	{
		return true;
	}
	return false;
}

istream& operator>>(std::istream& is, Salesman& t)
{
	is >> t.code >> t.name >> t.gender >> t.phone
		>> t.address >> t.birthDate
		>> t.employeeDate;
	return is;
}

ostream& operator<<(std::ostream& os, const Salesman& t)
{
	os.setf(ios::left);
	os << setw(16) << t.code << setw(8) << t.name
		<< setw(8) << t.gender << setw(16) << t.phone
		<< setw(32) << t.address << setw(16) << t.birthDate
		<< t.employeeDate;
	return os;
}

bool addSalesman(const string fileName)
{
	Salesman newSalesman;
	ofstream fp(fileName, ios::app);
	int flag = 1;
	do {
		Salesman::headerShow();
		cin >> newSalesman;
		fp << newSalesman << endl;
		cout << "�Ƿ������ӣ���1����0����\n";
		cin >> flag;
	} while (flag == 1);
	fp.close();
	return true;
}

bool searchSalesman(const string fileName)
{
	list<Salesman> salesmanList;
	readListFromFile(salesmanList, fileName);
	list<Salesman> newList;
	string nameToFind;
	int flag = 1;
	do
	{
		cout << "��������Ҫ��ѯ������Ա����\n";
		cin >> nameToFind;
		newList = searchFromList(salesmanList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "û��" << nameToFind << "����Ϣ\n";
		}
		else
		{
			Salesman::headerShow();
			traverseList(newList);
		}
		cout << "�Ƿ������ѯ��������Ա��Ϣ����1����0����\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool alterSalesman(const string fileName)
{
	list<Salesman> salesmanList;
	readListFromFile(salesmanList, fileName);
	list<Salesman> newList;
	string nameToFind;
	int flag = 1, choice = 0;
	do
	{
		cout << "��������Ҫ�޸ĵ�����Ա����\n";
		cin >> nameToFind;
		newList = searchFromList(salesmanList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "û��" << nameToFind << "����Ϣ\n";
		}
		else
		{
			Salesman::headerShow();
			traverseList(newList);
			cout << "��ѡ����Ҫ�޸ĵ�����Ա���������£���1��ʼ��ȡ����0��:\n";
			int count = 1;
			cin >> choice;
			for (auto curr = salesmanList.begin(); curr != salesmanList.end(); curr++)
			{
				if (curr->isName(nameToFind))
				{
					if (count == choice)
					{
						int type = 0;
						cout << "��ѡ����Ҫ�޸���Ϣ�����:\n";
						cout << "(1.����\t2.����\t3.�Ա�\t4.��ϵ�绰\t5.��ϵ��ַ\t6.����������\t7.��ְʱ��)\n";
						cin >> type;
						if (type >= 8 || type <= 0)
						{
							cout << "��Ч����\n";
						}
						else
						{
							string newContent;
							cout << "�������µ�����:\n";
							cin >> newContent;
							alterSalesmanFromList(curr, newContent, choice);
							listToFile(salesmanList, fileName);
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

bool deleteSalesman(const string fileName)
{
	list<Salesman> salesmanList;
	readListFromFile(salesmanList, fileName);
	list<Salesman> newList;
	string nameToFind;
	int flag = 1, choice = 0;
	do
	{
		cout << "��������Ҫɾ��������Ա����\n";
		cin >> nameToFind;
		newList = searchFromList(salesmanList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "û��" << nameToFind << "����Ϣ\n";
		}
		else
		{
			Salesman::headerShow();
			traverseList(newList);
			cout << "��ѡ����Ҫɾ��������Ա���������£���1��ʼ��ȡ����0��:\n";
			cin >> choice;
			if (deleteFromList(salesmanList, nameToFind, choice))
			{
				listToFile(salesmanList, fileName);
				cout << "ɾ���ɹ�" << endl;
			}
		}
		cout << "�Ƿ����ɾ����������Ա��Ϣ����1����0����\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool traverseSalesman(const string fileName)
{
	list<Salesman> salesmanList;
	readListFromFile(salesmanList, fileName);
	Salesman::headerShow();
	traverseList(salesmanList);
	cout << "���»س�������";
	cin.get();
	cin.get();
	return true;
}

bool alterSalesmanFromList(list<Salesman>::iterator curr, string newContent, int choice)
{
	switch (choice)
	{
	case 1:
		curr->setCode(newContent);
		break;
	case 2:
		curr->setName(newContent);
		break;
	case 3:
		curr->setGender(newContent);
		break;
	case 4:
		curr->setPhone(newContent);
		break;
	case 5:
		curr->setAddress(newContent);
		break;
	case 6:
		curr->setBirthDate(newContent);
		break;
	case 7:
		curr->setEmployeeDate(newContent);
		break;
	default:return false;
	}
	return true;
}