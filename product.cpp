#pragma warning(disable:4996)
#include<iomanip>
#include"sale.h"

string Filename(Product* p)
{
	return PRODUCTFILE;
}

void HeaderShow(Product* head)
{
	cout << "�� ��\t�� ��\t�� ��\t�� ��\t�� ��\t���ʱ��\n";
}

void SearchShow(Product* head)
{
	cout << "��������Ҫ��ѯ�Ĳ�Ʒ����\n";
}

void Change(Product* head)
{
	string content, name;
	int type;
	Product* p=nullptr;
	cout << "��������Ҫ�޸ĵĲ�Ʒ����\n";
	cin >> name;
	HeaderShow(p);
	p = Find(head, name);
	if (!p)
		return;
	cout << "��ѡ����Ҫ�޸���Ϣ�����:\n";
	cout << "(1.����\t2.����\t3.����\t4.����\t5.����\t6.���ʱ��(�磺xxxx-xx-xx)\n)";
	cin >> type;
	if (type >= 7 || type <= 0)
	{
		cout << "��Ч����\n";
		return;
	}
	cout << "�������µ�����:\n";
	cin >> content;
	switch (type)
	{
	case 1:
		strncpy(p->code, content.c_str(), CODESIZE);
		break;
	case 2:
		strncpy(p->name, content.c_str(), NAMESIZE);
		break;
	case 3:
		p->totalNumber = atoi(content.c_str());
		break;
	case 4:
		p->unitPrice = atof(content.c_str());
		break;
	case 5:
		strncpy(p->producer, content.c_str(), NAMESIZE);
		break;
	case 6:
		strncpy(p->stockDate, content.c_str(), DATESIZE);
		break;
	}
}

void CancelShow1(Product* p)
{
	cout << "��������Ҫɾ���Ĳ�Ʒ����\n";
}

void CancelShow2(Product* p)
{
	cout << "��ѡ����Ҫɾ���Ĳ�Ʒ���������£���1��ʼ��ȡ����0��:\n";
}

void Input(istream& t, Product* p)
{
	t >> p->code >> p->name >> p->totalNumber
		>> p->unitPrice >> p->producer >> p->stockDate;
}

void Output(ostream& t, Product* p)
{
	t.setf(ios::left);
	t << setw(8) << p->code << setw(8) << p->name
		<< setw(8) << p->totalNumber << setw(8) << p->unitPrice
		<< setw(8) << p->producer << p->stockDate << endl;
}