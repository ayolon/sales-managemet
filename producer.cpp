#pragma warning(disable:4996)
#include<iomanip>
#include"sale.h"

string Filename(Producer* p)
{
	return PRODUCERFILE;
}

void HeaderShow(Producer* head)
{
	cout << "�� ��\t��ϵ�绰\t��ϵ��ַ\n";
}

void SearchShow(Producer* head)
{
	cout << "��������Ҫ��ѯ�Ľ���������\n";
}

void Change(Producer* head)
{
	string content, name;
	int type;
	Producer* p=nullptr;
	cout << "��������Ҫ�޸ĵĽ����̵�����\n";
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

void CancelShow1(Producer* p)
{
	cout << "��������Ҫɾ���Ľ���������\n";
}

void CancelShow2(Producer* p)
{
	cout << "��ѡ����Ҫɾ���Ľ����̣��������£���1��ʼ��ȡ����0��:\n";
}

void Input(istream& t, Producer* p)
{
	t >> p->name >> p->phone >> p->address;
}

void Output(ostream& t, Producer* p)
{
	t.setf(ios::left);
	t << setw(8) << p->name << setw(16) << p->phone
		<< p->address << endl;
}