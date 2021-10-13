#include<iostream>
#include<fstream>
#include<iomanip>
#include"Customer.h"
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

void Customer::headerShow()
{
	cout << "�� ��\t��ϵ�绰\t��ϵ��ַ\n";
}

Customer::Customer()
{
	name[0] = '\0';
	phone[0] = address[0] = '\0';
}

bool Customer::setName(string newName)
{
	memcpy(name, newName.c_str(), CUSTOMER_NAME_SIZE);
	return true;
}

bool Customer::setPhone(string newPhone)
{
	memcpy(phone, newPhone.c_str(), CUSTOMER_PHONE_SIZE);
	return true;
}

bool Customer::setAddress(string newAddress)
{
	memcpy(address, newAddress.c_str(), CUSTOMER_ADDRESS_SIZE);
	return true;
}

bool Customer::isName(string newName)
{
	if (newName == name)
	{
		return true;
	}
	return false;
}

istream& operator>>(std::istream& is, Customer& t)
{
	is >> t.name >> t.phone >> t.address;
	return is;
}

ostream& operator<<(std::ostream& os, const Customer& t)
{
	os.setf(ios::left);
	os << setw(8) << t.name << setw(16) << t.phone
		<< t.address;
	return os;
}

bool addCustomer(const string fileName)
{
	Customer newCustomer;
	ofstream fp(fileName, ios::app);
	int flag = 1;
	do {
		Customer::headerShow();
		cin >> newCustomer;
		fp << newCustomer << endl;
		cout << "�Ƿ������ӣ���1����0����\n";
		cin >> flag;
	} while (flag == 1);
	fp.close();
	return true;
}

bool searchCustomer(const string fileName)
{
	list<Customer> customerList;
	readListFromFile(customerList, fileName);
	list<Customer> newList;
	string nameToFind;
	int flag = 1;
	do
	{
		cout << "��������Ҫ��ѯ�Ĺ˿�����\n";
		cin >> nameToFind;
		newList = searchFromList(customerList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "û��" << nameToFind << "����Ϣ\n";
		}
		else
		{
			Customer::headerShow();
			traverseList(newList);
		}
		cout << "�Ƿ������ѯ�����˿���Ϣ����1����0����\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool alterCustomer(const string fileName)
{
	list<Customer> customerList;
	readListFromFile(customerList, fileName);
	list<Customer> newList;
	string nameToFind;
	int flag = 1, choice = 0;
	do
	{
		cout << "��������Ҫ�޸ĵĹ˿�����\n";
		cin >> nameToFind;
		newList = searchFromList(customerList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "û��" << nameToFind << "����Ϣ\n";
		}
		else
		{
			Customer::headerShow();
			traverseList(newList);
			cout << "��ѡ����Ҫ�޸ĵĹ˿ͣ��������£���1��ʼ��ȡ����0��:\n";
			int count = 1;
			cin >> choice;
			for (auto curr = customerList.begin(); curr != customerList.end(); curr++)
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
							alterCustomerFromList(curr, newContent, choice);
							listToFile(customerList, fileName);
							cout << "�޸ĳɹ�\n";
							break;
						}
					}
					count++;
				}
			}
		}
		cout << "�Ƿ�����޸������˿���Ϣ����1����0����\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool deleteCustomer(const string fileName)
{
	list<Customer> customerList;
	readListFromFile(customerList, fileName);
	list<Customer> newList;
	string nameToFind;
	int flag = 1, choice = 0;
	do
	{
		cout << "��������Ҫɾ���Ĺ˿�����\n";
		cin >> nameToFind;
		newList = searchFromList(customerList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "û��" << nameToFind << "����Ϣ\n";
		}
		else
		{
			Customer::headerShow();
			traverseList(newList);
			cout << "��ѡ����Ҫɾ���Ĺ˿ͣ��������£���1��ʼ��ȡ����0��:\n";
			cin >> choice;
			if (deleteFromList(customerList, nameToFind, choice))
			{
				listToFile(customerList, fileName);
				cout << "ɾ���ɹ�" << endl;
			}
		}
		cout << "�Ƿ����ɾ�������˿���Ϣ����1����0����\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool traverseCustomer(const string fileName)
{
	list<Customer> customerList;
	readListFromFile(customerList, fileName);
	Customer::headerShow();
	traverseList(customerList);
	cout << "���»س�������";
	cin.get();
	cin.get();
	return true;
}

bool alterCustomerFromList(list<Customer>::iterator curr, string newContent, int choice)
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
