#include "header.h"
void menu();
extern void  mainprogramm();
void task() 

{
    std::cout << "                                Вариант 13 " << std::endl <<  "У администратора железнодорожных касс имеется информация о свободных местах в поездах на текущие сутки в следующем виде:" << std::endl << "Пункт назначения, время отправления, число свободных мест." << std::endl << "Вывести информацию о числе свободных мест в поездах, следующих до заданного пункта назначения" << std::endl << "Выполнил: Лапунов Иван" << std::endl << "Группа: 453501";
    std::cout << std::endl <<"Введите 0 для возврата в главное меню: ";
    int k;
    k = getValue();
    bool check = 0;
    while (check == 0) 
{
    if (k == 0)
    { 
        system("clear");
        menu();  
        check = 1;
    }
    else 
    {
        std::cout << "Введите повторно: ";
        k = getValue();
    }
    
}
}


void menu() 
{
    int n;
    std::cout << "\t\t\t\tЗадание 1" << std::endl;
    std::cout << "Нажмите 1, чтобы узнать информацию о программе" << std::endl << "Нажмите 2, чтобы запустить программу: " << std::endl << "Нажмите 3, чтобы завершить программу: ";
    n = getValue();
    bool check = 0;
    while(check == 0) {   
    if (n == 1) {
        system("clear");
        task();
        check = 1;
    }
    else if(n == 3) {
        system("clear");
        exit(0);
        check = 1;
    }
    else if(n == 2)  {
    mainprogramm();
    check = 1;
    }
    else { 
    std::cout << "Введите повторно: ";
    n = getValue();
    }
    }
}