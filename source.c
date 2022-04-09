#define _CRT_SECURE_NO_WARNINTS
#pragma warning(disable: 6031)
#pragma warning(disable: 6054)
#pragma warning(disable: 4996)

#include <stdio.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_POSITION 10
#define MAX_LIST 30

typedef struct champion {
	char name[MAX_NAME];
	int hp;
	int mp;
	int speed;
	int range;
	char position[MAX_POSITION];
}CHAMPION;

void menu();
void Search(CHAMPION*, int);
int Insert(CHAMPION*, int);
int Delete(CHAMPION*, int);
int DeleteAll(CHAMPION*, int);
void PrintAll(CHAMPION*, int);
void FindMaxHp(CHAMPION*, int);
void SortByHp(CHAMPION*, int);

int main()
{
	CHAMPION champion_list[MAX_LIST] = {
		{"가렌", 620, 0, 340, 175, "top"},
		{"갈리오", 562, 500, 335, 125, "mid"},
		{"베인", 515, 231, 330, 550, "bot"},
		{"티모", 528, 267, 330, 500, "top"},
		{"소라카", 535, 425, 325, 550, "support"},
		{"녹턴", 585, 275, 345, 125, "jungle"},
		{"블리츠크랭크", 582, 267, 325, 125, "support"},
		{"퀸", 532, 268, 335, 525, "top"},
		{"장지웅", 620, 0, 350, 500, "bot"},
		{"시비르", 530, 300, 325, 350, "bot"},
		{"모르가나", 500, 350, 320, 550, "support"},
		{"코르키", 550, 450, 125, 330, "mid"},
		{"리 신", 619, 0, 350, 250, "jungle"},
		{"레나타 글라스크", 500, 235, 330, 125, "support"},
		{"코르키", 500, 340, 330, 500, "mid"},
		{"바드", 490, 300, 330, 300, "support"},
		{"바루스", 510, 250, 345, 570, "bot"},
		{"쉔", 620, 0, 330, 200, "top"},
		{"애쉬", 500, 350, 330, 500, "bot"},
		{"라이즈", 550, 400, 325, 400, "mid"},
	};

	int select;
	static int champion_cnt = 20;

	while (1) {
		menu();
		printf("Input number: ");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			Search(champion_list, champion_cnt); break;
		case 2:
			champion_cnt = Insert(champion_list, champion_cnt); break;
		case 3:
			champion_cnt = Delete(champion_list, champion_cnt); break;
		case 4:
			champion_cnt = DeleteAll(champion_list, champion_cnt); break;
		case 5:
			PrintAll(champion_list, champion_cnt); break;
		case 6:
			FindMaxHp(champion_list, champion_cnt); break;
		case 7:
			SortByHp(champion_list, champion_cnt); break;
		}
	}
	return 0;
}

void menu()
{
	printf("\n\n1.Search\t2.Insert\t3.Delete\t4.DeleteAll\t5.PrintAll\t6.FindMaxHp\t7.SortByHp\n");
}

void Search(CHAMPION* champion_list, int champion_cnt)
{
	system("cls");
	char search_name[MAX_NAME];
	printf("검색할 챔피언 이름: ");
	scanf(" %[^\n]s", &search_name);

	int isCham = 0;
	for (int i = 0; i < champion_cnt; ++i) {
		if (strcmp(search_name, champion_list[i].name) == 0) {
			printf("name: %s\thp: %d\tmp: %d\tspeed: %d\trange: %d\tposition: %s\n", champion_list[i].name, champion_list[i].hp, champion_list[i].mp, champion_list[i].speed, champion_list[i].range, champion_list[i].position);
			isCham = 1;
		}
	}

	if (!isCham)
		printf("해당 챔피언이 없습니다.\n");
}

int Insert(CHAMPION* champion_list, int champion_cnt)
{
	system("cls");
	printf("name: ");
	scanf("%s", &champion_list[champion_cnt].name);
	printf("hp: ");
	scanf("%d", &champion_list[champion_cnt].hp);
	printf("mp: ");
	scanf("%d", &champion_list[champion_cnt].mp);
	printf("speed: ");
	scanf("%d", &champion_list[champion_cnt].speed);
	printf("range: ");
	scanf("%d", &champion_list[champion_cnt].range);
	printf("position: ");
	scanf("%s", &champion_list[champion_cnt].position);

	return ++champion_cnt;
}

int Delete(CHAMPION* champion_list, int champion_cnt)
{
	system("cls");
	char delete_name[MAX_NAME];
	printf("삭제할 챔피언 이름: ");
	scanf(" %[^\n]s", &delete_name);

	for (int i = 0; i < champion_cnt; ++i) {
		if (strcmp(delete_name, champion_list[i].name) == 0) {
			for (int j = i; j < champion_cnt; ++j) {
				memcpy(&champion_list[j], &champion_list[j + 1], sizeof(CHAMPION));
			}
		}
	}

	return --champion_cnt;
}

int DeleteAll(CHAMPION* champion_list, int champion_cnt)
{
	system("cls");
	char del_position[MAX_POSITION];
	printf("삭제할 position 입력: ");
	scanf("%s", &del_position);

	for (int i = 0; i < champion_cnt; ++i) {
		while (strcmp(del_position, champion_list[i].position) == 0) {
			for (int j = i; j < champion_cnt; ++j) {
				memcpy(&champion_list[j], &champion_list[j + 1], sizeof(CHAMPION));
			}
			--champion_cnt;
		}
	}
	return champion_cnt;
}

void PrintAll(CHAMPION* champion_list, int champion_cnt)
{
	system("cls");
	for (int i = 0; i < champion_cnt; ++i) {
		printf("name: %s\thp: %d\tmp: %d\tspeed: %d\trange: %d\tposition: %s\n", champion_list[i].name, champion_list[i].hp, champion_list[i].mp, champion_list[i].speed, champion_list[i].range, champion_list[i].position);
	}
}

void FindMaxHp(CHAMPION* champion_list, int champion_cnt)
{
	system("cls");
	int max_hp = 0;
	for (int i = 0; i < champion_cnt; ++i) {
		if (max_hp < champion_list[i].hp)
			max_hp = champion_list[i].hp;
	}

	for (int i = 0; i < champion_cnt; ++i) {
		if (champion_list[i].hp == max_hp)
			printf("name: %s\thp: %d\tmp: %d\tspeed: %d\trange: %d\tposition: %s\n", champion_list[i].name, champion_list[i].hp, champion_list[i].mp, champion_list[i].speed, champion_list[i].range, champion_list[i].position);
	}
}

void SortByHp(CHAMPION* champion_list, int champion_cnt)
{
	system("cls");
	CHAMPION copy_list[MAX_LIST];
	int ci = 0;

	while (ci != champion_cnt)
	{
		int max_hp = 0;
		int max_hp_i = 0;
		for (int i = 0; i < champion_cnt; ++i) {
			if (max_hp < champion_list[i].hp) {
				max_hp = champion_list[i].hp;
				max_hp_i = i;
			}
		}

		memcpy(&copy_list[ci], &champion_list[max_hp_i], sizeof(CHAMPION));
		++ci;

		for (int i = max_hp_i; i < champion_cnt; ++i) {
			memcpy(&champion_list[i], &champion_list[i + 1], sizeof(CHAMPION));
		}
	}

	for (int i = 0; i < champion_cnt; ++i) {
		memcpy(&champion_list[i], &copy_list[i], sizeof(CHAMPION));
	}
}
