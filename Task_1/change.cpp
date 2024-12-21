 #include "header.h"
 void change(trains* p, int n, trains buf)
    {
        system("clear");
        int n1, n2;
        if(n == 0)
        {
            system("clear");
            strmenu(p, n, buf);
        }
        std::cout << "Выберите поезд, для которого хотите изменить данные в диапазоне от 1 до " << n << ": " << std::endl;
        n1 = getinteger();
        n1--;
        system("clear");
        std::cin.clear();
        std::cin.ignore(32767,'\n');
        std::cout << "Нажмите 1, чтобы изменить пункт отправления: " << std::endl << "Нажмите 2, чтобы изменить время отправления: " << std::endl << "Нажмите 3, чтобы изменить количество мест: " << std::endl << "Нажмите 4, чтобы изменить цену: " << std::endl << "Нажмите 5, чтобы изменить время в дороге: " << std::endl << "Нажмите 6, чтобы изменить длину маршрута: ";
        n2 = getmenuValue();
        std::cin.clear();
        std::cin.ignore(32767,'\n');
        long offset_arr  =  (long)(&((trains*)(0))->arrivepoint); //размер поля структуры(далее аналогично)
        long offset_otpr =  (long)(&((trains*)(0))->timeotpr);
        long offset_num =  (long)(&((trains*)(0))->numplaces);
        long offset_price =  (long)(&((trains*)(0))->price);
        long offset_length =  (long)(&((trains*)(0))->length.b);
        long offset_time =  (long)(&((trains*)(0))->racetime);
        long offset_speed =  (long)(&((trains*)(0))->midspeed);
        if(n2 == 1)
        {
                std::cout << "Введите пункт отправления для поезда " << n1+1  << " :" <<std::endl;
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
                strncpy(p[n1].arrivepoint, check_str, 79);
                p[n1].arrivepoint[79] = '\0';
                FILE* f;
                f = fopen("trains.bin", "r+b");
                if(f)
                {                
                    int poswrite = (n1) * sizeof(trains) + offset_arr; //запись в бин  файл(позицияя для записи)
                    fseek(f, poswrite, SEEK_SET );//двигаемся
                    fwrite(((char *)(p+n1))+offset_arr, (sizeof(char) * 80), 1, f); //записыываем
                    fclose(f);//закрываем(аналогично дляя всех полей)
                }
        }
        if(n2 == 2)
        {
                std::cout << "Введите время отправления для поезда " << n1+1  << " :" <<std::endl;
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
                strncpy(p[n1].timeotpr, check_str1, 5);
                p[n1].timeotpr[5] = '\0'; 
                FILE* f;
                f = fopen("trains.bin", "r+b");
                if(f)
                {                
                    int poswrite = (n1) * sizeof(trains) + offset_otpr;
                    fseek(f, poswrite, SEEK_SET );
                    fwrite(((char *)(p+n1))+offset_otpr, (sizeof(char) * 6), 1, f);
                    fclose(f);
                }
        }
        if(n2 == 3)
        {
                std::cout << "Введите количество мест для поезда " << n1+1  << " :" <<std::endl;
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
                p[n1].numplaces = std::atoi(input_str);
                FILE* f;
                f = fopen("trains.bin", "r+b");
                if(f)
                {                
                    int poswrite = (n1) * sizeof(trains) + offset_num;
                    fseek(f, poswrite, SEEK_SET );
                    fwrite(((char *)(p+n1))+offset_num, sizeof(int) , 1, f);
                    fclose(f);
                } 
        }
        if(n2 == 4)
        {
                float f4 = getfloat(p, n, buf);;
                p[n1].price = f4;
                FILE* f;
                f = fopen("trains.bin", "r+b");
                if(f)
                {                
                    int poswrite = (n1) * sizeof(trains) + offset_price;
                    fseek(f, poswrite, SEEK_SET );
                    fwrite(((char *)(p+n1))+offset_price, sizeof(float) , 1, f);
                    fclose(f);
                } 
        }
        if(n2 == 5)
        {
                float f5 = getfloat(p, n, buf);
                p[n1].racetime = f5;
                p[n1].midspeed = p[n1].length.b / p[n1].racetime;
                FILE* f;
                f = fopen("trains.bin", "r+b");
                if(f)
                {                
                    int poswrite = (n1) * sizeof(trains) + offset_time;
                    int poswritepeed = (n1) * sizeof(trains) + offset_speed;
                    fseek(f, poswrite, SEEK_SET );
                    fwrite(((char *)(p+n1))+offset_time, sizeof(float), 1, f);
                    fseek(f, poswritepeed, SEEK_SET );
                    fwrite(((char *)(p+n1))+offset_speed, sizeof(float), 1, f);
                    fclose(f);
                } 
        }
        if(n2 == 6)
        {
                float f6 = getfloat(p, n, buf);
                p[n1].length.b= f6;
                p[n1].midspeed = p[n1].length.b / p[n1].racetime; 
                FILE* f;
                f = fopen("trains.bin", "r+b");
                if(f)
                {                
                    int poswrite = (n1) * sizeof(trains) + offset_length;
                    int poswritepeed = (n1) * sizeof(trains) + offset_speed;
                    fseek(f, poswrite, SEEK_SET );
                    fwrite(((char *)(p+n1))+offset_length, sizeof(float), 1, f);
                    fseek(f, poswritepeed, SEEK_SET );
                    fwrite(((char *)(p+n1))+offset_speed, sizeof(float), 1, f);
                    fclose(f);
                } 
        }
        

        system("clear");
        strmenu(p, n, buf);
    }