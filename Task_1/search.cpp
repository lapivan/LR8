#include "header.h"
    void search(trains* p, int n, trains buf)
    {
        system("clear");
        std::cout << "Нажмите 1, если хотите искать по пункту отправления" << std::endl;
        std::cout << "Нажмите 2, если хотите искать по времени" << std::endl;
        std::cout << "Нажмите 3, если хотите искать по количеству мест" << std::endl;
        std::cout << "Нажмите 4, если хотите искать по цене" << std::endl;
        std::cout << "Нажмите 5, если хотите искать по длине маршрута" << std::endl;
        std::cout << "Нажмите 6, если хотите искать по времени в дороге" << std::endl;
        std::cout << "Нажмите 7, если хотите искать по скорости движения" << std::endl;
        int n1 = 0;
        n1 = getmenuValue();
        std::cin.clear();
        std::cin.ignore(32767,'\n');
        bool checkz = 0;
        while(checkz == 0) 
        {
   
        if (n1 == 1) 
        {
            std::cout << "Введите искомую величину: ";
            bool check = 0;
            char check_str[80];
                while(!check)
                {
                    std::cin.getline(check_str, 1000000000);
                    if (strcmp(check_str, "!") == '\0') //восклицательный знак - прекращение  ввода
                    {
                        system("clear");
                        strmenu(p, n, buf);
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
                    else
                    {
                        check = 1;
                    }        
                }
            for(int i = 0; i < n; i++)
            {
                if(strcmp(check_str, p[i].arrivepoint)  == 0)
                {
                    std::cout << "Поезд " << i+1 << ": " << std::endl;
            std::cout << "Пункт отправления: ";
            if (strcmp(p[i].arrivepoint, "") == 0)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].arrivepoint << std::endl;
            }   
            std::cout << "Время отправления: ";
            if (strcmp(p[i].timeotpr, "") == 0)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].timeotpr << std::endl;
            }
            std::cout << "Количество мест: ";
            if (p[i].numplaces == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].numplaces<< std::endl;
            }
            std::cout << "Цена(р): ";
            if (p[i].price == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].price<< std::endl;
            }
            std::cout << "Время в дороге(ч): ";
            if (p[i].racetime == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].racetime << std::endl;
            }
            std::cout << "Длина маршрута(км): ";
            if (p[i].length.b == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].length.b << std::endl;
            }
            std::cout << "Средняя скорость(км/ч): ";
            if (p[i].length.b == -1 || p[i].racetime == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].midspeed << std::endl;
            }   
            }
            }
            checkz = 1;
        }
        else if(n1 == 2) 
        {
            std::cout << "Введите искомую величину: ";
            bool inputcheck = false;
            char check_str1[6];
            while(!inputcheck)
                {
                    bool flag = false;
                    std::cin.getline(check_str1, 10000000);
                    if (strcmp(check_str1, "!") == 0)
                    {
                        system("clear");
                        strmenu(p, n, buf); 
                    }
                    if (strlen(check_str1) > 79) 
                    {
                        std::cout << "Ошибка: строка слишком длинная. Попробуйте снова." << std::endl;
                        continue;
                    } 
                    for(int j = 0; j < 5; j++)
                    {
                        if(j == 2)
                        {
                            if(check_str1[2] == ':')
                            {
                                continue;
                            }
                            else
                            {
                                std::cout << "Ошибка ввода в формате HH:MM, повторите попытку: " << std::endl;
                                break;
                            }
                        }
                        if(check_str1[j] < 48 || check_str1[j] > 57)
                        {
                            std::cout << "Ошибка ввода в формате HH:MM, повторите попытку: " << std::endl;
                            break;
                        }
                        if(j == 4)
                        {
                            flag = 1;
                        }
                    }
                    if(flag == 1)
                    {
                        char first2[3];
                        char last2[3];
                        first2[0] = check_str1[0];
                        first2[1] = check_str1[1];
                        first2[2] = '\0';
                        last2[0] = check_str1[3];
                        last2[1] = check_str1[4];
                        last2[2] = '\0';
                        if(std::atoi(first2) > 23 || std::atoi(last2) > 60)
                        {
                            std::cout << "Ошибка ввода в формате HH:MM, повторите попытку: " << std::endl;
                            continue;
                        }
                        else
                        {
                            inputcheck = 1;
                        }
                    }
                    
                }
            for(int i = 0; i < n; i++)
            {
                if(strcmp(check_str1, p[i].timeotpr)  == 0)
                {
                    std::cout << "Поезд " << i+1 << ": " << std::endl;
            std::cout << "Пункт отправления: ";
            if (strcmp(p[i].arrivepoint, "") == 0)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].arrivepoint << std::endl;
            }   
            std::cout << "Время отправления: ";
            if (strcmp(p[i].timeotpr, "") == 0)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].timeotpr << std::endl;
            }
            std::cout << "Количество мест: ";
            if (p[i].numplaces == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].numplaces<< std::endl;
            }
            std::cout << "Цена(р): ";
            if (p[i].price == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].price<< std::endl;
            }
            std::cout << "Время в дороге(ч): ";
            if (p[i].racetime == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].racetime << std::endl;
            }
            std::cout << "Длина маршрута(км): ";
            if (p[i].length.b == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].length.b << std::endl;
            }
            std::cout << "Средняя скорость(км/ч): ";
            if (p[i].length.b == -1 || p[i].racetime == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].midspeed << std::endl;
            }
                            }
            }
            checkz = 1;
        }
        else if(n1 == 3)  
        {
            std::cout << "Введите искомую величину: ";
            char input_str[80];
                bool check = 0;
                while(!check)
                {
                    int pointcounter = 0;
                    std::cin.getline(input_str, 80);
                    if (strcmp(input_str, "!") == 0)
                    {
                        system("clear");
                        strmenu(p, n, buf); 
                    }
                    for(int i = 0; i < 80; i++)
                    {
                        if(input_str[0] == '\0')
                        {
                            std::cout << "Повторите ввод: " << std::endl;
                            break;
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
                        if((input_str[i] <  48 || input_str[i] > 57))
                        {
                            std::cout << "Повторите ввод: " << std::endl;
                            break;
                        }
                    }
                }
                int j1 = std::atoi(input_str);
            for(int i = 0; i < n; i++)
            {
                if(j1  == p[i].numplaces)
                {
                    std::cout << "Поезд " << i+1 << ": " << std::endl;
            std::cout << "Пункт отправления: ";
            if (strcmp(p[i].arrivepoint, "") == 0)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].arrivepoint << std::endl;
            }   
            std::cout << "Время отправления: ";
            if (strcmp(p[i].timeotpr, "") == 0)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].timeotpr << std::endl;
            }
            std::cout << "Количество мест: ";
            if (p[i].numplaces == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].numplaces<< std::endl;
            }
            std::cout << "Цена(р): ";
            if (p[i].price == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].price<< std::endl;
            }
            std::cout << "Время в дороге(ч): ";
            if (p[i].racetime == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].racetime << std::endl;
            }
            std::cout << "Длина маршрута(км): ";
            if (p[i].length.b == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].length.b << std::endl;
            }
            std::cout << "Средняя скорость(км/ч): ";
            if (p[i].length.b == -1 || p[i].racetime == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].midspeed << std::endl;
            }
                           }
            }
            checkz = 1;
        }
        else if(n1 == 4)  
        {
            float j2 = getfloat(p,n,buf);
            for(int i = 0; i < n; i++)
            {
                if(j2  == p[i].price)
                {
                    std::cout << "Поезд " << i+1 << ": " << std::endl;
            std::cout << "Пункт отправления: ";
            if (strcmp(p[i].arrivepoint, "") == 0)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].arrivepoint << std::endl;
            }   
            std::cout << "Время отправления: ";
            if (strcmp(p[i].timeotpr, "") == 0)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].timeotpr << std::endl;
            }
            std::cout << "Количество мест: ";
            if (p[i].numplaces == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].numplaces<< std::endl;
            }
            std::cout << "Цена(р): ";
            if (p[i].price == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].price<< std::endl;
            }
            std::cout << "Время в дороге(ч): ";
            if (p[i].racetime == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].racetime << std::endl;
            }
            std::cout << "Длина маршрута(км): ";
            if (p[i].length.b == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].length.b << std::endl;
            }
            std::cout << "Средняя скорость(км/ч): ";
            if (p[i].length.b == -1 || p[i].racetime == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].midspeed << std::endl;
            }
                           }
            }
            checkz = 1;
        }
        else if(n1 == 5)  
        {
            float j3 = getfloat(p,n,buf);
            for(int i = 0; i < n; i++)
            {
                if(j3  == p[i].length.b)
                {
                    std::cout << "Поезд " << i+1 << ": " << std::endl;
            std::cout << "Пункт отправления: ";
            if (strcmp(p[i].arrivepoint, "") == 0)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].arrivepoint << std::endl;
            }   
            std::cout << "Время отправления: ";
            if (strcmp(p[i].timeotpr, "") == 0)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].timeotpr << std::endl;
            }
            std::cout << "Количество мест: ";
            if (p[i].numplaces == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].numplaces<< std::endl;
            }
            std::cout << "Цена(р): ";
            if (p[i].price == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].price<< std::endl;
            }
            std::cout << "Время в дороге(ч): ";
            if (p[i].racetime == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].racetime << std::endl;
            }
            std::cout << "Длина маршрута(км): ";
            if (p[i].length.b == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].length.b << std::endl;
            }
            std::cout << "Средняя скорость(км/ч): ";
            if (p[i].length.b == -1 || p[i].racetime == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].midspeed << std::endl;
            }
                            }
            
            checkz = 1;
            }
        }
        else if(n1 == 6)  
        {
            float j4 = getfloat(p,n,buf);
            
            for(int i = 0; i < n; i++)
            {
                if(j4 == p[i].racetime)
            {
                std::cout << "Поезд " << i+1 << ": " << std::endl;
            std::cout << "Пункт отправления: ";
            if (strcmp(p[i].arrivepoint, "") == 0)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].arrivepoint << std::endl;
            }   
            std::cout << "Время отправления: ";
            if (strcmp(p[i].timeotpr, "") == 0)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].timeotpr << std::endl;
            }
            std::cout << "Количество мест: ";
            if (p[i].numplaces == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].numplaces<< std::endl;
            }
            std::cout << "Цена(р): ";
            if (p[i].price == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].price<< std::endl;
            }
            std::cout << "Время в дороге(ч): ";
            if (p[i].racetime == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].racetime << std::endl;
            }
            std::cout << "Длина маршрута(км): ";
            if (p[i].length.b == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].length.b << std::endl;
            }
            std::cout << "Средняя скорость(км/ч): ";
            if (p[i].length.b == -1 || p[i].racetime == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].midspeed << std::endl;
            }
            }
            checkz = 1;
            }
        }
        else if(n1 == 7)  
        {
            float j5 = getfloat(p,n,buf);;
            for(int i = 0; i < n; i++)
            {
                if(j5  == p[i].midspeed)
                {
                    std::cout << "Поезд " << i+1 << ": " << std::endl;
            std::cout << "Пункт отправления: ";
            if (strcmp(p[i].arrivepoint, "") == 0)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].arrivepoint << std::endl;
            }   
            std::cout << "Время отправления: ";
            if (strcmp(p[i].timeotpr, "") == 0)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].timeotpr << std::endl;
            }
            std::cout << "Количество мест: ";
            if (p[i].numplaces == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].numplaces<< std::endl;
            }
            std::cout << "Цена(р): ";
            if (p[i].price == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].price<< std::endl;
            }
            std::cout << "Время в дороге(ч): ";
            if (p[i].racetime == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].racetime << std::endl;
            }
            std::cout << "Длина маршрута(км): ";
            if (p[i].length.b == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].length.b << std::endl;
            }
            std::cout << "Средняя скорость(км/ч): ";
            if (p[i].length.b == -1 || p[i].racetime == -1)
            {
                std::cout << "Данные отсутствуют " << std::endl;
            }
            else 
            {
                std::cout << p[i].midspeed << std::endl;
            }
            }
            }
            checkz = 1;
        }
        
        else if(n1 == 0)  
        {
            system("clear");
            checkz = 1;
            strmenu(p, n, buf);
            
        }
        else 
        { 
            std::cout << "Введите повторно: ";
            n1 = getValue();
        }
        }
        std::cout << std::endl <<"Введите 0 для повторного поиска: " << std::endl << "Иначе введите 1: ";
        int k;
        k = getValue();
        bool check1 = 0;
        while(check1 == 0) 
        {
        if (k == 0)
        {
            system("clear");
            search(p, n, buf);
            check1 = 1;
        }
        else
        {
            system("clear");
            strmenu(p, n, buf);
        }
        }

    }