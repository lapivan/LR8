//#include <stdio.h>
//#include <stdlib.h>
#include <unistd.h>
//#include <sys/types.h>


#include "header.h"
extern void mainprogramm();
 void addnewelem(trains* p, int&n, trains buf) //добавление элементав массив  структур
    {
        if(n == 0)
        {
            std::cout << "В настощий момент поезда отсутствуют. " << std::endl;
            mainprogramm();
        }
        n++;
        p= (trains *)realloc(p, n * sizeof(trains)); //увеличиваем на 1 размер массива
        for(int i= n-1; i<n; i++)
        {
            p[i].length.b = -1;
            p[i].midspeed = -1;
            p[i].numplaces = -1;
            p[i].price = -1;
            p[i].racetime = -1;
            memset(p[i].arrivepoint, 0, sizeof(p[i].arrivepoint));
            memset(p[i].timeotpr, 0, sizeof(p[i].timeotpr));
        } 
        std::cout << "Введите данные для нового поезда: " << std::endl;
        inputdata(p, n, buf);
    }
    void deleteline(trains* p, int &n, int j, trains buf)
    {
        bool morethh = 0;
        while(!morethh)
        {
            if(j > n)
            {
                std::cout << "Ошибка ввода, нет такого поезда. Попробуйте еще: " << std::endl;
                j = getinteger();
            }
            else
            {
                morethh = 1;
            }
        }
        system("clear");
        FILE* f;
        f = fopen("trains.bin", "r+b");
        int ikeep=j-1;
        for(int i = j-1; i + 1 < n; i++)
        {
            p[i].length = p[i+1].length;
            p[i].midspeed = p[i+1].midspeed;
            p[i].numplaces = p[i+1].numplaces;
            p[i].price = p[i+1].price;
            p[i].racetime = p[i+1].racetime;
            p[i].midspeed = p[i+1].midspeed;
            strcpy(p[i].arrivepoint, p[i + 1].arrivepoint);
            strcpy(p[i].timeotpr, p[i + 1].timeotpr);
            if(f && (i+1 < n))
            {
                trains tmpread; //буферный обьект типа поезда
                int posread = (i+1) * sizeof(trains); //позиция скоторой  считываем
                int poswrite = (i) * sizeof(trains); //куда записваем то что считали
                fseek(f, posread, SEEK_SET ); //сдвиг
                fread(&tmpread, sizeof( trains ), 1, f); //считка
                fseek(f, poswrite, SEEK_SET ); //сдвиг куда пишем
                fwrite(&tmpread, sizeof( trains ), 1, f);  //пишем
                
            }
            ikeep = i;
        }
            long fsize;
            fseek(f,0L,SEEK_END); // Установить позицию на конец файла
            fsize = ftell(f);  //размер файла
            if(j == n)
            {
                int numstruct = (n-1) * sizeof(trains); //нова структура размер
                if(numstruct >= 0)
                {
                    ftruncate(fileno(f),   numstruct ); //изменение размера аналогия реаллок
                }
            }
            else
            {
                int numstruct = fsize - sizeof(trains); //нова структура размер
                if(numstruct >= 0)
                {
                    ftruncate(fileno(f),   numstruct ); //изменение размера аналогия реаллок
                }
            }
            
            fclose(f);
        
        if(f && (ikeep > n))
        {
            long fsize;
            fseek(f,0L,SEEK_END); // Установить позицию на конец файла
            fsize = ftell(f);  //размер файла
            int numstruct = fsize - sizeof(trains);
            if(numstruct >= 0)
            {
                ftruncate(fileno(f),   numstruct );
            }
            fclose(f);

        }
        n--;
        p= (trains *)realloc(p, n * sizeof(trains));
        strmenu(p, n, buf);
    }