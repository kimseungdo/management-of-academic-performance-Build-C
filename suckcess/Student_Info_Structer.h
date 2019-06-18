struct program {
	int total_size;
};
struct student {
	//char name[10]; //이름
	char *name;
	char *kor;
	char *eng;
	char *mat; //국어점수 영어점수 수학점수
	int sum;
	double avg;
	//char subK[2], subE[2], subM[2], totG[2];//국어등급 영어등급 수학등급 전체등급 
}profile;

struct add_student {
	//char name[10]; //이름
	char *name;
	char *kor;
	char *eng;
	char *mat; //국어점수 영어점수 수학점수
	int sum;
	double avg;
	//char subK[2], subE[2], subM[2], totG[2];//국어등급 영어등급 수학등급 전체등급 
}add_profile; //성적

struct load_student { //파일을 불러들일때 저장할 구조체
	//char name[10]; //이름
	char *name;
	char *kor;
	char *eng;
	char *mat; //국어점수 영어점수 수학점수
	int sum;
	double avg;
	//char subK[2], subE[2], subM[2], totG[2];//국어등급 영어등급 수학등급 전체등급 

}load_profile;

struct grade_info {
	char *subK;
	char *subE;
	char *subM;
	char *totG;
}grade;

struct load_grade_info {
	char *subK;
	char *subE;
	char *subM;
	char *totG;
}load_grade;