#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int i, j, k;

extern char login_name[10];
extern char mode[10];

void login_logic(); //�α���ȭ��

void admin_logic(); //������ ����
void professor_logic(); //���� ����
void student_logic(); //�л� ����

void gotoxy(int x, int y); //��ǥ

int main(void) {

	while (1) {
		login_logic();
		while (1) {
			printf("\t\t%s %s�� ����ʽÿ�", mode, login_name);

			if (strcmp(mode, "������") == 0) {
				admin_logic();
				break;
			}
			else if (strcmp(mode, "����") == 0) {
				system("cls");
				professor_logic();
				break;
			}
			else if (strcmp(mode, "�л�") == 0) {
				student_logic();
				break;
			}
			else {
				printf("\t\nƲ������ �ٽø����������������������������������������");
				Sleep(3000);
				exit(1);
			}
		}
	}


	return 0;
}