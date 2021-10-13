#include<iomanip>
#include"sale.h"

string Filename(Salesman *p)
{
	return SALESMANFILE;
}

void HeaderShow(Salesman* head)
{
	cout << "�� ��\t\t�� ��\t�Ա�\t��ϵ�绰\t��ϵ��ַ\t\t\t����������\t��ְʱ��\n";
}

void SearchShow(Salesman* head)
{
	cout << "��������Ҫ��ѯ������Ա����\n";
}

void Change(Salesman* head)
{
	Salesman* p=nullptr;
	string content, name;
	int type;
	cout << "��������Ҫ�޸ĵ�����Ա����\n";
	cin >> name;
	HeaderShow(p);
	p = Find(head, name);
	if (!p)
		return;
	cout << "��ѡ����Ҫ�޸���Ϣ�����:\n";
	cout << "(1.����\t2.����\t3.�Ա�\t4.��ϵ�绰\t5.��ϵ��ַ\t6.����������\t7.��ְʱ��)\n";
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
		memcpy(p->number, content.c_str(), CODESIZE);
		break;
	case 2:
		memcpy(p->name, content.c_str(), NAMESIZE);
		break;
	case 3:
		memcpy(p->gender, content.c_str(), GENDERSIZE);
		break;
	case 4:
		memcpy(p->phone, content.c_str(), PHONESIZE);
		break;
	case 5:
		memcpy(p->address, content.c_str(), ADRESSSIZE);
		break;
	case 6:
		memcpy(p->birthDate, content.c_str(), DATESIZE);
		break;
	case 7:
		memcpy(p->employedDate, content.c_str(), DATESIZE);
		break;
	}
	cout << "�޸ĳɹ�\n";
}

void CancelShow1(Salesman* p)
{
	cout << "��������Ҫɾ��������Ա����\n";
}

void CancelShow2(Salesman* p)
{
	cout << "��ѡ����Ҫɾ��������Ա���������£���1��ʼ��ȡ����0��:\n";
}

void Input(istream& t, Salesman* p)
{
	t >> p->number >> p->name >> p->gender
		>> p->phone >> p->address >> p->birthDate
		>> p->employedDate;
}

void Output(ostream& t, Salesman* p)
{
	t.setf(ios::left);
	t << setw(16) << p->number << setw(8) << p->name
		<< setw(8) << p->gender << setw(16) << p->phone
		<< setw(32) << p->address << setw(16) << p->birthDate
		<< p->employedDate << endl;
}