struct professor_info {//교수정보
	//char name[10]; //이름
	char *name;
	char *pass;

};
struct load_professor {
	char *name;
	char *pass;
};

struct student_info {//학생정보
	char *name;
	char *pass;
}info_student;

struct add_student_info {//추가학생정보
	char *name;
	char *pass;
}info_add_student;

struct load_student_info {
	char *name;
	char *pass;
}info_load_student;