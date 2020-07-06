#include "MyCrt.h"
#include "Stack.h"

#include <iostream>
#include <iomanip>
#include <conio.h>
#pragma warning(disable : 4996) 
using namespace std;

int clear()
{
	system("cls");
	return 0;
}
void SizeOfConsole()
{
	SetConsoleTitle(L"Калькулятор выражений");
	ScrSize(75, 20);
}
bool opr_chisel(char a)
{
	if ((char(a) > 47) && (char(a) < 58))
		return 1;
	else
		return 0;
} //выявление чисел во входной строке
void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}
bool znaki(char a) //определение знаков операций
{
	switch (a)
	{
	case '*':
	case '/':
	case '+':
	case '-':
	case '^':
		return 1;
	}
	return 0;
}
int prioritet(int a) //определение приоритета операций
{
	switch (a)
	{
	case '^':
		return 3;

	case '*':
	case '/':
		return 2;

	case '+':
	case '-':
		return 1;
	}
	return 0;
}
double function(double a, double b, int i) //функция подсчета бинарных операций
{
	if (i == 42)
		return a * b;
	if (i == 43)
		return a + b;
	if (i == 45)
		return a - b;
	if (i == 47)
		return a / b;
	if (i == 94)
		return powl(a, b);
}
double func(double a, char b)
{
	switch (b)
	{
	case '#':
		return sin(a);

	case '%':
		return cos(a) / sin(a);

	case '№':
		return cos(a);

	case '&':
		return tan(a);

	case '?':
		return log(a);
	}
	return 0;
}
int pravila()
{
	cout << endl << "\tВ калькуляторе возможно использование операций ";
	SetColor(0, 9);
	cout << "+, -, *, /, ^" << endl;
	SetColor(10, 0);
	cout << "\t функций ";
	SetColor(0, 11);
	cout << "sin, cos, tg, ctg";
	SetColor(10, 0);
	cout << ", натурального логарифма ";
	SetColor(0, 11);
	cout << "(log)";
	SetColor(10, 0);
	cout << "," << endl;
	cout << "\t\tопределена экспонента ";
	SetColor(0, 14);
	cout << "(e)";
	SetColor(10, 0);
	cout << " и число Пи ";
	SetColor(0, 14);
	cout << "(pi)";
	SetColor(10, 0);
	cout << endl;
	cout << endl << "Правила: заключите аргументы функции в круглые скобки: sin(x) - правильно," << endl;
	SetColor(0, 4);
	cout << "sin x";
	SetColor(10, 0);
	cout << " - неправильно. Не опускайте умножение: x*sin(x) - правильно," << endl;
	SetColor(0, 4);
	cout << "x sin(x)";
	SetColor(10, 0);
	cout << " - неправильно; log - натуральный логарифм" << endl;
	cout << endl << endl;
	cout << "Нажмите любую клавишу, чтобы вернуться в меню...";
	_getch();
	clear();
	return 0;
}
int Vihodizigri()
{
	TextForeground(10);
	clear();
	int hod = 0, kurs = 0;
	while (1)
	{
		GoToXY(25, 8);
		cout << "Вы уверены, что хотите выйти?";
		for (int i = 0; i < 2; ++i)
		{
			GoToXY(34 + i * 4, 9);
			if (i == 0)
				cout << "Нет";
			if (i == 1)
				cout << "ДА";

		}
		GoToXY(34 + hod * 4, 10);
		cout << "^^";
		kurs = _getch();
		if ((kurs == 97) || (kurs == 228) || (kurs == 75))
		{
			if (hod > 0)
				hod -= 1;
		}
		else if ((kurs == 100) || (kurs == 162) || (kurs == 77))
		{
			if (hod < 1)
				hod += 1;
		}
		else if (kurs == 13)
		{
			break;
		}
		clear();
	}
	return hod;
}
int MainMenu0(int kol)
{
	clear();
	kol -= 2;
	CursorVisible(0);
	int kurs = 0, hod = 0;
	for (int i = 0; i < kol + 1; ++i)
	{
		GoToXY(25, 4);
		SetConsoleCP(1251);
		cout << "\332";
		for (int i = 0; i < 20; ++i)
			cout << "\304";
		cout << "\277";
		SetConsoleCP(866);
		GoToXY(25, 5 + i);
		if (i == 0)
		{
			cout << "|";
			if (hod == 0)
				TextForeground(1);
			cout << " Калькулятор        ";
			TextForeground(10);
			cout << "| \n";
		}
		else if (i == 1)
			cout << "| Правила ввода      |       \n";
		else
			cout << "| Выход              |       \n";
	}
	while (1)
	{
		GoToXY(25, 8);
		SetConsoleCP(1251);
		cout << "\300";
		for (int i = 0; i < 20; ++i)
			cout << "\304";
		cout << "\331";
		SetConsoleCP(866);
		GoToXY(41, 5 + hod); //41
		//TextBackground(1);
		//cout << "<--";
		kurs = _getch();
		if ((kurs == 119) || (kurs == 230) || (kurs == 72))
		{
			if (hod > 0)
				hod -= 1;
		}
		else if ((kurs == 115) || (kurs == 235) || (kurs == 80))
		{
			if (hod < kol)
				hod += 1;
		}
		else if (kurs == 13)
		{
			clear();
			break;
		}
		//	clear();


		for (int i = 0; i < kol + 1; ++i)
		{
			GoToXY(25, 4);
			SetConsoleCP(1251);
			cout << "\332";
			for (int i = 0; i < 20; ++i)
				cout << "\304";
			cout << "\277";
			SetConsoleCP(866);
			GoToXY(25, 5 + i);
			if (i == 0)
			{
				cout << "|";
				if (hod == i)
					TextForeground(1);
				cout << " Калькулятор        ";
				TextForeground(10);
				cout << "| \n";
			}
			else if (i == 1)
			{
				cout << "|";
				if (hod == i)
					TextForeground(1);
				cout << " Правила ввода      ";
				TextForeground(10);
				cout << "| \n";
			}
			else
			{
				cout << "|";
				if (hod == i)
					TextForeground(1);
				cout << " Выход              ";
				TextForeground(10);
				cout << "| \n";
			}
		}
	}
	//clear();
	return hod;
}
void play()
{
	cout << "\t\t\t  КАЛЬКУЛЯТОР ВЫРАЖЕНИЙ";
	int NoUse = 0, lol = 0, live = 0;
	CursorVisible(1);
	do
	{
		char Sort[100];
		stack <char> Stack;
		stack <double> Stack_1;
		double a, b;
		int j = 0, i = 0, z = 0, x = 0, X, Y;
		char Inf[100], w, s1[] = " ", * p = Inf;
		cout << endl << endl << "Введите выражение: ";
		do
		{
			w = _getch();
			if ((w == 'p') && (((z == 0) || (znaki(Inf[z - 1])) || (Inf[z - 1] == '(')) ||
				((Inf[z - 1] == ' ') && ((znaki(Inf[z - 2])) || (Inf[z - 1] == '(')))))
			{
				Inf[z] = 'p';
				cout << 'p';
				Inf[z + 1] = 'i';
				cout << 'i';
				z += 2;
			}
			else if ((w == 'e') && (((z == 0) || (znaki(Inf[z - 1])) || (Inf[z - 1] == '(')) ||
				((Inf[z - 1] == ' ') && ((znaki(Inf[z - 2])) || (Inf[z - 1] == '(')))))
			{
				Inf[z] = 'e';
				cout << 'e';
				z++;
			}
			else if ((w == '.') && (((opr_chisel(Inf[z - 1]))) || ((Inf[z - 1] == ' ') && (opr_chisel(Inf[z - 1])))))
			{
				Inf[z] = '.';
				cout << '.';
				z++;
			}
			else if ((w == '(') && (((z == 0) || (znaki(Inf[z - 1])) || (Inf[z - 1] == '(')) || ((Inf[z - 1] == ' ') && ((znaki(Inf[z - 2])) || (Inf[z - 1] == '(')))))
			{
				Inf[z] = '(';
				cout << '(';
				z++;
				x++;
			}
			else if ((w == ')') && (x > 0) && (((Inf[z - 1] == 'e') || (Inf[z - 1] == ')') || (Inf[z - 1] == 'i') || (opr_chisel(Inf[z - 1]))) ||
				((Inf[z - 1] == ' ') && ((Inf[z - 1] == 'e') || (Inf[z - 1] == ')') || (Inf[z - 1] == 'i') || (opr_chisel(Inf[z - 1]))))))
			{
				Inf[z] = ')';
				z++;
				x--;
				cout << ')';
			}
			else if ((w == 's') && ((z == 0) || ((Inf[z - 1] == '(') || (znaki(Inf[z - 1]))) ||
				((Inf[z - 1] == ' ') && ((Inf[z - 2] == '(') || (znaki(Inf[z - 2]))))))
			{
				Inf[z] = 's';
				cout << 's';
				Inf[z + 1] = 'i';
				cout << 'i';
				Inf[z + 2] = 'n';
				cout << 'n';
				Inf[z + 3] = '(';
				cout << '(';
				z += 4;
				x++;
			}
			else if ((w == 'c') && ((z == 0) || ((Inf[z - 1] == '(') || (znaki(Inf[z - 1]))) || ((Inf[z - 1] == ' ') && ((Inf[z - 2] == '(') || (znaki(Inf[z - 2]))))))
			{
				cout << 'c';
				Inf[z] = 'c';
				z++;
			}
			else if ((w == 'o') && (Inf[z - 1] == 'c'))
			{
				Inf[z] = 'o';
				cout << 'o';
				Inf[z + 1] = 's';
				cout << 's';
				Inf[z + 2] = '(';
				cout << '(';
				z += 3;
				x++;
			}
			else if ((w == 'l') && ((z == 0) || ((Inf[z - 1] == '(') || (znaki(Inf[z - 1]))) ||
				((Inf[z - 1] == ' ') && ((Inf[z - 2] == '(') || (znaki(Inf[z - 2]))))))
			{
				Inf[z] = 'l';
				cout << 'l';
				Inf[z + 1] = 'o';
				cout << 'o';
				Inf[z + 2] = 'g';
				cout << 'g';
				Inf[z + 3] = '(';
				cout << '(';
				z += 4;
				x++;
			}
			else if ((w == 't') && (Inf[z - 1] == 'c'))
			{
				Inf[z] = 't';
				cout << 't';
				Inf[z + 1] = 'g';
				cout << 'g';
				Inf[z + 2] = '(';
				cout << '(';
				z += 3;
				x++;
			}
			else if ((w == 't') && ((z == 0) || ((Inf[z - 1] == '(') || (znaki(Inf[z - 1]))) || ((Inf[z - 1] == ' ') && ((Inf[z - 2] == '(') || (znaki(Inf[z - 2]))))))
			{
				Inf[z] = 't';
				cout << 't';
				Inf[z + 1] = 'g';
				cout << 'g';
				Inf[z + 2] = '(';
				cout << '(';
				z += 3;
				x++;
			}

			else if (((w >= 48) && (w <= 57)) && ((z == 0) || ((Inf[z - 1] == '(') || (znaki(Inf[z - 1])) || (opr_chisel(Inf[z - 1])) || (Inf[z - 1] == '.')) ||
				((Inf[z - 1] == ' ') && ((Inf[z - 2] == '(') || (znaki(Inf[z - 2]))))))
			{
				cout << w;
				Inf[z] = int(w);
				z++;
			}
			else if ((w == ' ') && (z != 0) && (Inf[z - 1] != ' ') && (Inf[z - 1] != '.'))
			{
				cout << w;
				Inf[z] = ' ';
				z++;
			}
			else if ((znaki(w)) && (((Inf[z - 1] == ')') || (opr_chisel(Inf[z - 1])) || (Inf[z - 1] == 'e') || (Inf[z - 1] == 'i')) ||
				((Inf[z - 1] == ' ') && ((Inf[z - 2] == ')') || (opr_chisel(Inf[z - 2])) || (Inf[z - 2] == 'e') || (Inf[z - 2] == 'i')))))
			{
				if (w == '+')
				{
					Inf[z] = '+';
					cout << w;
					z++;
				}
				if (w == '-')
				{
					Inf[z] = '-';
					cout << w;
					z++;
				}
				if (w == '*')
				{
					Inf[z] = '*';
					cout << w;
					z++;
				}
				if (w == '/')
				{
					Inf[z] = '/';
					cout << w;
					z++;
				}
				if (w == '^')
				{
					Inf[z] = '^';
					cout << w;
					z++;
				}
			}
			else if ((w == 8) && (z > 0))
			{
				if ((opr_chisel(Inf[z - 1])) || (Inf[z - 1] == ' ') || (Inf[z - 1] == 'e') || (Inf[z - 1] == 'c'))
				{
					cout << "\b \b";
					z--;
				}
				else if ((Inf[z - 1] == '(') && ((Inf[z - 2] == 'n') || (Inf[z - 2] == 's')))
				{
					cout << "\b \b\b \b\b \b\b \b";
					z -= 4;
					x--;
				}
				else if ((Inf[z - 1] == '(') && ((Inf[z - 2] == 'g') && (Inf[z - 3] == 't') && (Inf[z - 4] == 'c')))
				{
					cout << "\b \b\b \b\b \b\b \b";
					z -= 4;
					x--;
				}
				else if ((Inf[z - 1] == '(') && ((Inf[z - 2] == 'g') && (Inf[z - 3] == 't')))
				{
					cout << "\b \b\b \b\b \b";
					z -= 3;
					x--;
				}
				else if ((Inf[z - 1] == '(') && ((Inf[z - 2] == 'g') && (Inf[z - 3] == 'o') && (Inf[z - 4] == 'l')))
				{
					cout << "\b \b\b \b\b \b\b \b";
					z -= 4;
					x--;
				}
				else if ((znaki(Inf[z - 1])) || (Inf[z - 1] == '.'))
				{
					cout << "\b \b";
					z--;
				}
				else if (Inf[z - 1] == '(')
				{
					cout << "\b \b";
					z--;
					x--;
				}
				else if (Inf[z - 1] == ')')
				{
					cout << "\b \b";
					z--;
					x++;
				}
				else if (Inf[z - 1] == 'i')
				{
					cout << "\b \b\b \b";
					z -= 2;
				}
			}
		} while ((w != '=') || ((!opr_chisel(Inf[z - 1])) && (Inf[z - 1] != ')') && (Inf[z - 1] != 'i') && (Inf[z - 1] != 'e')));
		while (x > 0)
		{
			Inf[z] = ')';
			z++;
			x--;
		}
		Inf[z] = '\0';
		while ((p = strstr(Inf, s1)) != 0)
		{
			*p = 0;
			strcat(Inf, p + strlen(s1));
		}
		//gets(Inf);
		for (int i = 0; Inf[i] != '\0';)
		{
			if (Inf[i] == 'e')
			{
				Sort[j] = Inf[i];
				j++;
				i++;
			}
			if (Inf[i] == 'p')
			{
				Sort[j] = Inf[i];
				j++;
				i += 2;
			}
			if (opr_chisel(Inf[i])) //если символ является числом, добавляем его в выходную строку
			{
				while (opr_chisel(Inf[i]) || Inf[i] == '.')
				{
					Sort[j] = Inf[i];
					j++;
					i++;
				}
				Sort[j] = '@';
				j++;
			}
			if (char(Inf[i] == 's'))
			{
				Stack.push('#');//sin = #
				i += 3;
			}
			if (char(Inf[i] == 'c') && (char(Inf[i + 1] == 'o')))
			{
				Stack.push('№');//cos = №
				i += 3;
			}
			if (char(Inf[i] == 'c') && (char(Inf[i + 1] == 't')))
			{
				Stack.push('%');//ctg = %
				i += 3;
			}
			if (char(Inf[i] == 't'))
			{
				Stack.push('&');//tg = &
				i += 2;
			}
			if (char(Inf[i] == 'l'))
			{
				Stack.push('?'); //log = ? (натуральный логарифм)
				i += 3;
			}
			if (char(Inf[i]) == 40) //если символ является "(", добавляем его в стек
			{
				Stack.push(Inf[i]);
				i++;
			}
			if (char(Inf[i]) == 41) //если символ является ")"...
			{
				while (char(Stack.top()) != 40)
				{
					Sort[j] = Stack.top();
					j++;
					Stack.pop();
				}
				Stack.pop();
				i++;
			}
			if (znaki(Inf[i])) //если символ является знаком
			{
				while (((!Stack.empty()) && ((prioritet(Stack.top()) >= prioritet(Inf[i])))) ||
					((!Stack.empty()) && ((Stack.top() == '#') || (Stack.top() == '%') ||
					(Stack.top() == '№') || (Stack.top() == '&') || (Stack.top() == '?'))))
				{
					Sort[j] = Stack.top();
					Stack.pop();
					j++;
				}
				Stack.push(Inf[i]);
				i++;
			}
		}
		while (!Stack.empty())
		{
			Sort[j] = Stack.top();
			j++;
			Stack.pop();
		}
		Sort[j] = '\0';
		//cout << Sort;
		for (int i = 0; Sort[i] != '\0';) //обработка выходной строки в польской нотации
		{
			if (Sort[i] == 'e')
			{
				Stack_1.push(2.7182818);
				i++;
			}
			if (Sort[i] == 'p')
			{
				Stack_1.push(3.14159265);
				i++;
			}
			if (opr_chisel(Sort[i])) // если на вход передан операнд
			{
				double sum = Sort[i] - 48;
				while (opr_chisel(Sort[i + 1]))
				{
					sum = sum * 10 + (Sort[i + 1] - 48);
					i++;
				}
				if (Sort[i + 1] == '.') // если операнд дробный
				{
					double sum_1 = (Sort[i + 2] - 48) * 0.1;
					double j = 0.01;
					while (opr_chisel(Sort[i + 3]))
					{
						sum_1 = sum_1 + (Sort[i + 3] - 48) * j;
						i++;
						j = j * 0.1;
					}
					i += 2;
					sum = sum + sum_1;
				}
				Stack_1.push(sum);
				i += 2;
			}
			if (znaki(Sort[i])) // если на вход передан знак операции
			{
				b = Stack_1.top();
				Stack_1.pop();
				a = Stack_1.top();
				Stack_1.pop();
				Stack_1.push(function(a, b, Sort[i]));
				i++;
			}
			if ((Sort[i] == '#') || (Sort[i] == '%') || (Sort[i] == '№') || (Sort[i] == '&') || (Sort[i] == '?'))
			{
				a = Stack_1.top();
				Stack_1.pop();
				Stack_1.push(func(a, Sort[i]));
				i++;
			}

		}
		if ((Stack_1.top() >= 0) || (Stack_1.top() < 0))
		{
			cout << endl;
			cout << "Результат вычислений: ";
			SetColor(0, 9);
			cout << fixed << setprecision(2) << Stack_1.top() << endl;
			SetColor(10, 0);
			if (live == 0)
			{
				cout << endl << "Нажимайте любую кнопку для повторного ввода, ESC - для выхода в меню ";
				live++;
			}
		}
		NoUse = _getch();
	} while (NoUse != 27);
}

void proccess()
{
	int ko;
	while (1)
	{
		ko = MainMenu0(4);
		if (ko == 0)
			play();
		if (ko == 1)
			pravila();
		if (ko == 2)
		{
			int live = Vihodizigri();
			if (live == 1)
				break;
		}
	}
}

int main()
{
	setlocale(0, "");
	system("color 0A");
	CursorVisible(0);
	SizeOfConsole();
	//system("color 70");
	CursorVisible(1);
	proccess();
	return 0;
}

