#include "header.h"

int getValue()  //ввод для  главного  меню 
{
    while (true) 
    {
        int a;
        std::cin >> a;
 

        if (std::cin.fail()  || (std::cin.peek() != '\n'))
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n'); 
            std::cout << "Неопознанная команда. Введите повторно: ";
        }
        else if (a == 1) {
            return a; 
        }
        else if (a == 2) {
            return a; 
        }
        else if (a == 0) {
            return a; 
        }
        else if (a == 3) {
            return a; 
        }
        else
        {  
            std::cin.clear(); 
            std::cin.ignore(32767,'\n'); 
            std::cout << "Неопознанная команда. Введите повторно: ";
        }
}
}
float getfloat(trains *p, int n, trains buf) //ввод  вещественного положительного числа
{
       std::cout << "Введите необходимую величину: ";
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
                float j1 = std::atof(input_str);
                return j1;
}
int getmenuValue()  //для управлени в меню структур
{
    while (true) 
    {
        int a;
        std::cin >> a;
 

        if (std::cin.fail()  || (std::cin.peek() != '\n'))
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n'); 
            std::cout << "Неопознанная команда. Введите повторно: ";
        }
        else if (a == 1) {
            return a; 
        }
        else if (a == 2) {
            return a; 
        }
        else if (a == 0) {
            return a; 
        }
        else if (a == 3) {
            return a; 
        }
        else if (a == 4) {
            return a; 
        }
        else if (a == 5) {
            return a; 
        }
        else if (a == 6) {
            return a; 
        }
        else if (a == 7) {
            return a; 
        }
        else if (a == 8) {
            return a; 
        }
        else if (a == 9) {
            return a; 
        }
        else
        {  
            std::cin.clear(); 
            std::cin.ignore(32767,'\n'); 
            std::cout << "Неопознанная команда. Введите повторно: ";
        }
}
}
int getinteger() //целое положительное число
{
    while (true) 
    {
        int a;
        std::cin >> a;
 

        if (std::cin.fail()  || (std::cin.peek() != '\n') || a < 0)
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n'); 
            std::cout << "Неопознанная команда. Введите повторно: ";
        }
        else
        return a;
}
}
int nullone() //только  0 и 1
{
    while (true) 
    {
        int a;
        std::cin >> a;
 

        if (std::cin.fail()  || (std::cin.peek() != '\n'))
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n'); 
            std::cout << "Неопознанная команда. Введите повторно: ";
        }
        else if (a == 1) {
            return a; 
        }
        
        else if (a == 0) {
            return a; 
        }
        else
        {  
            std::cin.clear(); 
            std::cin.ignore(32767,'\n'); 
            std::cout << "Неопознанная команда. Введите повторно: ";
        }
}
}