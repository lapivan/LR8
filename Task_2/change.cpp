#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <fstream>
#include "header.h"
#include <cstdlib>
 void change(students* p, int n) //поменть отдельное поле
    {
        system("clear");
        int n1, n2;
        if(n == 0)
        {
            system("clear");
            strmenu(p, n);
        }
        std::cout << "Выберите студента, для которого хотите изменить данные в диапазоне от 1 до " << n << ": " << std::endl;
        n1 = getinteger();
        n1--;
        system("clear");
        std::cin.clear();
        std::cin.ignore(32767,'\n');
        std::cout << "Нажмите 1, чтобы изменить ФИО: " << std::endl << "Нажмите 2, чтобы изменить номер группы: " << std::endl << "Нажмите 3, чтобы изменить средний балл: " << std::endl << "Нажмите 4, чтобы изменить доход: " << std::endl << "Нажмите 5, чтобы изменить форму обучения: " << std::endl;
        n2 = getmenuValue();
        std::cin.clear();
        std::cin.ignore(32767,'\n');
        if(n2 == 1)
        {
            for(int i=  0; i < 80; i++)
            {
                p[n1].fio[i] = '\0';
            }
                std::cout << "Введите фамилию студента " << n1+1  << " :" <<std::endl;
                bool checkfam = 0;
                char check_str[80];
                char space[2];
                space[0] = ' ';
                space[1] = '\0';
                int counter = 0;
                while(!checkfam)
                {
                    std::cin.getline(check_str, 10000000);
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
                strncpy(p[n1].fio, check_str, counter);
                std::cout << "Введите имя студента " << n1+1  << " :" <<std::endl;
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
                strcat(p[n1].fio, space);
                strcat(p[n1].fio, check_str1);
                std::cout << "Введите отчество студента " << n1+1  << " :" <<std::endl;
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
                strcat(p[n1].fio, space);
                strcat(p[n1].fio, check_str2);
        }
        if(n2 == 2)
        {
                std::cout << "Введите номер группы для студента " << n1+1  << " :" <<std::endl;
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
                p[n1].group = std::atoi(input_str);
        }
        if(n2 == 3)
        {
                std::cout << "Введите средний балл студента " << n1+1  << " :" <<std::endl;
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
                p[n1].srednball = f1;
        }
        if(n2 == 4)
        {
                std::cout << "Введите доход родителя студента " << n1+1  << " :" <<std::endl;
                float f2 = getfloat(p, n);
                p[n1].doh = f2;
                
        }
        if(n2 == 5)
        {
                std::cout << "Нажмите 1, если студент - бюджетник: " << std::endl; 
                std::cout << "Иначе нажмите 0: " << std::endl;
                bool f3 = nullone();
                p[n1].budget.b = f3;
                std::cin.clear();
                std::cin.ignore(32767,'\n');
        }
        std::ofstream fout;
            fout.open("file.txt"); //открываем файл
            if(!fout.is_open()) //проверка на открытие
            {
                std::cout << "Ошибка открытия файла! " << std::endl;
            }
            else
            {
            for(int i = 0; i < n; i++) //перезапись всего файла
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
            fout.close();  //закрываем файл
        system("clear");
        strmenu(p, n);
    }