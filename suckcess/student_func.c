#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#include "Student_Info_Structer.h"
#include "logINFO_Structer.h"

int i, j, k;

extern char login_name[10];
extern char mode[10];
extern load_grade_count;

void search_myinfo(struct load_student *ls, struct load_student_info *lsi, struct grade_info *g, int last) {
	int ch;
	int s;
	for (s = 0; s < last; s++) {
		if (strcmp((lsi + s)->name, login_name) == 0)
			break;
	}
	while (1) {

		printf("��������������������������������������������������\n");
		printf("��            �̰Ž� �ڳ��� ����ǥ�ϼ�          ��\n");
		printf("��                                              ��\n");
		printf("��                                              ��\n");
		//printf(" ����   ����(����)  ����(����)  ����(����)   ����  ��ü���   ��ü����\n");
		for (i = 0; i < load_grade_count; i++) {
			if (strcmp(ls[i].name, login_name) == 0) {//�α����� �Է°� ������ �Էµ� ����ü �̸��� ����
					printf("��       �̸� :  %6s                         ��\n", (ls + i)->name);
					printf("��                                              ��\n");
					printf("��       ���� :  %s  ��� : %s                  ��\n", (ls + i)->kor, (g + i)->subK);
					printf("��       ���� :  %s  ��� : %s                  ��\n", (ls + i)->eng, (g + i)->subE);
					printf("��       ���� :  %s  ��� : %s                  ��\n", (ls + i)->mat, (g + i)->subM);
					printf("��                                              ��\n");
					printf("��       ���� :  %d                            ��\n", (ls + i)->sum);
					printf("��       ��� :  %lf  ��� : %s           ��\n", (ls + i)->avg, (g + i)->totG);
					/*
					printf("%2s %4s(%s) %8s(%s) %8s(%s) %6d %11lf %6s\n",//������ ����մϴ�.
						  (ls + i)->name, (ls + i)->kor, (g + i)->subK, (ls + i)->eng, (g + i)->subE, (ls + i)->mat, (g + i)->subM,
						  (ls + i)->sum, (ls + i)->avg, (g + i)->totG);
					*/
					break;
			}
			else if (i == (load_grade_count-1) && strcmp(ls[i].name, login_name) != 0) {//������ ������ ������ ���Է����� ó���Ѵ�
				printf("��       �̸� :  %6s                         ��\n", (lsi + s)->name);
				printf("��                                              ��\n");
				printf("��       ���� :  ���Է�  ��� : X               ��\n");
				printf("��       ���� :  ���Է�  ��� : X               ��\n");
				printf("��       ���� :  ���Է�  ��� : X               ��\n");
				printf("��                                              ��\n");
				printf("��       ���� :  ������                         ��\n");
				printf("��       ��� :  �����  ��� : X               ��\n");
			}

		}
		printf("��                                              ��\n");
		printf("��������������������������������������������������\n");


		printf("\t�� ���̼�? 1.yes 2.no : "); scanf("%d", &ch);
		switch (ch) {
		case 1:

			break;

		case 2:

			system("cls");
			continue;

		default:
			printf("�߸� �Է��ϼ̼�\n");
		}break;
	}

	system("cls");

}

void plz_give_AP() {

	printf("8888888b.  888      8888888888P.      d8888b.     d8b\n");
	printf("888   Y88b 888            d88P       d88P  Y88b   Y8P\n");
	printf("888    888 888           d88P        888    888\n");
	printf("888   d88P 888          d88P         888          888 888  888.d88b.\n");
	printf("8888888P'  888         d88P          888  88888   888 888  888 d8P  Y8b \n");
	printf("888        888        d88P           888    888   888 Y88  88P 88888888\n");
	printf("888        888       d88P            Y88b  d88P   888  Y8bd8P  Y8b.\n");
	printf("888        88888888 d8888888888       'Y8888P88   888   Y88P    'Y8888\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("888b     d888 8888888888             d8888\n");
	printf("888b     d888 8888888888             d8888\n");
	printf("8888b   d8888 888                   d88888\n");
	printf("88888b.d88888 888                  d88P888\n");
	printf("888Y88888P888 8888888             d88P 888   888\n");
	printf("888 Y888P 888 888                d88P  888 8888888\n");
	printf("888  Y8P  888 888               d88P   888   888\n");
	printf("888   '   888 888              d8888888888  \n");
	printf("888       888 8888888888      d88P     888\n");
	Sleep(1000);
	system("cls");
	int ch = 0;
	while (1) {
		printf("��������������������������������������������������\n");
		printf("��            �̰Ž� ������ ����ǥ�ϼ�          ��\n");
		printf("��                                              ��\n");
		printf("��                                              ��\n");
		printf("��       �̸� :  %6s                         ��\n", login_name);
		printf("��                                              ��\n");
		printf("��       ���� :  100     ��� : A+              ��\n");
		printf("��       ���� :  100     ��� : A+              ��\n");
		printf("��       ���� :  100     ��� : A+              ��\n");
		printf("��                                              ��\n");
		printf("��       ���� :  300                            ��\n");
		printf("��       ��� :  100     ��� : A+              ��\n");
		printf("��                                              ��\n");
		printf("��������������������������������������������������\n");

			printf("\t�� �� ���̼�? 1.yes 2.no : "); scanf("%d", &ch);
		switch (ch) {
			
		case 1:

			break;

		case 2:

			system("cls");
			continue;
			break;

		default:
			printf("�ٽ��Է��ϼ���\n");
			break;
		}break;
	}
}