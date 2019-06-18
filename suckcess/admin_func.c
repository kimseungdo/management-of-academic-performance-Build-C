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



void input_professor_info() { //1.교수정보입력

	struct professor_info *ip;//구조체 포인터 선언
	ip = malloc(sizeof(struct professor_info)*20);//관리자가 설정한 수만큼 구조체포인터 동적할당
	for (i = 0; i < 20; i++) {
		ip[i].name = (char*)malloc(sizeof(char) * 10);
		ip[i].pass = (char*)malloc(sizeof(int) * 10);
	}
	struct load_professor {
		char *name;
		char *pass;
	};
	struct load_professor *lp;//구조체 포인터 선언
	lp = malloc(sizeof(struct professor_info) * 20);//관리자가 설정한 수만큼 구조체포인터 동적할당
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
		//새정보 입력 추가하기 삭제하기
		gotoxy(22, 7);   printf("1. 교수 이름 입력(최초입력)"); // void 
		gotoxy(22, 8);	 printf("2. 교수 정보 추가"); //void add_professor 	FILE *fp = fopen(".\\professor_info.txt", "a");
		gotoxy(22, 9);   printf("3. 교수 정보 조회"); //void remove_professor 	FILE *fp = fopen(".\\professor_info.txt", "w");
		//gotoxy(22, 10);  printf("4. 파일정보 불러오기"); //void load_professor	    FILE *fp = fopen(".\\professor_info.txt", "r");
		gotoxy(22, 10);  printf("4. 나가기");

		gotoxy(22, 14);  printf("type nomber: "); scanf("%d", &ch);
		fflush(stdin);
		system("cls");

		switch (ch) {
		case 1://1. 교수 존함 입력 ( o.o )

			while (1) {
				int ch1;
				printf("현재 입력된 교수 목록입니다.\n");
				for (j = 0; j < ii; j++) {
					printf("\t%s\n", (ip + j)->name);
				}
				printf("교수의 이름을 입력하십시오 : (입력중 나가시려면 quit입력) "); scanf("%s", (ip + ii)->name); //구조체에 들어갈 이름 받음
				fflush(stdin);
				if (strcmp((ip + ii)->name, "quit") == 0) {
					FILE *fp = fopen(".\\login_file\\professor_info.txt", "w");//파일쓰기
					if (fp == NULL) {
						system("cls");
						gotoxy(20, 8); printf("응안열렸고 잘가시게");
						exit(0);
					}
					for (j = 0; j < ii; j++) {
						fprintf(fp, "%s %s\n", (ip + j)->name, (ip + j)->pass);
					}fclose(fp);
					(ip + ii)->name = "";
					break;
				}
				strcpy((ip + ii)->pass, "1234"); //초기 비밀번호는 1234기 때문
				//fprintf(fp, "%s %s", (ip + i)->name, (ip + i)->pass);
				printf("더 입력하시겠습니까? 1.Yes 2.No \n"); 
				printf("       type nomber : "); scanf("%d", &ch1); fflush(stdin);
				if (ch1 == 1) {
					system("cls");
					ii++;
					j++;
					continue;
				}
				else if (ch1 == 2) {
					FILE *fp = fopen(".\\login_file\\professor_info.txt", "w");//파일쓰기
					if (fp == NULL) {
						system("cls");
						gotoxy(20, 8); printf("응안열렸고 잘가시게");
						exit(0);
					}
					for (j = 0; j < ii+1; j++) {
						fprintf(fp, "%s %s\n", (ip + j)->name, (ip + j)->pass);
					}fclose(fp);
					system("cls");
					break;
				}
				else {
					printf("다시 입력하쇼");
				}
			}

			break;

		case 2://2. 교수 존함 추가  > ^ <

			while (1) {
				int ch1;
				char Pname[10];

				FILE *fp = fopen(".\\login_file\\professor_info.txt", "a+");

				if (fp == NULL) {
					system("cls");
					gotoxy(20, 8); printf("응안열렸고 잘가시게");
					exit(0);
				}
				i = 0;
				printf("현재 입력된 교수 목록\n");
				while (!feof(fp)){
					//공백으로 분리된 파일 읽기
					fscanf(fp, "%s %s\n", (lp+i)->name, (lp+i)->pass);
					printf("\t%s\n", (lp+i)->name);
					i++;//현재 파일에 들어가있는 총 크기
					count++;
				}

				printf("추가할 교수 이름을 입력하십시오 : (입력중 나가시려면 quit입력) "); scanf("%s", Pname);
				Padd++;
				if (strcmp(Pname, "quit") == 0) {
					
					system("cls");
					ii++;
					break;
				}

				printf("더 입력하시겠습니까? 1.Yes 2.No \n");
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
				else printf("다시입력하소\n");
			}
			break;

		case 3://3. 교수 조회

			while (1) {
				int ch1;
				i = 0;
				FILE *fp = fopen(".\\login_file\\professor_info.txt", "a+");

				if (fp == NULL) {
					system("cls");
					gotoxy(20, 8); printf("응안열렸고 잘가시게");
					exit(0);
				}

				printf("현재 입력된 교수 목록\n");
				while (!feof(fp)) {
					//공백으로 분리된 파일 읽기
					fscanf(fp, "%s %s\n", (lp + i)->name, (lp + i)->pass);
					printf("\t%s\n", (lp + i)->name);
					i++;//현재 파일에 들어가있는 총 크기
					count++;
				}

				printf("조회를 종료하시겠습니까? 1.Yes 2.No \n");
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

		/*case 4://4. 파일정보 불러오기

			while (1) {
				char buffer[10] = { 0, };    // 문자열 데이터 4바이트 NULL 1바이트. 4 + 1 = 5
				int count = 0;
				int total = 0;

				FILE *fp = fopen(".\\login_file\\professor_info.txt", "r");
				while (feof(fp) == 0) {    // 파일 포인터가 파일의 끝이 아닐 때 계속 반복
					count = fread(buffer, sizeof(char), 4, fp);    // 1바이트씩 4번(4바이트) 읽기
					printf("\t%s", buffer);                          // 읽은 내용 출력
					memset(buffer, 0, 5);                          // 버퍼를 0으로 초기화
					total += count;                                // 읽은 크기 누적
				}
			}
			break;*/

		case 4://5. 나가기

			break;

		default:
			gotoxy(22, 15); printf("ERROR :1부터 4까지 숫자를 입력하세요\n");
			break;
		}break;
		
	}
}

//void load_professor_info(struct professor *lp, int formal, int last) { }

/*void setting_program(struct program *pp) {//3.학생 정원관리 교수가 로드해서 학생인원수 받아올거

	system("cls");

	FILE *sp = fopen("set_program.txt", "w"); //쓰기모드
	if (sp == NULL) {
		system("cls");
		gotoxy(20, 8); printf("응안열렸고 잘가시게");
		exit(0);
	}

	gotoxy(20, 8); printf("최대인원을 몇명으로 ?: "); scanf("%d", &total_size);
	fprintf(sp, "%d", total_size);
	fflush(stdin); //버퍼제거
	fclose(sp);
	input_success();
}*/

void load_student_info() {

	struct student_info *kp;//구조체 포인터 선언
	kp = malloc(sizeof(struct student_info) * 20);//관리자가 설정한 수만큼 구조체포인터 동적할당
	for (i = 0; i < 20; i++) {
		kp[i].name = (char*)malloc(sizeof(char) * 10);
		kp[i].pass = (char*)malloc(sizeof(int) * 10);
	}
	struct load_student {
		char *name;
		char *pass;
	};
	struct load_student *jp;//구조체 포인터 선언
	jp = malloc(sizeof(struct professor_info) * 20);//관리자가 설정한 수만큼 구조체포인터 동적할당
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
		//새정보 입력 추가하기 삭제하기
		gotoxy(22, 7);   printf("1. 학생 이름 입력(최초입력)"); // void 
		gotoxy(22, 8);	 printf("2. 학생 정보 추가"); //void add_professor 	FILE *fp = fopen(".\\professor_info.txt", "a");
		gotoxy(22, 9);   printf("3. 학생 정보 조회"); //void remove_professor 	FILE *fp = fopen(".\\professor_info.txt", "w");
		//gotoxy(22, 10);  printf("4. 파일정보 불러오기"); //void load_professor	    FILE *fp = fopen(".\\professor_info.txt", "r");
		gotoxy(22, 10);  printf("4. 나가기");

		gotoxy(22, 14);  printf("type nomber: "); scanf("%d", &ch);
		fflush(stdin);
		system("cls");

		switch (ch) {
		case 1://1. 교수 존함 입력 ( o.o )

			while (1) {
				int ch1;
				printf("현재 입력된 학생 목록입니다.\n");
				for (j = 0; j < ii; j++) {
					printf("\t%s\n", (kp + j)->name);
				}
				printf("학생의 이름을 입력하십시오 : (입력중 나가시려면 quit입력) "); scanf("%s", (kp + ii)->name); //구조체에 들어갈 이름 받음
				fflush(stdin);
				if (strcmp((kp + ii)->name, "quit") == 0) {
					FILE *fp = fopen(".\\login_file\\student_info.txt", "w");//파일쓰기
					if (fp == NULL) {
						system("cls");
						gotoxy(20, 8); printf("응안열렸고 잘가시게");
						exit(0);
					}
					for (j = 0; j < ii; j++) {
						fprintf(fp, "%s %s\n", (kp + j)->name, (kp + j)->pass);
					}fclose(fp);
					(kp + ii)->name = "";
					break;
				}
				strcpy((kp + ii)->pass, "1234"); //초기 비밀번호는 1234기 때문
				//fprintf(fp, "%s %s", (ip + i)->name, (ip + i)->pass);
				printf("더 입력하시겠습니까? 1.Yes 2.No \n");
				printf("       type nomber : "); scanf("%d", &ch1); fflush(stdin);
				if (ch1 == 1) {
					system("cls");
					ii++;
					j++;
					continue;
				}
				else if (ch1 == 2) {
					FILE *fp = fopen(".\\login_file\\student_info.txt", "w");//파일쓰기
					if (fp == NULL) {
						system("cls");
						gotoxy(20, 8); printf("응안열렸고 잘가시게");
						exit(0);
					}
					for (j = 0; j < ii + 1; j++) {
						fprintf(fp, "%s %s\n", (kp + j)->name, (kp + j)->pass);
					}fclose(fp);
					system("cls");
					break;
				}
				else {
					printf("다시 입력하쇼");
				}
			}

			break;

		case 2://2. 교수 존함 추가  > ^ <

			while (1) {
				int ch1;
				char Sname[10];

				FILE *fp = fopen(".\\login_file\\student_info.txt", "a+");

				if (fp == NULL) {
					system("cls");
					gotoxy(20, 8); printf("응안열렸고 잘가시게");
					exit(0);
				}
				i = 0;
				printf("현재 입력된 학생 목록\n");
				while (!feof(fp)) {
					//공백으로 분리된 파일 읽기
					fscanf(fp, "%s %s\n", (jp + i)->name, (jp + i)->pass);
					printf("\t%s\n", (jp + i)->name);
					i++;//현재 파일에 들어가있는 총 크기
					count++;
				}

				printf("추가할 학생 이름을 입력하십시오 : (입력중 나가시려면 quit입력) "); scanf("%s", Sname);
				Padd++;
				if (strcmp(Sname, "quit") == 0) {

					system("cls");
					ii++;
					break;
				}

				printf("더 입력하시겠습니까? 1.Yes 2.No \n");
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
				else printf("다시입력하소\n");
			}
			break;

			case 3://3. 학생 조회

				while (1) {
					int ch1;
					i = 0;
					FILE *fp = fopen(".\\login_file\\student_info.txt", "a+");

					if (fp == NULL) {
						system("cls");
						gotoxy(20, 8); printf("응안열렸고 잘가시게");
						exit(0);
					}

					printf("현재 입력된 학생 목록\n");
					while (!feof(fp)) {
						//공백으로 분리된 파일 읽기
						fscanf(fp, "%s %s\n", (jp + i)->name, (jp + i)->pass);
						printf("\t%s\n", (jp + i)->name);
						i++;//현재 파일에 들어가있는 총 크기
						count++;
					}

					printf("조회를 종료하시겠습니까? 1.Yes 2.No \n");
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

			/*case 4://4. 파일정보 불러오기

				while (1) {
					char buffer[10] = { 0, };    // 문자열 데이터 4바이트 NULL 1바이트. 4 + 1 = 5
					int count = 0;
					int total = 0;

					FILE *fp = fopen(".\\login_file\\professor_info.txt", "r");
					while (feof(fp) == 0) {    // 파일 포인터가 파일의 끝이 아닐 때 계속 반복
						count = fread(buffer, sizeof(char), 4, fp);    // 1바이트씩 4번(4바이트) 읽기
						printf("\t%s", buffer);                          // 읽은 내용 출력
						memset(buffer, 0, 5);                          // 버퍼를 0으로 초기화
						total += count;                                // 읽은 크기 누적
					}
				}
				break;*/

		case 4://5. 나가기

			break;

		default:
			gotoxy(22, 15); printf("ERROR :1부터 3까지 숫자를 입력하세요\n");
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
			printf("파일명 : %s, 크기:%d\n", fd.name, fd.size);
			result = _findnext(handle, &fd);
		}

		_findclose(handle);
		printf("다봣수? 1종료 2계속"); scanf("%d", &ch);
		if (ch == 1) break;
		else continue;
	}
}