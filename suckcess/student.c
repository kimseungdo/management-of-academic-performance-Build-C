#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#include "logINFO_Structer.h"
#include "Student_Info_Structer.h"
int i, j;

extern char login_name[10];
extern char mode[10];
extern int stucheckcount;
extern int procheckcount;
extern int load_grade_count;

void gotoxy(int x, int y);
void search_myinfo(struct load_student *, struct load_student_info *, struct grade_info *, int last);
void load_setgrade(struct load_student *, struct grade_info *g, int load_grade_count); //�л� �Է��� ��޺ο�
void plz_give_AP();

void student_logic() {


	load_grade_count = 0;
	int line = 0;
	char c;
	FILE *fp = fopen(".\\login_file\\student_info.txt", "r");
	while ((c = fgetc(fp)) != EOF) {
		if (c == '\n')       line++;//�����鼭 ����ִ��� ����
	}//���Ͽ� ����ִ��� ����
	fclose(fp);

	FILE *pp = fopen("student.txt", "r");
	struct load_student *load_profile; //���� ���� ����ü ����
	load_profile = malloc(sizeof(struct load_student)*line);
	i = 0;
	while (1) {
		if (feof(pp)) break;
		load_profile[i].name = (char*)malloc(sizeof(char) * 10);
		load_profile[i].kor = (char*)malloc(sizeof(char) * 10);
		load_profile[i].eng = (char*)malloc(sizeof(char) * 10);
		load_profile[i].mat = (char*)malloc(sizeof(char) * 10);
		load_profile[i].sum = (int*)malloc(sizeof(int) * 10);
		//load_profile[i].avg = (double *)malloc(sizeof(double) * 10);
		fscanf(pp, "%s %s %s %s %d %lf\n", load_profile[i].name, load_profile[i].kor, load_profile[i].eng, load_profile[i].mat, &load_profile[i].sum, &load_profile[i].avg);
		//printf("%s %s %s %s\n", load_profile[i].name, load_profile[i].kor, load_profile[i].eng, load_profile[i].mat);
		load_grade_count++;
		i++;
	}fclose(pp);

	struct grade_info *grade;//��޺� ����ü ����
	grade = malloc(sizeof(struct grade_info) * line);
	i = 0;
	while (i < line) {//����ü ���� ���� �����Ҵ� ����
		grade[i].subK = (char*)malloc(sizeof(char) * 10);
		grade[i].subE = (char*)malloc(sizeof(char) * 10);
		grade[i].subM = (char*)malloc(sizeof(char) * 10);
		grade[i].totG = (char*)malloc(sizeof(char) * 10);
		i++;
	}

	FILE *ap = fopen(".\\login_file\\student_info.txt", "r");
	struct load_student_info *info_load_student; //���̵� ��й�ȣ ����
	info_load_student = malloc(sizeof(struct load_student_info)*10);
	i = 0;
	while(1) {
		if (feof(ap)) break;
		info_load_student[i].name = (char*)malloc(sizeof(char) * 10);
		info_load_student[i].pass = (char*)malloc(sizeof(char) * 30);
		fscanf(ap, "%s %s\n", info_load_student[i].name, info_load_student[i].pass);
		//printf("%s %s\n", info_load_student[i].name, info_load_student[i].pass);
		i++;
	}fclose(ap);
	load_setgrade(load_profile, grade, load_grade_count);




	while (1) {
		int ch; //���ù�
		system("cls");
		/*
		printf("������\n");
		for (i = 0; i < line; i++) {
		   printf("%d ��°�� %s %s %s %s\n", i, load_profile[i].name, load_profile[i].kor, load_profile[i].eng, load_profile[i].mat);
		}
		printf("�α��κ�\n");
		for (i = 0; i < line; i++) {
		   printf("%s %s\n", info_load_student[i].name, info_load_student[i].pass);
		}
		*/
		gotoxy(12, 5);   printf("����ʿ� %s %s�� ������ �Ͻðڽ��ϲ�?", mode, login_name);
		gotoxy(22, 6);   printf("1. ���� ��ȸ�ϱ�");
		gotoxy(22, 7);   printf("2. �α׾ƿ�");
		gotoxy(22, 8);   printf("3. ���α׷� ����");
		gotoxy(22, 9);   printf("4. A+�޶�� �ɸ���");

		gotoxy(22, 14);  printf("type nomber: "); scanf("%d", &ch);
		fflush(stdin);
		system("cls");

		switch (ch) {
		case 1: //������ ��ȸ

			search_myinfo(load_profile, info_load_student, grade, line);
			break;

		case 2:
			free(load_profile);
			free(info_load_student);
			free(grade);
			fflush(stdin);
			gotoxy(14, 8); printf("�α׾ƿ� �˴ϴ�.");
			Sleep(1500);
			system("cls");

			return 0;
			break;
			/*case 2: //A+ �޶�� �ɸ���

			   break;

			case 3: //���޶�� �ɸ���

			   break;

			case 4: //���н�û

			   break;

			case 5: //�����û


			   break;
			*/
		case 3: //���α׶� ����

			free(load_profile);
			free(info_load_student);
			free(grade);
			fflush(stdin);
			exit(0);
			break;

		case 4:

			plz_give_AP();
			break;

		default:

			gotoxy(22, 15); printf("ERROR :1���� 6���� ���ڸ� �Է��ϼ���\n");
			break;

		}
	}
}