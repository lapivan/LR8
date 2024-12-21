#include <iostream>
#include "header.h"
    void insertsort(students* p, int n) //каждый элемент вставляется в отсортированную часть массива на то место, где он должен находиться
    {
        for(int i = 1; i < n; i++)
        {
            int j = i - 1;
            students buf;
            while(p[i].srednball > p[j].srednball && j>=0)
            {
                buf = p[i];
                p[i] = p[j];
                p[j] = buf;
                j--;
                i--;
                if(j < 0)
                {
                    break;
                }
            }
        }
    }
    void sort(students* p, int n)
    {
        system("clear");
        std::cout << "Минимальная зарплата(2024) в РБ - 626р " << std::endl;
        for(int i = 0; i < n; i++)//сначала выводит тех у кого меньше двух минимальных
        {
            if(p[i].doh <= 1252 && p[i].doh > 0)
            {
                std::cout << p[i].fio << ' ' << ", Доход: " << p[i].doh << "p" << ", Средний балл: " << p[i].srednball << std::endl;
            }
        }
        insertsort(p, n); //сортировка
        for(int i = 0; i < n; i++)
        {
            if(p[i].doh > 1252 && p[i].srednball > 0)
            {
                std::cout << p[i].fio << ' ' << ", Доход: " << p[i].doh << "p" << ", Средний балл: " << p[i].srednball << std::endl;
            }
        }
        std::cout << std::endl <<"Введите 0 для возврата в главное меню: ";
        int k;
        k = getValue();
        bool check = 0;
        while (check == 0) 
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
        system("clear");
        strmenu(p, n);
    }