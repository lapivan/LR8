#include "header.h"
    void insertsort(trains* p, int n, trains buf) //каждый элемент вставляется в отсортированную часть массива на то место, где он должен находиться
    {
        for(int i = 1; i < n; i++)
        {
            int j = i - 1;
            trains buf;
            while(p[i].numplaces > p[j].numplaces && j>=0)
            {
                buf = p[i];
                p[i] = p[j];
                p[j] = buf;
                j--;
                i--;
                if(j < 0)
                {
                    break;
                }
            }
        }
        system("clear");
        strmenu(p, n, buf);
    }