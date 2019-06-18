#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int i, j, k;

extern char login_name[10];
extern char mode[10];

void login_logic(); //로그인화면

void admin_logic(); //관리자 로직
void professor_logic(); //교수 로직
void student_logic(); //학생 로직

void gotoxy(int x, int y); //좌표

int main(void) {

	while (1) {
		login_logic();
		while (1) {
			printf("\t\t%s %s님 어서오십시오", mode, login_name);

			if (strcmp(mode, "관리자") == 0) {
				admin_logic();
				break;
			}
			else if (strcmp(mode, "교수") == 0) {
				system("cls");
				professor_logic();
				break;
			}
			else if (strcmp(mode, "학생") == 0) {
				student_logic();
				break;
			}
			else {
				printf("\t\n틀렸으니 다시만들엌ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ");
				Sleep(3000);
				exit(1);
			}
		}
	}


	return 0;
}