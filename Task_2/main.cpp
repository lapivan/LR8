#include <iostream>
#include <fstream>
#include <cstring>
#include "header.h"

students *generatemass(int n) //создание массива структур
    {
        students *p = (students*)malloc(n * sizeof(students));
        return p;
    }

void deletemasstruct(students *p) //удаление массива структур
    {
        free(p);
    }

void strmenu(students* p, int n) //меню непосредственной работ с массивом структур
    {
        system("clear");
        int n1 = 0;
        std::cout << "Нажмите 1, чтобы увидеть введенную информацию: " << std::endl << "Нажмите 2, чтобы заполнить информацию: " << std::endl << "Нажмите 3, чтобы добавить еще студента: " << std::endl << "Нажмите 4, чтобы удалить какую-либо структуру: " << std::endl << "Нажмите 5, чтобы вывести студентов в приоритетном порядке для заселения: " << std::endl << "Нажмите 6, чтобы изменить поле структуры: " << std::endl << "Нажмите 0, чтобы вернуться в меню: ";
        n1 = getmenuValue();
        bool check = 0;
        while(check == 0) 
        {   
        if (n1 == 1) 
        {
            system("clear");
            showdata(p, n);
            check = 1;
        }
        else if(n1 == 0) 
        {
            system("clear");
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            deletemasstruct(p);
            menu();
            check = 1;
        }
        else if(n1 == 2)  
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            inputdata(p,n);
            check = 1;
        }
        else if(n1 == 3)  
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            addnewelem(p,n);
            check = 1;
        }
        else if(n1 == 4)  
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            system("clear");
            std::cout << "Введите номер студента, которого хотите удалить: ";
            bool check = false;
            int j = 0;
            while(!check)
            {
                j = getinteger();
                if(j > n)
                {
                    std::cout << "Введите повторно: ";
                    continue;
                }
                else
                {
                    check = true;
                }
            }
            
            deleteline(p, n, j);
            check = 1;
        }
        else if(n1 == 5)  
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            sort(p, n);
            check = 1;
        }
        else if(n1 == 6)  
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            change(p, n);
            check = 1;
        }
        else 
        { 
            std::cout << "Введите повторно: ";
            n1 = getValue();
        }
    }
        
    }

void mainprogramm()
    {
    system("clear");
    students *p =  NULL;
    int n = 0;
    std::cout << "Введите начальное количество студентов: " << std::endl;
    n = getinteger();
    p = generatemass(n); //создаем массив
    for(int i= 0; i<n; i++) //заполняем его значениями по умолчанию  
    {
        p[i].group = -1;
        p[i].srednball = -1;
        p[i].doh = -1;
        p[i].budget.a = -1;
        memset(p[i].fio, 0, sizeof(p[i].fio));
    }
    std::cin.clear();
    std::cin.ignore(32767,'\n');
    strmenu(p, n);
    }

int main() 
{
    menu();
    return 0;
}