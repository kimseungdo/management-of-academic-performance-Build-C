struct program {
	int total_size;
};
struct student {
	//char name[10]; //�̸�
	char *name;
	char *kor;
	char *eng;
	char *mat; //�������� �������� ��������
	int sum;
	double avg;
	//char subK[2], subE[2], subM[2], totG[2];//������ ������ ���е�� ��ü��� 
}profile;

struct add_student {
	//char name[10]; //�̸�
	char *name;
	char *kor;
	char *eng;
	char *mat; //�������� �������� ��������
	int sum;
	double avg;
	//char subK[2], subE[2], subM[2], totG[2];//������ ������ ���е�� ��ü��� 
}add_profile; //����

struct load_student { //������ �ҷ����϶� ������ ����ü
	//char name[10]; //�̸�
	char *name;
	char *kor;
	char *eng;
	char *mat; //�������� �������� ��������
	int sum;
	double avg;
	//char subK[2], subE[2], subM[2], totG[2];//������ ������ ���е�� ��ü��� 

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