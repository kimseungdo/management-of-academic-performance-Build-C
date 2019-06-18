#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#include "Student_Info_Structer.h"
#include "logINFO_Structer.h"

int i, j;
int change_count; //��� ����Ƚ���� Ȯ���ϱ����� ��������

extern char login_name[10];
extern char mode[10];
extern int total_size; //�����ڰ� ������ ���� ��üũ��.
extern int stucheckcount;
extern int procheckcount;

int input_count;//�Է� �л� ī����
int input_grade_count;//�Է� �л� ���� ī����
int add_count;//�߰� �л� ī����
int add_grade_count;//�߰� �л� ���� ī����
int load_count;//�ε� �л� ī����
int load_grade_count;//�ε��л� ���� ī����

extern load_count;
void gotoxy(int x, int y); //��ǥ

//int load_program_data(struct load_size); //��ȯ�� �л���
void change_mypass();//0�� ����ٲٱ�
void inputTHEstudent(struct student *, struct student_info *); //1�� ����ü ������, �迭 0��° ����, ������ �Է��ϰڴٰ� �� �л���
void inputTHEgrade(struct student *s, struct student_info *si); //2�� �л� �����Է�
void add_student(struct student *, struct student_info *, struct add_student *, struct add_student_info *); //3�� �л��߰�
void showNsort(struct student *, struct student_info *, struct add_student *, struct add_student_info *, struct grade_info *g); //4�� ���, ����
void changeTHEstudent(struct student *, struct student_info *, struct add_student *, struct add_student_info *, struct grade_info *g); //5�� ���, ����
void input_file(struct student *, struct student_info *, struct add_student *, struct add_student_info *, struct grade_info *g); //6�� ���Ͽ� �Է� ���ÿ� �л� ������ ���� ���̵�� �̸� ��й�ȣ�� �й�

void input_setgrade(struct student *, struct grade_info *g); //�л� �Է��� ��޺ο�
void add_setgrade(struct add_student *, struct grade_info *g); //�л� �Է��� ��޺ο�
//void load_setgrade(struct load_student *, struct load_grade_info *g); //�л� �Է��� ��޺ο�

void load_file();//6�� �л����� �ҷ����°�

void professor_logic() {

	time_t curr;
	struct tm *d;
	curr = time(NULL);
	d = localtime(&curr);

	FILE *isp = fopen(".\\login_file\\student_info.txt", "r");
	struct student_info *info_student;//�л�����
	info_student = malloc(sizeof(struct student_info)*10);//�����ڰ� ������ ����ŭ ����ü������ �����Ҵ� 100��
	i = 0;
	while (i < stucheckcount) {
		if (feof(isp)) break;
		info_student[i].name = (char*)malloc(sizeof(char) * 10);
		info_student[i].pass = (char*)malloc(sizeof(char) * 30);
		fscanf(isp, "%s %s", info_student[i].name, info_student[i].pass);
		//printf("%s\n %s\n", sp[i].name, sp[i].pass);
		//Sleep(1000);
		i++;
	}fclose(isp);

	struct student *profile;//���α׷��� �Է��� �л� ����
	profile = malloc(sizeof(struct student)*10);//�����ڰ� ������ ����ŭ ����ü������ �����Ҵ� 300��
	i = 0;
	while(i<stucheckcount) {//����ü ���� ���� �����Ҵ� ����
		profile[i].name = (char*)malloc(sizeof(char) * 10);
		profile[i].kor = (char*)malloc(sizeof(char) * 10);
		profile[i].eng = (char*)malloc(sizeof(char) * 10);
		profile[i].mat = (char*)malloc(sizeof(char) * 10);
		i++;
	}

	struct add_student_info *info_add_student;//�л�����
	info_add_student = malloc(sizeof(struct add_student_info) * 10);//�����ڰ� ������ ����ŭ ����ü������ �����Ҵ� 10��
	for (i = 0; i < 10; i++) {//����ü ���� ���� �����Ҵ� ����
		info_add_student[i].name = (char*)malloc(sizeof(char) * 10);
		info_add_student[i].pass = (char*)malloc(sizeof(char) * 20);
	}

	struct add_student *add_profile;//�߰��� �л� ����
	add_profile = malloc(sizeof(struct student)*10);//�����ڰ� ������ ����ŭ ����ü������ (ntdll.dll)��(suckcess.exe��) ó������ ���� ���ܰ� �ֽ��ϴ�. 0xC0000374: ���� �ջ�Ǿ����ϴ�(�Ű� ����: 0x0000000077C67C70).

	for (i = 0; i < 10; i++) {//����ü ���� ���� �����Ҵ� ����
		add_profile[i].name = (char*)malloc(sizeof(char) * 10);
		add_profile[i].kor = (char*)malloc(sizeof(char) * 10);
		add_profile[i].eng = (char*)malloc(sizeof(char) * 10);
		add_profile[i].mat = (char*)malloc(sizeof(char) * 10);
	}

	struct grade_info *grade;
	grade = malloc(sizeof(struct grade_info) * 10);
	i = 0;
	while (i < stucheckcount) {//����ü ���� ���� �����Ҵ� ����
		grade[i].subK = (char*)malloc(sizeof(char) * 10);
		grade[i].subE = (char*)malloc(sizeof(char) * 10);
		grade[i].subM = (char*)malloc(sizeof(char) * 10);
		grade[i].totG = (char*)malloc(sizeof(char) * 10);
		i++;
	}

	/*
		struct load_student_info *info_load_student;
	info_load_student = malloc(sizeof(struct student)*total_size);
	FILE *fp = fopen(".\\login_file\\student_info.txt", "r");
	while (!feof(fp)) {//�л������� ������ �о���� �ο��� �ľ�
		fscanf(fp, "%d %s %s", &info_load_student[i].sid, info_load_student[i].name, info_load_student[i].pass);
		i++;//����ü���� ���ֱ����ؼ� ���
		load_count++;//�����鼭 ����ִ��� ����
	}fclose(fp);
	*/

	/*FILE *fp = fopen(".\\login_file\\student_info.txt", "r");
	struct load_student_info *info_load_student;
	info_load_student = malloc(sizeof(struct student)*10);//���Ͼ� �ο�����ŭ �Ҵ�
	for (i = 0; i < 10; i++) {//����ü ���� ���� �����Ҵ� ����
		info_load_student[i].name = (char*)malloc(sizeof(char) * 10);
		info_load_student[i].pass = (char*)malloc(sizeof(char) * 20);
		fscanf(fp, "%s %s", info_load_student[i].name, info_load_student[i].pass);
	}	fclose(fp);


	FILE *zp = fopen("student.txt", "r");
	struct load_student *load_profile;
	load_profile = malloc(sizeof(struct student)*10);//
	for (i = 0; i < 10; i++) {//����ü ���� ���� �����Ҵ� ����
		load_profile[i].name = (char*)malloc(sizeof(char) * 10);
		load_profile[i].kor = (char*)malloc(sizeof(char) * 10);
		load_profile[i].eng = (char*)malloc(sizeof(char) * 10);
		load_profile[i].mat = (char*)malloc(sizeof(char) * 10);
		fscanf(zp, "%s %s %s %s \n",
			(load_profile + i)->name, (load_profile + i)->kor, (load_profile + i)->eng,
			(load_profile + i)->mat); //�̸�, ����, ����, ���� ������ ����. �� �̻��� ����
		load_grade_count++;
	}	fclose(zp);*/
	
	input_count = 0;
	input_grade_count = 0;
	add_count = 0;//�߰� �л� ī����
	add_grade_count = 0;//�߰� �л� ���� ī����
	int input_info = 0;

	while (1) {
		int ch; //���ù�

		printf("\t\t����ð��� %d��%d��%d�� �̹��ϴ�.\n", d->tm_hour, d->tm_min, d->tm_sec);
		printf("\t\t���� %d���� �л��� �Է��Ҽ� �ֽ��ϴ�.\n", total_size);

		gotoxy(12, 4);   printf("����ʽÿ� %s %s�� ������ �Ͻðڽ��ϱ�?", login_name, mode);
		//gotoxy(22, 5);   printf("0. ��й�ȣ ����"); //void chang_mypass();
		gotoxy(22, 6);   printf("1. �л� �������� �����");
		gotoxy(22, 7);   printf("2. �л� ���� �Է�");
		gotoxy(22, 8);	 printf("3. �л� �߰�");
		gotoxy(22, 9);   printf("4. �л� ���� ��ȸ ");
		gotoxy(22, 10);  printf("5. �л� ���� ����");
		gotoxy(22, 11);  printf("6. �л� ���� ���Ͽ� �Է�"); //�Էµ��л� �߰����л� 
		gotoxy(22, 12);  printf("7. �α׾ƿ�");
		gotoxy(22, 13);  printf("8. ���α׷�  ����");

		/*
		void inputTHEstudent(struct student *, struct student_info *); //1�� ����ü ������, �迭 0��° ����, ������ �Է��ϰڴٰ� �� �л���
		void setgrade(struct student *, struct add_student *); //�л� �Է��� ��޺ο�
		void inputTHEgrade(struct student *, struct student_info *) //2�� �л� �����Է�
		void changeTHEstudent(struct student *, struct add_student *, struct student_info *); //3�� �л� ��������
		void add_student(struct student *, int formal, int last); //4�� �л� �߰�
		void showNsort(struct student *, int formal, int last); //5�� �л� �������
		void input_file(struct student *, int formal, int last); //5�� ���Ͽ� �Է� ���ÿ� �л� ������ ���� ���̵�� �̸� ��й�ȣ�� �й�
		void load_file();//6�� �л����� �ҷ����°�
		*/
		gotoxy(22, 15);  printf("type nomber: "); scanf("%d", &ch);
		fflush(stdin);
		system("cls");

		switch (ch) {

			/*case 0: //�� ��й�ȣ ����

				change_mypass();
				break;
			*/
			case 1: //�л� �Է�

				system("cls");
				if (input_info == 0) {
					input_info = 1;
					inputTHEstudent(profile, info_student);
					//setgrade(profile, add_profile);
				}
				else {//�л����� ���� �ѹ��Է�
					gotoxy(22, 17); printf("������ �ѹ��� �Է� �����մϴ� ���� �߰��� �ϼ���.");
					break;
				}
				system("cls");
				continue;

			case 2: //�л� �����Է�

				system("cls");
				if (input_info == 1) {//�л� �̸��� �Է��ؾ߸� ������ �Է��Ҽ� �ִ�.
					inputTHEgrade(profile, info_student);
					input_setgrade(profile, grade);
					continue;
				}
				else {//�л����� ���� �ѹ��Է�
					gotoxy(22, 17); printf("�л��� �Է��ؾ� �����Է��� �����մϴ�.");
					Sleep(2500);
					continue;
				}
				system("cls");
				continue;

			case 3: //�л� ���� �߰�

				system("cls");
				add_student(profile, info_student, add_profile, info_add_student);
				add_setgrade(add_profile, grade);

				system("cls");
				continue;

			case 4: //�л� �������� ��� �л� ����Ʈ ��� ���� ���� �����ϱ�
				
				showNsort(profile, info_student, add_profile, info_add_student, grade);
				system("cls");
				continue;

			case 5: //�л� ���� ���� 1.�̸����� 2.�������� 3.�л����� 4.����
					//�Է��л� ���� �߰��л� ���� �Էµ� �л� ����
				changeTHEstudent(profile, info_student, add_profile, info_add_student, grade);
				system("cls");
				continue;

			case 6: //�л� ���Ͽ� ���� ����
					//�Է��л� ����W �߰��л�A �Էµ� �л�����
				input_file(profile, info_student, add_profile, info_add_student, grade);
				system("cls");
				continue;

			case 7: //�α׾ƿ�

				fflush(stdin);
				free(profile);
				free(info_student);
				free(add_profile);
				free(info_add_student);

				gotoxy(14, 8); printf("�α׾ƿ� �˴ϴ�.");
				Sleep(1500);
				system("cls");

				return 0;
				break;

			case 8: //���α׶� ����

				fflush(stdin);
				free(profile);
				free(info_student);
				free(add_profile);
				free(info_add_student);
				system("cls");
				exit(0);
				break;

			default:

				system("cls");
				gotoxy(22, 17); printf("ERROR :1���� 8���� ���ڸ� �Է��ϼ���\n");
				break;
			}
	}
}