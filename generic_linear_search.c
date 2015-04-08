#include <stdio.h>
#include <stdlib.h>


int genericLinearSearch(void *array, size_t elemSize, int lenArray, void *key, int (*cmp)(void *a, void *b))
{

    for(int i = 0; i < lenArray; i++)
    {
        void *currentElem = array + (elemSize * i);
        if (cmp(currentElem, key) == 0)
            return i;
    }
    return -1;

}

typedef struct
{
    int num, den;

} fraction;

int fractionCompare(fraction *f1, fraction *f2)
{
    float f1Val = (float)f1->num/(float)f1->den;
    float f2Val = (float)f2->num/(float)f2->den;

    if(f1Val == f2Val)
        return 0;
    else
        return -1;
}

int main()
{
    fraction fractions[5] = { (1,4), (3,5), (6,9), (2,5), (1,2)};

    fraction *key = (12,18);

    int arrayLength = sizeof(fractions)/sizeof(fraction);

    int indexOfKey = genericLinearSearch(fractions, sizeof(fraction), arrayLength, &key, fractionCompare);

    printf("%i\n", indexOfKey);

    return 0;
}