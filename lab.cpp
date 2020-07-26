//v1.0b
#include <iostream>
#include <cstdlib>
#include <ctime>
#define WALL '*'
#define NO_WALL ' '
//#define MAP_NUM 10  //Define Ипользовался в ранних версиях программы

using namespace std;
//int *map_ch;			//Переменная для хранения адреса размера массива
//char map [*map_ch][*map_ch];	//Попытка создать массив вне функции используя указатели
char map [100][100];
int map_bg [100][100];		//Фоновой массив следящий за перемещением
int i = 0, z = 0, map_size = 0;
int x = 1, y = 1;	//position
int map_num = 0;	//Временная переменная, чтобы проверить ее на не четность и передать значение в map_size

void map_print()	//Вывод массива на экран
{
	for (i = 0; i < map_size; i++)
	{
		for (z = 0; z < map_size; z++)
			cout << map[i][z];
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

void map_draw_lab()		//Алгоритм создания лабиринта
{

	switch(rand() % 4)
	{
		case 0:		//up
			if (map_bg [x -= 2][y] < 1) // возьми алгоритм со змейки dude
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
	map_draw_grid();
	map_print();
	map_draw_lab();

return 0;
}
