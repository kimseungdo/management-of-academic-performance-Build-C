#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int i, j, k;

extern char login_name[10];
extern char mode[10];

void login_logic(); //稽益昔鉢檎

void admin_logic(); //淫軒切 稽送
void professor_logic(); //嘘呪 稽送
void student_logic(); //俳持 稽送

void gotoxy(int x, int y); //疎妊

int main(void) {

	while (1) {
		login_logic();
		while (1) {
			printf("\t\t%s %s還 嬢辞神淑獣神", mode, login_name);

			if (strcmp(mode, "淫軒切") == 0) {
				admin_logic();
				break;
			}
			else if (strcmp(mode, "嘘呪") == 0) {
				system("cls");
				professor_logic();
				break;
			}
			else if (strcmp(mode, "俳持") == 0) {
				student_logic();
				break;
			}
			else {
				printf("\t\n堂携生艦 陥獣幻級埴せせせせせせせせせせせせせせせせせせ");
				Sleep(3000);
				exit(1);
			}
		}
	}


	return 0;
}