#include "header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstring>
extern void mainprogramm();
void addnewelem(students* p, int&n) //для добавления 1 структуры в массив 
    {
        if(n == 0)
        {
            std::cout << "В настощий момент студенты отсутствуют. " << std::endl;
            mainprogramm();
        }
        n++;
        p= (students *)realloc(p, n * sizeof(students)); //увеличиваем размер массива структур
        for(int i= n-1; i<n; i++)
        {
            p[i].group = -1;
            p[i].srednball = -1;
            p[i].doh = -1;
            p[i].budget.a = -1;
            memset(p[i].fio, 0, sizeof(p[i].fio));
        } 
        std::cout << "Введите данные для нового студента: " << std::endl;
        inputdata(p, n);
    }
    void deleteline(students* p, int &n, int j)// удаление одной структуры
    {
        system("clear");
        for(int i = j-1; i + 1 < n; i++)
        {
            p[i].budget.b = p[i+1].budget.b;
            p[i].doh = p[i+1].doh;
            p[i].group = p[i+1].group;
            p[i].srednball = p[i+1].srednball;
            strcpy(p[i].fio, p[i + 1].fio);
        }
        n--;
        p= (students *)realloc(p, n * sizeof(students)); //сокращение на 1 массива структур
        std::ofstream fout; //обьект класса офстримдля записи в текстовый файл
            fout.open("file.txt");
            if(!fout.is_open()) //перезаписваем весь текстовй файл
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
                    fout << p[i].group << std::endl;
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
        strmenu(p, n); //возврат в меню
    }