#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#include "Student_Info_Structer.h"
#include "logINFO_Structer.h"

//#define _CRT_SECURE_NO_WARNINGS
int i, j;
void gotoxy(int x, int y); //��ǥ
char name[10];


extern int total_size;
extern int change_count;
extern char login_name[10];
extern char mode[10];
extern int stucheckcount;
extern int procheckcount;


extern input_count;//�л� �Է��� ī����
extern input_grade_count;//�л� �����Է� ī����
extern add_count;//�߰� �л� ī����
extern add_grade_count;//�߰� �л� ���� ī����
extern load_count;//�ε� �л� ī����
extern load_grade_count;//�ε��л� ���� ī����

void load_setgrade(struct load_student *, struct grade_info *g, int load_grade_count);

void change_mypass() { //0��
	/*        .\\login_file\\professor_info.txt
		gotoxy(20, 14);   printf("���� �̸��� �ٲܲ���? ");  scanf("%s", change_name);
			for (i = formal; i < last; i++) {
				if (strcmp((os + i)->name, change_name) == 0) { //�̸��� �ٲٱ� ���� �̸��˻�
					gotoxy(20, 15); printf("���� �ٲܳ���? : ");
					scanf("%s", (os + i)->name);
					change_count++;
					//strcpy((os + i)->name, change_name); �̰��ϸ� ã�� �̸����� �ٽ� �ٲ�� �ȴ�.
				}
	*/
	char now_pass[20];

	FILE *fp = fopen(".\\login_file\\professor_info.txt", "r+");    //
	char buffer[10] = { 0, };    // ���ڿ� ������ 4����Ʈ NULL 1����Ʈ. 4 + 1 = 5
	int count = 0;
	int total = 0;

	/*
	while (feof(fp) == 0) {    // ���� �����Ͱ� ������ ���� �ƴ� �� ��� �ݺ�
		count = fread(buffer, sizeof(char), 4, fp);    // 1����Ʈ�� 4��(4����Ʈ) �б�
		printf("\t%s", buffer);                          // ���� ���� ���
		memset(buffer, 0, 5);                          // ���۸� 0���� �ʱ�ȭ
		total += count;                                // ���� ũ�� ����
	}	
	*/


	struct load_professor *lp;//����ü ������ ����
	lp = malloc(sizeof(struct load_professor) * total);//�����ڰ� ������ ����ŭ ����ü������ �����Ҵ�
	for (i = 0; i < total; i++) {
		lp[i].name = (char*)malloc(sizeof(char) * 10);
		lp[i].pass = (char*)malloc(sizeof(int) * 10);
	}

	i = 0;
	while (!feof(fp)) {
		fscanf(fp, "%s %s\n", lp[i].name, lp[i].pass);
		printf("%s %s\n", lp[i].name, lp[i].pass);
		count++; //���� ��ü ũ��˷��� ����?
		i++;
	}

	for (i = 0;  i < total; i++) {
		if (strcmp(lp[i].name, login_name) == 0) {
			printf("���� ��й�ȣ �Է����ּ�"); scanf("%s", now_pass);
			if (strcmp(now_pass, lp[i].pass) == 0) {
				printf("�ٲ� ��й�ȣ �Է����ּ�"); scanf("%s", (lp + i)->pass);
			}
		}
	}

	for (i = 0; i < count; i++) {
		fprintf(fp, "%s %s", lp[i].name, lp[i].pass);
	}fclose(fp);
	free(lp);
	fflush(stdin);
}

/*int load_program_data(struct load_size *ss, int total_size) {//�л� �ο��� �ҷ�����

	FILE *sp = fopen("set_program.txt", "r"); //�б���
	if (sp == NULL) {
		system("cls");
		gotoxy(20, 8); printf("���ȿ��Ȱ� �߰��ð�");
		exit(0);
	}
	fscanf(sp, "%d", total_size);
	return total_size;
}*/

void inputTHEstudent(struct student *is, struct student_info *iss) { //1. input_student �л� �Է� (is����, iss����) 

	//input_count = 0;
	j = 0;
	i = 0;
	int k;

	time_t now;
	now = time(NULL);
	srand(time(NULL));

	while (1) {
			int breakcheck = 0;

			printf("���� ���������� �Էµ� �л��Դϴ�\n");
			printf("�̸�\n");
			for (k = 0; k < stucheckcount; k++) {
				printf("%s\n", (iss + k)->name);
			}
			printf("���� ���������� ������� �л��Դϴ�\n");
			printf("�̸�\n");
			for (k = 0; k < input_count; k++) {
				printf("%s\n", (is + k)->name);
			}
			
			printf("���������� ���� �л� (�Է����� quit) :"); //�л� �Է�
			fflush(stdin);
			scanf("%s", (is + i)->name); fflush(stdin);
			Sleep(1000);
			if (strcmp((is + i)->name, "quit") == 0) { //������� �ϸ� �̸��� ���������ʰ� ����
				is[i].name = NULL;
				break;
			}

			else { //�˻縦 �հ� �����Է��̸� �й���
				for (j = 0; j < 10; j++) {//���ڿ��˻�
					if ((int)(is + i)->name[j] > 65 && (int)(is + i)->name[j] < 122) {
						gotoxy(17, 15); printf("ERROR : �������� �ƴϹ��ϴ� �ٽ� �Է����̼�\n");
						Sleep(1000);
						breakcheck++;
						break;
					}
					else if (strlen((is + i)->name) == 0) {
						gotoxy(17, 15); printf("ERROR : �Է��� ���ѰŰ������̴� �ٽ� �з����̼�\n");
						Sleep(1000);
						breakcheck++;
						break;
					}
					else if (strlen((is + i)->name) > 6) {
						gotoxy(17, 15); printf("ERROR : �̸��� ��״� �������� �ƴѰ� �������̴� �ٽ� �Է��ϼ�\n");
						Sleep(1000);
						breakcheck++;
						break;
					}
				}//���ڿ� �˻簡 �������� 

				if (breakcheck != 0) {
					system("cls");
					continue;
				}
				strcpy(iss[i].name, is[i].name); //�Է����̸� �л������� ����
				//int random = rand();
				//iss[i].sid = now; //�л������� �й��ο�
				strcpy(iss[i].pass, "1234"); //�л������� ��й�ȣ �ο� �ʱ��ȣ�� 1234�ϱ�
				printf("%s �л��� ���������Ͱ� ����������ϴ�.", (is + i)->name);
				Sleep(1000);
				i++;
				input_count++;
				system("cls");
			}

		
	}
}

void inputTHEgrade(struct student *s, struct student_info *si) {//2�� �л� �����Է� (s����, si����)
	//input_grade_count = 0;

	while (1) {
		char name[10];
		int breakcheck = 0;

		printf("%s���� �Է��� �л����Դϴ�.\n", login_name);
		printf("�̸�    �����Է¿��� \n");
		for (i = 0; i < input_count; i++) {
			printf("%s", s[i].name);
			if (atoi((s + i)->kor) > 0 && atoi((s + i)->kor) <= 100) {//0~100����
				printf("       (O) \n");
			}
			else {
				printf("       (X) \n");
			}
		}

		printf("\n� �л� ������ �Է��Ͻðڽ��ϱ� (�Է����� quit) : "); scanf("%s", name);
		if (strcmp(name, "quit") == 0) { //quit�ԷµǸ� ������
			system("cls");
			break;
		}
		else {//���ᰡ �ƴϸ� ���ڿ��˻�
			for (j = 0; j < 10; j++) {
				if ((int)name[j] > 65 && (int)name[j] < 122) {
					//system("cls");
					printf("ERROR : �������� �ƴϹ��ϴ� �ٽ� �Է����̼�\n");
					Sleep(1000);
					breakcheck++;
					break;
				}
				else if (strlen(name) == 0) {
					//system("cls");
					printf("ERROR : �Է��� ���ѰŰ������̴� �ٽ� �з����̼�\n");
					Sleep(1000);
					breakcheck++;
					break;
				}
				else if (strlen(name) > 6) {
					//system("cls");
					printf("ERROR : �̸��� ��״� �������� �ƴѰ� �������̴� �ٽ� �Է��ϼ�\n");
					Sleep(1000);
					breakcheck++;
					break;
				}
			}
		}//���ڿ� �˻簡 �����ٸ�
		
		for (i = 0; i < input_count; i++) {
			if (strcmp(name, s[i].name) == 0) {//���ڿ� �˻簡 ������ ������ �Է��� �л��� ��ġ�ϸ�
				while (1) {
					printf("\n\n%s�л��� ���������� �Է����ּ��� ", s[i].name); scanf("%s", (s + i)->kor);
					int korscore = atoi((s + i)->kor);
					if (korscore < 0 || korscore > 100) {//0~100����
						printf("�߸� �ԷµǾ����ϴ�. �ٽ� �Է��ϼ���\n");
					}
					else if (isStringDouble((s + i)->kor) == 0) {//���� �̿��� ����
						printf("�߸� �ԷµǾ����ϴ�. �ٽ� �Է��ϼ���\n");
					}
					else {//�������� �Էµǰ� ���ڰ� �Է¾ȵǸ� Ż��
						break;
					}
				}
				while (1) {
					printf("%s�л��� ���������� �Է����ּ��� ", s[i].name); scanf("%s", (s + i)->eng);
					int englishscore = atoi((s + i)->eng);
					if (englishscore < 0 || englishscore > 100) {//0~100����
						printf("�߸� �ԷµǾ����ϴ�. �ٽ� �Է��ϼ���\n");
					}
					else if (isStringDouble((s + i)->kor) == 0) {//���� �̿��� ����
						printf("�߸� �ԷµǾ����ϴ�. �ٽ� �Է��ϼ���\n");
					}
					else {//�������� �Էµǰ� ���ڰ� �Է¾ȵǸ� Ż��
						break;
					}
				}
				while (1) {
					printf("%s�л��� ���������� �Է����ּ��� ", s[i].name); scanf("%s", (s + i)->mat);
					int mathscore = atoi((s + i)->mat);
					if (mathscore < 0 || mathscore > 100) {//0~100����
						printf("�߸� �ԷµǾ����ϴ�. �ٽ� �Է��ϼ���\n");
					}
					else if (isStringDouble((s + i)->kor) == 0) {//���� �̿��� ����
						printf("�߸� �ԷµǾ����ϴ�. �ٽ� �Է��ϼ���\n");
					}
					else {//�������� �Էµǰ� ���ڰ� �Է¾ȵǸ� Ż��
						break;
					}
				}
				input_grade_count++;
			}
			else if (i==input_grade_count && strcmp(name, s[i].name) != 0) {
				printf("\n\n���������Ͱ� �Էµ��� �ʾҽ��ϴ�.");
			}
		}system("cls");
	}
}
//add_student(profile, info_student, add_profile, info_add_student);
void add_student(struct student *s, struct student_info * si, struct add_student *as, struct add_student_info * asi) { //3�� �л� �߰�

	// �ִ��л� �Է½� �����Է�
	// �л��� ������ �л� �߰���
	j = 0;
	i = 0;
	int k;
	char name[10];

	time_t now;
	now = time(NULL);
	srand(time(NULL));
	
	while (1) {
		int breakcheck = 0;
		int addbreakcheck = 0;

		printf("%3s���� �Է��� �л����Դϴ�.\n", login_name);
		printf("�̸�    �����Է¿��� \n");
		for (k = 0; k < input_count; k++) {
			printf("%s", si[k].name);
				if (atoi((s + k)->kor) > 0 && atoi((s + k)->kor) <= 100) {//0~100����
					printf("       (O) \n");
				}
				else {
					printf("       (X) \n");
				}
		}printf("====================================\n");
		printf("%3s���� �߰��� �л����Դϴ�.\n", login_name);
		printf("�̸�    �����Է¿��� \n");
		for (k = 0; k < add_count; k++) {
			printf("%s", asi[k].name);
				if (atoi((as + k)->kor) > 0 && atoi((as + k)->kor) <= 100) {//0~100����
					printf("       (O) \n");
				}
				else {
					printf("       (X) \n");
				}
		}
		printf("\n�߰��Է��� �л��� �ٽ� �Է��Ͻø� ������ �߰��մϴ�\n");
		printf("� �л� ������ �Է��Ͻðڽ��ϱ� (�Է����� quit) : "); scanf("%s", name);

		if (strcmp(name, "quit") == 0) {
			system("cls");
			break;
		}
		else {//���ᰡ �ƴϸ� ���ڿ��˻�
			strcpy((as + add_count)->name, name);
			for (j = 0; j < 10; j++) {
				if ((int)(as + add_count)->name[j] > 65 && (int)(as + add_count)->name[j] < 122) {
					//system("cls");
					printf("ERROR : �������� �ƴϹ��ϴ� �ٽ� �Է����̼�\n");
					Sleep(1000);
					breakcheck++;
					break;
				}
				else if (strlen((as + add_count)->name) == 0) {
					//system("cls");
					printf("ERROR : �Է��� ���ѰŰ������̴� �ٽ� �з����̼�\n");
					Sleep(1000);
					breakcheck++;
					break;
				}
				else if (strlen((as + add_count)->name) > 6) {
					//system("cls");
					printf("ERROR : �̸��� ��״� �������� �ƴѰ� �������̴� �ٽ� �Է��ϼ�\n");
					Sleep(1000);
					breakcheck++;
					break;
				}
			}//���ڿ� �˻簡 �����ٸ�
			//strcpy(asi[i].name, name); //�Է����̸� �л������� ����
			//asi[i].sid = now; //�л������� �й��ο�
			//strcpy(asi[i].pass, "1234"); //�л������� ��й�ȣ �ο� �ʱ��ȣ�� 1234�ϱ�

			//system("cls");
		}

		if (breakcheck != 0) {
			system("cls");
			continue;
		}

			for (i = 0; i < add_count; i++) {
				if (strcmp((as + i)->name, name) == 0) {//���ڿ� �˻簡 ������ ������ �Է��� �л��� ��ġ�ϸ�
					while (1) {
						printf("\n\n%s�л��� ���������� �Է����ּ��� ", as[i].name); scanf("%s", (as + i)->kor);
						int korscore = atoi((as + i)->kor);
						if (korscore < 0 || korscore > 100) {//0~100����
							printf("�߸� �ԷµǾ����ϴ�. �ٽ� �Է��ϼ���\n");
						}
						else if (isStringDouble((as + i)->kor) == 0) {//���� �̿��� ����
							printf("�߸� �ԷµǾ����ϴ�. �ٽ� �Է��ϼ���\n");
						}
						else {//�������� �Էµǰ� ���ڰ� �Է¾ȵǸ� Ż��
							break;
						}
					}
					while (1) {
						printf("%s�л��� ���������� �Է����ּ��� ", as[i].name); scanf("%s", (as + i)->eng);
						int englishscore = atoi((as + i)->eng);
						if (englishscore < 0 || englishscore > 100) {//0~100����
							printf("�߸� �ԷµǾ����ϴ�. �ٽ� �Է��ϼ���\n");
						}
						else if (isStringDouble((as + i)->kor) == 0) {//���� �̿��� ����
							printf("�߸� �ԷµǾ����ϴ�. �ٽ� �Է��ϼ���\n");
						}
						else {//�������� �Էµǰ� ���ڰ� �Է¾ȵǸ� Ż��
							break;
						}
					}
					while (1) {
						printf("%s�л��� ���������� �Է����ּ��� ", as[i].name); scanf("%s", (as + i)->mat);
						int mathscore = atoi((as + i)->mat);
						if (mathscore < 0 || mathscore > 100) {//0~100����
							printf("�߸� �ԷµǾ����ϴ�. �ٽ� �Է��ϼ���\n");
						}
						else if (isStringDouble((as + i)->kor) == 0) {//���� �̿��� ����
							printf("�߸� �ԷµǾ����ϴ�. �ٽ� �Է��ϼ���\n");
						}
						else {//�������� �Էµǰ� ���ڰ� �Է¾ȵǸ� Ż��
							break;
						}
					}
					add_grade_count++;//�߰��Է� ī��Ʈ ����
					printf("�߰��л��� ������ �ԷµǾ����ϴ�.");
					Sleep(1000);
					system("cls");
					i++;
					addbreakcheck++;
					break;
				}
				else if (i == add_count && strcmp((as + i)->name, name) != 0){
					printf("\n\n�׷��л��� �Էµ��� �ʾҽ��ϴ�");
				}
			}
			if (addbreakcheck != 0)
				continue;


		strcpy(asi[add_count].name, (as + add_count)->name); //�Է����̸� �л������� ����
		//asi[i].sid = now; //�л������� �й��ο�
		strcpy(asi[add_count].pass, "1234"); //�л������� ��й�ȣ �ο� �ʱ��ȣ�� 1234�ϱ�
		printf("%s �л��� ���������Ͱ� �߰��Ǿ����ϴ�.", (as + add_count)->name);
		Sleep(1000);
		i++;
		add_count++;//�߰� ī��Ʈ ����
		system("cls");
	}
}

void showNsort(struct student *s, struct student_info *si, struct add_student *as, struct add_student_info *asi, struct grade_info *g) {	//4�� �л� ����Ʈ ��� ���� ���� ����

	int ch;
	int load_size;

	while (1) {
		if (input_count == 0) {//�л� ������ �ԷµǾ��ٸ�
			printf("�Է��� �л��� �����ϴ�.\n");
		}
		else {
			printf("%s���� �Է��� �л��Դϴ�.\n", login_name);
			printf("�̸�    �����Է¿��� \n");
			for (i = 0; i < input_count; i++) {
				printf("%s", s[i].name);
				if (atoi((s + i)->kor) > 0 && atoi((s + i)->kor) <= 100) {//0~100����
					printf("       (O) \n");
				}
				else {
					printf("       (X) \n");
				}
			}
		}

		if (add_count == 0) {//�л��� �߰��Ǿ��ٸ�
			printf("�߰��Է��� �л��� �����ϴ�.\n");
		}
		else {
			printf("%s���� �߰��� �л��Դϴ�.\n", login_name);
			printf("�̸�    �����Է¿��� \n");
			for (i = 0; i < add_count; i++) {
				printf("%s", as[i].name);
				if (atoi((as + i)->kor) > 0 && atoi((as + i)->kor) <= 100) {//0~100����
					printf("       (O) \n");
				}
				else {
					printf("       (X) \n");
				}
			}
		}

		/*if (load_count == 0) {//�л��� �ҷ������ٸ�
			printf("���Ͽ� �л��� �����ϴ�.\n");
		}
		else {
			printf("%s���� ���Ͽ� �Է��� �л����Դϴ�g.\n");
			printf("�̸�    �����Է¿��� \n");
			for (i = 0; i < input_count; i++) {
				printf("%s", ls[i].name);
				if (atoi((ls + i)->kor) > 0 && atoi((ls + i)->kor) <= 100) {//0~100����
					printf("       (O) \n");
				}
				else {
					printf("       (X) \n");
				}
			}
		}*/


		/*   ������ ���
		printf("================================����ǥ===================================\n");
		printf(" ����   ����(����)  ����(����)  ����(����)   ����  ��ü���    ��ü����\n");
		for (i = 0; i < last; i++) {
			printf("%2s %4s(%s) %8s(%s) %8s(%s) %6d %11lf %6s\n",
				(ss + i)->name, (ss + i)->kor, (ss + i)->subK, (ss + i)->eng, (ss + i)->subE, (ss + i)->mat, (ss + i)->subM,
				(ss + i)->sum, (ss + i)->avg, (ss + i)->totG);
		}
		printf("==========================================================================\n");
		*/
		extern input_grade_count;//�л� �����Է� ī����
		extern add_grade_count;//�߰� �л� ���� ī����
		extern load_grade_count;//�ε��л� ���� ī����
		printf("\t\t1. ���� �����Է��� �л�����\n");
		printf("\t\t2. ������ �Էµ� �л�����\n");
		printf("\t\t3. ����\n");
		printf("\t\t type nomber: "); scanf("%d", &ch);

		switch (ch) {

			case 1:

				while (1) {
					printf("================================����ǥ===================================\n");
					printf(" ����   ����(����)  ����(����)  ����(����)   ����  ��ü���    ��ü����\n");
					if (input_grade_count > 0) {//������ �ԷµǾ���
						for (i = 0; i < input_grade_count; i++) {
							if (atoi((s + i)->kor) > 0 && atoi((s + i)->kor) <= 100) {//����� �Է��� ������ �׳��� ���
								printf("%2s %4s(%s) %8s(%s) %8s(%s) %6d %11lf %6s\n",
									(s + i)->name, (s + i)->kor, (g + i)->subK, (s + i)->eng, (g + i)->subE, (s + i)->mat, (g + i)->subM,
									(s + i)->sum, (s + i)->avg, (g + i)->totG);
							}
						}
					}
					if (add_grade_count > 0) {
						for (i = 0; i < add_grade_count; i++) {
							if (atoi((as + i)->kor) > 0 && atoi((as + i)->kor) <= 100) {//����� �Է��� ������ �׳��� ���
								printf("%2s %4s(%s) %8s(%s) %8s(%s) %6d %11lf %6s\n",
									(as + i)->name, (as + i)->kor, (g + i)->subK, (as + i)->eng, (g + i)->subE, (as + i)->mat, (g + i)->subM,
									(as + i)->sum, (as + i)->avg, (g + i)->totG);
							}
						}
					}
					/*if (load_grade_count > 0) {
						for (i = 0; i < load_grade_count; i++) {
							if (atoi((ls + i)->kor) > 0 && atoi((ls + i)->kor) <= 100) {//����� �Է��� ������ �׳��� ���
								printf("%2s %4s(%s) %8s(%s) %8s(%s) %6d %11lf %6s\n",
									(ls + i)->name, (ls + i)->kor, (g + i)->subK, (ls + i)->eng, (g + i)->subE, (ls + i)->mat, (g + i)->subM,
									(ls + i)->sum, (ls + i)->avg, (g + i)->totG);
							}
						}
					}*/
					printf("==========================================================================\n");

					//printf("\t\t\t 1.�������� ����(������)\n");
					//printf("\t\t\t 1.�������� ����(������)\n");
					//printf("\t\t\t 3.�ǵ��ư���\n");
					printf("�����Ͻðڽ��ϱ�? 1.y 2.n");
					printf("\t\t type nomber: "); scanf("%d", &ch);
					
					switch (ch) {
						
						case 1:

							break;

						case 2:
							system("cls");
							continue;

						default:
							printf("1~2 ������ ���ڸ� �Է��ϼ���\n");
					}
					break;
				}

			case 2:
				load_size = input_count + add_count;
				load_grade_count = 0;
				/*FILE *load_si = fopen(".\\login_file\\student_info.txt", "r");
				struct load_student_info *info_load_student;
				info_load_student = malloc(sizeof(struct student) * 20);//���Ͼ� �ο�����ŭ �Ҵ�
				for (i = 0; i < load_size; i++) {//����ü ���� ���� �����Ҵ� ����
					info_load_student[i].name = (char*)malloc(sizeof(char) * 10);
					info_load_student[i].pass = (char*)malloc(sizeof(char) * 20);
					fscanf(load_si, "%s %s", info_load_student[i].name, info_load_student[i].pass);
				}fclose(load_si);*/

				FILE *load_p = fopen("student.txt", "r");
				struct load_student *load_profile;
				load_profile = malloc(sizeof(struct student) * 20);//
				i = 0;
				while (i < 20) {//����ü ���� ���� �����Ҵ� ����
					if (feof(load_p)) break;
					(load_profile + i)->name = (char*)malloc(sizeof(char) * 10);
					(load_profile + i)->kor = (char*)malloc(sizeof(char) * 10);
					(load_profile + i)->eng = (char*)malloc(sizeof(char) * 10);
					(load_profile + i)->mat = (char*)malloc(sizeof(char) * 10);
					(load_profile + i)->sum = (int *)malloc(sizeof(int) * 10);
					fscanf(load_p, "%s %s %s %s %d %lf\n",
						(load_profile + i)->name, (load_profile + i)->kor, (load_profile + i)->eng,
						(load_profile + i)->mat, &load_profile[i].sum, &load_profile[i].avg); //�̸�, ����, ����, ���� ������ ����. �� �̻��� ����
					load_grade_count++;
					i++;
				}fclose(load_p);
				//load_grade_count--;

				/*struct load_grade_info *load_grade;
				load_grade = malloc(sizeof(struct load_grade_info) * 20);
				i = 0;
				while (i < 20) {//����ü ���� ���� �����Ҵ� ����
					load_grade[i].subK = (char*)malloc(sizeof(char) * 10);
					load_grade[i].subE = (char*)malloc(sizeof(char) * 10);
					load_grade[i].subM = (char*)malloc(sizeof(char) * 10);
					load_grade[i].totG = (char*)malloc(sizeof(char) * 10);
					i++;
				}*/

				load_setgrade(load_profile, g, load_grade_count);

				printf("\n");
				for (i = 0; i < load_grade_count; i++) {
					if (atoi((load_profile + i)->kor) > 0 && atoi((load_profile + i)->kor) <= 100) {//����� �Է��� ������ �׳��� ���
						printf("%2s %4s(%s) %8s(%s) %8s(%s) %6d %11lf %6s\n",
							(load_profile + i)->name, (load_profile + i)->kor, (g + i)->subK, (load_profile + i)->eng, (g + i)->subE, (load_profile + i)->mat, (g + i)->subM,
							(load_profile + i)->sum, (load_profile + i)->avg, (g + i)->totG);
					}
				}

				printf("==========================================================================\n");

				printf("�����Ͻðڽ��ϱ�? 1.y 2.n");
				printf("\t\t type nomber: "); scanf("%d", &ch);

				switch (ch) {

				case 1:
					free(load_profile, load_grade);
					break;

				case 2:
					system("cls");
					continue;

				default:
					printf("1~2 ������ ���ڸ� �Է��ϼ���\n");
				}
				break;

			case 3:

				break;

			default :
				printf("1~2 ���ڸ� �Է��ϼ���\n");
		}break;
	}
}

void changeTHEstudent(struct student *s, struct student_info *si, struct add_student *as, struct add_student_info *asi, struct grade_info *g) { //5�� ��°� ����
	  //�̸� ����(����) ����(����) ����(����) ���� ��� �������
	int ch;
	char *change_name = (char*)malloc(sizeof(char) * 10);


	while (1) {
		if (input_count == 0) {//�л� ������ �ԷµǾ��ٸ�
			printf("�Է��� �л��� �����ϴ�.\n");
		}
		else {
			printf("%s���� �Է��� �л��Դϴ�.\n", login_name);
			printf("�̸�    �����Է¿��� \n");
			for (i = 0; i < input_count; i++) {
				printf("%s", s[i].name);
				if (atoi((s + i)->kor) > 0 && atoi((s + i)->kor) <= 100) {//0~100����
					printf("       (O) \n");
				}
				else {
					printf("       (X) \n");
				}
			}
		}

		if (add_count == 0) {//�л��� �߰��Ǿ��ٸ�
			printf("�߰��Է��� �л��� �����ϴ�.\n");
		}
		else {
			printf("%s���� �߰��� �л��Դϴ�.\n", login_name);
			printf("�̸�    �����Է¿��� \n");
			for (i = 0; i < input_count; i++) {
				printf("%s", as[i].name);
				if (atoi((as + i)->kor) > 0 && atoi((as + i)->kor) <= 100) {//0~100����
					printf("       (O) \n");
				}
				else {
					printf("       (X) \n");
				}
			}
		}

		/*if (load_count == 0) {//�л��� �ҷ������ٸ�
			printf("���Ͽ� �л��� �����ϴ�.\n");
		}
		else {
			printf("%s���� ���Ͽ� �Է��� �л����Դϴ�g.\n");
			printf("�̸�    �����Է¿��� \n");
			for (i = 0; i < input_count; i++) {
				printf("%s", ls[i].name);
				if (atoi((ls + i)->kor) > 0 && atoi((ls + i)->kor) <= 100) {//0~100����
					printf("       (O) \n");
				}
				else {
					printf("       (X) \n");
				}
			}
		}*/
		printf("\t\t\t1. �̸�����\n");
		printf("\t\t\t2. ��������\n");
		//printf("\t\t\t3. �л�����(������)\n");
		printf("\t\t\t3. ����\n");
		printf("\t\t    ���� %d�� �����Ͽ����ϴ�.\n", change_count);
		printf("\t\t\t type number : "); scanf("%d", &ch);
		
		switch (ch) {
		case 1://�̸����� ���� �̸��� ��ġ�� ����
			//������ �˻��Ѵ� or �����л� �߰��л� �Է��л� �������ؼ� �����Ѵ�
			printf("���� �̸��� �ٲܲ���? ");  scanf("%s", change_name);
			for (i = 0; i < input_count; i++) {
				if (strcmp((s + i)->name, change_name) == 0) { //���α׷��� �Է��� ����ü����
					printf("���α׷����� �Է��� �л��Դϴ�\n"); //�̸��� �ٲٱ� ���� �̸��˻�
					printf("���� �ٲܳ���? : "); scanf("%s", (s + i)->name);
					strcpy((si + i)->name, (s + i)->name);//�л� �ؽ�Ʈ ���� ����ü�� ���
					change_count++;
					//strcpy((os + i)->name, change_name); �̰��ϸ� ã�� �̸����� �ٽ� �ٲ�� �ȴ�.

				}
				else if (i == (input_count - 1) && strcmp((s + i)->name, change_name) != 0) {
					printf("�׷������ �������̴� �ٽ� �ϼ���\n");
					break;
				}
			}

			for (i = 0; i < add_count; i++) {
				if (strcmp((as + i)->name, change_name) == 0) { //�̸��� �ٲٱ� ���� �̸��˻�
					printf("�߰� �Է��� �л��Դϴ�\n");
					printf("���� �ٲܳ���? : "); scanf("%s", (as + i)->name);
					strcpy((asi + i)->name, (as + i)->name);//�л� �ؽ�Ʈ ���� ����ü�� ���
					change_count++;
					//strcpy((os + i)->name, change_name); �̰��ϸ� ã�� �̸����� �ٽ� �ٲ�� �ȴ�.
				}
				else if (i == (add_count - 1) && strcmp((as + i)->name, change_name) != 0) {
					printf("�׷������ �������̴� �ٽ� �ϼ���\n");
					break;
				}
			}

			/*for (i = 0; i < load_count; i++) {
				if (strcmp((ls + i)->name, change_name) == 0) { //�̸��� �ٲٱ� ���� �̸��˻�
					printf("���Ͽ� �ҷ��� �л��Դϴ�\n");
					printf("���� �ٲܳ���? : "); scanf("%s", (ls + i)->name);
					strcpy((lsi + i)->name, (ls + i)->name);//�л� �ؽ�Ʈ ���� ����ü�� ���
					change_count++;
					//strcpy((os + i)->name, change_name); �̰��ϸ� ã�� �̸����� �ٽ� �ٲ�� �ȴ�.
				}
				else if (i == (load_count - 1) && strcmp((ls + i)->name, change_name) != 0) {
					printf("�׷������ �������̴� �ٽ� �ϼ���\n");
					break;
				}
			}*/

			
			system("cls");
			break;

		case 2://��������
			//
			system("cls");
			while (1) {
				int ch;

				if (atoi((s + i)->kor) > 0 && atoi((s + i)->kor) <= 100) {//0~100���� ������ �Էµ� �װ��̸�
					printf("�Է��� ������\n");
					printf("================================����ǥ===================================\n");
					printf(" ����   ����(����)  ����(����)  ����(����)   ����  ��ü���    ��ü����\n");
					for (i = 0; i < input_grade_count; i++) {
						printf("%2s %4s(%s) %8s(%s) %8s(%s) %6d %11lf %6s\n",
							(s + i)->name, (s + i)->kor, (g + i)->subK, (s + i)->eng, (g + i)->subE, (s + i)->mat, (g + i)->subM,
							(s + i)->sum, (s + i)->avg, (g + i)->totG);
					}
				}
				if (atoi((as + i)->kor) > 0 && atoi((as + i)->kor) <= 100) {//0~100���� ������ �Էµ� �װ��̸�
					printf("�߰��Է��� ������\n");
					printf("================================����ǥ===================================\n");
					printf(" ����   ����(����)  ����(����)  ����(����)   ����  ��ü���    ��ü����\n");
					for (i = 0; i < add_grade_count; i++) {
						printf("%2s %4s(%s) %8s(%s) %8s(%s) %6d %11lf %6s\n",
							(as + i)->name, (as + i)->kor, (g + i)->subK, (as + i)->eng, (g + i)->subE, (as + i)->mat, (g + i)->subM,
							(as + i)->sum, (as + i)->avg, (g + i)->totG);
					}
				}
				/*if (atoi((ls + i)->kor) > 0 && atoi((ls + i)->kor) <= 100) {//0~100���� ������ �Էµ� �װ��̸�
					printf("���α׷��� �Էµ� ������\n");
					printf("================================����ǥ===================================\n");
					printf(" ����   ����(����)  ����(����)  ����(����)   ����  ��ü���    ��ü����\n");
					for (i = 0; i < load_grade_count; i++) {
						printf("%2s %4s(%s) %8s(%s) %8s(%s) %6d %11lf %6s\n",
							(ls + i)->name, (ls + i)->kor, (g + i)->subK, (ls + i)->eng, (g + i)->subE, (ls + i)->mat, (g + i)->subM,
							(ls + i)->sum, (ls + i)->avg, (g + i)->totG);
					}
				}*/
				printf("\t\t\t1. �������� ����\n");
				printf("\t\t\t2. �������� ����\n");
				printf("\t\t\t3. �������� ����\n");
				printf("\t\t\t4. ����\n");
				printf("\t\t    ���� %d�� �����Ͽ����ϴ�.\n", change_count);
				printf("\t\t\t type number : "); scanf("%d", &ch);

				switch (ch) {
				case 1:
/*
extern input_count;//�л� �Է��� ī����
extern add_count;//�߰� �л� ī����
extern load_count;//�ε� �л� ī����

extern input_grade_count;//�л� �����Է� ī����
extern add_grade_count;//�߰� �л� ���� ī����
extern load_grade_count;//�ε��л� ���� ī����
*/
					printf("������ ���������� �ٲܲ���? (�����÷��� quit)");  scanf("%s", change_name);
					if (strcmp(change_name, "quit") == 0) {
						system("cls");
						break;
					}

					while (1) {
						if (strcmp((s + i)->name, change_name) == 0) { //���α׷��� �Է��� ����ü����
							printf("���α׷����� �Է��� �л��Դϴ�\n"); //���� �ٲٱ����� �Է����̸� �˻� 
							printf("���� ���������� %s �Դϴ� �������� �ٲٽ�?? : ", (s + i)->kor); scanf("%s", (s + i)->kor);
							change_count++;
							break;//�Է������� ������
						}
						if (strcmp((as + i)->name, change_name) == 0) { //���� �ٲٱ����� �Է����̸� �˻� 
							printf("�߰� �Է��� �л��Դϴ�\n");
							printf("���� ���������� %s �Դϴ� �������� �ٲٽ�?? : ", (as + i)->kor); scanf("%s", (as + i)->kor);
							change_count++;
							break;//�Է������� ������
						}
						/*if (strcmp((ls + i)->name, change_name) == 0) { //���� �ٲٱ����� �Է����̸� �˻� 
							printf("���Ͽ� �ҷ��� �л��Դϴ�\n");
							printf("���� ���������� %s �Դϴ� �������� �ٲٽ�?? : ", (ls + i)->kor); scanf("%s", (ls + i)->kor);
							change_count++;
							break;//�Է������� ������
						}*/
						/*
						else if (i == (input_count - 1) && strcmp((s + i)->name, change_name) != 0) {
							printf("�׷������ �������̴� �ٽ� �ϼ���\n");
							break;
						}

						else if (i == (add_count - 1) && strcmp((as + i)->name, change_name) != 0) {
							printf("�׷������ �������̴� �ٽ� �ϼ���\n");
							break;
						}

						else if (i == (load_count - 1) && strcmp((ls + i)->name, change_name) != 0) {
							printf("�׷������ �������̴� �ٽ� �ϼ���\n");
							break;
						}
						*/

						i++;
						if (i == (input_grade_count + add_grade_count + load_grade_count)) {//�� ���ĵ� ����� ������ �ʴٸ�
							printf("�׷� ����� �������̴� �ٽ� �ϼ���\n");
							break;
						}
					}
					/*
					for (i = 0; i < input_grade_count; i++) {//������ �Էµ� �л��� �˻�
						if (strcmp((s + i)->name, change_name) == 0) { //���α׷��� �Է��� ����ü����
							printf("���α׷����� �Է��� �л��Դϴ�\n"); //���� �ٲٱ����� �Է����̸� �˻� 
							printf("���� ���������� %s �Դϴ� �������� �ٲٽ�?? : ", (s + i)->kor); scanf("%s", (s + i)->kor);
							change_count++;
						}
						else if (i == (input_count - 1) && strcmp((s + i)->name, change_name) != 0) {
							printf("�׷������ �������̴� �ٽ� �ϼ���\n");
							break;
						}
					}
					for (i = 0; i < add_grade_count; i++) {
						if (strcmp((as + i)->name, change_name) == 0) { //���� �ٲٱ����� �Է����̸� �˻� 
							printf("�߰� �Է��� �л��Դϴ�\n");
							printf("���� ���������� %s �Դϴ� �������� �ٲٽ�?? : ", (as+i)->kor); scanf("%s", (as + i)->kor);
							change_count++;
						}
						else if (i == (add_count - 1) && strcmp((as + i)->name, change_name) != 0) {
							printf("�׷������ �������̴� �ٽ� �ϼ���\n");
							break;
						}
					}
					for (i = 0; i < load_grade_count; i++) {
						if (strcmp((ls + i)->name, change_name) == 0) { //���� �ٲٱ����� �Է����̸� �˻� 
							printf("���Ͽ� �ҷ��� �л��Դϴ�\n");
							printf("���� ���������� %s �Դϴ� �������� �ٲٽ�?? : ", (ls + i)->kor); scanf("%s", (ls + i)->kor);
							change_count++;
						}
						else if (i == (load_count - 1) && strcmp((ls + i)->name, change_name) != 0) {
							printf("�׷������ �������̴� �ٽ� �ϼ���\n");
							break;
						}
					}
					*/
					system("cls");
					break;

				case 2:

					printf("������ ���������� �ٲܲ���? (�����÷��� quit)");  scanf("%s", change_name);
					if (strcmp(change_name, "quit") == 0) {
						system("cls");
						break;
					}

					while (1) {
						if (strcmp((s + i)->name, change_name) == 0) { //���α׷��� �Է��� ����ü����
							printf("���α׷����� �Է��� �л��Դϴ�\n"); //���� �ٲٱ����� �Է����̸� �˻� 
							printf("���� ���������� %s �Դϴ� �������� �ٲٽ�?? : ", (s + i)->mat); scanf("%s", (s + i)->mat);
							change_count++;
							break;//�Է������� ������
						}
						if (strcmp((as + i)->name, change_name) == 0) { //���� �ٲٱ����� �Է����̸� �˻� 
							printf("�߰� �Է��� �л��Դϴ�\n");
							printf("���� ���������� %s �Դϴ� �������� �ٲٽ�?? : ", (as + i)->mat); scanf("%s", (as + i)->mat);
							change_count++;
							break;//�Է������� ������
						}
						/*if (strcmp((ls + i)->name, change_name) == 0) { //���� �ٲٱ����� �Է����̸� �˻� 
							printf("���Ͽ� �ҷ��� �л��Դϴ�\n");
							printf("���� ���������� %s �Դϴ� �������� �ٲٽ�?? : ", (ls + i)->mat); scanf("%s", (ls + i)->mat);
							change_count++;
							break;//�Է������� ������
						}*/
						/*
						else if (i == (input_count - 1) && strcmp((s + i)->name, change_name) != 0) {
							printf("�׷������ �������̴� �ٽ� �ϼ���\n");
							break;
						}

						else if (i == (add_count - 1) && strcmp((as + i)->name, change_name) != 0) {
							printf("�׷������ �������̴� �ٽ� �ϼ���\n");
							break;
						}

						else if (i == (load_count - 1) && strcmp((ls + i)->name, change_name) != 0) {
							printf("�׷������ �������̴� �ٽ� �ϼ���\n");
							break;
						}
						*/

						i++;
						if (i == (input_grade_count + add_grade_count + load_grade_count)) {//�� ���ĵ� ����� ������ �ʴٸ�
							printf("�׷� ����� �������̴� �ٽ� �ϼ���\n");
							break;
						}
					}
					system("cls");
					break;

				case 3:

					printf("������ ���������� �ٲܲ���? (�����÷��� quit)");  scanf("%s", change_name);
					if (strcmp(change_name, "quit") == 0) {
						system("cls");
						break;
					}

					while (1) {
						if (strcmp((s + i)->name, change_name) == 0) { //���α׷��� �Է��� ����ü����
							printf("���α׷����� �Է��� �л��Դϴ�\n"); //���� �ٲٱ����� �Է����̸� �˻� 
							printf("���� ���������� %s �Դϴ� �������� �ٲٽ�?? : ", (s + i)->eng); scanf("%s", (s + i)->eng);
							change_count++;
							break;//�Է������� ������
						}
						if (strcmp((as + i)->name, change_name) == 0) { //���� �ٲٱ����� �Է����̸� �˻� 
							printf("�߰� �Է��� �л��Դϴ�\n");
							printf("���� ���������� %s �Դϴ� �������� �ٲٽ�?? : ", (as + i)->eng); scanf("%s", (as + i)->eng);
							change_count++;
							break;//�Է������� ������
						}
						/*if (strcmp((ls + i)->name, change_name) == 0) { //���� �ٲٱ����� �Է����̸� �˻� 
							printf("���Ͽ� �ҷ��� �л��Դϴ�\n");
							printf("���� ���������� %s �Դϴ� �������� �ٲٽ�?? : ", (ls + i)->eng); scanf("%s", (ls + i)->eng);
							change_count++;
							break;//�Է������� ������
						}*/
						/*
						else if (i == (input_count - 1) && strcmp((s + i)->name, change_name) != 0) {
							printf("�׷������ �������̴� �ٽ� �ϼ���\n");
							break;
						}

						else if (i == (add_count - 1) && strcmp((as + i)->name, change_name) != 0) {
							printf("�׷������ �������̴� �ٽ� �ϼ���\n");
							break;
						}

						else if (i == (load_count - 1) && strcmp((ls + i)->name, change_name) != 0) {
							printf("�׷������ �������̴� �ٽ� �ϼ���\n");
							break;
						}
						*/

						i++;
						if (i == (input_grade_count + add_grade_count + load_grade_count)) {//�� ���ĵ� ����� ������ �ʴٸ�
							printf("�׷� ����� �������̴� �ٽ� �ϼ���\n");
							break;
						}
					}
					system("cls");
					break;

				case 4://���� ���� ����

					break;

				default:
					printf("1���� 4���� ���� �Է��ϼ�\n");
				}
			}
			break;

		/*case 3://�л����� �� �ȱ���

			break;
		*/
		case 3://����
			
			break;

		default :
			printf("1���� 3���� �Է��Ͻʽÿ�\n");
		}
		break;

	}
	system("cls");
}

void input_file(struct student *s, struct student_info *si, struct add_student *as, struct add_student_info *asi, struct grade_info *g) { //6�� ���Ͽ� �Է�

	int ch;
	int awr=0;//���� ���� �Է¸�带 �����Ҳ�
	char c;
	/*FILE *fp = fopen("student.txt", "r");
	while ((c = fgetc(fp)) != EOF) {
		if (c == '\n') 		awr++;//�����鼭 ����ִ��� ����
	}fclose(fp);
		/*
		���Ͽ� �ƹ��͵� �Ⱦ����ִٸ� w���� ���ξ���
		fprintf(p, "%d %d \n", &n &nn);
		���Ͽ� ������ �������ִٸ�
		�ε��� ������ �ٽ� w���� �����
		�߰��л��� ���α׷��� �Է��� �л��� a����
		*/
	while (1) {
		printf("���� ���α׷��� �Էµ� �� �л��� ���� %d���̰�\n", input_count + add_count + load_count);
		printf("�������� �Էµ� �л��� �� %d�� �Դϴ�.\n", input_grade_count + add_grade_count + load_grade_count);

		printf("\t\t\t1. ���Ͽ� ����\n");
		printf("\t\t\t2. ����\n");
		printf("\t\t\t type number : "); scanf("%d", &ch);
	

		switch (ch) {
		case 1:
			printf("���Ͽ� �����Ͽ����ϴ�.");
			FILE *svp = fopen("student.txt", "a+");
			for (i = 0; i < input_grade_count; i++) {
				fprintf(svp, "%s %s %s %s %d %lf\n",
					(s + i)->name, (s + i)->kor, (s + i)->eng, (s + i)->mat,
					(s + i)->sum, (s + i)->avg);
			}
			fclose(svp);
			FILE *svap = fopen("student.txt", "a+");
			for (i = 0; i < add_grade_count; i++) {
				fprintf(svap, "%s %s %s %s %d %lf\n",
					(as + i)->name, (as + i)->kor, (as + i)->eng, (as + i)->mat,
					(as + i)->sum, (as + i)->avg);
			}fclose(svap);
			Sleep(1000);
			/*
			extern input_count;//�л� �Է��� ī����
			extern add_count;//�߰� �л� ī����
			extern load_count;//�ε� �л� ī����

			extern input_grade_count;//�л� �����Է� ī����
			extern add_grade_count;//�߰� �л� ���� ī����
			extern load_grade_count;//�ε��л� ���� ī����
			*/
			/*if (load_count > 0) {//�ε��л��� �����Ѵٸ� ���� ��
				FILE *p = fopen(".\\login_file\\student_info.txt", "w");//���� ����
				FILE *fp = fopen("student,txt", "w");//��������
				for (i = 0; i < load_count; i++) {//�������Ͽ��� ��
					fprintf(p, "%s %s\n", lsi[i].name, lsi[i].pass);
				}fclose(p);
				for (i = 0; i < load_grade_count; i++) {//�������Ͽ��� ��
					fprintf(fp, "%2s %4s %s  %8s %s  %8s %s  %6d %11lf %6s\n",
						(ls + i)->name, (ls + i)->kor, (g + i)->subK, (ls + i)->eng, (g + i)->subE, (ls + i)->mat, (g + i)->subM,
						(ls + i)->sum, (ls + i)->avg, (g + i)->totG);
				}fclose(fp);
				if (add_count > 0) {//�ε��л��� �����ϰ� �߰��л��� �����ϸ� ����
					FILE *p = fopen(".\\login_file\\student_info.txt", "a");//���� ����
					FILE *fp = fopen("student,txt", "a");//��������
					for (i = 0; i < add_count; i++) {//�������Ͽ��� ��
						fprintf(p, "%s %s\n", asi[i].name, asi[i].pass);
					}fclose(p);
					for (i = 0; i < add_grade_count; i++) {//�������Ͽ��� ��
						fprintf(fp, "%2s %4s %s  %8s %s  %8s %s  %6d %11lf %6s\n",
							(as + i)->name, (as + i)->kor, (g + i)->subK, (as + i)->eng, (g + i)->subE, (as + i)->mat, (g + i)->subM,
							(as + i)->sum, (as + i)->avg, (g + i)->totG);
					}fclose(fp);
					if (input_count > 0) {//�ε��л��� �����ϰ� �߰��л��� �����ϰ� �Է��л��� ������ ���Ͽ� ����
						FILE *p = fopen(".\\login_file\\student_info.txt", "a");//���� ����
						FILE *fp = fopen("student,txt", "a");//��������
						for (i = 0; i < input_count; i++) {//�������Ͽ��� ��
							fprintf(p, "%s %s\n", si[i].name, si[i].pass);
						}fclose(p);
						for (i = 0; i < add_grade_count; i++) {//�������Ͽ��� ��
							fprintf(fp, "%2s %4s %s  %8s %s  %8s %s  %6d %11lf %6s\n",
								(s + i)->name, (s + i)->kor, (g + i)->subK, (s + i)->eng, (g + i)->subE, (s + i)->mat, (g + i)->subM,
								(s + i)->sum, (s + i)->avg, (g + i)->totG);
						}fclose(fp);
					}
					else {//�ε��л��� �����ϰ� �߰��л��� �����ϰ� �Է��л��� ������ �ε�� �߰��л��� ����
						break;
					}
				}
				else {//�ε��л��� �ְ� �߰������� ������
					if (input_count > 0) {//�ε��л��� �Է��л��� ����
						FILE *p = fopen("student,txt", "a");
						for (i = 0; i < input_count; i++) {
							fprintf(p, "%s %s\n", si[i].name, si[i].pass);
						}fclose(p);
					}
					else {//�ε��л��� �ְ� �߰����ϵ����� �Է��л��� ������ �ε��л��� ����
						break;
					}
				}
			}
			else {//�ε��л��� ���������ʰ�
				if (add_count > 0) {//�߰��л����� �����Ѵٸ�
					FILE *p = fopen(".\\login_file\\student_info.txt", "w");//���� ����
					FILE *fp = fopen("student,txt", "a");//��������
					for (i = 0; i < add_count; i++) {//�������Ͽ��� ��
						fprintf(p, "%s %s\n", asi[i].name, asi[i].pass);
					}fclose(p);
					for (i = 0; i < add_grade_count; i++) {//�������Ͽ��� ��
						fprintf(fp, "%2s %4s %s %8s %s %8s %s  %6d %11lf %6s\n",
							(as + i)->name, (as + i)->kor, (g + i)->subK, (as + i)->eng, (g + i)->subE, (as + i)->mat, (g + i)->subM,
							(as + i)->sum, (as + i)->avg, (g + i)->totG);
					}fclose(fp);
					if (input_count > 0) {//�߰��л��� �����ϰ� �Է��л��� �����ϸ� �C����
						FILE *p = fopen(".\\login_file\\student_info.txt", "a");//���� ����
						FILE *fp = fopen("student,txt", "a");//��������
						for (i = 0; i < input_count; i++) {//�������Ͽ��� ��
							fprintf(p, "%s %s\n", si[i].name, si[i].pass);
						}fclose(p);
						for (i = 0; i < add_grade_count; i++) {//�������Ͽ��� ��
							fprintf(fp, "%2s %4s %s %8s %s %8s %s %6d %11lf %6s\n",
								(s + i)->name, (s + i)->kor, (g + i)->subK, (s + i)->eng, (g + i)->subE, (s + i)->mat, (g + i)->subM,
								(s + i)->sum, (s + i)->avg, (g + i)->totG);
						}fclose(fp);
					}
					else {//�ε��л������� �Է��л��� ������ �߰��л��� ������
						break;
					}

				}
				else {//�߰��л��� ���������ʰ�
						if (input_count > 0) {//�Է��л��� �����ϸ� �Է��л����� ���ξ�
							FILE *p = fopen(".\\login_file\\student_info.txt", "w");//���� ����
							FILE *fp = fopen("student,txt", "a");//��������
							for (i = 0; i < input_count; i++) {//�������Ͽ��� ��
								fprintf(p, "%s %s\n", si[i].name, si[i].pass);
							}fclose(p);
							for (i = 0; i < add_grade_count; i++) {//�������Ͽ��� ��
								fprintf(fp, "%2s %4s %s %8s %s %8s %s %6d %11lf %6s\n",
									(s + i)->name, (s + i)->kor, (g + i)->subK, (s + i)->eng, (g + i)->subE, (s + i)->mat, (g + i)->subM,
									(s + i)->sum, (s + i)->avg, (g + i)->totG);
							}fclose(fp);
						}
						else {
							printf("\n\n�ε��л������� �߰��л������� �Է��л��� �����ϴ� \n");
							Sleep(4000);
						}
				}
			}*/
			break;

		case 2:


			break;

		default:
			printf("�ٽ� �Է��ϼ���\n");
		}
		break;
	}
	fflush(stdin);
	//input_success();
}

void input_setgrade(struct student *s, struct grade_info *g) { //1-1. �л� ���� �Է´����� ��޺ο��ϴ°�

	for (i = 0; i < stucheckcount; i++) {
		if (atoi((s + i)->kor) > 95)
			(g + i)->subK = "A+";
		else if (atoi((s + i)->kor) > 90 && atoi((s + i)->kor) <= 95)
			(g + i)->subK = "A ";
		else if (atoi((s + i)->kor) > 85 && atoi((s + i)->kor) <= 90)
			(g + i)->subK = "B+";
		else if (atoi((s + i)->kor) > 80 && atoi((s + i)->kor) <= 85)
			(g + i)->subK = "B ";
		else if (atoi((s + i)->kor) > 75 && atoi((s + i)->kor) <= 80)
			(g + i)->subK = "C+";
		else if (atoi((s + i)->kor) > 70 && atoi((s + i)->kor) <= 75)
			(g + i)->subK = "C ";
		else if (atoi((s + i)->kor) > 65 && atoi((s + i)->kor) <= 70)
			(g + i)->subK = "D+";
		else if (atoi((s + i)->kor) > 60 && atoi((s + i)->kor) <= 65)
			(g + i)->subK = "D ";
		else
			(g + i)->subK = "F ";
	}
	for (i = 0; i < stucheckcount; i++) {
		if (atoi((s + i)->eng) > 95)
			(g + i)->subE = "A+";
		else if (atoi((s + i)->eng) > 90 && atoi((s + i)->eng) <= 95)
			(g + i)->subE = "A ";
		else if (atoi((s + i)->eng) > 85 && atoi((s + i)->eng) <= 90)
			(g + i)->subE = "B+";
		else if (atoi((s + i)->eng) > 80 && atoi((s + i)->eng) <= 85)
			(g + i)->subE = "B ";
		else if (atoi((s + i)->eng) > 75 && atoi((s + i)->eng) <= 80)
			(g + i)->subE = "C+";
		else if (atoi((s + i)->eng) > 70 && atoi((s + i)->eng) <= 75)
			(g + i)->subE = "C ";
		else if (atoi((s + i)->eng) > 65 && atoi((s + i)->eng) <= 70)
			(g + i)->subE = "D+";
		else if (atoi((s + i)->eng) > 60 && atoi((s + i)->eng) <= 65)
			(g + i)->subE = "D ";
		else
			(g + i)->subE = "F ";
	}
	for (i = 0; i < stucheckcount; i++) {
		if (atoi((s + i)->mat) > 95)
			(g + i)->subM = "A+";
		else if (atoi((s + i)->mat) > 90 && atoi((s + i)->mat) <= 95)
			(g + i)->subM = "A ";
		else if (atoi((s + i)->mat) > 85 && atoi((s + i)->mat) <= 90)
			(g + i)->subM = "B+";
		else if (atoi((s + i)->mat) > 80 && atoi((s + i)->mat) <= 85)
			(g + i)->subM = "B ";
		else if (atoi((s + i)->mat) > 75 && atoi((s + i)->mat) <= 80)
			(g + i)->subM = "C+";
		else if (atoi((s + i)->mat) > 70 && atoi((s + i)->mat) <= 75)
			(g + i)->subM = "C ";
		else if (atoi((s + i)->mat) > 65 && atoi((s + i)->mat) <= 70)
			(g + i)->subM = "D+";
		else if (atoi((s + i)->mat) > 60 && atoi((s + i)->mat) <= 65)
			(g + i)->subM = "D ";
		else
			(g + i)->subM = "F ";
	}

	for (i = 0; i < stucheckcount; i++) {
		//�Էµ� ������ ���� ���� �׿����� ��հ� �����ο�            
		(s + i)->sum = atoi((s + i)->kor) + atoi((s + i)->eng) + atoi((s + i)->mat);
		(s + i)->avg = (double)((s + i)->sum) / 3;
		//��տ����� �����ο�
		if ((s + i)->avg > 95)
			(g + i)->totG = "A+";
		else if ((s + i)->avg > 90 && (s + i)->avg <= 95)
			(g + i)->totG = "A ";
		else if ((s + i)->avg > 85 && (s + i)->avg <= 90)
			(g + i)->totG = "B+";
		else if ((s + i)->avg > 80 && (s + i)->avg <= 85)
			(g + i)->totG = "B ";
		else if ((s + i)->avg > 75 && (s + i)->avg <= 80)
			(g + i)->totG = "C+";
		else if ((s + i)->avg > 70 && (s + i)->avg <= 75)
			(g + i)->totG = "C ";
		else if ((s + i)->avg > 65 && (s + i)->avg <= 70)
			(g + i)->totG = "D+";
		else if ((s + i)->avg > 60 && (s + i)->avg <= 65)
			(g + i)->totG = "D ";
		else
			(g + i)->totG = "F ";
	}
}
void add_setgrade(struct add_student *as, struct grade_info *g) {
	for (i = 0; i < stucheckcount; i++) {
		if (atoi((as + i)->kor) > 95)
			(g + i)->subK = "A+";
		else if (atoi((as + i)->kor) > 90 && atoi((as + i)->kor) <= 95)
			(g + i)->subK = "A ";
		else if (atoi((as + i)->kor) > 85 && atoi((as + i)->kor) <= 90)
			(g + i)->subK = "B+";
		else if (atoi((as + i)->kor) > 80 && atoi((as + i)->kor) <= 85)
			(g + i)->subK = "B ";
		else if (atoi((as + i)->kor) > 75 && atoi((as + i)->kor) <= 80)
			(g + i)->subK = "C+";
		else if (atoi((as + i)->kor) > 70 && atoi((as + i)->kor) <= 75)
			(g + i)->subK = "C ";
		else if (atoi((as + i)->kor) > 65 && atoi((as + i)->kor) <= 70)
			(g + i)->subK = "D+";
		else if (atoi((as + i)->kor) > 60 && atoi((as + i)->kor) <= 65)
			(g + i)->subK = "D ";
		else
			(g + i)->subK = "F ";
	}
	for (i = 0; i < stucheckcount; i++) {
		if (atoi((as + i)->eng) > 95)
			(g + i)->subE = "A+";
		else if (atoi((as + i)->eng) > 90 && atoi((as + i)->eng) <= 95)
			(g + i)->subE = "A ";
		else if (atoi((as + i)->eng) > 85 && atoi((as + i)->eng) <= 90)
			(g + i)->subE = "B+";
		else if (atoi((as + i)->eng) > 80 && atoi((as + i)->eng) <= 85)
			(g + i)->subE = "B ";
		else if (atoi((as + i)->eng) > 75 && atoi((as + i)->eng) <= 80)
			(g + i)->subE = "C+";
		else if (atoi((as + i)->eng) > 70 && atoi((as + i)->eng) <= 75)
			(g + i)->subE = "C ";
		else if (atoi((as + i)->eng) > 65 && atoi((as + i)->eng) <= 70)
			(g + i)->subE = "D+";
		else if (atoi((as + i)->eng) > 60 && atoi((as + i)->eng) <= 65)
			(g + i)->subE = "D ";
		else
			(g + i)->subE = "F ";
	}
	for (i = 0; i < stucheckcount; i++) {
		if (atoi((as + i)->mat) > 95)
			(g + i)->subM = "A+";
		else if (atoi((as + i)->mat) > 90 && atoi((as + i)->mat) <= 95)
			(g + i)->subM = "A ";
		else if (atoi((as + i)->mat) > 85 && atoi((as + i)->mat) <= 90)
			(g + i)->subM = "B+";
		else if (atoi((as + i)->mat) > 80 && atoi((as + i)->mat) <= 85)
			(g + i)->subM = "B ";
		else if (atoi((as + i)->mat) > 75 && atoi((as + i)->mat) <= 80)
			(g + i)->subM = "C+";
		else if (atoi((as + i)->mat) > 70 && atoi((as + i)->mat) <= 75)
			(g + i)->subM = "C ";
		else if (atoi((as + i)->mat) > 65 && atoi((as + i)->mat) <= 70)
			(g + i)->subM = "D+";
		else if (atoi((as + i)->mat) > 60 && atoi((as + i)->mat) <= 65)
			(g + i)->subM = "D ";
		else
			(g + i)->subM = "F ";
	}

	for (i = 0; i < stucheckcount; i++) {
		//�Էµ� ������ ���� ���� �׿����� ��հ� �����ο�            
		(as + i)->sum = atoi((as + i)->kor) + atoi((as + i)->eng) + atoi((as + i)->mat);
		(as + i)->avg = (double)((as + i)->sum) / 3;
		//��տ����� �����ο�
		if ((as + i)->avg > 95)
			(g + i)->totG = "A+";
		else if ((as + i)->avg > 90 && (as + i)->avg <= 95)
			(g + i)->totG = "A ";
		else if ((as + i)->avg > 85 && (as + i)->avg <= 90)
			(g + i)->totG = "B+";
		else if ((as + i)->avg > 80 && (as + i)->avg <= 85)
			(g + i)->totG = "B ";
		else if ((as + i)->avg > 75 && (as + i)->avg <= 80)
			(g + i)->totG = "C+";
		else if ((as + i)->avg > 70 && (as + i)->avg <= 75)
			(g + i)->totG = "C ";
		else if ((as + i)->avg > 65 && (as + i)->avg <= 70)
			(g + i)->totG = "D+";
		else if ((as + i)->avg > 60 && (as + i)->avg <= 65)
			(g + i)->totG = "D ";
		else
			(g + i)->totG = "F ";
	}
}

void load_setgrade(struct load_student *ls, struct grade_info *g, int load_grade_count) { //�л� �Է��� ��޺ο�
		for (i = 0; i < load_grade_count; i++) {
		if (atoi((ls + i)->kor) > 95)
			(g + i)->subK = "A+";
		else if (atoi((ls + i)->kor) > 90 && atoi((ls + i)->kor) <= 95)
			(g + i)->subK = "A ";
		else if (atoi((ls + i)->kor) > 85 && atoi((ls + i)->kor) <= 90)
			(g + i)->subK = "B+";
		else if (atoi((ls + i)->kor) > 80 && atoi((ls + i)->kor) <= 85)
			(g + i)->subK = "B ";
		else if (atoi((ls + i)->kor) > 75 && atoi((ls + i)->kor) <= 80)
			(g + i)->subK = "C+";
		else if (atoi((ls + i)->kor) > 70 && atoi((ls + i)->kor) <= 75)
			(g + i)->subK = "C ";
		else if (atoi((ls + i)->kor) > 65 && atoi((ls + i)->kor) <= 70)
			(g + i)->subK = "D+";
		else if (atoi((ls + i)->kor) > 60 && atoi((ls + i)->kor) <= 65)
			(g + i)->subK = "D ";
		else
			(g + i)->subK = "F ";
	}
	for (i = 0; i < load_grade_count; i++) {
		if (atoi((ls + i)->eng) > 95)
			(g + i)->subE = "A+";
		else if (atoi((ls + i)->eng) > 90 && atoi((ls + i)->eng) <= 95)
			(g + i)->subE = "A ";
		else if (atoi((ls + i)->eng) > 85 && atoi((ls + i)->eng) <= 90)
			(g + i)->subE = "B+";
		else if (atoi((ls + i)->eng) > 80 && atoi((ls + i)->eng) <= 85)
			(g + i)->subE = "B ";
		else if (atoi((ls + i)->eng) > 75 && atoi((ls + i)->eng) <= 80)
			(g + i)->subE = "C+";
		else if (atoi((ls + i)->eng) > 70 && atoi((ls + i)->eng) <= 75)
			(g + i)->subE = "C ";
		else if (atoi((ls + i)->eng) > 65 && atoi((ls + i)->eng) <= 70)
			(g + i)->subE = "D+";
		else if (atoi((ls + i)->eng) > 60 && atoi((ls + i)->eng) <= 65)
			(g + i)->subE = "D ";
		else
			(g + i)->subE = "F ";
	}
	for (i = 0; i < load_grade_count; i++) {
		if (atoi((ls + i)->mat) > 95)
			(g + i)->subM = "A+";
		else if (atoi((ls + i)->mat) > 90 && atoi((ls + i)->mat) <= 95)
			(g + i)->subM = "A ";
		else if (atoi((ls + i)->mat) > 85 && atoi((ls + i)->mat) <= 90)
			(g + i)->subM = "B+";
		else if (atoi((ls + i)->mat) > 80 && atoi((ls + i)->mat) <= 85)
			(g + i)->subM = "B ";
		else if (atoi((ls + i)->mat) > 75 && atoi((ls + i)->mat) <= 80)
			(g + i)->subM = "C+";
		else if (atoi((ls + i)->mat) > 70 && atoi((ls + i)->mat) <= 75)
			(g + i)->subM = "C ";
		else if (atoi((ls + i)->mat) > 65 && atoi((ls + i)->mat) <= 70)
			(g + i)->subM = "D+";
		else if (atoi((ls + i)->mat) > 60 && atoi((ls + i)->mat) <= 65)
			(g + i)->subM = "D ";
		else
			(g + i)->subM = "F ";
	}

	for (i = 0; i < load_grade_count; i++) {
		//�Էµ� ������ ���� ���� �׿����� ��հ� �����ο�            
		(ls + i)->sum = atoi((ls + i)->kor) + atoi((ls + i)->eng) + atoi((ls + i)->mat);
		(ls + i)->avg = (double)((ls + i)->sum) / 3;
		//��տ����� �����ο�
		if ((ls + i)->avg > 95)
			(g + i)->totG = "A+";
		else if ((ls + i)->avg > 90 && (ls + i)->avg <= 95)
			(g + i)->totG = "A ";
		else if ((ls + i)->avg > 85 && (ls + i)->avg <= 90)
			(g + i)->totG = "B+";
		else if ((ls + i)->avg > 80 && (ls + i)->avg <= 85)
			(g + i)->totG = "B ";
		else if ((ls + i)->avg > 75 && (ls + i)->avg <= 80)
			(g + i)->totG = "C+";
		else if ((ls + i)->avg > 70 && (ls + i)->avg <= 75)
			(g + i)->totG = "C ";
		else if ((ls + i)->avg > 65 && (ls + i)->avg <= 70)
			(g + i)->totG = "D+";
		else if ((ls + i)->avg > 60 && (ls + i)->avg <= 65)
			(g + i)->totG = "D ";
		else
			(g + i)->totG = "F ";
	}
}
int isStringDouble(char *s) { //���ڿ� �˻�
	size_t size = strlen(s);
	if (size == 0) return 0; // 0����Ʈ ���ڿ��� ���ڰ� �ƴ�

	for (int i = 0; i < (int)size; i++) {
		if (s[i] == '.' || s[i] == '-' || s[i] == '+') continue;
		if (s[i] < '0' || s[i] > '9') return 0; // ���ĺ� ���� ������ ���� �ƴ�
	}
	return 1; // �׹��� ���� ������
}