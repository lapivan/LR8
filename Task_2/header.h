union budj
{
    int a;
    bool b;
};
typedef struct students
{
    char fio[80];
    int group;
    float srednball;
    float doh;
    budj budget;
}students;
void strmenu(students* p, int n);
int getValue();
float getfloat(students *p, int n);
int getmenuValue();
int getinteger();
void menu();
void task();
void menu();
bool russian(const char* input);
void inputdata(students* p, int n);
void showdata(students *p, int n);
void addnewelem(students* p, int&n);
void deleteline(students* p, int &n, int j);
void sort(students* p, int n);
void insertsort(students* p, int n);
void change(students* p, int n);
int nullone();