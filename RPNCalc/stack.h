#pragma once

/// <summary>
/// ��������� ��� �������� ��������� �����
/// </summary>

struct elem
{
	/// <summary>
	/// ����������� � ����� ��������
	/// </summary>
	char x;
	/// <summary>
	/// ��������� �� ��������� ������� � �����
	/// </summary>
	elem* next = nullptr;
};

/// <summary>
/// ���������� �������� � ����
/// </summary>
/// <param name="stack">��������� �� ������� �����</param>
/// <param name="x">����������� � ����� �������</param>
void push(elem*& stack, char x);

/// <summary>
/// ������� �� ����� ������� � ���������� ��� ��������
/// </summary>
/// <param name="stack">��������� �� ������� �����</param>
/// <param name="x">������������ �������</param>
/// <returns>
/// true, ���� ������� ������ �� ����� ������� �
/// false � ��������� ������
/// </returns>
bool pop(elem*& stack, char& x);

/// <summary>
/// ���������� �������� �������� � ������� �����, �� ��������� ��� ������� � �����
/// </summary>
/// <param name="stack">��������� �� ������� �����</param>
/// <param name="x">������������ �������� �������� � ������� �����</param>
/// <returns>
/// true, ���� ������� �������� �� ����� ������� �
/// false � ��������� ������
/// </returns>
bool peek(const elem* stack, char& x);

/// <summary>
/// ������� �������� ����� �� ������ 
/// </summary>
/// <param name="stack">��������� �� ������� ���������� �����</param>
void clear(elem*& stack);

struct elem_i
{
	/// <summary>
	/// ����������� � ����� ��������
	/// </summary>
	double x;
	/// <summary>
	/// ��������� �� ��������� ������� � �����
	/// </summary>
	elem_i* next = nullptr;
};

/// <summary>
/// ���������� �������� � ����
/// </summary>
/// <param name="stack">��������� �� ������� �����</param>
/// <param name="x">����������� � ����� �������</param>
void push(elem_i*& stack, double x);

/// <summary>
/// ������� �� ����� ������� � ���������� ��� ��������
/// </summary>
/// <param name="stack">��������� �� ������� �����</param>
/// <param name="x">������������ �������</param>
/// <returns>
/// true, ���� ������� ������ �� ����� ������� �
/// false � ��������� ������
/// </returns>
bool pop(elem_i*& stack, double& x);

/// <summary>
/// ���������� �������� �������� � ������� �����, �� ��������� ��� ������� � �����
/// </summary>
/// <param name="stack">��������� �� ������� �����</param>
/// <param name="x">������������ �������� �������� � ������� �����</param>
/// <returns>
/// true, ���� ������� �������� �� ����� ������� �
/// false � ��������� ������
/// </returns>
bool peek(const elem_i* stack, double& x);

/// <summary>
/// ������� �������� ����� �� ������ 
/// </summary>
/// <param name="stack">��������� �� ������� ���������� �����</param>
void clear(elem_i*& stack);
