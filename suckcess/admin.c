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
int total_size = 300; //학생은 300명
int professor_size = 10; //교수는 10명

extern char login_name[10];
extern char mode[10];
extern int login_count;

void gotoxy(int x, int y);
void input_professor_info(); //1. 파일에 교수쓰기
//void load_professor_info(struct professor *, int formal, int last); //1-1. 교수파일 불러오기
void setting_program(struct program *);//3.학생 정원관리
void list_dir(); //4.파일목록 불러옴
void load_student_info(); //학생파일 불러오기

void admin_logic() {

	time_t curr;
	struct tm *d;
	curr = time(NULL);
	d = localtime(&curr);

	struct program *total_s; //학새ㅇ 인원수 설정할 구조체포인터 선언
	total_s = malloc(sizeof(struct program) * sizeof(int));
	
	while (1) {
		int ch; //선택문
		system("cls");

		printf("\t\t현재시간은 %d시%d분%d초 입니다.\n", d->tm_hour, d->tm_min, d->tm_sec);

		gotoxy(12, 5);   printf("어서오십시오 %s %s님 무엇을 하시겠습니까?", mode, login_name);
		gotoxy(22, 6);   printf("1. 교수 계정 관리");
		gotoxy(22, 7);   printf("2. 학생 계정 관리");
		gotoxy(22, 8);   printf("3. 로그아웃");
		gotoxy(22, 9);   printf("4. 프로그램 종료");

		gotoxy(22, 14);  printf("type nomber: "); scanf("%d", &ch);
		fflush(stdin);
		system("cls");
		
		switch (ch) {
			case 1: //교수계정 관리
					//계정목록 보기 수정 추가
				input_professor_info();
				break;

			case 2: //학생계정 관리
					//계정목록 보기 수정 추가
				load_student_info();
				break;

			case 3: //로그아웃

					free(total_s);
					gotoxy(14, 8); printf("로그아웃 됩니다.");
					Sleep(1500);

				//login_logic(); // 다시 로그인함수 호출 근데 여기서 오류점 생김
				return 0;
				break;

			case 4: //프로그람 종료

				free(total_s);
				fflush(stdin);
				exit(0);
				break;

			default:

				gotoxy(22, 15); printf("ERROR :1부터 5까지 숫자를 입력하세요\n");
				break;

			}
	}

}
