#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <io.h>

#include "logINFO_Structer.h"
#include "Student_Info_Structer.h"
int i, j;
int total_size = 300; //�л��� 300��
int professor_size = 10; //������ 10��

extern char login_name[10];
extern char mode[10];
extern int login_count;

void gotoxy(int x, int y);
void input_professor_info(); //1. ���Ͽ� ��������
//void load_professor_info(struct professor *, int formal, int last); //1-1. �������� �ҷ�����
void setting_program(struct program *);//3.�л� ��������
void list_dir(); //4.���ϸ�� �ҷ���
void load_student_info(); //�л����� �ҷ�����

void admin_logic() {

	time_t curr;
	struct tm *d;
	curr = time(NULL);
	d = localtime(&curr);

	struct program *total_s; //�л��� �ο��� ������ ����ü������ ����
	total_s = malloc(sizeof(struct program) * sizeof(int));
	
	while (1) {
		int ch; //���ù�
		system("cls");

		printf("\t\t����ð��� %d��%d��%d�� �Դϴ�.\n", d->tm_hour, d->tm_min, d->tm_sec);

		gotoxy(12, 5);   printf("����ʽÿ� %s %s�� ������ �Ͻðڽ��ϱ�?", mode, login_name);
		gotoxy(22, 6);   printf("1. ���� ���� ����");
		gotoxy(22, 7);   printf("2. �л� ���� ����");
		gotoxy(22, 8);   printf("3. �α׾ƿ�");
		gotoxy(22, 9);   printf("4. ���α׷� ����");

		gotoxy(22, 14);  printf("type nomber: "); scanf("%d", &ch);
		fflush(stdin);
		system("cls");
		
		switch (ch) {
			case 1: //�������� ����
					//������� ���� ���� �߰�
				input_professor_info();
				break;

			case 2: //�л����� ����
					//������� ���� ���� �߰�
				load_student_info();
				break;

			case 3: //�α׾ƿ�

					free(total_s);
					gotoxy(14, 8); printf("�α׾ƿ� �˴ϴ�.");
					Sleep(1500);

				//login_logic(); // �ٽ� �α����Լ� ȣ�� �ٵ� ���⼭ ������ ����
				return 0;
				break;

			case 4: //���α׶� ����

				free(total_s);
				fflush(stdin);
				exit(0);
				break;

			default:

				gotoxy(22, 15); printf("ERROR :1���� 5���� ���ڸ� �Է��ϼ���\n");
				break;

			}
	}

}
