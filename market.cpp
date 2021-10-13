#pragma warning(disable:4996)
#include<iomanip>
#include"sale.h"

string Filename(Market* p)
{
	return MARKETFILE;
}

void HeaderShow(Market* head)
{
	cout << "����Ա\t�� ��\t�˿���ϵ��ʽ\t��Ʒ����\t��Ʒ����\t��������\t�� ��\t˵ ��\t����ʱ��\n";
}

void SearchShow(Market* head)
{
	cout << "��������Ҫ��ѯ�Ĳ�Ʒ����\n";
}

void Change(Market* head)
{
	Market* p=nullptr;
	string content, name;
	int type;
	cout << "��������Ҫ�޸ĵ����ۼ�¼�Ĳ�Ʒ����\n";
	cin >> name;
	HeaderShow(p);
	p = Find(head, name);
	if (!p)
		return;
	cout << "��ѡ����Ҫ�޸���Ϣ�����:\n";
	cout << "(1.����Ա\t2.�� ��\t3.�˿���ϵ��ʽ\t4.��������\t5.�� ��\t6.˵ ��\t7.����ʱ��)\n";
	cin >> type;
	if (type >= 8 || type <= 0)
	{
		cout << "��Ч����\n";
		return;
	}
	cout << "�������µ�����:\n";
	cin >> content;
	switch (type)
	{
	case 1:
		strncpy(p->salesman, content.c_str(), NAMESIZE);
		break;
	case 2:
		strncpy(p->customer, content.c_str(), NAMESIZE);
		break;
	case 3:
		strncpy(p->customerPhone, content.c_str(), PHONESIZE);
		break;
	case 4:
		p->amount = atoi(content.c_str());
		break;
	case 5:
		p->unitPrice = atof(content.c_str());
		break;
	case 6:
		strncpy(p->notes, content.c_str(), 30);
		break;
	case 7:
		strncpy(p->salesDate, content.c_str(), DATESIZE);
		break;
	}
	cout << "�޸ĳɹ�\n";
}

void CancelShow1(Market* p)
{
	cout << "��������Ҫɾ�������ۼ�¼�Ĳ�Ʒ����\n";
}

void CancelShow2(Market* p)
{
	cout << "��ѡ����Ҫɾ�������ۼ�¼���������£���1��ʼ��ȡ����0��:\n";
}

void Input(istream& t, Market* p)
{
	t >> p->salesman >> p->customer >> p->customerPhone
		>> p->name >> p->productCode >> p->amount
		>> p->unitPrice >> p->notes >> p->salesDate;
}

void Output(ostream& t, Market* p)
{
	t.setf(ios::left);
	t << setw(8) << p->salesman << setw(8) << p->customer
		<< setw(16) << p->customerPhone << setw(16) << p->name
		<< setw(16) << p->productCode << setw(16) << p->amount
		<< setw(8) << p->unitPrice << setw(8) << p->notes
		<< p->salesDate << endl;
}