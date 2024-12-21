#include "header.h"
    void inputdata(trains* p, int n, trains buf)
    {

        system("clear");
        std::cout << "Для прекращения ввода пропишите '!' : " << std::endl;
        for(int i = 0; i < n; i++)
        {
            if(p[i].arrivepoint[0] == '\0')
            {
                std::cout << "Введите пункт отправления для поезда " << i+1  << " :" <<std::endl;
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
                strncpy(p[i].arrivepoint, check_str, 79);
                p[i].arrivepoint[79] = '\0';
                if ((strcmp(p[i].arrivepoint, buf.arrivepoint) == 0)) //в буф записанозаранее введенное  особое значение
                {
                    std::cout << "Особое значение найдено" << std::endl;
                    std::cout << "Введите 1 для продолжения ввода" << std::endl  << "Введите 0 для возврата в меню: " << std::endl;
                    int n1 = getmenuValue();
                    if(n1 == 0)
                    {
                        strmenu(p, n, buf);
                    }
                    std::cin.clear();
                    std::cin.ignore(32767,'\n');
                }

            }
            if(p[i].timeotpr[0] == '\0')
            {
                bool inputcheck = false;
                std::cout << "Введите время отправления для поезда(HH:MM) " << i+1 << " (остальная часть строки будет обрезана)" << " :" <<std::endl;
                while(!inputcheck)
                {
                    bool flag = false;
                    char check_str1[6];
                    std::cin.getline(check_str1, 6);
                    if (strcmp(check_str1, "!") == 0)
                    {
                        system("clear");
                        strmenu(p, n, buf); 
                    }
                    strncpy(p[i].timeotpr, check_str1, 6);
                    p[i].timeotpr[5] = '\0';
                    for(int j = 0; j < 5; j++)
                    {
                        if(j == 2)
                        {
                            if(p[i].timeotpr[j] == ':')
                            {
                                continue;
                            }
                            else
                            {
                                std::cout << "Ошибка ввода в формате HH:MM, повторите попытку: " << std::endl;
                                break;
                            }
                        }
                        if(p[i].timeotpr[j] < 48 || p[i].timeotpr[j] > 57)
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
                        first2[0] = p[i].timeotpr[0];
                        first2[1] = p[i].timeotpr[1];
                        first2[2] = '\0';
                        last2[0] = p[i].timeotpr[3];
                        last2[1] = p[i].timeotpr[4];
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
                if (strcmp(p[i].timeotpr, buf.timeotpr) == 0)
                {
                    std::cout << "Особое значение найдено" << std::endl;
                    std::cout << "Введите 1 для продолжения ввода" << std::endl  << "Введите 0 для возврата в меню: " << std::endl;
                    int n1 = getmenuValue();
                    if(n1 == 0)
                    {
                        strmenu(p, n, buf);
                    }
                    
                }
            }
            if(p[i].numplaces == -1)
            {
                //std::cin.clear();
                //std::cin.ignore(32767,'\n');
                std::cout << "Введите количество мест для поезда " << i+1  << " :" <<std::endl;
                bool check = 0;
                char input_str[80];
                while(!check)
                {
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
                p[i].numplaces = std::atoi(input_str);
                if(p[i].numplaces < 0)
                {
                    p[i].numplaces = 0;
                }
                if (p[i].numplaces == buf.numplaces)
                {
                    std::cout << "Особое значение найдено" << std::endl;
                    std::cout << "Введите 1 для продолжения ввода" << std::endl  << "Введите 0 для возврата в меню: " << std::endl;
                    int n1 = getmenuValue();
                    if(n1 == 0)
                    {
                        strmenu(p, n, buf);
                    }
                    std::cin.clear();
                    std::cin.ignore(32767,'\n');
                }
            }
            if(p[i].price == -1)
            {
                std::cout << "Введите цену билета для поезда(p) " << i+1  << " :" <<std::endl;
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
                p[i].price = std::atof(input_str);
                if(p[i].price < 0)
                {
                    p[i].price = 0;
                }
                if (p[i].price == buf.price)
                {
                    std::cout << "Особое значение найдено" << std::endl;
                    std::cout << "Введите 1 для продолжения ввода" << std::endl  << "Введите 0 для возврата в меню: " << std::endl;
                    int n1 = getmenuValue();
                    if(n1 == 0)
                    {
                        strmenu(p, n, buf);
                    }
                    std::cin.clear();
                    std::cin.ignore(32767,'\n');
                } 
            }
            if(p[i].racetime == -1)
            {
                std::cout << "Введите время в дороге для поезда(ч) " << i+1  << " :" <<std::endl;
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
                p[i].racetime = std::atof(input_str);
                if(p[i].racetime < 0)
                {
                    p[i].racetime = 0;
                }
                if (p[i].racetime == buf.racetime)
                {
                    std::cout << "Особое значение найдено" << std::endl;
                    std::cout << "Введите 1 для продолжения ввода" << std::endl  << "Введите 0 для возврата в меню: " << std::endl;
                    int n1 = getmenuValue();
                    if(n1 == 0)
                    {
                        strmenu(p, n, buf);
                    }
                    std::cin.clear();
                    std::cin.ignore(32767,'\n');
                } 
            }
            if(p[i].length.b == -1)
            {
                std::cout << "Введите длину маршрута до пункта назначения дляя поезда(км) " << i+1  << " :" <<std::endl;
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
                p[i].length.b = std::atof(input_str);
                if(p[i].length.b < 0)
                {
                    p[i].length.b = 0;
                }
                if (p[i].length.b == buf.length.b)
                {
                    std::cout << "Особое значение найдено" << std::endl;
                    std::cout << "Введите 1 для продолжения ввода" << std::endl  << "Введите 0 для возврата в меню: " << std::endl;
                    int n1 = getmenuValue();
                    if(n1 == 0)
                    {
                        strmenu(p, n, buf);
                    }
                    std::cin.clear();
                    std::cin.ignore(32767,'\n');
                } 
            }
            if(p[i].midspeed == -1)
            {
                p[i].midspeed = p[i].length.b/p[i].racetime;
                if (p[i].midspeed == buf.midspeed)
                {
                    std::cout << "Особое значение найдено(для скорости)" << std::endl;
                    std::cout << "Введите 1 для продолжения ввода" << std::endl  << "Введите 0 для возврата в меню: " << std::endl;
                    int n1 = getmenuValue();
                    if(n1 == 0)
                    {
                        strmenu(p, n, buf);
                    }
                    std::cin.clear();
                    std::cin.ignore(32767,'\n');
                }
            }
        }
        //  сохраним  в  файле  наши  поезда
        FILE *f = fopen("trains.bin", "wb+");
        if(f)
        {
            fseek(f,0L,SEEK_END);
            fwrite( p, sizeof( trains ), n, f );
            fclose(f);
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
                strmenu(p, n, buf);
                check = 1;
            }
            else
            {
                std::cout << "Введите повторно: ";
                k = getValue(); 
            }

        }
    }