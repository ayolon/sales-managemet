#include<iostream>
#include<fstream>
#include<iomanip>
#include"market.h"
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

void Market::headerShow()
{
	cout << "����Ա\t�� ��\t�˿���ϵ��ʽ\t��Ʒ����\t��Ʒ����\t��������\t�� ��\t˵ ��\t����ʱ��\n";
}

Market::Market()
{
	salesman[0] = customer[0] = '\0';
	customerPhone[0] = name[0] = '\0';
	productCode[0] = salesDate[0] = '\0';
	note[0] = '\0';
	amount = 0;
	unitPrice = 0.0;
}

bool Market::setSalesman(string newSalesman)
{
	memcpy(salesman, newSalesman.c_str(), NAME_SIZE);
	return true;
}

bool Market::setCustomer(string newCustomer)
{
	memcpy(customer, newCustomer.c_str(), NAME_SIZE);
	return true;
}

bool Market::setCustomerPhone(string newCustomerPhone)
{
	memcpy(customerPhone, newCustomerPhone.c_str(), PHONE_SIZE);
	return true;

}

bool Market::setName(string newName)
{
	memcpy(name, newName.c_str(), NAME_SIZE);
	return true;
}

bool Market::setProductCode(string newProductCode)
{
	memcpy(productCode, newProductCode.c_str(), CODE_SIZE);
	return true;
}

bool Market::setSalesDate(string newSalesDate)
{
	memcpy(salesDate, newSalesDate.c_str(), NAME_SIZE);
	return true;
}

bool Market::setNote(string newNote)
{
	memcpy(note, newNote.c_str(), NOTE_SIZE);
	return true;
}

bool Market::setAmount(int newAmount)
{
	amount = newAmount;
	return true;
}

bool Market::setUnitPrice(double newUnitPrice)
{
	unitPrice = newUnitPrice;
	return true;
}

bool Market::isName(string newName)
{
	if (newName == name)
	{
		return true;
	}
	return false;
}

istream& operator>>(std::istream& is, Market& t)
{
	is >> t.salesman >> t.customer >> t.customerPhone
		>> t.name >> t.productCode >> t.amount
		>> t.unitPrice >> t.note >> t.salesDate;
	return is;
}

ostream& operator<<(std::ostream& os, const Market& t)
{
	os.setf(ios::left);
	os << setw(8) << t.salesman << setw(8) << t.customer
		<< setw(16) << t.customerPhone << setw(16) << t.name
		<< setw(16) << t.productCode << setw(16) << t.amount
		<< setw(8) << t.unitPrice << setw(8) << t.note
		<< t.salesDate;
	return os;
}

bool addMarket(const string fileName)
{
	Market newMarket;
	ofstream fp(fileName, ios::app);
	int flag = 1;
	do {
		Market::headerShow();
		cin >> newMarket;
		fp << newMarket << endl;
		cout << "�Ƿ������ӣ���1����0����\n";
		cin >> flag;
	} while (flag == 1);
	fp.close();
	return true;
}

bool searchMarket(const string fileName)
{
	list<Market> marketList;
	readListFromFile(marketList, fileName);
	list<Market> newList;
	string nameToFind;
	int flag = 1;
	do
	{
		cout << "��������Ҫ��ѯ�Ĳ�Ʒ����\n";
		cin >> nameToFind;
		newList = searchFromList(marketList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "û��" << nameToFind << "����Ϣ\n";
		}
		else
		{
			Market::headerShow();
			traverseList(newList);
		}
		cout << "�Ƿ������ѯ������Ʒ���ƣ���1����0����\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool alterMarket(const string fileName)
{
	list<Market> marketList;
	readListFromFile(marketList, fileName);
	list<Market> newList;
	string nameToFind;
	int flag = 1, choice = 0;
	do
	{
		cout << "��������Ҫ�޸ĵ����ۼ�¼�Ĳ�Ʒ����\n";
		cin >> nameToFind;
		newList = searchFromList(marketList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "û��" << nameToFind << "����Ϣ\n";
		}
		else
		{
			Market::headerShow();
			traverseList(newList);
			cout << "��ѡ����Ҫ�޸ĵ����ۼ�¼���������£���1��ʼ��ȡ����0��:\n";
			int count = 1;
			cin >> choice;
			for (auto curr = marketList.begin(); curr != marketList.end(); curr++)
			{
				if (curr->isName(nameToFind))
				{
					if (count == choice)
					{
						int type = 0;
						cout << "��ѡ����Ҫ�޸���Ϣ�����:\n";
						cout << "(1.����Ա\t2.�� ��\t3.�˿���ϵ��ʽ\t4.��������\t5.�� ��\t6.˵ ��\t7.����ʱ��)\n";
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
							alterMarketFromList(curr, newContent, choice);
							listToFile(marketList, fileName);
							cout << "�޸ĳɹ�\n";
							break;
						}
					}
					count++;
				}
			}
		}
		cout << "�Ƿ�����޸��������ۼ�¼����1����0����\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool deleteMarket(const string fileName)
{
	list<Market> marketList;
	readListFromFile(marketList, fileName);
	list<Market> newList;
	string nameToFind;
	int flag = 1, choice = 0;
	do
	{
		cout << "��������Ҫɾ�������ۼ�¼�Ĳ�Ʒ����\n";
		cin >> nameToFind;
		newList = searchFromList(marketList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "û��" << nameToFind << "����Ϣ\n";
		}
		else
		{
			Market::headerShow();
			traverseList(newList);
			cout << "��ѡ����Ҫɾ�������ۼ�¼���������£���1��ʼ��ȡ����0��:\n";
			cin >> choice;
			if (deleteFromList(marketList, nameToFind, choice))
			{
				listToFile(marketList, fileName);
				cout << "ɾ���ɹ�" << endl;
			}
		}
		cout << "�Ƿ����ɾ���������ۼ�¼����1����0����\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool traverseMarket(const string fileName)
{
	list<Market> marketList;
	readListFromFile(marketList, fileName);
	Market::headerShow();
	traverseList(marketList);
	cout << "���»س�������";
	cin.get();
	cin.get();
	return true;
}

bool alterMarketFromList(list<Market>::iterator curr, string newContent, int choice)
{
	switch (choice)
	{
	case 1:
		curr->setSalesman(newContent);
		break;
	case 2:
		curr->setCustomer(newContent);
		break;
	case 3:
		curr->setCustomerPhone(newContent);
		break;
	case 4:
		curr->setAmount(atoi(newContent.c_str()));
		break;
	case 5:
		curr->setUnitPrice(atof(newContent.c_str()));
		break;
	case 6:
		curr->setNote(newContent);
		break;
	case 7:
		curr->setSalesDate(newContent);
		break;
	default:return false;
	}
	return true;
}