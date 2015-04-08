#include <stdio.h>
#include <stdlib.h>

// This generic linear search algorithms can search an array of with elements of any 
// type.  It takes an array pointer, size of the elements, lenght of the array, the 
// key, and a comparison function supplied by the user.  
int genericLinearSearch(void *array, 
                        size_t elemSize, 
                        int lenArray, 
                        void *key, 
                        int (*cmp)(void *a, void *b))
{

    for(int i = 0; i < lenArray; i++)
    {
        // calculates location of current element
        void *currentElem = array + (elemSize * i);
        //compares current element and key using fractionCompare function
        if (cmp(currentElem, key) == 0)
            return i;
    }
    return -1;

}

//create fraction struct
typedef struct
{
    int num, den;

} fraction;

// to compare fraction values, regardless of numerator and denominator sizes
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

    //calculates length of array fractions.
    int arrayLength = sizeof(fractions)/sizeof(fraction);

    int indexOfKey = genericLinearSearch(fractions, sizeof(fraction), arrayLength, &key, fractionCompare);

    //prints index of key to screen.  If key is not found, -1 will be printed to screen.  
    printf("%i\n", indexOfKey);

    return 0;
}