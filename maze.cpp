// maze.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

//работа с консолью
#include <iostream>
//очистка консоли
#include <stdlib.h>
//подлючение времени для случайных чисел
#include <ctime>
//динамический контейнер хранящий уникальные элементы в неупорядоченном виде
#include <unordered_set>

using namespace std;

int main()
{
	//ввод длинны лабиринта
	int LongMaze = 0;
	cout << "input long = ";	//от1 до1000
	cin >> LongMaze;
	//ввод ширины лабиринта
	int WidthMaze = 0;
	cout << "input width = ";	//от1 до1000
	cin >> WidthMaze;
	
	//все возможные символы и их число
	/*for (size_t i = 0; i < 255; i++)
	{
		cout << "number = " << i << "symbol = " << (char)i << endl;
	}*/

	//стена = 219
	int const wall = 219; //"█"
	//пустота = 32
	int const zero = 32;  //" "

	//очистка консоли
	system("cls");

	//длинна массива лабиринта
	int LongArray = (WidthMaze + 2) * (LongMaze + 2);
	cout << LongArray << endl;
	//создание массива символов (неизвестного размера при начале компиляции)
	char* MazeSpace = new char[LongArray];
	//рисование границы
	for (int a = 0; a < LongMaze + 2; a++)
	{
		for (int b = 0; b < WidthMaze + 2; b++)
		{
			if ((a > 0 and a < LongMaze + 1) and (b > 0 and b < WidthMaze + 1))
			{
				MazeSpace[a * (WidthMaze + 2) + b] = (char)32;
			}
			else
			{
				MazeSpace[a * (WidthMaze + 2) + b] = (char)219;
			}
		}
	}

	//зависимость случайного числа от времени
	srand(time(NULL));

	//создание случайных точек 
	
	// старт  
	int RandomStart = rand();
	RandomStart = (RandomStart % WidthMaze) + 1;
	MazeSpace[RandomStart] = 'S';
	//финиш
	int RandomFinish = rand();
	RandomFinish = (RandomFinish % WidthMaze) + ((1 + LongMaze) * (WidthMaze + 2)) + 1;
	MazeSpace[RandomFinish] = 'F';

	//постройка маршрута лабиринта
	unordered_set<char> CreateMaze = { MazeSpace[RandomStart],};

	//моя позиция
	int MyPosition = RandomStart;
	//моя предыдущая позиция
	int MyPrePosition = MyPosition;
	//наличие пустоты в пространстве лабиринта
	/*bool PresenceZero = true;
	while (PresenceZero)
	{
		PresenceZero = false;
		for (size_t i = 0; i < LongArray; i++)
		{
			if (MazeSpace[i]==(char)zero)
			{
				PresenceZero = true;
				break;
			}	
		}
		//количество возможных путей
		int chance = 0;
		//возможные пути
		bool up = false;
		bool left = false;
		bool down = false;
		bool right = false;
		if (PresenceZero)
		{
			//возможные ходы

			if (MazeSpace[MyPosition - (WidthMaze + 2)] == (char)zero)
			{
				up = true;
				chance += 1;
			}
			if (MazeSpace[MyPosition + (WidthMaze + 2)] == (char)zero)
			{
				down = true;
				chance += 1;
			}
			if (MazeSpace[MyPosition - 1] == (char)zero)
			{
				left = true;
				chance += 1;
			}
			if (MazeSpace[MyPosition + 1] == (char)zero)
			{
				right = true;
				chance += 1;
			}
		}
////////////////////////////////////////////////////////////////////////////////////////////////////конец работы на сегодня
		if (chance==0 and PresenceZero)
		{
			//удаление последнего символа в "CreateMaze"
			MyPosition = CreateMaze
		}
		else if (chance==1)
		{
			//сдвинуть свою позицию в направлении "(char)zero"
			//и вместо MyPosition(*) проложить дорогу от предыдущей своей позиции к настоящей
			if (up)
			{
				MyPosition -= (WidthMaze + 2);
			}
			else if (down)
			{
				MyPosition += (WidthMaze + 2);
			}
			else if (left)
			{
				MyPosition -= 1;
			}
			else
			{
				MyPosition += 1;
			}

		}
		else if (chance>1 and chance<4)
		{

		}
		else if (!PresenceZero)
		{
			break;
		}
		else
		{
			cout << "error 'chanse = 4'";
			return 4;
		}
	}*/
	//отображение в консоль
	bool MazeOut = true;
	while(MazeOut)
	{
		for (int a = 0; a < LongMaze + 2; a++)
		{
			for (int b = 0; b < WidthMaze + 2; b++)
			{
				cout <<MazeSpace[ a * (WidthMaze + 2) + b];
			}
			cout  << endl;
		}
		MazeOut = false;
	}

	//Удаление массива из памяти
	delete[] MazeSpace;
	cout << "End Program"<<endl;
	//конец
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.