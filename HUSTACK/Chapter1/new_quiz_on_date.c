#include <stdio.h>
#include <string.h>
// #include <malloc.h>
#include <ctype.h>
#include<stdlib.h>


typedef char NGAYTHANG[11];
typedef char GIO[9];
typedef char TEN[100];
typedef char CAUHOI[100];

NGAYTHANG* pDate = NULL;
int* answerCount = NULL;
int dateCount = 0;

int main()
{
    while (0 == 0)
    {
        char line[1000] =  { 0 }; 
        fgets(line, sizeof(line) - 1, stdin);
        if (strstr(line,"*") != NULL)
        {
            free(pDate);
            pDate = NULL;
            return 0;
        }else
        {
            NGAYTHANG tmp = { 0 };
            sscanf(line,"%s", tmp);
            int found = 0;
            int i = 0;
            for (i = 0;i < dateCount;i++)
            {
                if (strcmp(pDate[i], tmp) == 0)
                {
                    found = 1;
                    break;
                }
            }
            if (found == 0)
            {
                pDate = (NGAYTHANG*)realloc(pDate, (dateCount + 1) * sizeof(NGAYTHANG));
                strcpy(pDate[dateCount], tmp);
                answerCount[dateCount] = 1;
                dateCount++;
            }else
            {
                answerCount[i] += 1;
            }
        }
    }
    //SAP XEP -> IN
    for(int i = 0; i < dateCount; i ++) {
        for(int j = i + 1; j < dateCount; j ++) {
            if(strcmp(pDate[i], pDate[j]) > 0) {
                NGAYTHANG tmpDate = {0};
                strcpy(tmpDate, pDate[i]);
                strcpy(pDate[i], pDate[j]);
                strcpy(pDate[j], tmpDate);
                int tmpCount = 0;

            }
        }
    }
}