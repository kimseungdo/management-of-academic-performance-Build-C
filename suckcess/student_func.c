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

		printf("┏━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃            이거슨 자네의 성적표일세          ┃\n");
		printf("┃                                              ┃\n");
		printf("┃                                              ┃\n");
		//printf(" 존함   국어(학점)  영어(학점)  수학(학점)   총점  전체평균   전체평점\n");
		for (i = 0; i < load_grade_count; i++) {
			if (strcmp(ls[i].name, login_name) == 0) {//로그인한 입력과 성적이 입력된 구조체 이름이 같고
					printf("┃       이름 :  %6s                         ┃\n", (ls + i)->name);
					printf("┃                                              ┃\n");
					printf("┃       국어 :  %s  등급 : %s                  ┃\n", (ls + i)->kor, (g + i)->subK);
					printf("┃       영어 :  %s  등급 : %s                  ┃\n", (ls + i)->eng, (g + i)->subE);
					printf("┃       수학 :  %s  등급 : %s                  ┃\n", (ls + i)->mat, (g + i)->subM);
					printf("┃                                              ┃\n");
					printf("┃       총점 :  %d                            ┃\n", (ls + i)->sum);
					printf("┃       평균 :  %lf  등급 : %s           ┃\n", (ls + i)->avg, (g + i)->totG);
					/*
					printf("%2s %4s(%s) %8s(%s) %8s(%s) %6d %11lf %6s\n",//성적을 출력합니다.
						  (ls + i)->name, (ls + i)->kor, (g + i)->subK, (ls + i)->eng, (g + i)->subE, (ls + i)->mat, (g + i)->subM,
						  (ls + i)->sum, (ls + i)->avg, (g + i)->totG);
					*/
					break;
			}
			else if (i == (load_grade_count-1) && strcmp(ls[i].name, login_name) != 0) {//범위내 성적이 없으면 미입력으로 처리한다
				printf("┃       이름 :  %6s                         ┃\n", (lsi + s)->name);
				printf("┃                                              ┃\n");
				printf("┃       국어 :  미입력  등급 : X               ┃\n");
				printf("┃       영어 :  미입력  등급 : X               ┃\n");
				printf("┃       수학 :  미입력  등급 : X               ┃\n");
				printf("┃                                              ┃\n");
				printf("┃       총점 :  응없어                         ┃\n");
				printf("┃       평균 :  어없어  등급 : X               ┃\n");
			}

		}
		printf("┃                                              ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━┛\n");


		printf("\t다 보셨수? 1.yes 2.no : "); scanf("%d", &ch);
		switch (ch) {
		case 1:

			break;

		case 2:

			system("cls");
			continue;

		default:
			printf("잘못 입력하셨수\n");
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
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃            이거슨 주작한 성적표일세          ┃\n");
		printf("┃                                              ┃\n");
		printf("┃                                              ┃\n");
		printf("┃       이름 :  %6s                         ┃\n", login_name);
		printf("┃                                              ┃\n");
		printf("┃       국어 :  100     등급 : A+              ┃\n");
		printf("┃       영어 :  100     등급 : A+              ┃\n");
		printf("┃       수학 :  100     등급 : A+              ┃\n");
		printf("┃                                              ┃\n");
		printf("┃       총점 :  300                            ┃\n");
		printf("┃       평균 :  100     등급 : A+              ┃\n");
		printf("┃                                              ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━┛\n");

			printf("\t거 다 보셨수? 1.yes 2.no : "); scanf("%d", &ch);
		switch (ch) {
			
		case 1:

			break;

		case 2:

			system("cls");
			continue;
			break;

		default:
			printf("다시입력하세요\n");
			break;
		}break;
	}
}