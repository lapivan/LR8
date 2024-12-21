#include "header.h"
#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
void showdata(students *p, int n) //вывод информации
    {
        system("clear");
        for(int i = 0; i < n; i++)
        {
            std::cout << "Студент " << i+1 << ": " << std::endl;
            std::cout << "ФИО: ";
            if (strcmp(p[i].fio, "") == 0) //по умолчанию 0, поэтому если 0, то не заполнено(аналогично  для всех)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].fio << std::endl;
            }   
            std::cout << "Номер группы: ";
            if (p[i].group == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].group << std::endl;
            }
            std::cout << "Средний балл: ";
            if (p[i].srednball == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].srednball<< std::endl;
            }
            std::cout << "Доход: ";
            if (p[i].doh == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].doh <<  "p" << std::endl;
            }
            std::cout << "Форма обучения: ";
            if (p[i].budget.a == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                if(p[i].budget.b == 0)
                {
                    std::cout << "Платная " << std::endl;
                }
                else
                {
                    std::cout << "Бюджет " << std::endl;
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl <<"Введите 0 для возврата в меню: ";
        int k;
        k = getValue();
        bool check = 0;
        while(check == 0) 
        {
        if (k == 0)
        {
            system("clear");
            strmenu(p, n);
            check = 1;
        }
        else
        {
            std::cout << "Введите повторно: ";
            k = getValue(); 
        }
        }
    }