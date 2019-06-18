#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#include "Student_Info_Structer.h"
#include "logINFO_Structer.h"

//#define _CRT_SECURE_NO_WARNINGS
int i, j;
void gotoxy(int x, int y); //좌표
char name[10];


extern int total_size;
extern int change_count;
extern char login_name[10];
extern char mode[10];
extern int stucheckcount;
extern int procheckcount;


extern input_count;//학생 입력한 카운터
extern input_grade_count;//학생 성적입력 카운터
extern add_count;//추가 학생 카운터
extern add_grade_count;//추가 학생 성적 카운터
extern load_count;//로드 학생 카운터
extern load_grade_count;//로드학생 성적 카운터

void load_setgrade(struct load_student *, struct grade_info *g, int load_grade_count);

void change_mypass() { //0번
	/*        .\\login_file\\professor_info.txt
		gotoxy(20, 14);   printf("누구 이름을 바꿀꺼고? ");  scanf("%s", change_name);
			for (i = formal; i < last; i++) {
				if (strcmp((os + i)->name, change_name) == 0) { //이름을 바꾸기 위해 이름검사
					gotoxy(20, 15); printf("뭐로 바꿀끼고? : ");
					scanf("%s", (os + i)->name);
					change_count++;
					//strcpy((os + i)->name, change_name); 이걸하면 찾은 이름으로 다시 바뀌게 된다.
				}
	*/
	char now_pass[20];

	FILE *fp = fopen(".\\login_file\\professor_info.txt", "r+");    //
	char buffer[10] = { 0, };    // 문자열 데이터 4바이트 NULL 1바이트. 4 + 1 = 5
	int count = 0;
	int total = 0;

	/*
	while (feof(fp) == 0) {    // 파일 포인터가 파일의 끝이 아닐 때 계속 반복
		count = fread(buffer, sizeof(char), 4, fp);    // 1바이트씩 4번(4바이트) 읽기
		printf("\t%s", buffer);                          // 읽은 내용 출력
		memset(buffer, 0, 5);                          // 버퍼를 0으로 초기화
		total += count;                                // 읽은 크기 누적
	}	
	*/


	struct load_professor *lp;//구조체 포인터 선언
	lp = malloc(sizeof(struct load_professor) * total);//관리자가 설정한 수만큼 구조체포인터 동적할당
	for (i = 0; i < total; i++) {
		lp[i].name = (char*)malloc(sizeof(char) * 10);
		lp[i].pass = (char*)malloc(sizeof(int) * 10);
	}

	i = 0;
	while (!feof(fp)) {
		fscanf(fp, "%s %s\n", lp[i].name, lp[i].pass);
		printf("%s %s\n", lp[i].name, lp[i].pass);
		count++; //파일 전체 크기알려줌 ㅇㅋ?
		i++;
	}

	for (i = 0;  i < total; i++) {
		if (strcmp(lp[i].name, login_name) == 0) {
			printf("현재 비밀번호 입력해주쇼"); scanf("%s", now_pass);
			if (strcmp(now_pass, lp[i].pass) == 0) {
				printf("바꿀 비밀번호 입력해주쇼"); scanf("%s", (lp + i)->pass);
			}
		}
	}

	for (i = 0; i < count; i++) {
		fprintf(fp, "%s %s", lp[i].name, lp[i].pass);
	}fclose(fp);
	free(lp);
	fflush(stdin);
}

/*int load_program_data(struct load_size *ss, int total_size) {//학생 인원수 불러오기

	FILE *sp = fopen("set_program.txt", "r"); //읽기모드
	if (sp == NULL) {
		system("cls");
		gotoxy(20, 8); printf("응안열렸고 잘가시게");
		exit(0);
	}
	fscanf(sp, "%d", total_size);
	return total_size;
}*/

void inputTHEstudent(struct student *is, struct student_info *iss) { //1. input_student 학생 입력 (is성적, iss정보) 

	//input_count = 0;
	j = 0;
	i = 0;
	int k;

	time_t now;
	now = time(NULL);
	srand(time(NULL));

	while (1) {
			int breakcheck = 0;

			printf("현재 계정정보가 입력된 학생입니다\n");
			printf("이름\n");
			for (k = 0; k < stucheckcount; k++) {
				printf("%s\n", (iss + k)->name);
			}
			printf("현재 성적정보가 만들어진 학생입니다\n");
			printf("이름\n");
			for (k = 0; k < input_count; k++) {
				printf("%s\n", (is + k)->name);
			}
			
			printf("성적정보를 만들 학생 (입력종료 quit) :"); //학생 입력
			fflush(stdin);
			scanf("%s", (is + i)->name); fflush(stdin);
			Sleep(1000);
			if (strcmp((is + i)->name, "quit") == 0) { //나가라고 하면 이름을 저장하지않고 나감
				is[i].name = NULL;
				break;
			}

			else { //검사를 뚫고 정상입력이면 학번과
				for (j = 0; j < 10; j++) {//문자열검사
					if ((int)(is + i)->name[j] > 65 && (int)(is + i)->name[j] < 122) {
						gotoxy(17, 15); printf("ERROR : 한쿡사람이 아니무니다 다시 입력하이소\n");
						Sleep(1000);
						breakcheck++;
						break;
					}
					else if (strlen((is + i)->name) == 0) {
						gotoxy(17, 15); printf("ERROR : 입력을 안한거같스무이다 다시 압력하이소\n");
						Sleep(1000);
						breakcheck++;
						break;
					}
					else if (strlen((is + i)->name) > 6) {
						gotoxy(17, 15); printf("ERROR : 이름이 깁네다 한쿡사람이 아닌거 같스무이다 다시 입력하소\n");
						Sleep(1000);
						breakcheck++;
						break;
					}
				}//문자열 검사가 끝났으면 

				if (breakcheck != 0) {
					system("cls");
					continue;
				}
				strcpy(iss[i].name, is[i].name); //입력한이름 학생정보에 복사
				//int random = rand();
				//iss[i].sid = now; //학생정보에 학번부여
				strcpy(iss[i].pass, "1234"); //학생정보에 비밀번호 부여 초기번호는 1234니까
				printf("%s 학생의 성적데이터가 만들어졌습니다.", (is + i)->name);
				Sleep(1000);
				i++;
				input_count++;
				system("cls");
			}

		
	}
}

void inputTHEgrade(struct student *s, struct student_info *si) {//2번 학생 성적입력 (s성적, si정보)
	//input_grade_count = 0;

	while (1) {
		char name[10];
		int breakcheck = 0;

		printf("%s님이 입력한 학생들입니다.\n", login_name);
		printf("이름    성적입력여부 \n");
		for (i = 0; i < input_count; i++) {
			printf("%s", s[i].name);
			if (atoi((s + i)->kor) > 0 && atoi((s + i)->kor) <= 100) {//0~100범위
				printf("       (O) \n");
			}
			else {
				printf("       (X) \n");
			}
		}

		printf("\n어떤 학생 성적을 입력하시겠습니까 (입력종료 quit) : "); scanf("%s", name);
		if (strcmp(name, "quit") == 0) { //quit입력되면 나가리
			system("cls");
			break;
		}
		else {//종료가 아니면 문자열검사
			for (j = 0; j < 10; j++) {
				if ((int)name[j] > 65 && (int)name[j] < 122) {
					//system("cls");
					printf("ERROR : 한쿡사람이 아니무니다 다시 입력하이소\n");
					Sleep(1000);
					breakcheck++;
					break;
				}
				else if (strlen(name) == 0) {
					//system("cls");
					printf("ERROR : 입력을 안한거같스무이다 다시 압력하이소\n");
					Sleep(1000);
					breakcheck++;
					break;
				}
				else if (strlen(name) > 6) {
					//system("cls");
					printf("ERROR : 이름이 깁네다 한쿡사람이 아닌거 같스무이다 다시 입력하소\n");
					Sleep(1000);
					breakcheck++;
					break;
				}
			}
		}//문자열 검사가 끝났다면
		
		for (i = 0; i < input_count; i++) {
			if (strcmp(name, s[i].name) == 0) {//문자열 검사가 끝났고 교수가 입력한 학생이 일치하면
				while (1) {
					printf("\n\n%s학생의 국어점수를 입력해주세요 ", s[i].name); scanf("%s", (s + i)->kor);
					int korscore = atoi((s + i)->kor);
					if (korscore < 0 || korscore > 100) {//0~100범위
						printf("잘못 입력되었습니다. 다시 입력하세요\n");
					}
					else if (isStringDouble((s + i)->kor) == 0) {//숫자 이외의 문자
						printf("잘못 입력되었습니다. 다시 입력하세요\n");
					}
					else {//범위내에 입력되고 문자가 입력안되면 탈출
						break;
					}
				}
				while (1) {
					printf("%s학생의 영어점수를 입력해주세요 ", s[i].name); scanf("%s", (s + i)->eng);
					int englishscore = atoi((s + i)->eng);
					if (englishscore < 0 || englishscore > 100) {//0~100범위
						printf("잘못 입력되었습니다. 다시 입력하세요\n");
					}
					else if (isStringDouble((s + i)->kor) == 0) {//숫자 이외의 문자
						printf("잘못 입력되었습니다. 다시 입력하세요\n");
					}
					else {//범위내에 입력되고 문자가 입력안되면 탈출
						break;
					}
				}
				while (1) {
					printf("%s학생의 수학점수를 입력해주세요 ", s[i].name); scanf("%s", (s + i)->mat);
					int mathscore = atoi((s + i)->mat);
					if (mathscore < 0 || mathscore > 100) {//0~100범위
						printf("잘못 입력되었습니다. 다시 입력하세요\n");
					}
					else if (isStringDouble((s + i)->kor) == 0) {//숫자 이외의 문자
						printf("잘못 입력되었습니다. 다시 입력하세요\n");
					}
					else {//범위내에 입력되고 문자가 입력안되면 탈출
						break;
					}
				}
				input_grade_count++;
			}
			else if (i==input_grade_count && strcmp(name, s[i].name) != 0) {
				printf("\n\n성적데이터가 입력되지 않았습니다.");
			}
		}system("cls");
	}
}
//add_student(profile, info_student, add_profile, info_add_student);
void add_student(struct student *s, struct student_info * si, struct add_student *as, struct add_student_info * asi) { //3번 학생 추가

	// 있는학생 입력시 성적입력
	// 학생이 없으면 학생 추가로
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

		printf("%3s님이 입력한 학생들입니다.\n", login_name);
		printf("이름    성적입력여부 \n");
		for (k = 0; k < input_count; k++) {
			printf("%s", si[k].name);
				if (atoi((s + k)->kor) > 0 && atoi((s + k)->kor) <= 100) {//0~100범위
					printf("       (O) \n");
				}
				else {
					printf("       (X) \n");
				}
		}printf("====================================\n");
		printf("%3s님이 추가한 학생들입니다.\n", login_name);
		printf("이름    성적입력여부 \n");
		for (k = 0; k < add_count; k++) {
			printf("%s", asi[k].name);
				if (atoi((as + k)->kor) > 0 && atoi((as + k)->kor) <= 100) {//0~100범위
					printf("       (O) \n");
				}
				else {
					printf("       (X) \n");
				}
		}
		printf("\n추가입력한 학생을 다시 입력하시면 성적을 추가합니다\n");
		printf("어떤 학생 성적을 입력하시겠습니까 (입력종료 quit) : "); scanf("%s", name);

		if (strcmp(name, "quit") == 0) {
			system("cls");
			break;
		}
		else {//종료가 아니면 문자열검사
			strcpy((as + add_count)->name, name);
			for (j = 0; j < 10; j++) {
				if ((int)(as + add_count)->name[j] > 65 && (int)(as + add_count)->name[j] < 122) {
					//system("cls");
					printf("ERROR : 한쿡사람이 아니무니다 다시 입력하이소\n");
					Sleep(1000);
					breakcheck++;
					break;
				}
				else if (strlen((as + add_count)->name) == 0) {
					//system("cls");
					printf("ERROR : 입력을 안한거같스무이다 다시 압력하이소\n");
					Sleep(1000);
					breakcheck++;
					break;
				}
				else if (strlen((as + add_count)->name) > 6) {
					//system("cls");
					printf("ERROR : 이름이 깁네다 한쿡사람이 아닌거 같스무이다 다시 입력하소\n");
					Sleep(1000);
					breakcheck++;
					break;
				}
			}//문자열 검사가 끝났다면
			//strcpy(asi[i].name, name); //입력한이름 학생정보에 복사
			//asi[i].sid = now; //학생정보에 학번부여
			//strcpy(asi[i].pass, "1234"); //학생정보에 비밀번호 부여 초기번호는 1234니까

			//system("cls");
		}

		if (breakcheck != 0) {
			system("cls");
			continue;
		}

			for (i = 0; i < add_count; i++) {
				if (strcmp((as + i)->name, name) == 0) {//문자열 검사가 끝났고 교수가 입력한 학생이 일치하면
					while (1) {
						printf("\n\n%s학생의 국어점수를 입력해주세요 ", as[i].name); scanf("%s", (as + i)->kor);
						int korscore = atoi((as + i)->kor);
						if (korscore < 0 || korscore > 100) {//0~100범위
							printf("잘못 입력되었습니다. 다시 입력하세요\n");
						}
						else if (isStringDouble((as + i)->kor) == 0) {//숫자 이외의 문자
							printf("잘못 입력되었습니다. 다시 입력하세요\n");
						}
						else {//범위내에 입력되고 문자가 입력안되면 탈출
							break;
						}
					}
					while (1) {
						printf("%s학생의 영어점수를 입력해주세요 ", as[i].name); scanf("%s", (as + i)->eng);
						int englishscore = atoi((as + i)->eng);
						if (englishscore < 0 || englishscore > 100) {//0~100범위
							printf("잘못 입력되었습니다. 다시 입력하세요\n");
						}
						else if (isStringDouble((as + i)->kor) == 0) {//숫자 이외의 문자
							printf("잘못 입력되었습니다. 다시 입력하세요\n");
						}
						else {//범위내에 입력되고 문자가 입력안되면 탈출
							break;
						}
					}
					while (1) {
						printf("%s학생의 수학점수를 입력해주세요 ", as[i].name); scanf("%s", (as + i)->mat);
						int mathscore = atoi((as + i)->mat);
						if (mathscore < 0 || mathscore > 100) {//0~100범위
							printf("잘못 입력되었습니다. 다시 입력하세요\n");
						}
						else if (isStringDouble((as + i)->kor) == 0) {//숫자 이외의 문자
							printf("잘못 입력되었습니다. 다시 입력하세요\n");
						}
						else {//범위내에 입력되고 문자가 입력안되면 탈출
							break;
						}
					}
					add_grade_count++;//추가입력 카운트 증가
					printf("추가학생의 성적이 입력되었습니다.");
					Sleep(1000);
					system("cls");
					i++;
					addbreakcheck++;
					break;
				}
				else if (i == add_count && strcmp((as + i)->name, name) != 0){
					printf("\n\n그런학생은 입력되지 않았습니다");
				}
			}
			if (addbreakcheck != 0)
				continue;


		strcpy(asi[add_count].name, (as + add_count)->name); //입력한이름 학생정보에 복사
		//asi[i].sid = now; //학생정보에 학번부여
		strcpy(asi[add_count].pass, "1234"); //학생정보에 비밀번호 부여 초기번호는 1234니까
		printf("%s 학생의 성적데이터가 추가되었습니다.", (as + add_count)->name);
		Sleep(1000);
		i++;
		add_count++;//추가 카운트 증가
		system("cls");
	}
}

void showNsort(struct student *s, struct student_info *si, struct add_student *as, struct add_student_info *asi, struct grade_info *g) {	//4번 학생 리스트 까보고 성적 볼지 선택

	int ch;
	int load_size;

	while (1) {
		if (input_count == 0) {//학생 정보가 입력되었다면
			printf("입력한 학생이 없습니다.\n");
		}
		else {
			printf("%s님이 입력한 학생입니다.\n", login_name);
			printf("이름    성적입력여부 \n");
			for (i = 0; i < input_count; i++) {
				printf("%s", s[i].name);
				if (atoi((s + i)->kor) > 0 && atoi((s + i)->kor) <= 100) {//0~100범위
					printf("       (O) \n");
				}
				else {
					printf("       (X) \n");
				}
			}
		}

		if (add_count == 0) {//학생이 추가되었다면
			printf("추가입력한 학생이 없습니다.\n");
		}
		else {
			printf("%s님이 추가한 학생입니다.\n", login_name);
			printf("이름    성적입력여부 \n");
			for (i = 0; i < add_count; i++) {
				printf("%s", as[i].name);
				if (atoi((as + i)->kor) > 0 && atoi((as + i)->kor) <= 100) {//0~100범위
					printf("       (O) \n");
				}
				else {
					printf("       (X) \n");
				}
			}
		}

		/*if (load_count == 0) {//학생이 불러와졌다면
			printf("파일에 학생이 없습니다.\n");
		}
		else {
			printf("%s님이 파일에 입력한 학생들입니다g.\n");
			printf("이름    성적입력여부 \n");
			for (i = 0; i < input_count; i++) {
				printf("%s", ls[i].name);
				if (atoi((ls + i)->kor) > 0 && atoi((ls + i)->kor) <= 100) {//0~100범위
					printf("       (O) \n");
				}
				else {
					printf("       (X) \n");
				}
			}
		}*/


		/*   성적문 양식
		printf("================================성적표===================================\n");
		printf(" 존함   국어(학점)  영어(학점)  수학(학점)   총점  전체평균    전체평점\n");
		for (i = 0; i < last; i++) {
			printf("%2s %4s(%s) %8s(%s) %8s(%s) %6d %11lf %6s\n",
				(ss + i)->name, (ss + i)->kor, (ss + i)->subK, (ss + i)->eng, (ss + i)->subE, (ss + i)->mat, (ss + i)->subM,
				(ss + i)->sum, (ss + i)->avg, (ss + i)->totG);
		}
		printf("==========================================================================\n");
		*/
		extern input_grade_count;//학생 성적입력 카운터
		extern add_grade_count;//추가 학생 성적 카운터
		extern load_grade_count;//로드학생 성적 카운터
		printf("\t\t1. 현재 성적입력한 학생보기\n");
		printf("\t\t2. 기존에 입력된 학생보기\n");
		printf("\t\t3. 종료\n");
		printf("\t\t type nomber: "); scanf("%d", &ch);

		switch (ch) {

			case 1:

				while (1) {
					printf("================================성적표===================================\n");
					printf(" 존함   국어(학점)  영어(학점)  수학(학점)   총점  전체평균    전체평점\n");
					if (input_grade_count > 0) {//성적이 입력되었고
						for (i = 0; i < input_grade_count; i++) {
							if (atoi((s + i)->kor) > 0 && atoi((s + i)->kor) <= 100) {//제대로 입력이 됬으면 그놈을 출력
								printf("%2s %4s(%s) %8s(%s) %8s(%s) %6d %11lf %6s\n",
									(s + i)->name, (s + i)->kor, (g + i)->subK, (s + i)->eng, (g + i)->subE, (s + i)->mat, (g + i)->subM,
									(s + i)->sum, (s + i)->avg, (g + i)->totG);
							}
						}
					}
					if (add_grade_count > 0) {
						for (i = 0; i < add_grade_count; i++) {
							if (atoi((as + i)->kor) > 0 && atoi((as + i)->kor) <= 100) {//제대로 입력이 됬으면 그놈을 출력
								printf("%2s %4s(%s) %8s(%s) %8s(%s) %6d %11lf %6s\n",
									(as + i)->name, (as + i)->kor, (g + i)->subK, (as + i)->eng, (g + i)->subE, (as + i)->mat, (g + i)->subM,
									(as + i)->sum, (as + i)->avg, (g + i)->totG);
							}
						}
					}
					/*if (load_grade_count > 0) {
						for (i = 0; i < load_grade_count; i++) {
							if (atoi((ls + i)->kor) > 0 && atoi((ls + i)->kor) <= 100) {//제대로 입력이 됬으면 그놈을 출력
								printf("%2s %4s(%s) %8s(%s) %8s(%s) %6d %11lf %6s\n",
									(ls + i)->name, (ls + i)->kor, (g + i)->subK, (ls + i)->eng, (g + i)->subE, (ls + i)->mat, (g + i)->subM,
									(ls + i)->sum, (ls + i)->avg, (g + i)->totG);
							}
						}
					}*/
					printf("==========================================================================\n");

					//printf("\t\t\t 1.오름차순 정렬(못구현)\n");
					//printf("\t\t\t 1.내림차순 정렬(못구현)\n");
					//printf("\t\t\t 3.되돌아가기\n");
					printf("종료하시겠습니까? 1.y 2.n");
					printf("\t\t type nomber: "); scanf("%d", &ch);
					
					switch (ch) {
						
						case 1:

							break;

						case 2:
							system("cls");
							continue;

						default:
							printf("1~2 사이의 숫자만 입력하세요\n");
					}
					break;
				}

			case 2:
				load_size = input_count + add_count;
				load_grade_count = 0;
				/*FILE *load_si = fopen(".\\login_file\\student_info.txt", "r");
				struct load_student_info *info_load_student;
				info_load_student = malloc(sizeof(struct student) * 20);//파일안 인원수만큼 할당
				for (i = 0; i < load_size; i++) {//구조체 내부 변수 동적할당 선언
					info_load_student[i].name = (char*)malloc(sizeof(char) * 10);
					info_load_student[i].pass = (char*)malloc(sizeof(char) * 20);
					fscanf(load_si, "%s %s", info_load_student[i].name, info_load_student[i].pass);
				}fclose(load_si);*/

				FILE *load_p = fopen("student.txt", "r");
				struct load_student *load_profile;
				load_profile = malloc(sizeof(struct student) * 20);//
				i = 0;
				while (i < 20) {//구조체 내부 변수 동적할당 선언
					if (feof(load_p)) break;
					(load_profile + i)->name = (char*)malloc(sizeof(char) * 10);
					(load_profile + i)->kor = (char*)malloc(sizeof(char) * 10);
					(load_profile + i)->eng = (char*)malloc(sizeof(char) * 10);
					(load_profile + i)->mat = (char*)malloc(sizeof(char) * 10);
					(load_profile + i)->sum = (int *)malloc(sizeof(int) * 10);
					fscanf(load_p, "%s %s %s %s %d %lf\n",
						(load_profile + i)->name, (load_profile + i)->kor, (load_profile + i)->eng,
						(load_profile + i)->mat, &load_profile[i].sum, &load_profile[i].avg); //이름, 국어, 영어, 수학 까지만 가능. 그 이상은 터짐
					load_grade_count++;
					i++;
				}fclose(load_p);
				//load_grade_count--;

				/*struct load_grade_info *load_grade;
				load_grade = malloc(sizeof(struct load_grade_info) * 20);
				i = 0;
				while (i < 20) {//구조체 내부 변수 동적할당 선언
					load_grade[i].subK = (char*)malloc(sizeof(char) * 10);
					load_grade[i].subE = (char*)malloc(sizeof(char) * 10);
					load_grade[i].subM = (char*)malloc(sizeof(char) * 10);
					load_grade[i].totG = (char*)malloc(sizeof(char) * 10);
					i++;
				}*/

				load_setgrade(load_profile, g, load_grade_count);

				printf("\n");
				for (i = 0; i < load_grade_count; i++) {
					if (atoi((load_profile + i)->kor) > 0 && atoi((load_profile + i)->kor) <= 100) {//제대로 입력이 됬으면 그놈을 출력
						printf("%2s %4s(%s) %8s(%s) %8s(%s) %6d %11lf %6s\n",
							(load_profile + i)->name, (load_profile + i)->kor, (g + i)->subK, (load_profile + i)->eng, (g + i)->subE, (load_profile + i)->mat, (g + i)->subM,
							(load_profile + i)->sum, (load_profile + i)->avg, (g + i)->totG);
					}
				}

				printf("==========================================================================\n");

				printf("종료하시겠습니까? 1.y 2.n");
				printf("\t\t type nomber: "); scanf("%d", &ch);

				switch (ch) {

				case 1:
					free(load_profile, load_grade);
					break;

				case 2:
					system("cls");
					continue;

				default:
					printf("1~2 사이의 숫자만 입력하세요\n");
				}
				break;

			case 3:

				break;

			default :
				printf("1~2 숫자만 입력하세요\n");
		}break;
	}
}

void changeTHEstudent(struct student *s, struct student_info *si, struct add_student *as, struct add_student_info *asi, struct grade_info *g) { //5번 출력과 수정
	  //이름 국어(학점) 영어(학점) 수학(학점) 총점 평균 평균학점
	int ch;
	char *change_name = (char*)malloc(sizeof(char) * 10);


	while (1) {
		if (input_count == 0) {//학생 정보가 입력되었다면
			printf("입력한 학생이 없습니다.\n");
		}
		else {
			printf("%s님이 입력한 학생입니다.\n", login_name);
			printf("이름    성적입력여부 \n");
			for (i = 0; i < input_count; i++) {
				printf("%s", s[i].name);
				if (atoi((s + i)->kor) > 0 && atoi((s + i)->kor) <= 100) {//0~100범위
					printf("       (O) \n");
				}
				else {
					printf("       (X) \n");
				}
			}
		}

		if (add_count == 0) {//학생이 추가되었다면
			printf("추가입력한 학생이 없습니다.\n");
		}
		else {
			printf("%s님이 추가한 학생입니다.\n", login_name);
			printf("이름    성적입력여부 \n");
			for (i = 0; i < input_count; i++) {
				printf("%s", as[i].name);
				if (atoi((as + i)->kor) > 0 && atoi((as + i)->kor) <= 100) {//0~100범위
					printf("       (O) \n");
				}
				else {
					printf("       (X) \n");
				}
			}
		}

		/*if (load_count == 0) {//학생이 불러와졌다면
			printf("파일에 학생이 없습니다.\n");
		}
		else {
			printf("%s님이 파일에 입력한 학생들입니다g.\n");
			printf("이름    성적입력여부 \n");
			for (i = 0; i < input_count; i++) {
				printf("%s", ls[i].name);
				if (atoi((ls + i)->kor) > 0 && atoi((ls + i)->kor) <= 100) {//0~100범위
					printf("       (O) \n");
				}
				else {
					printf("       (X) \n");
				}
			}
		}*/
		printf("\t\t\t1. 이름변경\n");
		printf("\t\t\t2. 점수변경\n");
		//printf("\t\t\t3. 학생제거(못구현)\n");
		printf("\t\t\t3. 종료\n");
		printf("\t\t    현재 %d번 수정하였습니다.\n", change_count);
		printf("\t\t\t type number : "); scanf("%d", &ch);
		
		switch (ch) {
		case 1://이름변경 만약 이름이 겹치면 좆됨
			//세개를 검사한다 or 파일학생 추가학생 입력학생 구분을해서 변경한다
			printf("누구 이름을 바꿀꺼고? ");  scanf("%s", change_name);
			for (i = 0; i < input_count; i++) {
				if (strcmp((s + i)->name, change_name) == 0) { //프로그램에 입력한 구조체에서
					printf("프로그램에서 입력한 학생입니다\n"); //이름을 바꾸기 위해 이름검사
					printf("뭐로 바꿀끼고? : "); scanf("%s", (s + i)->name);
					strcpy((si + i)->name, (s + i)->name);//학생 텍스트 정보 구조체에 덮어씀
					change_count++;
					//strcpy((os + i)->name, change_name); 이걸하면 찾은 이름으로 다시 바뀌게 된다.

				}
				else if (i == (input_count - 1) && strcmp((s + i)->name, change_name) != 0) {
					printf("그런사람은 없스무이다 다시 하세요\n");
					break;
				}
			}

			for (i = 0; i < add_count; i++) {
				if (strcmp((as + i)->name, change_name) == 0) { //이름을 바꾸기 위해 이름검사
					printf("추가 입력한 학생입니다\n");
					printf("뭐로 바꿀끼고? : "); scanf("%s", (as + i)->name);
					strcpy((asi + i)->name, (as + i)->name);//학생 텍스트 정보 구조체에 덮어씀
					change_count++;
					//strcpy((os + i)->name, change_name); 이걸하면 찾은 이름으로 다시 바뀌게 된다.
				}
				else if (i == (add_count - 1) && strcmp((as + i)->name, change_name) != 0) {
					printf("그런사람은 없스무이다 다시 하세요\n");
					break;
				}
			}

			/*for (i = 0; i < load_count; i++) {
				if (strcmp((ls + i)->name, change_name) == 0) { //이름을 바꾸기 위해 이름검사
					printf("파일에 불러온 학생입니다\n");
					printf("뭐로 바꿀끼고? : "); scanf("%s", (ls + i)->name);
					strcpy((lsi + i)->name, (ls + i)->name);//학생 텍스트 정보 구조체에 덮어씀
					change_count++;
					//strcpy((os + i)->name, change_name); 이걸하면 찾은 이름으로 다시 바뀌게 된다.
				}
				else if (i == (load_count - 1) && strcmp((ls + i)->name, change_name) != 0) {
					printf("그런사람은 없스무이다 다시 하세요\n");
					break;
				}
			}*/

			
			system("cls");
			break;

		case 2://점수변경
			//
			system("cls");
			while (1) {
				int ch;

				if (atoi((s + i)->kor) > 0 && atoi((s + i)->kor) <= 100) {//0~100범위 성적이 입력된 닝겐이면
					printf("입력한 동무들\n");
					printf("================================성적표===================================\n");
					printf(" 존함   국어(학점)  영어(학점)  수학(학점)   총점  전체평균    전체평점\n");
					for (i = 0; i < input_grade_count; i++) {
						printf("%2s %4s(%s) %8s(%s) %8s(%s) %6d %11lf %6s\n",
							(s + i)->name, (s + i)->kor, (g + i)->subK, (s + i)->eng, (g + i)->subE, (s + i)->mat, (g + i)->subM,
							(s + i)->sum, (s + i)->avg, (g + i)->totG);
					}
				}
				if (atoi((as + i)->kor) > 0 && atoi((as + i)->kor) <= 100) {//0~100범위 성적이 입력된 닝겐이면
					printf("추가입력한 동무들\n");
					printf("================================성적표===================================\n");
					printf(" 존함   국어(학점)  영어(학점)  수학(학점)   총점  전체평균    전체평점\n");
					for (i = 0; i < add_grade_count; i++) {
						printf("%2s %4s(%s) %8s(%s) %8s(%s) %6d %11lf %6s\n",
							(as + i)->name, (as + i)->kor, (g + i)->subK, (as + i)->eng, (g + i)->subE, (as + i)->mat, (g + i)->subM,
							(as + i)->sum, (as + i)->avg, (g + i)->totG);
					}
				}
				/*if (atoi((ls + i)->kor) > 0 && atoi((ls + i)->kor) <= 100) {//0~100범위 성적이 입력된 닝겐이면
					printf("프로그렘에 입력된 동무들\n");
					printf("================================성적표===================================\n");
					printf(" 존함   국어(학점)  영어(학점)  수학(학점)   총점  전체평균    전체평점\n");
					for (i = 0; i < load_grade_count; i++) {
						printf("%2s %4s(%s) %8s(%s) %8s(%s) %6d %11lf %6s\n",
							(ls + i)->name, (ls + i)->kor, (g + i)->subK, (ls + i)->eng, (g + i)->subE, (ls + i)->mat, (g + i)->subM,
							(ls + i)->sum, (ls + i)->avg, (g + i)->totG);
					}
				}*/
				printf("\t\t\t1. 국어점수 변경\n");
				printf("\t\t\t2. 수학점수 변경\n");
				printf("\t\t\t3. 영어점수 변경\n");
				printf("\t\t\t4. 종료\n");
				printf("\t\t    현재 %d번 수정하였습니다.\n", change_count);
				printf("\t\t\t type number : "); scanf("%d", &ch);

				switch (ch) {
				case 1:
/*
extern input_count;//학생 입력한 카운터
extern add_count;//추가 학생 카운터
extern load_count;//로드 학생 카운터

extern input_grade_count;//학생 성적입력 카운터
extern add_grade_count;//추가 학생 성적 카운터
extern load_grade_count;//로드학생 성적 카운터
*/
					printf("누구의 국어점수를 바꿀꺼고? (나가시려면 quit)");  scanf("%s", change_name);
					if (strcmp(change_name, "quit") == 0) {
						system("cls");
						break;
					}

					while (1) {
						if (strcmp((s + i)->name, change_name) == 0) { //프로그램에 입력한 구조체에서
							printf("프로그램에서 입력한 학생입니다\n"); //성적 바꾸기위해 입력한이름 검사 
							printf("현재 국어점수는 %s 입니다 몇점으로 바꾸쉴?? : ", (s + i)->kor); scanf("%s", (s + i)->kor);
							change_count++;
							break;//입력했으면 빤스런
						}
						if (strcmp((as + i)->name, change_name) == 0) { //성적 바꾸기위해 입력한이름 검사 
							printf("추가 입력한 학생입니다\n");
							printf("현재 국어점수는 %s 입니다 몇점으로 바꾸쉴?? : ", (as + i)->kor); scanf("%s", (as + i)->kor);
							change_count++;
							break;//입력했으면 빤스런
						}
						/*if (strcmp((ls + i)->name, change_name) == 0) { //성적 바꾸기위해 입력한이름 검사 
							printf("파일에 불러온 학생입니다\n");
							printf("현재 국어점수는 %s 입니다 몇점으로 바꾸쉴?? : ", (ls + i)->kor); scanf("%s", (ls + i)->kor);
							change_count++;
							break;//입력했으면 빤스런
						}*/
						/*
						else if (i == (input_count - 1) && strcmp((s + i)->name, change_name) != 0) {
							printf("그런사람은 없스무이다 다시 하세요\n");
							break;
						}

						else if (i == (add_count - 1) && strcmp((as + i)->name, change_name) != 0) {
							printf("그런사람은 없스무이다 다시 하세요\n");
							break;
						}

						else if (i == (load_count - 1) && strcmp((ls + i)->name, change_name) != 0) {
							printf("그런사람은 없스무이다 다시 하세요\n");
							break;
						}
						*/

						i++;
						if (i == (input_grade_count + add_grade_count + load_grade_count)) {//다 합쳐도 사람이 나오지 않다면
							printf("그런 사람은 없스무이다 다시 하세요\n");
							break;
						}
					}
					/*
					for (i = 0; i < input_grade_count; i++) {//성적이 입력된 학생만 검사
						if (strcmp((s + i)->name, change_name) == 0) { //프로그램에 입력한 구조체에서
							printf("프로그램에서 입력한 학생입니다\n"); //성적 바꾸기위해 입력한이름 검사 
							printf("현재 국어점수는 %s 입니다 몇점으로 바꾸쉴?? : ", (s + i)->kor); scanf("%s", (s + i)->kor);
							change_count++;
						}
						else if (i == (input_count - 1) && strcmp((s + i)->name, change_name) != 0) {
							printf("그런사람은 없스무이다 다시 하세요\n");
							break;
						}
					}
					for (i = 0; i < add_grade_count; i++) {
						if (strcmp((as + i)->name, change_name) == 0) { //성적 바꾸기위해 입력한이름 검사 
							printf("추가 입력한 학생입니다\n");
							printf("현재 국어점수는 %s 입니다 몇점으로 바꾸쉴?? : ", (as+i)->kor); scanf("%s", (as + i)->kor);
							change_count++;
						}
						else if (i == (add_count - 1) && strcmp((as + i)->name, change_name) != 0) {
							printf("그런사람은 없스무이다 다시 하세요\n");
							break;
						}
					}
					for (i = 0; i < load_grade_count; i++) {
						if (strcmp((ls + i)->name, change_name) == 0) { //성적 바꾸기위해 입력한이름 검사 
							printf("파일에 불러온 학생입니다\n");
							printf("현재 국어점수는 %s 입니다 몇점으로 바꾸쉴?? : ", (ls + i)->kor); scanf("%s", (ls + i)->kor);
							change_count++;
						}
						else if (i == (load_count - 1) && strcmp((ls + i)->name, change_name) != 0) {
							printf("그런사람은 없스무이다 다시 하세요\n");
							break;
						}
					}
					*/
					system("cls");
					break;

				case 2:

					printf("누구의 수학점수를 바꿀꺼고? (나가시려면 quit)");  scanf("%s", change_name);
					if (strcmp(change_name, "quit") == 0) {
						system("cls");
						break;
					}

					while (1) {
						if (strcmp((s + i)->name, change_name) == 0) { //프로그램에 입력한 구조체에서
							printf("프로그램에서 입력한 학생입니다\n"); //성적 바꾸기위해 입력한이름 검사 
							printf("현재 수학점수는 %s 입니다 몇점으로 바꾸쉴?? : ", (s + i)->mat); scanf("%s", (s + i)->mat);
							change_count++;
							break;//입력했으면 빤스런
						}
						if (strcmp((as + i)->name, change_name) == 0) { //성적 바꾸기위해 입력한이름 검사 
							printf("추가 입력한 학생입니다\n");
							printf("현재 수학점수는 %s 입니다 몇점으로 바꾸쉴?? : ", (as + i)->mat); scanf("%s", (as + i)->mat);
							change_count++;
							break;//입력했으면 빤스런
						}
						/*if (strcmp((ls + i)->name, change_name) == 0) { //성적 바꾸기위해 입력한이름 검사 
							printf("파일에 불러온 학생입니다\n");
							printf("현재 수학점수는 %s 입니다 몇점으로 바꾸쉴?? : ", (ls + i)->mat); scanf("%s", (ls + i)->mat);
							change_count++;
							break;//입력했으면 빤스런
						}*/
						/*
						else if (i == (input_count - 1) && strcmp((s + i)->name, change_name) != 0) {
							printf("그런사람은 없스무이다 다시 하세요\n");
							break;
						}

						else if (i == (add_count - 1) && strcmp((as + i)->name, change_name) != 0) {
							printf("그런사람은 없스무이다 다시 하세요\n");
							break;
						}

						else if (i == (load_count - 1) && strcmp((ls + i)->name, change_name) != 0) {
							printf("그런사람은 없스무이다 다시 하세요\n");
							break;
						}
						*/

						i++;
						if (i == (input_grade_count + add_grade_count + load_grade_count)) {//다 합쳐도 사람이 나오지 않다면
							printf("그런 사람은 없스무이다 다시 하세요\n");
							break;
						}
					}
					system("cls");
					break;

				case 3:

					printf("누구의 영어점수를 바꿀꺼고? (나가시려면 quit)");  scanf("%s", change_name);
					if (strcmp(change_name, "quit") == 0) {
						system("cls");
						break;
					}

					while (1) {
						if (strcmp((s + i)->name, change_name) == 0) { //프로그램에 입력한 구조체에서
							printf("프로그램에서 입력한 학생입니다\n"); //성적 바꾸기위해 입력한이름 검사 
							printf("현재 영어점수는 %s 입니다 몇점으로 바꾸쉴?? : ", (s + i)->eng); scanf("%s", (s + i)->eng);
							change_count++;
							break;//입력했으면 빤스런
						}
						if (strcmp((as + i)->name, change_name) == 0) { //성적 바꾸기위해 입력한이름 검사 
							printf("추가 입력한 학생입니다\n");
							printf("현재 영어점수는 %s 입니다 몇점으로 바꾸쉴?? : ", (as + i)->eng); scanf("%s", (as + i)->eng);
							change_count++;
							break;//입력했으면 빤스런
						}
						/*if (strcmp((ls + i)->name, change_name) == 0) { //성적 바꾸기위해 입력한이름 검사 
							printf("파일에 불러온 학생입니다\n");
							printf("현재 영어점수는 %s 입니다 몇점으로 바꾸쉴?? : ", (ls + i)->eng); scanf("%s", (ls + i)->eng);
							change_count++;
							break;//입력했으면 빤스런
						}*/
						/*
						else if (i == (input_count - 1) && strcmp((s + i)->name, change_name) != 0) {
							printf("그런사람은 없스무이다 다시 하세요\n");
							break;
						}

						else if (i == (add_count - 1) && strcmp((as + i)->name, change_name) != 0) {
							printf("그런사람은 없스무이다 다시 하세요\n");
							break;
						}

						else if (i == (load_count - 1) && strcmp((ls + i)->name, change_name) != 0) {
							printf("그런사람은 없스무이다 다시 하세요\n");
							break;
						}
						*/

						i++;
						if (i == (input_grade_count + add_grade_count + load_grade_count)) {//다 합쳐도 사람이 나오지 않다면
							printf("그런 사람은 없스무이다 다시 하세요\n");
							break;
						}
					}
					system("cls");
					break;

				case 4://성적 수정 종료

					break;

				default:
					printf("1부터 4까지 수를 입력하쇼\n");
				}
			}
			break;

		/*case 3://학생제거 응 안구현

			break;
		*/
		case 3://종료
			
			break;

		default :
			printf("1부터 3까지 입력하십시오\n");
		}
		break;

	}
	system("cls");
}

void input_file(struct student *s, struct student_info *si, struct add_student *as, struct add_student_info *asi, struct grade_info *g) { //6번 파일에 입력

	int ch;
	int awr=0;//파일 쓰기 입력모드를 결정할꺼
	char c;
	/*FILE *fp = fopen("student.txt", "r");
	while ((c = fgetc(fp)) != EOF) {
		if (c == '\n') 		awr++;//읽으면서 몇마리있는지 세줌
	}fclose(fp);
		/*
		파일에 아무것도 안쓰여있다면 w모드로 새로쓰고
		fprintf(p, "%d %d \n", &n &nn);
		파일에 기존에 쓰여져있다면
		로드한 파일을 다시 w모드로 덮어쓰고
		추가학생과 프로그램에 입력한 학생을 a모드로
		*/
	while (1) {
		printf("현재 프로그램에 입력된 총 학생의 수는 %d명이고\n", input_count + add_count + load_count);
		printf("성적까지 입력된 학생은 총 %d명 입니다.\n", input_grade_count + add_grade_count + load_grade_count);

		printf("\t\t\t1. 파일에 쓰기\n");
		printf("\t\t\t2. 종료\n");
		printf("\t\t\t type number : "); scanf("%d", &ch);
	

		switch (ch) {
		case 1:
			printf("파일에 저장하였습니다.");
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
			extern input_count;//학생 입력한 카운터
			extern add_count;//추가 학생 카운터
			extern load_count;//로드 학생 카운터

			extern input_grade_count;//학생 성적입력 카운터
			extern add_grade_count;//추가 학생 성적 카운터
			extern load_grade_count;//로드학생 성적 카운터
			*/
			/*if (load_count > 0) {//로드학생이 존재한다면 새로 씀
				FILE *p = fopen(".\\login_file\\student_info.txt", "w");//정보 파일
				FILE *fp = fopen("student,txt", "w");//성적파일
				for (i = 0; i < load_count; i++) {//정보파일에다 씀
					fprintf(p, "%s %s\n", lsi[i].name, lsi[i].pass);
				}fclose(p);
				for (i = 0; i < load_grade_count; i++) {//성적파일에다 씀
					fprintf(fp, "%2s %4s %s  %8s %s  %8s %s  %6d %11lf %6s\n",
						(ls + i)->name, (ls + i)->kor, (g + i)->subK, (ls + i)->eng, (g + i)->subE, (ls + i)->mat, (g + i)->subM,
						(ls + i)->sum, (ls + i)->avg, (g + i)->totG);
				}fclose(fp);
				if (add_count > 0) {//로드학생이 존재하고 추가학생이 존재하면 더함
					FILE *p = fopen(".\\login_file\\student_info.txt", "a");//정보 파일
					FILE *fp = fopen("student,txt", "a");//성적파일
					for (i = 0; i < add_count; i++) {//정보파일에다 씀
						fprintf(p, "%s %s\n", asi[i].name, asi[i].pass);
					}fclose(p);
					for (i = 0; i < add_grade_count; i++) {//성적파일에다 씀
						fprintf(fp, "%2s %4s %s  %8s %s  %8s %s  %6d %11lf %6s\n",
							(as + i)->name, (as + i)->kor, (g + i)->subK, (as + i)->eng, (g + i)->subE, (as + i)->mat, (g + i)->subM,
							(as + i)->sum, (as + i)->avg, (g + i)->totG);
					}fclose(fp);
					if (input_count > 0) {//로드학생이 존재하고 추가학생이 존재하고 입력학생이 있으면 파일에 더함
						FILE *p = fopen(".\\login_file\\student_info.txt", "a");//정보 파일
						FILE *fp = fopen("student,txt", "a");//성적파일
						for (i = 0; i < input_count; i++) {//정보파일에다 씀
							fprintf(p, "%s %s\n", si[i].name, si[i].pass);
						}fclose(p);
						for (i = 0; i < add_grade_count; i++) {//성적파일에다 씀
							fprintf(fp, "%2s %4s %s  %8s %s  %8s %s  %6d %11lf %6s\n",
								(s + i)->name, (s + i)->kor, (g + i)->subK, (s + i)->eng, (g + i)->subE, (s + i)->mat, (g + i)->subM,
								(s + i)->sum, (s + i)->avg, (g + i)->totG);
						}fclose(fp);
					}
					else {//로드학생이 존재하고 추가학생이 존재하고 입력학생이 없으면 로드와 추가학생을 더함
						break;
					}
				}
				else {//로드학생이 있고 추가파일이 없으면
					if (input_count > 0) {//로드학생과 입력학생을 더함
						FILE *p = fopen("student,txt", "a");
						for (i = 0; i < input_count; i++) {
							fprintf(p, "%s %s\n", si[i].name, si[i].pass);
						}fclose(p);
					}
					else {//로드학생은 있고 추가파일도없고 입력학생도 없으면 로드학생만 더함
						break;
					}
				}
			}
			else {//로드학생이 존재하지않고
				if (add_count > 0) {//추가학생부터 존재한다면
					FILE *p = fopen(".\\login_file\\student_info.txt", "w");//정보 파일
					FILE *fp = fopen("student,txt", "a");//성적파일
					for (i = 0; i < add_count; i++) {//정보파일에다 씀
						fprintf(p, "%s %s\n", asi[i].name, asi[i].pass);
					}fclose(p);
					for (i = 0; i < add_grade_count; i++) {//성적파일에다 씀
						fprintf(fp, "%2s %4s %s %8s %s %8s %s  %6d %11lf %6s\n",
							(as + i)->name, (as + i)->kor, (g + i)->subK, (as + i)->eng, (g + i)->subE, (as + i)->mat, (g + i)->subM,
							(as + i)->sum, (as + i)->avg, (g + i)->totG);
					}fclose(fp);
					if (input_count > 0) {//추가학생이 존재하고 입력학생이 존재하면 덪붙임
						FILE *p = fopen(".\\login_file\\student_info.txt", "a");//정보 파일
						FILE *fp = fopen("student,txt", "a");//성적파일
						for (i = 0; i < input_count; i++) {//정보파일에다 씀
							fprintf(p, "%s %s\n", si[i].name, si[i].pass);
						}fclose(p);
						for (i = 0; i < add_grade_count; i++) {//성적파일에다 씀
							fprintf(fp, "%2s %4s %s %8s %s %8s %s %6d %11lf %6s\n",
								(s + i)->name, (s + i)->kor, (g + i)->subK, (s + i)->eng, (g + i)->subE, (s + i)->mat, (g + i)->subM,
								(s + i)->sum, (s + i)->avg, (g + i)->totG);
						}fclose(fp);
					}
					else {//로드학생도없고 입력학생이 없으면 추가학생을 덫붙임
						break;
					}

				}
				else {//추가학생이 존재하지않고
						if (input_count > 0) {//입력학생이 존재하면 입력학생으로 새로씀
							FILE *p = fopen(".\\login_file\\student_info.txt", "w");//정보 파일
							FILE *fp = fopen("student,txt", "a");//성적파일
							for (i = 0; i < input_count; i++) {//정보파일에다 씀
								fprintf(p, "%s %s\n", si[i].name, si[i].pass);
							}fclose(p);
							for (i = 0; i < add_grade_count; i++) {//성적파일에다 씀
								fprintf(fp, "%2s %4s %s %8s %s %8s %s %6d %11lf %6s\n",
									(s + i)->name, (s + i)->kor, (g + i)->subK, (s + i)->eng, (g + i)->subE, (s + i)->mat, (g + i)->subM,
									(s + i)->sum, (s + i)->avg, (g + i)->totG);
							}fclose(fp);
						}
						else {
							printf("\n\n로드학생도없고 추가학생도없고 입력학생도 없습니다 \n");
							Sleep(4000);
						}
				}
			}*/
			break;

		case 2:


			break;

		default:
			printf("다시 입력하세요\n");
		}
		break;
	}
	fflush(stdin);
	//input_success();
}

void input_setgrade(struct student *s, struct grade_info *g) { //1-1. 학생 정보 입력다음에 등급부여하는거

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
		//입력된 점수로 합을 구함 그에따른 평균과 학점부여            
		(s + i)->sum = atoi((s + i)->kor) + atoi((s + i)->eng) + atoi((s + i)->mat);
		(s + i)->avg = (double)((s + i)->sum) / 3;
		//평균에따른 학점부여
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
		//입력된 점수로 합을 구함 그에따른 평균과 학점부여            
		(as + i)->sum = atoi((as + i)->kor) + atoi((as + i)->eng) + atoi((as + i)->mat);
		(as + i)->avg = (double)((as + i)->sum) / 3;
		//평균에따른 학점부여
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

void load_setgrade(struct load_student *ls, struct grade_info *g, int load_grade_count) { //학생 입력후 등급부여
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
		//입력된 점수로 합을 구함 그에따른 평균과 학점부여            
		(ls + i)->sum = atoi((ls + i)->kor) + atoi((ls + i)->eng) + atoi((ls + i)->mat);
		(ls + i)->avg = (double)((ls + i)->sum) / 3;
		//평균에따른 학점부여
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
int isStringDouble(char *s) { //문자열 검사
	size_t size = strlen(s);
	if (size == 0) return 0; // 0바이트 문자열은 숫자가 아님

	for (int i = 0; i < (int)size; i++) {
		if (s[i] == '.' || s[i] == '-' || s[i] == '+') continue;
		if (s[i] < '0' || s[i] > '9') return 0; // 알파벳 등이 있으면 숫자 아님
	}
	return 1; // 그밖의 경우는 숫자임
}