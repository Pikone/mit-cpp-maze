//v1.0b
#include <iostream>
#include <cstdlib>
#include <ctime>
#define WALL '*'
#define NO_WALL ' '
#define PATH '#'
//#define MAP_NUM 10  //Define Ипользовался в ранних версиях программы

using namespace std;
//int *map_ch;			//Переменная для хранения адреса размера массива
//char map [*map_ch][*map_ch];	//Попытка создать массив вне функции используя указатели
char map [100][100];
int map_bg [100][100];		//Фоновой массив следящий за перемещением
int i = 0, z = 0, map_size = 0;
int x = 1, y = 1;	//position
int map_num = 0;	//Временная переменная, чтобы проверить ее на не четность и передать значение в map_size
int for_count_bg_map = 3;	//Переменная для записи ее в фоновой массив

void map_print()	//Вывод массива на экран
{
	for (i = 0; i < map_size; i++)
	{
		for (z = 0; z < map_size; z++)
			cout << map[i][z];
		cout << endl;
	}
}

void map_bg_print()
{
	for (i = 0; i < map_size; i++)
	{
		for (z = 0; z < map_size; z++)
			cout << map_bg[i][z] << "\t";
		cout << endl;
	}
}

void map_bg_fill()	//Заполнение background массива
{
	for (i = 0; i < map_size; i++)
	{
		for (z = 0; z < map_size; z++)
			map_bg[i][z] = 0;
	}

	for (i = 0; i < map_size; i++)
	{
		map_bg[0][i] = 1;
		map_bg[i][0] = 1;
		map_bg[map_size - 1][i] = 1;
		map_bg[i][map_size - 1] = 1;
	}
	map_bg[1][1] = 2; 	//Тактический костыль
}

void map_draw_grid()	//Отрисовка сетки (без вывода)
{
	for (i = 0; i < map_size; i++)
	{
		for (z = 0; z < map_size; z++)
		{
			if (i % 2 == 0){
				map[i][z] = WALL;
			}
			else{
				if (z % 2 != 0)
					map[i][z] = NO_WALL;
				else
					map[i][z] = WALL;
			}
		}
	}
}

void map_draw_lab()		//Алгоритм создания лабиринта (один шаг)
{

	switch(rand() % 4)
	{
		case 0:		//up
			if (map_bg [x - 1][y] != 1) // возьми алгоритм со змейки dude
			{
				if (map_bg [x - 1][y] < 1)
				{
					map_bg[--x][y] = for_count_bg_map; for_count_bg_map++; cout << "x" << " " << x << " ";
					map[x][y] = PATH; cout << x << " ";
					map_bg[--x][y] = for_count_bg_map; for_count_bg_map++; cout << x << " ";
					map[x][y] = PATH; cout << x << " " << endl;
				}
			}
		break;

		case 1:		//right
			if (map_bg [x][y + 1] != 1)
			{
				if (map_bg [x][y + 1] < 1)
				{
					map_bg[x][++y] = for_count_bg_map; for_count_bg_map++; cout << "y" << " " << y << " ";
					map[x][y] = PATH; cout << y << " ";
					map_bg[x][++y] = for_count_bg_map; for_count_bg_map++; cout << y << " ";
					map[x][y] = PATH; cout << y << " " << endl;
				}
			}
		break;

		case 2:		//down
			if (map_bg [x + 1][y] != 1)
			{
				if (map_bg [x + 1][y] < 1)
				{
					map_bg[++x][y] = for_count_bg_map; for_count_bg_map++; cout << "x" << " " << x << " ";
					map[x][y] = PATH; cout << x << " ";
					map_bg[++x][y] = for_count_bg_map; for_count_bg_map++; cout << x << " ";
					map[x][y] = PATH; cout << x << " " << endl;
				}
			}
		break;

		case 3:		//left
			if (map_bg [x][y - 1] != 1)
			{
				if (map_bg [x][y - 1] < 1)
				{
					map_bg[x][--y] = for_count_bg_map; for_count_bg_map++; cout << "y" << " " << y << " ";
					map[x][y] = PATH; cout << y << " ";
					map_bg[x][--y] = for_count_bg_map; for_count_bg_map++; cout << y << " ";
					map[x][y] = PATH; cout << y << " " << endl;
				}
			}
		break;
	}
}

int main ()
{
	srand(time(0));
	cin >> map_num;
	//map_ch = &map_num;	//Отпало, не работает
	if (map_num % 2 == 0)
		map_size = map_num - 1;
	else
		map_size = map_num;

	map_bg_fill();		//Заполнение массива backgroung
	map_draw_grid();	//Отрисовка сетки (без вывода)
	map_print();		//Вывод массива на экран
	map_bg_print();
	do{
	map_draw_lab();		//Вызов алгоритма отрисовывания шага лабиринта
	}while(map_bg[x - 1][y] == 0 || map_bg[x + 1][y] == 0 || map_bg[x][y - 1] == 0 || map_bg[x][y + 1] == 0);
	map_print();
	map_bg_print();

return 0;
}
