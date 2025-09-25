/*
PAIR SUM
• Description:
  Given a sequence of positive integer numbers a1...an and a query integer x,
  calculate the number of pairs (ai, aj) where ai + aj <= x.
• Input:
  - Line 1: Contains n (number of elements)
  - Line 2: Contains n positive integers a1...an
  - Line 3: Contains q (number of queries)
  - Next q lines: Each contains a query integer x
• Output:
  - q lines, each containing the number of pairs satisfying the corresponding query
• Example:
  Input:
    5
    5 10 2 7 9
    2
    15
    13
  Output:
    7
    5
*/
#include<stdio.h>
#include<stdlib.h>

int compare2integer(const void *elementA, const void *elementB) {
    int valueA = *(const int*)elementA;
    int valueB = *(const int*)elementB;
    return valueA - valueB;
}
long long countpair(int sortedArray[], int NumberOfElement, int limitX) {
    long long paircount = 0;
    int leftIndex = 0;
    int rightIndex = NumberOfElement - 1;
    for(int i = 0; i < NumberOfElement; i ++) {
        if(sortedArray[leftIndex] + sortedArray[rightIndex] <= limitX) {
            paircount += (rightIndex - leftIndex);
            leftIndex ++;
        } else {
            rightIndex --;
        }
    }
    return paircount;
}
int main() {
    int NumberOfElement;
    scanf("%d", &NumberOfElement);

    int ArrayOfElement[NumberOfElement];
    for(int i = 0; i < NumberOfElement; i ++) {
        scanf("%d", &ArrayOfElement[i]);
    }

    qsort(ArrayOfElement, NumberOfElement, sizeof(int), compare2integer);


    int numberofquery;
    scanf("%d", &numberofquery);

    long long result[numberofquery];

    for(int i = 0; i < numberofquery; i ++) {
        int limitX;
        scanf("%d", &limitX);
        
        result[i] = countpair(ArrayOfElement, NumberOfElement, limitX);
    }
    for(int i = 0; i < numberofquery; i ++) {
        printf("%lld\n", result[i]);
    }
    return 0;
}