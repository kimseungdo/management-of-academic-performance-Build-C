#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <conio.h>

#include "logINFO_Structer.h"
int i, j, k;
static int ii;
void gotoxy(int x, int y);
extern int total_size;



void input_professor_info() { //1.���������Է�

	struct professor_info *ip;//����ü ������ ����
	ip = malloc(sizeof(struct professor_info)*20);//�����ڰ� ������ ����ŭ ����ü������ �����Ҵ�
	for (i = 0; i < 20; i++) {
		ip[i].name = (char*)malloc(sizeof(char) * 10);
		ip[i].pass = (char*)malloc(sizeof(int) * 10);
	}
	struct load_professor {
		char *name;
		char *pass;
	};
	struct load_professor *lp;//����ü ������ ����
	lp = malloc(sizeof(struct professor_info) * 20);//�����ڰ� ������ ����ŭ ����ü������ �����Ҵ�
	for (i = 0; i < 20; i++) {
		lp[i].name = (char*)malloc(sizeof(char) * 10);
		lp[i].pass = (char*)malloc(sizeof(int) * 10);
	}
	system("cls");

		ii=0;
		int count = 0;
		int total = 0;
		int Padd = 0;
	while (1) {
		int ch;
		//������ �Է� �߰��ϱ� �����ϱ�
		gotoxy(22, 7);   printf("1. ���� �̸� �Է�(�����Է�)"); // void 
		gotoxy(22, 8);	 printf("2. ���� ���� �߰�"); //void add_professor 	FILE *fp = fopen(".\\professor_info.txt", "a");
		gotoxy(22, 9);   printf("3. ���� ���� ��ȸ"); //void remove_professor 	FILE *fp = fopen(".\\professor_info.txt", "w");
		//gotoxy(22, 10);  printf("4. �������� �ҷ�����"); //void load_professor	    FILE *fp = fopen(".\\professor_info.txt", "r");
		gotoxy(22, 10);  printf("4. ������");

		gotoxy(22, 14);  printf("type nomber: "); scanf("%d", &ch);
		fflush(stdin);
		system("cls");

		switch (ch) {
		case 1://1. ���� ���� �Է� ( o.o )

			while (1) {
				int ch1;
				printf("���� �Էµ� ���� ����Դϴ�.\n");
				for (j = 0; j < ii; j++) {
					printf("\t%s\n", (ip + j)->name);
				}
				printf("������ �̸��� �Է��Ͻʽÿ� : (�Է��� �����÷��� quit�Է�) "); scanf("%s", (ip + ii)->name); //����ü�� �� �̸� ����
				fflush(stdin);
				if (strcmp((ip + ii)->name, "quit") == 0) {
					FILE *fp = fopen(".\\login_file\\professor_info.txt", "w");//���Ͼ���
					if (fp == NULL) {
						system("cls");
						gotoxy(20, 8); printf("���ȿ��Ȱ� �߰��ð�");
						exit(0);
					}
					for (j = 0; j < ii; j++) {
						fprintf(fp, "%s %s\n", (ip + j)->name, (ip + j)->pass);
					}fclose(fp);
					(ip + ii)->name = "";
					break;
				}
				strcpy((ip + ii)->pass, "1234"); //�ʱ� ��й�ȣ�� 1234�� ����
				//fprintf(fp, "%s %s", (ip + i)->name, (ip + i)->pass);
				printf("�� �Է��Ͻðڽ��ϱ�? 1.Yes 2.No \n"); 
				printf("       type nomber : "); scanf("%d", &ch1); fflush(stdin);
				if (ch1 == 1) {
					system("cls");
					ii++;
					j++;
					continue;
				}
				else if (ch1 == 2) {
					FILE *fp = fopen(".\\login_file\\professor_info.txt", "w");//���Ͼ���
					if (fp == NULL) {
						system("cls");
						gotoxy(20, 8); printf("���ȿ��Ȱ� �߰��ð�");
						exit(0);
					}
					for (j = 0; j < ii+1; j++) {
						fprintf(fp, "%s %s\n", (ip + j)->name, (ip + j)->pass);
					}fclose(fp);
					system("cls");
					break;
				}
				else {
					printf("�ٽ� �Է��ϼ�");
				}
			}

			break;

		case 2://2. ���� ���� �߰�  > ^ <

			while (1) {
				int ch1;
				char Pname[10];

				FILE *fp = fopen(".\\login_file\\professor_info.txt", "a+");

				if (fp == NULL) {
					system("cls");
					gotoxy(20, 8); printf("���ȿ��Ȱ� �߰��ð�");
					exit(0);
				}
				i = 0;
				printf("���� �Էµ� ���� ���\n");
				while (!feof(fp)){
					//�������� �и��� ���� �б�
					fscanf(fp, "%s %s\n", (lp+i)->name, (lp+i)->pass);
					printf("\t%s\n", (lp+i)->name);
					i++;//���� ���Ͽ� ���ִ� �� ũ��
					count++;
				}

				printf("�߰��� ���� �̸��� �Է��Ͻʽÿ� : (�Է��� �����÷��� quit�Է�) "); scanf("%s", Pname);
				Padd++;
				if (strcmp(Pname, "quit") == 0) {
					
					system("cls");
					ii++;
					break;
				}

				printf("�� �Է��Ͻðڽ��ϱ�? 1.Yes 2.No \n");
				printf("       type nomber : "); scanf("%d", &ch1);
				Padd++;

				strcpy((lp + Padd)->name, Pname);
				strcpy((lp + Padd)->pass, "1234");
				fprintf(fp, "%s %s\n", (lp + Padd)->name, (lp + Padd)->pass);

				if (ch1 == 1) {
					fclose(fp);
					system("cls");
					continue;
				}
				else if (ch1 == 2) {
					fclose(fp);
					system("cls");
					break;
				}
				else printf("�ٽ��Է��ϼ�\n");
			}
			break;

		case 3://3. ���� ��ȸ

			while (1) {
				int ch1;
				i = 0;
				FILE *fp = fopen(".\\login_file\\professor_info.txt", "a+");

				if (fp == NULL) {
					system("cls");
					gotoxy(20, 8); printf("���ȿ��Ȱ� �߰��ð�");
					exit(0);
				}

				printf("���� �Էµ� ���� ���\n");
				while (!feof(fp)) {
					//�������� �и��� ���� �б�
					fscanf(fp, "%s %s\n", (lp + i)->name, (lp + i)->pass);
					printf("\t%s\n", (lp + i)->name);
					i++;//���� ���Ͽ� ���ִ� �� ũ��
					count++;
				}

				printf("��ȸ�� �����Ͻðڽ��ϱ�? 1.Yes 2.No \n");
				printf("       type nomber : "); scanf("%d", &ch1);
				if (ch1 == 1) {
					fclose(fp);
					system("cls");
					break;
				}
				else if (ch1 == 2) {
					fclose(fp);
					system("cls");
					continue;
				}
			}
			break;

		/*case 4://4. �������� �ҷ�����

			while (1) {
				char buffer[10] = { 0, };    // ���ڿ� ������ 4����Ʈ NULL 1����Ʈ. 4 + 1 = 5
				int count = 0;
				int total = 0;

				FILE *fp = fopen(".\\login_file\\professor_info.txt", "r");
				while (feof(fp) == 0) {    // ���� �����Ͱ� ������ ���� �ƴ� �� ��� �ݺ�
					count = fread(buffer, sizeof(char), 4, fp);    // 1����Ʈ�� 4��(4����Ʈ) �б�
					printf("\t%s", buffer);                          // ���� ���� ���
					memset(buffer, 0, 5);                          // ���۸� 0���� �ʱ�ȭ
					total += count;                                // ���� ũ�� ����
				}
			}
			break;*/

		case 4://5. ������

			break;

		default:
			gotoxy(22, 15); printf("ERROR :1���� 4���� ���ڸ� �Է��ϼ���\n");
			break;
		}break;
		
	}
}

//void load_professor_info(struct professor *lp, int formal, int last) { }

/*void setting_program(struct program *pp) {//3.�л� �������� ������ �ε��ؼ� �л��ο��� �޾ƿð�

	system("cls");

	FILE *sp = fopen("set_program.txt", "w"); //������
	if (sp == NULL) {
		system("cls");
		gotoxy(20, 8); printf("���ȿ��Ȱ� �߰��ð�");
		exit(0);
	}

	gotoxy(20, 8); printf("�ִ��ο��� ������� ?: "); scanf("%d", &total_size);
	fprintf(sp, "%d", total_size);
	fflush(stdin); //��������
	fclose(sp);
	input_success();
}*/

void load_student_info() {

	struct student_info *kp;//����ü ������ ����
	kp = malloc(sizeof(struct student_info) * 20);//�����ڰ� ������ ����ŭ ����ü������ �����Ҵ�
	for (i = 0; i < 20; i++) {
		kp[i].name = (char*)malloc(sizeof(char) * 10);
		kp[i].pass = (char*)malloc(sizeof(int) * 10);
	}
	struct load_student {
		char *name;
		char *pass;
	};
	struct load_student *jp;//����ü ������ ����
	jp = malloc(sizeof(struct professor_info) * 20);//�����ڰ� ������ ����ŭ ����ü������ �����Ҵ�
	for (i = 0; i < 20; i++) {
		jp[i].name = (char*)malloc(sizeof(char) * 10);
		jp[i].pass = (char*)malloc(sizeof(int) * 10);
	}
	system("cls");

	ii = 0;
	int count = 0;
	int total = 0;
	int Padd = 0;
	while (1) {
		int ch;
		//������ �Է� �߰��ϱ� �����ϱ�
		gotoxy(22, 7);   printf("1. �л� �̸� �Է�(�����Է�)"); // void 
		gotoxy(22, 8);	 printf("2. �л� ���� �߰�"); //void add_professor 	FILE *fp = fopen(".\\professor_info.txt", "a");
		gotoxy(22, 9);   printf("3. �л� ���� ��ȸ"); //void remove_professor 	FILE *fp = fopen(".\\professor_info.txt", "w");
		//gotoxy(22, 10);  printf("4. �������� �ҷ�����"); //void load_professor	    FILE *fp = fopen(".\\professor_info.txt", "r");
		gotoxy(22, 10);  printf("4. ������");

		gotoxy(22, 14);  printf("type nomber: "); scanf("%d", &ch);
		fflush(stdin);
		system("cls");

		switch (ch) {
		case 1://1. ���� ���� �Է� ( o.o )

			while (1) {
				int ch1;
				printf("���� �Էµ� �л� ����Դϴ�.\n");
				for (j = 0; j < ii; j++) {
					printf("\t%s\n", (kp + j)->name);
				}
				printf("�л��� �̸��� �Է��Ͻʽÿ� : (�Է��� �����÷��� quit�Է�) "); scanf("%s", (kp + ii)->name); //����ü�� �� �̸� ����
				fflush(stdin);
				if (strcmp((kp + ii)->name, "quit") == 0) {
					FILE *fp = fopen(".\\login_file\\student_info.txt", "w");//���Ͼ���
					if (fp == NULL) {
						system("cls");
						gotoxy(20, 8); printf("���ȿ��Ȱ� �߰��ð�");
						exit(0);
					}
					for (j = 0; j < ii; j++) {
						fprintf(fp, "%s %s\n", (kp + j)->name, (kp + j)->pass);
					}fclose(fp);
					(kp + ii)->name = "";
					break;
				}
				strcpy((kp + ii)->pass, "1234"); //�ʱ� ��й�ȣ�� 1234�� ����
				//fprintf(fp, "%s %s", (ip + i)->name, (ip + i)->pass);
				printf("�� �Է��Ͻðڽ��ϱ�? 1.Yes 2.No \n");
				printf("       type nomber : "); scanf("%d", &ch1); fflush(stdin);
				if (ch1 == 1) {
					system("cls");
					ii++;
					j++;
					continue;
				}
				else if (ch1 == 2) {
					FILE *fp = fopen(".\\login_file\\student_info.txt", "w");//���Ͼ���
					if (fp == NULL) {
						system("cls");
						gotoxy(20, 8); printf("���ȿ��Ȱ� �߰��ð�");
						exit(0);
					}
					for (j = 0; j < ii + 1; j++) {
						fprintf(fp, "%s %s\n", (kp + j)->name, (kp + j)->pass);
					}fclose(fp);
					system("cls");
					break;
				}
				else {
					printf("�ٽ� �Է��ϼ�");
				}
			}

			break;

		case 2://2. ���� ���� �߰�  > ^ <

			while (1) {
				int ch1;
				char Sname[10];

				FILE *fp = fopen(".\\login_file\\student_info.txt", "a+");

				if (fp == NULL) {
					system("cls");
					gotoxy(20, 8); printf("���ȿ��Ȱ� �߰��ð�");
					exit(0);
				}
				i = 0;
				printf("���� �Էµ� �л� ���\n");
				while (!feof(fp)) {
					//�������� �и��� ���� �б�
					fscanf(fp, "%s %s\n", (jp + i)->name, (jp + i)->pass);
					printf("\t%s\n", (jp + i)->name);
					i++;//���� ���Ͽ� ���ִ� �� ũ��
					count++;
				}

				printf("�߰��� �л� �̸��� �Է��Ͻʽÿ� : (�Է��� �����÷��� quit�Է�) "); scanf("%s", Sname);
				Padd++;
				if (strcmp(Sname, "quit") == 0) {

					system("cls");
					ii++;
					break;
				}

				printf("�� �Է��Ͻðڽ��ϱ�? 1.Yes 2.No \n");
				printf("       type nomber : "); scanf("%d", &ch1);
				Padd++;

				strcpy((jp + Padd)->name, Sname);
				strcpy((jp + Padd)->pass, "1234");
				fprintf(fp, "%s %s\n", (jp + Padd)->name, (jp + Padd)->pass);

				if (ch1 == 1) {
					fclose(fp);
					system("cls");
					continue;
				}
				else if (ch1 == 2) {
					fclose(fp);
					system("cls");
					break;
				}
				else printf("�ٽ��Է��ϼ�\n");
			}
			break;

			case 3://3. �л� ��ȸ

				while (1) {
					int ch1;
					i = 0;
					FILE *fp = fopen(".\\login_file\\student_info.txt", "a+");

					if (fp == NULL) {
						system("cls");
						gotoxy(20, 8); printf("���ȿ��Ȱ� �߰��ð�");
						exit(0);
					}

					printf("���� �Էµ� �л� ���\n");
					while (!feof(fp)) {
						//�������� �и��� ���� �б�
						fscanf(fp, "%s %s\n", (jp + i)->name, (jp + i)->pass);
						printf("\t%s\n", (jp + i)->name);
						i++;//���� ���Ͽ� ���ִ� �� ũ��
						count++;
					}

					printf("��ȸ�� �����Ͻðڽ��ϱ�? 1.Yes 2.No \n");
					printf("       type nomber : "); scanf("%d", &ch1);
					if (ch1 == 1) {
						fclose(fp);
						system("cls");
						break;
					}
					else if (ch1 == 2) {
						fclose(fp);
						system("cls");
						continue;
					}
				}

				break;

			/*case 4://4. �������� �ҷ�����

				while (1) {
					char buffer[10] = { 0, };    // ���ڿ� ������ 4����Ʈ NULL 1����Ʈ. 4 + 1 = 5
					int count = 0;
					int total = 0;

					FILE *fp = fopen(".\\login_file\\professor_info.txt", "r");
					while (feof(fp) == 0) {    // ���� �����Ͱ� ������ ���� �ƴ� �� ��� �ݺ�
						count = fread(buffer, sizeof(char), 4, fp);    // 1����Ʈ�� 4��(4����Ʈ) �б�
						printf("\t%s", buffer);                          // ���� ���� ���
						memset(buffer, 0, 5);                          // ���۸� 0���� �ʱ�ȭ
						total += count;                                // ���� ũ�� ����
					}
				}
				break;*/

		case 4://5. ������

			break;

		default:
			gotoxy(22, 15); printf("ERROR :1���� 3���� ���ڸ� �Է��ϼ���\n");
			break;
		}break;

	}
}

void list_dir() {
	int ch;
	while (1) {
		struct _finddata_t fd;
		long handle;
		int result = 1;

		handle = _findfirst(".\\*.*", &fd);
		if (handle == -1)return;

		while (result != -1){
			printf("���ϸ� : %s, ũ��:%d\n", fd.name, fd.size);
			result = _findnext(handle, &fd);
		}

		_findclose(handle);
		printf("�ٔf��? 1���� 2���"); scanf("%d", &ch);
		if (ch == 1) break;
		else continue;
	}
}