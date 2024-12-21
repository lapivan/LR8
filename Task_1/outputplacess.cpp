#include "header.h"

void outputplases(trains *p, int n, trains buf)
{
    std::cin.clear();
    bool  out = 0; //для выхода из цикла
    while(!out)
    {
        std::cin.clear();
        system("clear");
        std::cout << "Введите необходимый пункт отправления для поезда: " <<std::endl;
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
        bool nothing = 0;
        for(int i = 0; i <  n; i++)
        {
            if (strcmp(p[i].arrivepoint, check_str) == 0)
            {
                if (p[i].numplaces == -1) //по умолчанию -1, поэтому если не заполнено, там  -1 
                {
                    std::cout << "Данные отсутствуют " << std::endl;
                    nothing = 1;
                }
                else
                {
                    std::cout << "Поезд " << i+1 << " : Количество мест - " << p[i].numplaces << std::endl;
                    nothing = 1;
                }
            }
            if(i == n-1 && nothing == 0)
            {
                std::cout << "Ничего не найдено " << std::endl;
            }
        }
        std::cout << "Введите 1 для повторного поиска: " << std::endl  << "Введите 0 для возврата в меню: " << std::endl;
        int n1 = getmenuValue();
        if(n1 == 0)
        {
            strmenu(p, n, buf);
        }
        std::cin.ignore(32767,'\n');
    }
}