#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

#include "logINFO_Structer.h" //�α��� ������ �����ϱ����� ����ü


int i;
static int login_count = 0;

extern int total_size;
extern int professor_size;
int procheckcount = 0;
int stucheckcount = 0;

char login_name[10]; //���߿� id�� �ɰ� ������ �̸����� �ĺ�
char mode[10]; //�̸� �ĺ��� ���� ���� �ο�

void show_success();
void show_welcome();
void show_fail();

int procheck(char *passwd, struct professor_info *lp);
int stucheck(char *passwd, struct student_info *sp);


void login_logic() {

	i = 0;
	procheckcount = 0;
	FILE *p = fopen(".\\login_file\\professor_info.txt", "r"); //�������� �ε�
	struct professor_info *lp = malloc(sizeof(struct professor_info)*professor_size);
	while (1) {
		if (feof(p)) break;
		lp[i].name = (char*)malloc(sizeof(char) * 10);
		lp[i].pass = (char*)malloc(sizeof(char) * 20);
		fscanf(p, "%s %s", lp[i].name, lp[i].pass);
		//printf("%s\n %s\n", lp[i].name, lp[i].pass);
		//Sleep(1000);
		i++;
		procheckcount++;
	} 
	procheckcount--;
	/*for (i = 0; i < professor_size; i++) {
		lp[i].name = (char*)malloc(sizeof(char) * 10);
		lp[i].pass = (char*)malloc(sizeof(char) * 20);
		fscanf(p, "%s %s", lp[i].name, lp[i].pass);
		printf("%s\n %s\n", lp[i].name, lp[i].pass);
		Sleep(1000);
	}*/
	system("cls");
	fclose(p);

	i = 0;
	stucheckcount = 0;
	FILE *s = fopen(".\\login_file\\student_info.txt", "r"); //�л����� �ε�
	struct student_info *sp = malloc(sizeof(struct student_info)*10);
	while(1) {
		if (feof(s)) break;
		sp[i].name = (char*)malloc(sizeof(char) * 10);
		sp[i].pass = (char*)malloc(sizeof(char) * 30);
		fscanf(s, "%s %s", sp[i].name, sp[i].pass);
		//printf("%s\n %s\n", sp[i].name, sp[i].pass);
		//Sleep(1000);
		i++;
		stucheckcount++;
	}
	stucheckcount--;
	system("cls");
	fclose(s);

	if (login_count > 1) {
		login_name[10] = "";
		mode[10] = "";
	}
	printf("ooooo                                ooooo ooooo      ooo\n");
	printf("`888'                                `888' `888b.     `8'\n");
	printf(" 888          .ooooo.   .oooooooo     888   8 `88b.    8\n");
	printf(" 888         d88' `88b 888' `88b      888   8   `88b.  8\n");
	printf(" 888         888   888 888   888      888   8     `88b.8\n");
	printf(" 888       o 888   888 `88bod8P'      888   8       `888\n");
	printf("o888ooooood8 `Y8bod8P' `8oooooo.     o888o o8o        `8\n");
	printf("                       d*     YD\n");
	printf("                       *Y88888P\n");

	char *passwd;//Ű�� �޴� �迭
	passwd = (char *)malloc(sizeof(10));

	int key = 0;//Ű�� �޴� ����
	int Keycount = 0;
	int passnum = 0;
	int firstkey = 0;


	printf("\t\t���̵� : "); scanf("%s", login_name);
	printf("\t��й�ȣ [�ִ���̴� 10, �ʱ� ��й�ȣ�� 1234] : ");
	while (1) {
		key = _getch();  // �� ���� �Է¹���
		if (key == 13)  // ���� Ű�� ����
			break;
		if (key != '\0' && Keycount == 0) {
			putchar('*');  // ȭ�鿡 �� ǥ��
			*(passwd + passnum) = (char)key;
			firstkey = key;
			//passwd[passnum] = (char)key; // ���ۿ� ���� �����ϰ� ī��Ʈ 1 ����
			//printf("%c", *(passwd + passnum));
			Keycount++;
		}
		else if (key != '\0' && Keycount != 0) {
			putchar('*');  // ȭ�鿡 �� ǥ��
			*(passwd + passnum) = (char)key;
			*(passwd + passnum - Keycount) = *(passwd + passnum);
			//passwd[passnum] = (char)key;   // ���ۿ� ���� �����ϰ� ī��Ʈ 1 ����
			//passwd[passnum - Keycount] = passwd[passnum];
			//printf("%c", *(passwd + passnum - Keycount));
			Keycount++;
		}
		passnum++;
	}
	passwd[0] = (char)firstkey;
	passwd[Keycount] = '\0';

	system("cls");

	if (strcmp(login_name, "������") == 0) { //�����ڸ��
		if (strcmp(passwd, "1234") == 0) { //�α��� ������
			show_success();
			//Sleep(2);
			show_welcome();
			//Sleep(1);
			//mode[10] = "������";
			strcpy(mode, "������");
			//printf("%s", mode);
			Sleep(2000);

		}
	}

	else if (procheck(passwd, lp) == 1) {
		show_success();
		Sleep(2);
		show_welcome();
		Sleep(1);
		
		strcpy(mode, "����");
		free(lp);
	}
	/*else if (procheck(passwd, lp) != 1) {
		free(lp);
	}*/

	/*printf("%s", (sp + 0)->pass);
	Sleep(1000);
	system("cls");*/
	
	else if (stucheck(passwd, sp) == 1) {
		show_success();
		Sleep(2);
		show_welcome();
		Sleep(1);

		strcpy(mode, "�л�");
		free(sp);
	}

	else {
		printf("���̵� Ȥ�� ��й�ȣ�� �߸� �Է��ϼ̽��ϴ�.\n");
		printf("%s", passwd);
		Sleep(1000);
		free(passwd);
		strcpy(mode, "����");
		system("cls");
	}
}

int procheck(char *passwd, struct professor_info *lp) {
	for (i = 0; i < procheckcount; i++) { //���� �̸��˻� ���������� �л����� ���
							   //�̸� �˻� �Ѿ���� �޸� ��ȯ
		/*printf("%s\n", (lp + i)->name);
		printf("%s\n", (lp + i)->pass);
		Sleep(1000);*/
		if (strcmp(login_name, (lp + i)->name) == 0) {
			if (strcmp(passwd, (lp + i)->pass) == 0) {
				return 1;
			}
			else if (i == procheckcount && strcmp(passwd, (lp + i)->pass) != 0) {
				printf("��ȣ�� Ʋ���ϴ�.");
				Sleep(1000);
				break;
			}
		}
		else if (i == procheckcount && strcmp(login_name, (lp + i)->name) != 0)
			break;
		else
			continue;
	}
	system("cls");
}

int stucheck(char *passwd, struct student_info *sp) {
	for (i = 0; i < stucheckcount; i++) {

		/*printf("%s\n", (sp + i)->name);
		printf("%s\n", (sp + i)->pass);
		Sleep(1000);*/
		if ((sp + i)->name == NULL) { //����ü�� �ڷᰡ ������ �ȉ����� ������
		   free(sp);
		   break;
		}

		if (strcmp(login_name, (sp + i)->name) == 0) {
			if (strcmp(passwd, (sp + i)->pass) == 0) {
				return 1;
			}
			else if (i == stucheckcount && strcmp(passwd, (sp + i)->pass) != 0) {
				printf("��ȣ�� Ʋ���ϴ�.");
				Sleep(1000);
				return -1;
			}
		}
		else if (i == stucheckcount && strcmp(login_name, (sp + i)->name) != 0) {
			printf("���� ����Դϴ�.");
			Sleep(1000);
			break;
		}

		
	}
}
	/*
	
	

	
	for (i = 0; i < professor_size; i++) { //���� �̸��˻� ���������� �л����� ���
								  //�̸� �˻� �Ѿ���� �޸� ��ȯ
	   if (strcmp(login_name, (lp + i)->name) == 0) {
		  if (strcmp(passwd, (lp + i)->pass) == 0) {
			 show_success();
			 Sleep(2);
			 show_welcome();
			 Sleep(1);

			 strcpy(mode, "����");
		  }
	   }
	}free(lp);
	for (i = 0; i < total_size; i++) {

	   if ((sp+i) != NULL) { //����ü�� �ڷᰡ ������ �ȉ����� ������
		  free(sp);
		  break;
	   }

	   if (strcmp(login_name, (sp + i)->name) == 0) {
		  if (strcmp(passwd, (sp + i)->pass) == 0) {
			 show_success();
			 Sleep(2);
			 show_welcome();
			 Sleep(1);

			 strcpy(mode, "�л�");
		  }
	   }
	}free(sp);*/




