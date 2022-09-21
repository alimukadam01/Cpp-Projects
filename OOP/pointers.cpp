#include<iostream>
#include<conio.h>
using namespace std;

int getMax(int array[], int size)
{
    int max = array[0];

    for(int i = 1; i < size; i++)
    {
        if(array[i] > max )
        {
            max = array[i];
        }
    }
    
    return max;
}

int main()
{   
    int l1[5] = {1, 2, 3, 4, 5};

    cout << "The maximum number from the given array is: " << getMax(l1, 5) << endl;


    return 0;
}



/* NOTES

- The address of the array is the address of the first element in the array.
- Indexing in arrays is done with de-refrencing. This is done by adding addresses to the initial address at index 0
and then navigating like that.
- "&" sign is used to show the addresses of the code written alogside it.
- "*" sign is used to show the content of the code written alogside it.
- could also store values in lists using pointers.
- 
*/