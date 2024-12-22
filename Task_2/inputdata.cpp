#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include "header.h"
#include <cstdlib>
#include <fstream>

void inputdata(students* p, int n) //заполнение полей структур
    {
        system("clear");
        std::cout << "Для прекращения ввода пропишите '!' : " << std::endl;
        for(int i = 0; i < n; i++)
        {
            if(p[i].fio[0] == '\0')
            {
                std::cout << "Введите фамилию студента " << i+1  << " :" <<std::endl;
                bool checkfam = 0;
                char check_str[80];
                char space[2];
                space[0] = ' ';
                space[1] = '\0';
                int counter = 0;
                while(!checkfam)
                {
                    std::cin.getline(check_str, 100000);
                    if (strcmp(check_str, "!") == '\0')
                    {
                        system("clear");
                        strmenu(p, n);
                    }
                    if (strlen(check_str) > 79) 
                    {
                        std::cout << "Ошибка: строка слишком длинная. Попробуйте снова." << std::endl;
                        continue;
                    }
                    if(check_str[0] == '\0')
                    {
                        std::cout << "Ошибка ввода, повторите попытку: " << std::endl;
                    }
                    for(int i =  0; check_str[i] != '\0'; i++)
                    {
                        if((check_str[i] < 65 || check_str[i] > 90))
                        {
                            if((check_str[i] < 97 || check_str[i] > 122))
                            {
                                if(russian(check_str) == false)
                                {
                                    checkfam = 0;
                                    std::cout << "Ошибка ввода, повторите попытку: " << std::endl;
                                    break;
                                }
                            }                            
                        }
                        counter++;
                        if(check_str[i+1] == '\0')
                        {
                            checkfam = 1;
                        }
                    }
                    if(checkfam == 0)
                    {
                        continue;
                    }
                    else
                    {
                        checkfam = 1;
                    }        
                }
                strncpy(p[i].fio, check_str, counter);
                std::cout << "Введите имя студента " << i+1  << " :" <<std::endl;
                bool checkname= 0;
                char check_str1[80];
                while(!checkname)
                {
                    std::cin.getline(check_str1, 80);
                    if (strcmp(check_str1, "!") == '\0')
                    {
                        system("clear");
                        strmenu(p, n);
                    }
                    if(check_str1[0] == '\0')
                    {
                        std::cout << "Ошибка ввода, повторите попытку: " << std::endl;
                    }
                    for(int i =  0; check_str1[i] != '\0'; i++)
                    {
                        if((check_str1[i] < 65 || check_str1[i] > 90))
                        {
                            if((check_str1[i] < 97 || check_str1[i] > 122))
                            {
                                if(russian(check_str1) == false)
                                {
                                    checkfam = 0;
                                    std::cout << "Ошибка ввода, повторите попытку: " << std::endl;
                                    break;
                                }
                            }                            
                        }
                        counter++;
                        if(check_str1[i+1] == '\0')
                        {
                            checkname = 1;
                        }
                    }
                    if(checkname == 0)
                    {
                        continue;
                    }
                    else
                    {
                        checkname = 1;
                    }        
                }
                strcat(p[i].fio, space);
                strcat(p[i].fio, check_str1);
                std::cout << "Введите отчество студента " << i+1  << " :" <<std::endl;
                bool checkotch= 0;
                char check_str2[80];
                while(!checkotch)
                {
                    std::cin.getline(check_str2, 80);
                    if (strcmp(check_str1, "!") == '\0')
                    {
                        system("clear");
                        strmenu(p, n);
                    }
                    if(check_str2[0] == '\0')
                    {
                        std::cout << "Ошибка ввода, повторите попытку: " << std::endl;
                    }
                    for(int i =  0; check_str2[i] != '\0'; i++)
                    {
                        if((check_str2[i] < 65 || check_str2[i] > 90))
                        {
                            if((check_str2[i] < 97 || check_str2[i] > 122))
                            {
                                if(russian(check_str) == false)
                                {
                                    checkfam = 0;
                                    std::cout << "Ошибка ввода, повторите попытку: " << std::endl;
                                    break;
                                }
                            }                            
                        }
                        if(check_str2[i+1] == '\0')
                        {
                            checkotch = 1;
                        }
                    }
                    if(checkotch == 0)
                    {
                        continue;
                    }
                    else
                    {
                        checkotch = 1;
                    }        
                }
                strcat(p[i].fio, space);
                strcat(p[i].fio, check_str2);
                filerecorder(p, n);
            }
            if(p[i].group == -1)
            {
                std::cout << "Введите номер группы для студента " << i+1  << " :" <<std::endl;
                bool check = 0;
                char input_str[80];
                while(!check)
                {
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
                        if(input_str[i] == '\0')
                        {
                            check= 1;
                            break;
                        }
                        if(input_str[i] <  48 || input_str[i] > 57)
                        {
                            std::cout << "Повторите ввод: " << std::endl;
                            break;
                        }
                    }
                }
                p[i].group = std::atoi(input_str);
                filerecorder(p, n);
            }
            if(p[i].srednball == -1)
            {
                std::cout << "Введите средний балл студента " << i+1  << " :" <<std::endl;
                bool check = 0;
                float f1 = 0;
                while(!check)
                {
                    f1 = getfloat(p, n);
                    if(f1 >= 0 && f1 <= 10)
                    {
                        check = true;
                    }
                    else
                    {
                        std::cout<< "Повторите ввод: "  << std::endl;
                    }
                }
                p[i].srednball = f1;
                filerecorder(p, n);
            }
                
            
            if(p[i].doh == -1)
            {
                std::cout << "Введите доход родителя студента(p) " << i+1  << " :" <<std::endl;
                float f2 = getfloat(p, n);
                p[i].doh = f2;
                filerecorder(p, n);
               
            }
            if(p[i].budget.a == -1)
            {
                std::cout << "Нажмите 1, если студент - бюджетник: " << std::endl; 
                std::cout << "Иначе нажмите 0: " << std::endl;
                bool f3 = nullone();
                p[i].budget.b = f3;
                std::cin.clear();
                std::cin.ignore(32767,'\n');
                filerecorder(p, n);
            }
            filerecorder(p, n);
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