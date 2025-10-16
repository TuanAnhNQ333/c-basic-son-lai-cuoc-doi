#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef char STRING[1000000];
const long long M = 1000000007;
STRING inp = { 0 };
int main()
{
    scanf("%s", inp);
    while (0 == 0)
    {
        char* op = strstr(inp, "*");
        if (op != NULL)
        {
            char* left = op - 1;
            while (left >= inp && isdigit(*left))
            {
                left -= 1;
            }
            left += 1;
            char* right = op + 1;
            while (right < inp + strlen(inp) && isdigit(*right))
            {
                right += 1;
            }
            right -= 1;
            if (!isdigit(*left) || !isdigit(*right))
            {
                printf("NOT_CORRECT");
                return 0;
            }else
            {
                long long lv = 0; // left value
                int i = 0;
                while (isdigit(left[i]))
                {
                    lv = lv * 10 + (left[i] - '0');
                    i++;
                }
                long long rv = 0;
                char* tmp = op + 1;
                while (tmp < inp + strlen(inp) && isdigit(*tmp))
                {
                    rv = rv * 10 + (tmp[0] - '0');
                    tmp++;
                }
                long long kq = (lv * rv) % M;
                STRING tmpStr = { 0 };
                memcpy(tmpStr, inp, left - inp);
                sprintf(tmpStr + strlen(tmpStr), "%lld", kq);
                if (right < inp + strlen(inp))
                {
                    strcpy(tmpStr + strlen(tmpStr), right + 1);
                }
                strcpy(inp, tmpStr);
            }
        }else
        {
            op = strstr(inp, "+");
            if (op != NULL)
            {
                char* left = op - 1;
                while (left >= inp && isdigit(*left))
                {
                    left -= 1;
                }
                left += 1;
                char* right = op + 1;
                while (right < inp + strlen(inp) && isdigit(*right))
                {
                    right += 1;
                }
                right -= 1;
                if (!isdigit(*left) || !isdigit(*right))
                {
                    printf("NOT_CORRECT");
                    return 0;
                }else
                {
                    long long lv = 0;
                    int i = 0;
                    while (isdigit(left[i]))
                    {
                        lv = lv * 10 + (left[i] - '0');
                        i++;
                    }
                    long long rv = 0;
                    char* tmp = op + 1;
                    while (tmp < inp + strlen(inp) && isdigit(*tmp))
                    {
                        rv = rv * 10 + (tmp[0] - '0');
                        tmp++;
                    }
                    long long kq = (lv + rv) % M;
                    STRING tmpStr = { 0 };
                    memcpy(tmpStr, inp, left - inp);
                    sprintf(tmpStr + strlen(tmpStr), "%lld", kq);
                    if (right < inp + strlen(inp))
                    {
                        strcpy(tmpStr + strlen(tmpStr), right + 1);
                    }
                    strcpy(inp, tmpStr);
                }
            }else
            {
                long long x = 0;
                for (int i = 0;i < strlen(inp);i++)
                {
                    x = x * 10 + (inp[i] - '0');
                }
                printf("%lld", x % M);
                return 0;
            }
        }
    }
}