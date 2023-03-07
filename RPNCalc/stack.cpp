#include "stack.h"

void push(elem*& top, char x)
{
	//������� ������� ����� (��������� � ������)
	elem* new_el = new elem;
	new_el->x = x;
	//�������� ��������� �� ��������� ������� �����
	new_el->next = top;
	//������������ ��������� �� ������� �����
	top = new_el;
}

bool pop(elem*& top, char& x)
{
	//�������� ����� �� �������
	if (!top) return false;
	//���������� �������� �������� �����
	x = top->x;
	//���������� ��������� �� ������� ������� �� ��������� ����������
	elem* old_el = top;
	//��������� ������� �����
	top = top->next;
	//������� ������ ��-��� ���������� ��������
	delete old_el;
	return true;
}

bool peek(const elem* top, char& x)
{
	//�������� ����� �� �������
	if (!top) return false;
	//���������� �������� �������� �����
	x = top->x;	
	return true;
}

void clear(elem*& top)
{
	char x;
	while (top) pop(top, x);
}
void push(elem_i*& top, double x)
{
	//������� ������� ����� (��������� � ������)
	elem_i* new_el = new elem_i;
	new_el->x = x;
	//�������� ��������� �� ��������� ������� �����
	new_el->next = top;
	//������������ ��������� �� ������� �����
	top = new_el;
}

bool pop(elem_i*& top, double& x)
{
	//�������� ����� �� �������
	if (!top) return false;
	//���������� �������� �������� �����
	x = top->x;
	//���������� ��������� �� ������� ������� �� ��������� ����������
	elem_i* old_el = top;
	//��������� ������� �����
	top = top->next;
	//������� ������ ��-��� ���������� ��������
	delete old_el;
	return true;
}

bool peek(const elem_i* top, double& x)
{
	//�������� ����� �� �������
	if (!top) return false;
	//���������� �������� �������� �����
	x = top->x;
	return true;
}

void clear(elem_i*& top)
{
	double x;
	while (top) pop(top, x);
}