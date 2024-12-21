#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <cstdlib>

union len
{
    int a;
    float b;
};

typedef struct trains
{
    char arrivepoint[80];
    char timeotpr[6];
    int numplaces;
    float price;
    float racetime;
    len length;
    float midspeed;
}trains;

void menu();
void strmenu(trains* p, int n, trains buf);
void task();
int getValue();
int getmenuValue();
int getinteger();
void search(trains* p, int n, trains buf);
void addnewelem(trains* p, int&n, trains buf);
void inputdata(trains* p, int n, trains buf);
void deleteline(trains* p, int &n, int j, trains buf);
void change(trains* p, int n, trains buf);
void insertsort(trains* p, int n, trains buf);
trains stopinput(trains* p, int n, trains buf);
void outputplases(trains *p, int n, trains buf);
float getfloat(trains *p, int n, trains buf);
int nullone();