struct professor_info {//��������
	//char name[10]; //�̸�
	char *name;
	char *pass;

};
struct load_professor {
	char *name;
	char *pass;
};

struct student_info {//�л�����
	char *name;
	char *pass;
}info_student;

struct add_student_info {//�߰��л�����
	char *name;
	char *pass;
}info_add_student;

struct load_student_info {
	char *name;
	char *pass;
}info_load_student;