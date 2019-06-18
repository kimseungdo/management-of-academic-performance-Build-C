#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

#include "logINFO_Structer.h" //로그인 정보를 저장하기위한 구조체


int i;
static int login_count = 0;

extern int total_size;
extern int professor_size;
int procheckcount = 0;
int stucheckcount = 0;

char login_name[10]; //나중에 id가 될거 지금은 이름으로 식별
char mode[10]; //이름 식별에 따른 권한 부여

void show_success();
void show_welcome();
void show_fail();

int procheck(char *passwd, struct professor_info *lp);
int stucheck(char *passwd, struct student_info *sp);


void login_logic() {

	i = 0;
	procheckcount = 0;
	FILE *p = fopen(".\\login_file\\professor_info.txt", "r"); //교수정보 로드
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
	FILE *s = fopen(".\\login_file\\student_info.txt", "r"); //학생정보 로드
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

	char *passwd;//키를 받는 배열
	passwd = (char *)malloc(sizeof(10));

	int key = 0;//키를 받는 변수
	int Keycount = 0;
	int passnum = 0;
	int firstkey = 0;


	printf("\t\t아이디 : "); scanf("%s", login_name);
	printf("\t비밀번호 [최대길이는 10, 초기 비밀번호는 1234] : ");
	while (1) {
		key = _getch();  // 한 글자 입력받음
		if (key == 13)  // 엔터 키면 종료
			break;
		if (key != '\0' && Keycount == 0) {
			putchar('*');  // 화면에 별 표시
			*(passwd + passnum) = (char)key;
			firstkey = key;
			//passwd[passnum] = (char)key; // 버퍼에 글자 저장하고 카운트 1 증가
			//printf("%c", *(passwd + passnum));
			Keycount++;
		}
		else if (key != '\0' && Keycount != 0) {
			putchar('*');  // 화면에 별 표시
			*(passwd + passnum) = (char)key;
			*(passwd + passnum - Keycount) = *(passwd + passnum);
			//passwd[passnum] = (char)key;   // 버퍼에 글자 저장하고 카운트 1 증가
			//passwd[passnum - Keycount] = passwd[passnum];
			//printf("%c", *(passwd + passnum - Keycount));
			Keycount++;
		}
		passnum++;
	}
	passwd[0] = (char)firstkey;
	passwd[Keycount] = '\0';

	system("cls");

	if (strcmp(login_name, "관리자") == 0) { //관리자모드
		if (strcmp(passwd, "1234") == 0) { //로그인 성공시
			show_success();
			//Sleep(2);
			show_welcome();
			//Sleep(1);
			//mode[10] = "관리자";
			strcpy(mode, "관리자");
			//printf("%s", mode);
			Sleep(2000);

		}
	}

	else if (procheck(passwd, lp) == 1) {
		show_success();
		Sleep(2);
		show_welcome();
		Sleep(1);
		
		strcpy(mode, "교수");
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

		strcpy(mode, "학생");
		free(sp);
	}

	else {
		printf("아이디 혹은 비밀번호를 잘못 입력하셨습니다.\n");
		printf("%s", passwd);
		Sleep(1000);
		free(passwd);
		strcpy(mode, "오류");
		system("cls");
	}
}

int procheck(char *passwd, struct professor_info *lp) {
	for (i = 0; i < procheckcount; i++) { //교수 이름검사 문제없으면 학생으로 통과
							   //이름 검사 넘어갔을때 메모리 반환
		/*printf("%s\n", (lp + i)->name);
		printf("%s\n", (lp + i)->pass);
		Sleep(1000);*/
		if (strcmp(login_name, (lp + i)->name) == 0) {
			if (strcmp(passwd, (lp + i)->pass) == 0) {
				return 1;
			}
			else if (i == procheckcount && strcmp(passwd, (lp + i)->pass) != 0) {
				printf("암호가 틀립니다.");
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
		if ((sp + i)->name == NULL) { //구조체에 자료가 저장이 안됬으면 나가라
		   free(sp);
		   break;
		}

		if (strcmp(login_name, (sp + i)->name) == 0) {
			if (strcmp(passwd, (sp + i)->pass) == 0) {
				return 1;
			}
			else if (i == stucheckcount && strcmp(passwd, (sp + i)->pass) != 0) {
				printf("암호가 틀립니다.");
				Sleep(1000);
				return -1;
			}
		}
		else if (i == stucheckcount && strcmp(login_name, (sp + i)->name) != 0) {
			printf("없는 사람입니다.");
			Sleep(1000);
			break;
		}

		
	}
}
	/*
	
	

	
	for (i = 0; i < professor_size; i++) { //교수 이름검사 문제없으면 학생으로 통과
								  //이름 검사 넘어갔을때 메모리 반환
	   if (strcmp(login_name, (lp + i)->name) == 0) {
		  if (strcmp(passwd, (lp + i)->pass) == 0) {
			 show_success();
			 Sleep(2);
			 show_welcome();
			 Sleep(1);

			 strcpy(mode, "교슈");
		  }
	   }
	}free(lp);
	for (i = 0; i < total_size; i++) {

	   if ((sp+i) != NULL) { //구조체에 자료가 저장이 안됬으면 나가라
		  free(sp);
		  break;
	   }

	   if (strcmp(login_name, (sp + i)->name) == 0) {
		  if (strcmp(passwd, (sp + i)->pass) == 0) {
			 show_success();
			 Sleep(2);
			 show_welcome();
			 Sleep(1);

			 strcpy(mode, "학생");
		  }
	   }
	}free(sp);*/




