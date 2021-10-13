#include<iostream>
#include<fstream>
#include<iomanip>
#include"product.h"
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

void Product::headerShow()
{
	cout << "�� ��\t�� ��\t�� ��\t�� ��\t�� ��\t���ʱ��\n";
}

Product::Product()
{
	code[0] = name[0] = '\0';
	producer[0] = stockDate[0] = '\0';
	totalNumber = 0;
	unitPrice = 0.0;
}

bool Product::setCode(string newCode)
{
	memcpy(code, newCode.c_str(), PRODUCT_CODE_SIZE);
	return true;
}

bool Product::setName(string newName)
{
	memcpy(name, newName.c_str(), PRODUCT_NAME_SIZE);
	return true;
}

bool Product::setProducer(string newProducer)
{
	memcpy(producer, newProducer.c_str(), PRODUCT_NAME_SIZE);
	return true;
}

bool Product::setStockDate(string newStockDate)
{
	memcpy(stockDate, newStockDate.c_str(), PRODUCT_DATE_SIZE);
	return true;
}

bool Product::setTotalNumber(int newNumber)
{
	totalNumber = newNumber;
	return true;
}

bool Product::setUnitPrice(double newPrice)
{
	unitPrice = newPrice;
	return true;
}

bool Product::isName(string newName)
{
	if (newName == name)
	{
		return true;
	}
	return false;
}

istream& operator>>(std::istream& is, Product& t)
{
	is >> t.code >> t.name >> t.totalNumber
		>> t.unitPrice >> t.producer >> t.stockDate;
	return is;
}

ostream& operator<<(std::ostream& os, const Product& t)
{
	os.setf(ios::left);
	os << setw(8) << t.code << setw(8) << t.name
		<< setw(8) << t.totalNumber << setw(8) << t.unitPrice
		<< setw(8) << t.producer << t.stockDate;
	return os;
}

bool addProduct(const string fileName)
{
	Product newProduct;
	ofstream fp(fileName, ios::app);
	int flag = 1;
	do {
		Product::headerShow();
		cin >> newProduct;
		fp << newProduct << endl;
		cout << "�Ƿ������ӣ���1����0����\n";
		cin >> flag;
	} while (flag == 1);
	fp.close();
	return true;
}

bool searchProduct(const string fileName)
{
	list<Product> productList;
	readListFromFile(productList, fileName);
	list<Product> newList;
	string nameToFind;
	int flag = 1;
	do
	{
		cout << "��������Ҫ��ѯ����Ʒ����\n";
		cin >> nameToFind;
		newList = searchFromList(productList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "û��" << nameToFind << "����Ϣ\n";
		}
		else
		{
			Product::headerShow();
			traverseList(newList);
		}
		cout << "�Ƿ������ѯ������Ʒ��Ϣ����1����0����\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool alterProduct(const string fileName)
{
	list<Product> productList;
	readListFromFile(productList, fileName);
	list<Product> newList;
	string nameToFind;
	int flag = 1, choice = 0;
	do
	{
		cout << "��������Ҫ�޸ĵĲ�Ʒ����\n";
		cin >> nameToFind;
		newList = searchFromList(productList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "û��" << nameToFind << "����Ϣ\n";
		}
		else
		{
			Product::headerShow();
			traverseList(newList);
			cout << "��ѡ����Ҫ�޸ĵĲ�Ʒ���������£���1��ʼ��ȡ����0��:\n";
			int count = 1;
			cin >> choice;
			for (auto curr = productList.begin(); curr != productList.end(); curr++)
			{
				if (curr->isName(nameToFind))
				{
					if (count == choice)
					{
						int type = 0;
						cout << "��ѡ����Ҫ�޸���Ϣ�����:\n";
						cout << "(1.����\t2.����\t3.����\t4.����\t5.����\t6.���ʱ��(�磺xxxx-xx-xx)\n)";
						cin >> type;
						if (type >= 7 || type <= 0)
						{
							cout << "��Ч����\n";
						}
						else
						{
							string newContent;
							cout << "�������µ�����:\n";
							cin >> newContent;
							alterProductFromList(curr, newContent, choice);
							listToFile(productList, fileName);
							cout << "�޸ĳɹ�\n";
							break;
						}
					}
					count++;
				}
			}
		}
		cout << "�Ƿ�����޸�������Ʒ��Ϣ����1����0����\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool deleteProduct(const string fileName)
{
	list<Product> productList;
	readListFromFile(productList, fileName);
	list<Product> newList;
	string nameToFind;
	int flag = 1, choice = 0;
	do
	{
		cout << "��������Ҫɾ���Ĳ�Ʒ����\n";
		cin >> nameToFind;
		newList = searchFromList(productList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "û��" << nameToFind << "����Ϣ\n";
		}
		else
		{
			Product::headerShow();
			traverseList(newList);
			cout << "��ѡ����Ҫɾ���Ĳ�Ʒ���������£���1��ʼ��ȡ����0��:\n";
			cin >> choice;
			if (deleteFromList(productList, nameToFind, choice))
			{
				listToFile(productList, fileName);
				cout << "ɾ���ɹ�" << endl;
			}
		}
		cout << "�Ƿ����ɾ��������Ʒ��Ϣ����1����0����\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool traverseProduct(const string fileName)
{
	list<Product> productList;
	readListFromFile(productList, fileName);
	Product::headerShow();
	traverseList(productList);
	cout << "���»س�������";
	cin.get();
	cin.get();
	return true;
}

bool alterProductFromList(list<Product>::iterator curr, string newContent, int choice)
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
		curr->setTotalNumber(atoi(newContent.c_str()));
		break;
	case 4:
		curr->setUnitPrice(atof(newContent.c_str()));
		break;
	case 5:
		curr->setProducer(newContent);
		break;
	case 6:
		curr->setStockDate(newContent);
		break;
	default:return false;
	}
	return true;
}