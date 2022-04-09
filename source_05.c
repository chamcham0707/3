#define _CRT_SECURE_NO_WARNINGS // testing
#pragma warning(disable: 6031)

#include <stdio.h>
#include <string.h>
#include <malloc.h>

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
	CHAMPION* next;
}CHAMPION;

//typedef struct NODE { // ���� ����Ʈ�� ��� ����ü
//	NODE* next; // ���� ����� �ּҸ� ������ ������
//	CHAMPION data; // �����͸� ������ ���
//}NODE;

void Array2LinckedList(CHAMPION*);
void menu();
CHAMPION Search(CHAMPION*, int, const char*);
void Insert(CHAMPION*, int);
void Delete(CHAMPION*, int, const char*);
void DeleteAll(CHAMPION*, int, const char*);
void PrintAll(CHAMPION*, int);
int FindMaxHp(CHAMPION*, int);
CHAMPION* SortByHp(CHAMPION*, int);

int main()
{
	CHAMPION champion_list[MAX_LIST] = {
		{"����", 620, 0, 340, 175, "top"},
		{"������", 562, 500, 335, 125, "mid"},
		{"����", 515, 231, 330, 550, "bot"},
		{"Ƽ��", 528, 267, 330, 500, "top"},
		{"�Ҷ�ī", 535, 425, 325, 550, "support"},
		{"����", 585, 275, 345, 125, "jungle"},
		{"����ũ��ũ", 582, 267, 325, 125, "support"},
		{"��", 532, 268, 335, 525, "top"},
		{"���縮�콺", 620, 0, 350, 500, "bot"},
		{"�ú�", 530, 300, 325, 350, "bot"},
		{"�𸣰���", 500, 350, 320, 550, "support"},
		{"�ڸ�Ű", 550, 450, 125, 330, "mid"},
		{"�� ��", 619, 0, 350, 250, "jungle"},
		{"����Ÿ �۶�ũ", 500, 235, 330, 125, "support"},
		{"�ڸ�Ű", 500, 340, 330, 500, "mid"},
		{"�ٵ�", 490, 300, 330, 300, "support"},
		{"�ٷ罺", 510, 250, 345, 570, "bot"},
		{"��", 620, 0, 330, 200, "top"},
		{"�ֽ�", 500, 350, 330, 500, "bot"},
		{"������", 550, 400, 325, 400, "mid"},
	};

	int select;
	while (1) {
		menu();
		printf("Input number: ");
		scanf("%d", &select);
		printf("\n");

		char search_name;
		char delete_name;
		char del_position;
		int max_hp;
		CHAMPION* sort_list;
		switch (select)
		{
		case 1:
			printf("�˻��� è�Ǿ� �̸�: ");
			scanf(" %[^\n]s", &search_name);
			CHAMPION search_find = Search(champion_list, MAX_LIST, &search_name);
			printf("name: %s\thp: %d\tmp: %d\tspeed: %d\trange: %d\tposition: %s\n", search_find.name,
				search_find.hp, search_find.mp, search_find.speed,
				search_find.range, search_find.position);
			break;
		case 2:
			Insert(champion_list, MAX_LIST); break;
		case 3:
			printf("������ è�Ǿ� �Է�: ");
			scanf(" %[^\n]s", &delete_name);
			Delete(champion_list, MAX_LIST, &delete_name);
			break;
		case 4:
			printf("������ position �Է�: ");
			scanf("%s", &del_position);
			DeleteAll(champion_list, MAX_LIST, &del_position);
			break;
		case 5:
			PrintAll(champion_list, MAX_LIST); break;
		case 6:
			max_hp = FindMaxHp(champion_list, MAX_LIST);
			for (int i = 0; i < MAX_LIST; ++i) {
				if (champion_list[i].hp == max_hp)
					printf("name: %s\thp: %d\tmp: %d\tspeed: %d\trange: %d\tposition: %s\n", 
						champion_list[i].name, champion_list[i].hp, champion_list[i].mp,
						champion_list[i].speed, champion_list[i].range, champion_list[i].position);
			}
			break;
		case 7:
			sort_list = SortByHp(champion_list, MAX_LIST);
			PrintAll(champion_list, MAX_LIST); break;
		}
	}
	return 0;
}

void Array2LinckedList(CHAMPION* champion_list)
{
	CHAMPION* head = champion_list;

	champion_list->next = champion_list + 1;
}

void menu()
{
	printf("\n1.Search\t2.Insert\t3.Delete\t4.DeleteAll\t5.PrintAll\t6.FindMaxHp\t7.SortByHp\n");
}

CHAMPION Search(CHAMPION* champion_list, int max_list, const char* search_name)
{
	if (0 == max_list)
		return;
	else if (strcmp(search_name, champion_list[MAX_LIST - max_list].name) == 0)
		return champion_list[MAX_LIST - max_list];
	else
		Search(champion_list, max_list - 1, search_name);
}

void Insert(CHAMPION* champion_list, int max_list)
{
	if (champion_list[MAX_LIST - max_list].hp == 0) {
		printf("name: ");
		scanf("%s", &champion_list[MAX_LIST - max_list].name);
		printf("hp: ");
		scanf("%d", &champion_list[MAX_LIST - max_list].hp);
		printf("mp: ");
		scanf("%d", &champion_list[MAX_LIST - max_list].mp);
		printf("speed: ");
		scanf("%d", &champion_list[MAX_LIST - max_list].speed);
		printf("range: ");
		scanf("%d", &champion_list[MAX_LIST - max_list].range);
		printf("position: ");
		scanf("%s", &champion_list[MAX_LIST - max_list].position);
	}
	else 
		Insert(champion_list, max_list - 1);
}

void Delete(CHAMPION* champion_list, int max_list, const char* delete_name)
{
	if (0 == max_list)
		printf("�ش� è�Ǿ��� �����ϴ�.");
	else if (strcmp(delete_name, champion_list[MAX_LIST - max_list].name) == 0)
		champion_list[MAX_LIST - max_list].hp = 0;
	else
		Delete(champion_list, max_list - 1, delete_name);
}

void DeleteAll(CHAMPION* champion_list, int max_list, const char* del_position)
{
	if (0 == max_list)
		return;
	else if (strcmp(champion_list[MAX_LIST - max_list].position, del_position) == 0) {
		champion_list[MAX_LIST - max_list].hp = 0;
		DeleteAll(champion_list, max_list - 1, del_position);
	}
	else
		DeleteAll(champion_list, max_list - 1, del_position);
}

void PrintAll(CHAMPION* champion_list, int max_list)
{
	if (0 == max_list)
		return;
	else if (champion_list[MAX_LIST - max_list].hp != 0) {
		printf("name: %s\thp: %d\tmp: %d\tspeed: %d\trange: %d\tposition: %s\n",
			champion_list[MAX_LIST - max_list].name, champion_list[MAX_LIST - max_list].hp, champion_list[MAX_LIST - max_list].mp,
			champion_list[MAX_LIST - max_list].speed, champion_list[MAX_LIST - max_list].range, champion_list[MAX_LIST - max_list].position);
		PrintAll(champion_list, max_list - 1);
	} else
		PrintAll(champion_list, max_list - 1);
}

int FindMaxHp(CHAMPION* champion_list, int max_list)
{
	static int max_hp = 0;
	if (0 == max_list) {
		int temp = max_hp;
		max_hp = 0;
		return temp;
	} else if (champion_list[MAX_LIST - max_list].hp > max_hp) {
		max_hp = champion_list[MAX_LIST - max_list].hp;
		FindMaxHp(champion_list, max_list - 1);
	} else
		FindMaxHp(champion_list, max_list - 1);
}

CHAMPION* SortByHp(CHAMPION* champion_list, int max_list)
{
	if (0 == max_list)
		return champion_list;

	for (int i = 0; i < max_list - 1; ++i) {
		if (champion_list[i].hp < champion_list[i + 1].hp) {
			CHAMPION champion_temp = champion_list[i];
			champion_list[i] = champion_list[i + 1];
			champion_list[i + 1] = champion_temp;
		}
	}

	SortByHp(champion_list, max_list - 1);
}
