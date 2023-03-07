#include <iostream>
#include <fstream>
#include "cgi.cpp"
#include "stack.cpp"

using namespace std;
const char* header = "Вычисление в ОПЗ";



int check_prior(char a)
{
	if (a == '~') return 5;
	if (a == '-' || a == '+') return 2;
	if (a == '*' || a == '/') return 3;
	if (a == '^') return 4;
	if (a == '(') return 1;
}

bool is_op(char a)
{
	if (a == '+' || a == '-' || a == '*' || a == '/' || a == '^') return true;
	return false;
}

bool is_un(char* str, int n)
{
	if (n == 0) return true;
	if (str[n] == '-' && (is_op(str[n - 1]) || str[n - 1] == '(')) return true;
	return false;
}

int to_num(char a)
{
	if (a == '0') return 0;
	if (a == '1') return 1;
	if (a == '2') return 2;
	if (a == '3') return 3;
	if (a == '4') return 4;
	if (a == '5') return 5;
	if (a == '6') return 6;
	if (a == '7') return 7;
	if (a == '8') return 8;
	if (a == '9') return 9;
}

int get_num_part(char* str, int& n)
{
	int num = to_num(str[n]);
	while (str[n + 1] >= '0' && str[n + 1] <= '9')
	{
		num *= 10;
		num += to_num(str[n + 1]);
		n++;
	}
	return num;
}

double get_num(char* str, int& n)
{
	double whole = get_num_part(str, n);
	int mant;
	double num;
	int mant1 = 0;
	int c = 0;
	if (str[n+1] == '.')
	{
		n += 2;
		mant = get_num_part(str, n);
	}
	else return whole;
	mant1 = mant;
	while (mant1)
	{
		mant1 = mant1 / 10;
		c++;
	}
	num = whole + mant/pow(10, c);
	return num;
}

char to_char(char a)
{
	if (a == 0) return '0';
	if (a == 1) return '1';
	if (a == 2) return '2';
	if (a == 3) return '3';
	if (a == 4) return '4';
	if (a == 5) return '5';
	if (a == 6) return '6';
	if (a == 7) return '7';
	if (a == 8) return '8';
	if (a == 9) return '9';
}

int turn_to_whole(double a)
{
	int b = a;
	double mant = a - b;
	while (mant)
	{
		a *= 10;
		b = a;
		mant = a - b;
	}
	return b;
}

void write_num(char*& str, int& n, double num)
{
	int whole = num;
	double mant = num - whole;
	int part2;
	elem* a = nullptr;
	if (whole) {
		while (whole)
		{
			push(a, whole % 10);
			whole = whole / 10;
		}
		while (a)
		{
			pop(a, str[n]);
			str[n] = to_char(str[n]);
			n++;
		}
	}
	else
	{
		str[n] = '0';
		n++;
	}
	if (mant)
	{
		str[n] = '.';
		n++;
		part2 = turn_to_whole(mant);
		while (part2)
		{
			push(a, part2 % 10);
			part2 = part2 / 10;
		}
		while (a)
		{
			pop(a,str[n]);
			str[n] = to_char(str[n]);
			n++;
		}
	}
	str[n] = ' ';
	n++;
	clear(a);
}

void turn_to_RPN(char*& str)
{
	char* res = new char[512];
	elem* ops = nullptr;
	int resi = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			double num = get_num(str, i);
			write_num(res, resi, num);
		}
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			res[resi] = str[i];
			resi++;
		}
		if (str[i] == '(')
		{
			push(ops, str[i]);
		}
		if (str[i] == ')')
		{
			char el = '0';
			while (el != '(' && peek(ops, el))
			{
				pop(ops, el);
				if (el != '(')
				{
					res[resi] = el;
					resi++;
					res[resi] = ' ';
					resi++;
				}
			}
		}
		if (str[i] == '-' && is_un(str, i))
		{
			push(ops, '~');
		}
		if (is_op(str[i]) && !(is_un(str, i)))
		{
			if (ops) {
				char el = '0';
				peek(ops, el);
				while (check_prior(str[i]) <= check_prior(el))
				{
					if (pop(ops, el))
					{
						if (el != '(')
						{
							res[resi] = el;
							resi++;
							res[resi] = ' ';
							resi++;
						}
					}
					else break;
				}
				push(ops, str[i]);
			}
			else push(ops, str[i]);
		}
	}
	while (ops)
	{
		char el = '0';
		pop(ops, el);
		res[resi] = el;
		resi++;
		res[resi] = ' ';
		resi++;
	}
	res[resi] = '\0';
	char* temp = str;
	str = res;
	delete[] temp;
	clear(ops);


}
void pow2(double& a, int b, double a1)
{
	a *= a1;
}
double power(double a, int b)
{
	double s1 = a;
	if (b == 0) return 1;
	if (b < 0)
	{
		b = b * (-1);
		a = 1 / a;
		power(a, b);
	}
	if (b > 0)
	{
		while (b)
		{
			pow2(a, b, s1);
			b--;
		}
	}
	return a;
}

bool IsDelim(char a)
{
	if (a == ' ') return true;
	return false;
}

double calc(char* exp)
{
	elem_i* elems = nullptr;
	double e1, e2;
	for (int i = 0; i < strlen(exp); i++)
	{
		if (exp[i] >= '0' && exp[i] <= '9')
		{
			double num = get_num(exp, i);
			push(elems, num);
		}
		if (exp[i] == '~')
		{
			pop(elems, e1);
			e1 *= -1;
			push(elems, e1);
		}
		if (exp[i] == '+')
		{
			pop(elems, e1);
			pop(elems, e2);
			push(elems, e1 + e2);
		}
		if (exp[i] == '-')
		{
			pop(elems, e1);
			pop(elems, e2);
			push(elems, e1 - e2);
		}
		if (exp[i] == '*')
		{
			pop(elems, e1);
			pop(elems, e2);
			push(elems, e1 * e2);
		}
		if (exp[i] == '/')
		{
			pop(elems, e1);
			pop(elems, e2);
			push(elems, e2 / e1);
		}
		if (exp[i] == '^')
		{
			pop(elems, e1);
			pop(elems, e2);
			push(elems, pow(e2, e1));
		}
	}
	pop(elems, e1);
	return e1;
}

void show_menu()
{
	ifstream f;
	f.open("template/menu.txt");
	if (f.is_open())
	{
		while (!f.eof())
		{
			char* line = new char[256];
			f.getline(line, 256);
			char* part2;
			strtok_s(line, " ", &part2);
			cout << "<div class='menuitem'><a href='"
				<< line << "'>" <<
				part2 << "</a></div>";
		}
		f.close();
	}
}

void show_form(const char* data)
{
	char* param_value = nullptr;
	get_param_value(param_value, "exp", data);
	cout << "<form method='post' action='RPNCalc.cgi'>\n";
	cout << "<table><tr><td>Введите выражение: </td><td>" <<
		"<input type='text' name='exp' value='" << param_value << "'>" <<
		"<tr><td></td><td>";
	delete[] param_value;
}

void show_user_data(const char* data)
{
	char* str = new char[150];
	char* param_value = nullptr;
	get_param_value(param_value, "exp", data);
	strcpy_s(str, 150, data);
	turn_to_RPN(param_value);
	cout << "Ответ: " << calc(param_value) << "<br>";
	//	clear(stack);
	delete[] param_value;
}

/*void save_data(char*& data)
{
	char* name = nullptr;
	char* content = nullptr;
	int i = 0;
	get_param_value(name, "exp", data);
	ofstream out;
	out.open("data/comments", ios::binary || ios::app);
	if (out.is_open())
	out.close();
}*/

void show_content()
{
	char* data = nullptr;
	get_form_data(data);
	show_form(data);
	//	save_data(data);
	show_user_data(data);
	delete[] data;
}

int main()
{
	cout << "Content-type: text/html; charset=Windows-1251\n\n";
	ifstream f;
	f.open("template/main.html");
	if (f.is_open())
	{
		while (!f.eof())
		{
			char* line = new char[65536];
			f.getline(line, 65535);
			if (strcmp(line, "<!--header-->") == 0)
				cout << header;
			else if (strcmp(line, "<!--menu-->") == 0)
				show_menu();
			else if (strcmp(line, "<!--content-->") == 0)
				show_content();
			else
				cout << line;
		}
		f.close();
	}
	else
	{
		cout << "Can't open template file :(";
	}
	return 0;
}
