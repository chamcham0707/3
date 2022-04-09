#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6054)

#include <stdio.h>
#include <string.h>

#define NAME_SIZE 20
#define POSITION_SIZE 10
#define LIST_SIZE 30

typedef struct champion {
	char name[NAME_SIZE];
	int hp;
	int mp;
	int speed;
	int range;
	char position[POSITION_SIZE];
}CHAMPION;

void menu();
int Insert(CHAMPION*, int);
void PrintAll(CHAMPION*, int);
void Search(CHAMPION*, int);
int Delete(CHAMPION*, int);
int DeleteAll(CHAMPION*, int);
void FindMaxHp(CHAMPION*, int);
void SortByHp(CHAMPION*, int);

int main(void)
{
	CHAMPION list[LIST_SIZE] = {
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
	static int cnt = 20; // 현재 저장된 챔피언의 수

	while (1)
	{
		menu();
		printf("번호를 입력하세요: ");
		scanf("%d", &select);

		switch (select) {
		case 1:
			cnt = Insert(list, cnt);	break;
		case 2:
			Search(list, cnt);	break;
		case 3:
			cnt = Delete(list, cnt);	break;
		case 4:
			PrintAll(list, cnt);	break;
		case 5:
			cnt = DeleteAll(list, cnt);	break;
		case 6:
			FindMaxHp(list, cnt);	break;
		case 7:
			SortByHp(list, cnt);		break;
		}
	}

	return 0;
}

void menu()
{
	printf("=======================================\n");
	printf("1.추가\n2.검색\n3.삭제\n4.전체출력\n5.부분삭제\n6.체력이 가장 큰 챔피언\n7.체력이 큰 챔피언부터 저장\n");
	printf("=======================================\n");
}


int Insert(CHAMPION* list, int cnt)
{
	printf("=======================================\n");
	printf("name: ");
	scanf(" %[^\n]s", &list[cnt].name);
	printf("hp: ");
	scanf(" %d", &list[cnt].hp);
	printf("mp: ");
	scanf(" %d", &list[cnt].mp);
	printf("speed: ");
	scanf(" %d", &list[cnt].speed);
	printf("range: ");
	scanf(" %d", &list[cnt].range);
	printf("position: ");
	scanf(" %s", &list[cnt].position);
	printf("=======================================\n");

	return ++cnt;
}

void PrintAll(CHAMPION* list, int cnt)
{
	printf("=======================================\n");
	if (cnt == 0) {
		printf("등록되어 있는 챔피언이 없습니다.\n");
	}
	for (int i = 0; i < cnt; ++i) {
		printf("%d. ", i + 1);
		printf("name: %s\t\t", list[i].name);
		printf("hp: %d\t", list[i].hp);
		printf("mp: %d\t", list[i].mp);
		printf("speed: %d\t", list[i].speed);
		printf("range: %d\t", list[i].range);
		printf("position: %s\n", list[i].position);
	}
	printf("=======================================\n");
}

void Search(CHAMPION* list, int cnt)
{
	char name[NAME_SIZE];
	int isCham = 0;

	printf("=======================================\n");
	printf("검색할 챔피언의 이름을 입력하세요: ");
	scanf(" %[^\n]s", &name);
	printf("=======================================\n");

	for (int i = 0; i < cnt; ++i) {
		if ((strcmp(name, list[i].name)) == 0) {
			printf("name: %s\t", list[i].name);
			printf("hp: %d\t", list[i].hp);
			printf("mp: %d\t", list[i].mp);
			printf("speed: %d\t", list[i].speed);
			printf("range: %d\t", list[i].range);
			printf("position: %s\n", list[i].position);

			isCham = 1;
		}
	}

	if (isCham == 0) {
		printf("해당 챔피언이 없습니다.\n");
	}
}

int Delete(CHAMPION* list, int cnt)
{
	char name[NAME_SIZE];

	printf("=======================================\n");
	printf("삭제할 챔피언의 이름을 입력하세요: ");
	scanf(" %[^\n]s", &name);
	printf("=======================================\n");

	for (int i = 0; i < cnt; ++i) {
		if ((strcmp(name, list[i].name)) == 0) {
			for (int j = i; j < cnt; ++j) {
				memcpy(&list[j], &list[j + 1], sizeof(CHAMPION));
			}
		}
	}

	return --cnt;
}

int DeleteAll(CHAMPION* list, int cnt) // Delete[position]: 주어진 위치의 모든 챔피언 정보를 삭제한다.
{
	char position[POSITION_SIZE];

	printf("=======================================\n");
	printf("삭제할 position을 입력하세요: ");
	scanf("%s", &position);
	printf("=======================================\n");

	for (int i = 0; i < cnt; ++i) {
		while (strcmp(position, list[i].position) == 0) {
			for (int j = i; j < cnt; ++j) {
				memcpy(&list[j], &list[j + 1], sizeof(CHAMPION));
			}
			--cnt;
		}
	}

	return cnt;
}

void FindMaxHp(CHAMPION* list, int cnt) // 가장 체력이 큰 챔피언의 정보를 출력한다.
{
	int max_hp = 0;
	int cham_i[10] = {0};
	int j = 0;

	for (int i = 0; i < cnt; ++i) {
		if (list[i].hp > max_hp) {
			max_hp = list[i].hp;
			cham_i[j] = i;
			++j;
		}
		else if (list[i].hp == max_hp) {
			cham_i[j] = i;
			++j;
		}
	}

	printf("=======================================\n");
	for (int i = 0; i < j; ++i) {
		printf("name: %s\t", list[cham_i[i]].name);
		printf("hp: %d\t", list[cham_i[i]].hp);
		printf("mp: %d\t", list[cham_i[i]].mp);
		printf("speed: %d\t", list[cham_i[i]].speed);
		printf("range: %d\t", list[cham_i[i]].range);
		printf("position: %s\n", list[cham_i[i]].position);
	}
	printf("=======================================\n");
}

void SortByHp(CHAMPION* list, int cnt) // 체력이 큰 챔피언부터 순서대로 저장한다.
{
	int max_hp = 0;
	CHAMPION max_list[LIST_SIZE] = {0};
	int cham_i = 0;
	int j = 0;
	int _cnt = cnt;

	while (j != cnt)
	{
		// FindMaxHp
		for (int i = 0; i < _cnt; ++i) {
			if (list[i].hp > max_hp) {
				max_hp = list[i].hp;
				cham_i = i;
			}
		}

		// Insert
		max_list[j] = list[cham_i];

		// Delete
		for (int i = cham_i; i < _cnt; ++i) {
			memcpy(&list[i], &list[i + 1], sizeof(CHAMPION));
		}
		--_cnt;

		++j;
		max_hp = 0;
	}

	for (int i = 0; i < cnt; ++i) {
		memmove(&list[i], &max_list[i], sizeof(CHAMPION));
	}
}