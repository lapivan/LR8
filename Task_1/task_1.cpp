#include "header.h"

    trains *generatemass(int n) //создание массива структур с введенным размером
    {
        trains *p = (trains*)malloc(n * sizeof(trains));
        return p;
    }


   

    void showdata(trains *p, int n, trains buf) //функция выводит на экран заполненную информацию.если  ничего в какое-либо  поле не введено - сообщение  об отсутствии данных
    {
        system("clear");
        for(int i = 0; i < n; i++)
        {
            std::cout << "Поезд " << i+1 << ": " << std::endl;
            std::cout << "Пункт отправления: ";
            if (strcmp(p[i].arrivepoint, "") == 0) //строка сравнивается с 0. если 0 - туда ничего не записали. аналогично для  всех полей структуры
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
    void deletemasstruct(trains *p) //для удаленияя массиваструктур по окончании работы
    {
        free(p);
    }
    
    void strmenu(trains* p, int n, trains buf) //основное меню в котором реализованосновне функции
    {
        system("clear");
        int n1 = 0;
        std::cout << "Нажмите 1, чтобы увидеть введенную информацию: " << std::endl << "Нажмите 2, чтобы заполнить информацию: " << std::endl << "Нажмите 3, чтобы добавить еще поезд: " << std::endl << "Нажмите 4, чтобы удалить какую-либо структуру: " << std::endl << "Нажмите 5, чтобы изменить какой-либо признак одного из элементов: " << std::endl << "Нажмите 6, чтобы найти и вывести структуру по  указанному признаку: "<< std::endl << "Нажмите 7, чтобы отсортировать структуры по числу мест: "  <<  std::endl<< "Нажмите 8, чтобы добавить особй признак: " << std::endl << "Нажмите 9, чтобы вывести информацию о числе свободных мест в поездах, следующих до заданного пункта назначения: " << std::endl << "Нажмите 0, чтобы вернутьсяя в меню: ";
        n1 = getmenuValue();
        bool check = 0;
        while(check == 0) 
        {   
        if (n1 == 1) {
            system("clear");
            showdata(p, n, buf);
            check = 1;
        }
        else if(n1 == 0) 
        {
            system("clear");
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            deletemasstruct(p);
            menu();
            check = 1;
        }
        else if(n1 == 2)  
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            inputdata(p,n, buf);
            check = 1;
        }
        else if(n1 == 3)  
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            addnewelem(p,n,buf);
            check = 1;
        }
        else if(n1 == 4)  
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            system("clear");
            std::cout << "Введите номер поезда, который хотите удалить: ";
            int j = getinteger();
            deleteline(p, n, j, buf);
            check = 1;
        }
        else if(n1 == 5)  
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            change(p, n, buf);
            check = 1;
        }
        else if(n1 == 6)  
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            search(p, n, buf);
            check = 1;
        }
        else if(n1 == 7)  
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            insertsort(p, n, buf);
            check = 1;
        }
        else if(n1 == 8)  
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            buf = stopinput(p, n, buf);
            strmenu(p, n, buf);
            check = 1;
        }
        else if(n1 == 9)  
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            outputplases(p, n, buf);
            
            check = 1;
        }
            

        else 
        { 
            std::cout << "Введите повторно: ";
            n1 = getValue();
        }
    }
        
    }
    void mainprogramm()
    {
    system("clear");
    trains *p =  NULL;
    int n = 0;
    trains buf;
    FILE* f;
    int filetrains = 0;

    f = fopen("trains.bin", "rb"); //открывает файл
    if(f == NULL)
    {
        //такого файла не существует
    }
    else
    {
        //файл существует
        std::cout << "Восстановить данные из файла? 0 - нет 1 - да";
        int n1 = nullone();
        if(n1 == 0) //для того чтобы очистить файл
        {
            fclose(f);
            f = fopen("trains.bin", "wb");
            fclose(f);
        }
        else
        {
            //получим размер файла и определим число структур в нем и прочитаем наши элементы
            long fsize;
            fseek(f,0L,SEEK_END); // Установить позицию на конец файла
            fsize = ftell(f);  //размер файла
            int numstruct = fsize / sizeof(trains);
            //сместимся в начало файла
            fseek(f,0L,SEEK_SET);
            n = numstruct;
            p = generatemass(n);
            filetrains = n;
            // for(int i = 0; i < numstruct;i++)
            // {

            // }
            long numread; //суммарнй размер массива
            numread = fread( p, sizeof( trains ), n, f );
            fclose(f);

        }
    }
    if(filetrains ==  0)
    {
        std::cout << "Введите начальное количество поездов: " << std::endl;
        n = getinteger();
        p = generatemass(n);
        for(int i= 0; i<n; i++) //заполнение массива
        {
            p[i].length.b = -1;
            p[i].midspeed = -1;
            p[i].numplaces = -1;
            p[i].price = -1;
            p[i].racetime = -1;
            p[i].midspeed = -1;
            memset(p[i].arrivepoint, 0, sizeof(p[i].arrivepoint));
            memset(p[i].timeotpr, 0, sizeof(p[i].timeotpr));
        }
    }
        
    std::cin.clear();
    std::cin.ignore(32767,'\n');
    strmenu(p, n, buf);
    //inputdata(p, n);
    }


int main() {
    menu();
    return 0;
}