#include "header.h"
trains stopinput(trains* p, int n, trains buf)
    {
        system("clear");
        std::cout << "Нажмите 1, чтобы сделать особым значение пунктa отправления: " << std::endl << "Нажмите 2, чтобы сделать особым значение времени отправления: " << std::endl << "Нажмите 3, чтобы сделать особым значение количества мест: " << std::endl << "Нажмите 4, чтобы сделать особым значение цены: " << std::endl << "Нажмите 5, чтобы сделать особым значение времени в дороге: " << std::endl << "Нажмите 6, чтобы сделать особым значение длины маршрута: " << std::endl << "Нажмите 7, чтобы сделать особым значение средней скорости:"; 
        int n1 = getmenuValue();
        std::cin.clear();
        std::cin.ignore(32767,'\n');
        buf.arrivepoint[0] = '-'; 
        buf.arrivepoint[1] = '5';
        buf.arrivepoint[2] = '\0';
        buf.timeotpr[0] =  '-';
        buf.timeotpr[1] = '5';
        buf.timeotpr[2] = '\0';
        buf.length.b = -5;
        buf.midspeed   = -5;
        buf.numplaces = -5;
        buf.price = -5;
        buf.racetime = -5;
        if(n1 == 1)
        {
            std::cout << "Введите особое значение: " << std::endl;
            bool check = 0;
            char check_str[80];
                while(!check)
                {
                    std::cin.getline(check_str, 80);
                    if (strcmp(check_str, "!") == '\0')
                    {
                        system("clear");
                        strmenu(p, n, buf);
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
            strncpy(buf.arrivepoint, check_str, 79); //заполняем буфер, а затем при вводе сравниваем определенное поле с полями буфера
            buf.arrivepoint[79] = '\0';
        }
        if(n1 == 2)
        {
            std::cout << "Введите особое значение: " << std::endl;
            bool inputcheck = false;
            char check_str1[6];
            while(!inputcheck)
                {
                    bool flag = false;
                    std::cin.getline(check_str1, 6);
                    if (strcmp(check_str1, "!") == 0)
                    {
                        system("clear");
                        strmenu(p, n, buf); 
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
            strncpy(buf.timeotpr, check_str1, 6);
            buf.timeotpr[79] = '\0';
        }
        if(n1 == 3)
        {
            std::cout << "Введите особое значение: " << std::endl;
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
            buf.numplaces = n1;
        }
        if(n1 == 4)
        {
            std::cout << "Введите особое значение: " << std::endl;
            float n1 = getfloat(p,n, buf);
            buf.price = n1;
        }
        if(n1 == 5)
        {
            std::cout << "Введите особое значение: " << std::endl;
            float n1 = getfloat(p,n, buf);
            buf.racetime = n1;
        }
        if(n1 == 6)
        {
            std::cout << "Введите особое значение: " << std::endl;
            float n1 = getfloat(p,n, buf);
            buf.length.b = n1;
        }
        if(n1 == 7)
        {
            std::cout << "Введите особое значение: " << std::endl;
            float n1 = getfloat(p,n, buf);
            buf.midspeed = n1;
        }
        return buf;
    }