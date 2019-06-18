#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#include "Student_Info_Structer.h"
#include "logINFO_Structer.h"

int i, j;
int change_count; //출력 변경횟수를 확인하기위한 전역변수

extern char login_name[10];
extern char mode[10];
extern int total_size; //관리자가 설정한 파일 전체크기.
extern int stucheckcount;
extern int procheckcount;

int input_count;//입력 학생 카운터
int input_grade_count;//입력 학생 성적 카운터
int add_count;//추가 학생 카운터
int add_grade_count;//추가 학생 성적 카운터
int load_count;//로드 학생 카운터
int load_grade_count;//로드학생 성적 카운터

extern load_count;
void gotoxy(int x, int y); //좌표

//int load_program_data(struct load_size); //반환할 학생슈
void change_mypass();//0번 비번바꾸기
void inputTHEstudent(struct student *, struct student_info *); //1번 구조체 포인터, 배열 0번째 시작, 교수가 입력하겠다고 한 학생수
void inputTHEgrade(struct student *s, struct student_info *si); //2번 학생 성적입력
void add_student(struct student *, struct student_info *, struct add_student *, struct add_student_info *); //3번 학생추가
void showNsort(struct student *, struct student_info *, struct add_student *, struct add_student_info *, struct grade_info *g); //4번 출력, 정렬
void changeTHEstudent(struct student *, struct student_info *, struct add_student *, struct add_student_info *, struct grade_info *g); //5번 출력, 수정
void input_file(struct student *, struct student_info *, struct add_student *, struct add_student_info *, struct grade_info *g); //6번 파일에 입력 동시에 학생 계정도 생성 아이디는 이름 비밀번호는 학번

void input_setgrade(struct student *, struct grade_info *g); //학생 입력후 등급부여
void add_setgrade(struct add_student *, struct grade_info *g); //학생 입력후 등급부여
//void load_setgrade(struct load_student *, struct load_grade_info *g); //학생 입력후 등급부여

void load_file();//6번 학생파일 불러오는거

void professor_logic() {

	time_t curr;
	struct tm *d;
	curr = time(NULL);
	d = localtime(&curr);

	FILE *isp = fopen(".\\login_file\\student_info.txt", "r");
	struct student_info *info_student;//학생정보
	info_student = malloc(sizeof(struct student_info)*10);//관리자가 설정한 수만큼 구조체포인터 동적할당 100개
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

	struct student *profile;//프로그램에 입력한 학생 성적
	profile = malloc(sizeof(struct student)*10);//관리자가 설정한 수만큼 구조체포인터 동적할당 300개
	i = 0;
	while(i<stucheckcount) {//구조체 내부 변수 동적할당 선언
		profile[i].name = (char*)malloc(sizeof(char) * 10);
		profile[i].kor = (char*)malloc(sizeof(char) * 10);
		profile[i].eng = (char*)malloc(sizeof(char) * 10);
		profile[i].mat = (char*)malloc(sizeof(char) * 10);
		i++;
	}

	struct add_student_info *info_add_student;//학생정보
	info_add_student = malloc(sizeof(struct add_student_info) * 10);//관리자가 설정한 수만큼 구조체포인터 동적할당 10개
	for (i = 0; i < 10; i++) {//구조체 내부 변수 동적할당 선언
		info_add_student[i].name = (char*)malloc(sizeof(char) * 10);
		info_add_student[i].pass = (char*)malloc(sizeof(char) * 20);
	}

	struct add_student *add_profile;//추가할 학생 성적
	add_profile = malloc(sizeof(struct student)*10);//관리자가 설정한 수만큼 구조체포인터 (ntdll.dll)에(suckcess.exe의) 처리되지 않은 예외가 있습니다. 0xC0000374: 힙이 손상되었습니다(매개 변수: 0x0000000077C67C70).

	for (i = 0; i < 10; i++) {//구조체 내부 변수 동적할당 선언
		add_profile[i].name = (char*)malloc(sizeof(char) * 10);
		add_profile[i].kor = (char*)malloc(sizeof(char) * 10);
		add_profile[i].eng = (char*)malloc(sizeof(char) * 10);
		add_profile[i].mat = (char*)malloc(sizeof(char) * 10);
	}

	struct grade_info *grade;
	grade = malloc(sizeof(struct grade_info) * 10);
	i = 0;
	while (i < stucheckcount) {//구조체 내부 변수 동적할당 선언
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
	while (!feof(fp)) {//학생정보를 끝까지 읽어버림 인원수 파악
		fscanf(fp, "%d %s %s", &info_load_student[i].sid, info_load_student[i].name, info_load_student[i].pass);
		i++;//구조체마다 써주기위해서 사용
		load_count++;//읽으면서 몇마리있는지 세줌
	}fclose(fp);
	*/

	/*FILE *fp = fopen(".\\login_file\\student_info.txt", "r");
	struct load_student_info *info_load_student;
	info_load_student = malloc(sizeof(struct student)*10);//파일안 인원수만큼 할당
	for (i = 0; i < 10; i++) {//구조체 내부 변수 동적할당 선언
		info_load_student[i].name = (char*)malloc(sizeof(char) * 10);
		info_load_student[i].pass = (char*)malloc(sizeof(char) * 20);
		fscanf(fp, "%s %s", info_load_student[i].name, info_load_student[i].pass);
	}	fclose(fp);


	FILE *zp = fopen("student.txt", "r");
	struct load_student *load_profile;
	load_profile = malloc(sizeof(struct student)*10);//
	for (i = 0; i < 10; i++) {//구조체 내부 변수 동적할당 선언
		load_profile[i].name = (char*)malloc(sizeof(char) * 10);
		load_profile[i].kor = (char*)malloc(sizeof(char) * 10);
		load_profile[i].eng = (char*)malloc(sizeof(char) * 10);
		load_profile[i].mat = (char*)malloc(sizeof(char) * 10);
		fscanf(zp, "%s %s %s %s \n",
			(load_profile + i)->name, (load_profile + i)->kor, (load_profile + i)->eng,
			(load_profile + i)->mat); //이름, 국어, 영어, 수학 까지만 가능. 그 이상은 터짐
		load_grade_count++;
	}	fclose(zp);*/
	
	input_count = 0;
	input_grade_count = 0;
	add_count = 0;//추가 학생 카운터
	add_grade_count = 0;//추가 학생 성적 카운터
	int input_info = 0;

	while (1) {
		int ch; //선택문

		printf("\t\t현재시간은 %d시%d분%d초 이무니다.\n", d->tm_hour, d->tm_min, d->tm_sec);
		printf("\t\t현재 %d명의 학생을 입력할수 있습니다.\n", total_size);

		gotoxy(12, 4);   printf("어서오십시오 %s %s님 무엇을 하시겠습니까?", login_name, mode);
		//gotoxy(22, 5);   printf("0. 비밀번호 수정"); //void chang_mypass();
		gotoxy(22, 6);   printf("1. 학생 성적정보 만들기");
		gotoxy(22, 7);   printf("2. 학생 성적 입력");
		gotoxy(22, 8);	 printf("3. 학생 추가");
		gotoxy(22, 9);   printf("4. 학생 성적 조회 ");
		gotoxy(22, 10);  printf("5. 학생 정보 수정");
		gotoxy(22, 11);  printf("6. 학생 정보 파일에 입력"); //입력된학생 추가된학생 
		gotoxy(22, 12);  printf("7. 로그아웃");
		gotoxy(22, 13);  printf("8. 프로그램  종료");

		/*
		void inputTHEstudent(struct student *, struct student_info *); //1번 구조체 포인터, 배열 0번째 시작, 교수가 입력하겠다고 한 학생수
		void setgrade(struct student *, struct add_student *); //학생 입력후 등급부여
		void inputTHEgrade(struct student *, struct student_info *) //2번 학생 성적입력
		void changeTHEstudent(struct student *, struct add_student *, struct student_info *); //3번 학생 정보수정
		void add_student(struct student *, int formal, int last); //4번 학생 추가
		void showNsort(struct student *, int formal, int last); //5번 학생 정보출력
		void input_file(struct student *, int formal, int last); //5번 파일에 입력 동시에 학생 계정도 생성 아이디는 이름 비밀번호는 학번
		void load_file();//6번 학생파일 불러오는거
		*/
		gotoxy(22, 15);  printf("type nomber: "); scanf("%d", &ch);
		fflush(stdin);
		system("cls");

		switch (ch) {

			/*case 0: //내 비밀번호 수정

				change_mypass();
				break;
			*/
			case 1: //학생 입력

				system("cls");
				if (input_info == 0) {
					input_info = 1;
					inputTHEstudent(profile, info_student);
					//setgrade(profile, add_profile);
				}
				else {//학생정보 최초 한번입력
					gotoxy(22, 17); printf("정보는 한번만 입력 가능합니다 정보 추가를 하세요.");
					break;
				}
				system("cls");
				continue;

			case 2: //학생 성적입력

				system("cls");
				if (input_info == 1) {//학생 이름을 입력해야만 성적을 입력할수 있다.
					inputTHEgrade(profile, info_student);
					input_setgrade(profile, grade);
					continue;
				}
				else {//학생정보 최초 한번입력
					gotoxy(22, 17); printf("학생을 입력해야 성적입력이 가능합니다.");
					Sleep(2500);
					continue;
				}
				system("cls");
				continue;

			case 3: //학생 정보 추가

				system("cls");
				add_student(profile, info_student, add_profile, info_add_student);
				add_setgrade(add_profile, grade);

				system("cls");
				continue;

			case 4: //학생 성적까지 출력 학생 리스트 까보고 성적 볼지 선택하기
				
				showNsort(profile, info_student, add_profile, info_add_student, grade);
				system("cls");
				continue;

			case 5: //학생 정보 수정 1.이름수정 2.점수수정 3.학생제거 4.종료
					//입력학생 수정 추가학생 수정 입력된 학생 수정
				changeTHEstudent(profile, info_student, add_profile, info_add_student, grade);
				system("cls");
				continue;

			case 6: //학생 파일에 쓰기 끝판
					//입력학생 쓰기W 추가학생A 입력된 학생쓰기
				input_file(profile, info_student, add_profile, info_add_student, grade);
				system("cls");
				continue;

			case 7: //로그아웃

				fflush(stdin);
				free(profile);
				free(info_student);
				free(add_profile);
				free(info_add_student);

				gotoxy(14, 8); printf("로그아웃 됩니다.");
				Sleep(1500);
				system("cls");

				return 0;
				break;

			case 8: //프로그람 종료

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
				gotoxy(22, 17); printf("ERROR :1부터 8까지 숫자를 입력하세요\n");
				break;
			}
	}
}