#include <iostream>
#include "header.h"
#include <string>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <fstream>

int getValue() //главное меню
{
    while (true) 
    {
        int a;
        std::cin >> a;
 

        if (std::cin.fail()  || (std::cin.peek() != '\n'))
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n'); 
            std::cout << "Неопознанная команда. Введите повторно: ";
        }
        else if (a == 1) {
            return a; 
        }
        else if (a == 2) {
            return a; 
        }
        else if (a == 0) {
            return a; 
        }
        else if (a == 3) {
            return a; 
        }
        else
        {  
            std::cin.clear(); 
            std::cin.ignore(32767,'\n'); 
            std::cout << "Неопознанная команда. Введите повторно: ";
        }
}
}
float getfloat(students *p, int n) //вещественное  число
{
            char input_str[80];
                bool check = 0;
                while(!check)
                {
                    int pointcounter = 0;
                    std::cin.getline(input_str, 80);
                    if (strcmp(input_str, "!") == 0)
                    {
                        system("clear");
                        strmenu(p, n); 
                    }
                    for(int i = 0; i < 80; i++)
                    {
                        if(input_str[0] == '\0')
                        {
                            std::cout << "Повторите ввод: " << std::endl;
                            break;
                        }
                        if(input_str[i] == '.')
                        {
                            pointcounter++;
                        }
                        if(pointcounter > 1)
                        {
                            std::cout << "Повторите ввод: " << std::endl;
                            break;
                        }
                        if(input_str[i] == '\0')
                        {
                            check= 1;
                            break;
                        }
                        if((input_str[i] <  48 || input_str[i] > 57) && input_str[i] != '.')
                        {
                            std::cout << "Повторите ввод: " << std::endl;
                            break;
                        }
                    }
                }
                float j1 = std::atof(input_str);
                return j1;
}
int getmenuValue() //обыычное меню
{
    while (true) 
    {
        int a;
        std::cin >> a;
 

        if (std::cin.fail()  || (std::cin.peek() != '\n'))
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n'); 
            std::cout << "Неопознанная команда. Введите повторно: ";
        }
        else if (a == 1) {
            return a; 
        }
        else if (a == 2) {
            return a; 
        }
        else if (a == 0) {
            return a; 
        }
        else if (a == 3) {
            return a; 
        }
        else if (a == 4) {
            return a; 
        }
        else if (a == 5) {
            return a; 
        }
        else if (a == 6) {
            return a; 
        }
        else
        {  
            std::cin.clear(); 
            std::cin.ignore(32767,'\n'); 
            std::cout << "Неопознанная команда. Введите повторно: ";
        }
}
}

bool findsymbol(unsigned  short  s)//проверка  ввода русских слов
{
    bool ret=false;
    char  symbol[] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя\0\0";
    for ( unsigned short * ptr = (unsigned short * )symbol; *ptr != 0; ptr++)
    {
        if(*ptr==s)
        {
            ret=true;
            break;
        }
    } 
    return ret;
}
bool russian(const char* input) 
{
    unsigned short * ptr = (unsigned short * )input;
    for ( ; ( char)*ptr != 0; ptr++) 
    {

        if(findsymbol(*ptr)==false)
        {
            return false;
            
        }
    }
    return true;
}
int getinteger()
{
    while (true) 
    {
        int a;
        std::cin >> a;
 

        if (std::cin.fail()  || (std::cin.peek() != '\n') || a < 0)
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n'); 
            std::cout << "Неопознанная команда. Введите повторно: ";
        }
        else
        return a;
}
}
int nullone() //только 0 и 1
{
    while (true) 
    {
        int a;
        std::cin >> a;
 

        if (std::cin.fail()  || (std::cin.peek() != '\n'))
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n'); 
            std::cout << "Неопознанная команда. Введите повторно: ";
        }
        else if (a == 1) {
            return a; 
        }
        
        else if (a == 0) {
            return a; 
        }
        else
        {  
            std::cin.clear(); 
            std::cin.ignore(32767,'\n'); 
            std::cout << "Неопознанная команда. Введите повторно: ";
        }
}
}
void filerecorder(students* p , int n)
{
    std::ofstream fout; //обьект класса офстрим для записи в файл
            fout.open("file.txt"); //перезапись файла
            if(!fout.is_open())
            {
                std::cout << "Ошибка открытия файла! " << std::endl;
            }
            else
            {
            for(int i = 0; i < n; i++)
            {
                fout << "Студент " << i+1 << ": " << std::endl;
                fout << "ФИО: ";
                if (strcmp(p[i].fio, "") == 0)
                {
                    fout << "Данные отсутствуют " << std::endl;
                }
                else 
                {
                    fout << p[i].fio << std::endl;
                }   
                fout << "Номер группы: ";
                if (p[i].group == -1)
                {
                    fout << "Данные отсутствуют " << std::endl;
                }
                else 
                {
                    fout << p[i].group  << std::endl;
                }
                fout << "Средний балл: ";
                if (p[i].srednball == -1)
                {
                    fout << "Данные отсутствуют " << std::endl;
                }
                else 
                {
                    fout << p[i].srednball<< std::endl;
                }
                fout << "Доход: ";
                if (p[i].doh == -1)
                {
                    fout << "Данные отсутствуют " << std::endl;
                }
                else 
                {
                    fout << p[i].doh<< std::endl;
                }
                fout << "Форма обучения: ";
                if (p[i].budget.a == -1)
                {
                    fout << "Данные отсутствуют " << std::endl;
                }
                else 
                {
                    if(p[i].budget.b == 0)
                    {
                        fout << "Платная " << std::endl;
                    }
                    else
                    {
                        fout << "Бюджет " << std::endl;
                    }
                }
                fout << std::endl;
            }
            }
            fout.close();
}