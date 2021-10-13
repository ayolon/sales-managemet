#pragma warning(disable:4996)
#include<iomanip>
#include"sale.h"

string Filename(Customer* p)
{
	return CUSTOMERFILE;
}

void HeaderShow(Customer* head)
{
	cout << "�� ��\t��ϵ�绰\t��ϵ��ַ\n";
}

void SearchShow(Customer* head)
{
	cout << "��������Ҫ��ѯ�Ĺ˿�����\n";
}

void Change(Customer* head)
{
	string content, name;
	int type;
	Customer* p=nullptr;
	cout << "��������Ҫ�޸ĵĹ˿͵�����\n";
	cin >> name;
	HeaderShow(p);
	p = Find(head, name);
	if (!p)
		return;
	cout << "��ѡ����Ҫ�޸���Ϣ�����:\n";
	cout << "(1.����\t2.��ϵ�绰\t3.��ϵ��ַ)\n";
	cin >> type;
	if (type >= 4 || type <= 0)
	{
		cout << "��Ч����\n";
		return;
	}
	cout << "�������µ�����:\n";
	cin >> content;
	switch (type)
	{
	case 1:
		strncpy(p->name, content.c_str(), NAMESIZE);
		break;
	case 2:
		strncpy(p->phone, content.c_str(), PHONESIZE);
		break;
	case 3:
		strncpy(p->address, content.c_str(), ADRESSSIZE);
		break;
	}
	cout << "�޸ĳɹ�\n";
}

void CancelShow1(Customer* p)
{
	cout << "��������Ҫɾ���Ĺ˿�����\n";
}

void CancelShow2(Customer* p)
{
	cout << "��ѡ����Ҫɾ���Ĺ˿ͣ��������£���1��ʼ��ȡ����0��:\n";
}

void Input(istream& t, Customer* p)
{
	t >> p->name >> p->phone >> p->address;
}

void Output(ostream& t, Customer* p)
{
	t.setf(ios::left);
	t << setw(8) << p->name << setw(16) << p->phone
		<< p->address << endl;
}