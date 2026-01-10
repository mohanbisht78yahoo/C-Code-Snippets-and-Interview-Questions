#include <stdio.h>
#include <stdlib.h>


/* Using a single pointer and a 1D array with pointer arithmetic: 
A simple way is to allocate a memory block of size r*c and access its elements using simple pointer arithmetic. 
*/
int main(void)
{
    int r = 3, c = 4;

    int* ptr = malloc((r * c) * sizeof(int));

    /* Putting 1 to 12 in the 1D array in a sequence */
    for (int i = 0; i < r * c; i++)
        ptr[i] = i + 1;

    /* Accessing the array values as if it was a 2D array */
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%d ", ptr[i * c + j]);
        printf("\n");
    }

    free(ptr);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>


/* Using double pointer  - pointer to a pointer 
We can create an array of pointers also dynamically using a double pointer.
Once we have an array pointers allocated dynamically, we can dynamically allocate memory and for every row like method 2. 
*/
int main()
{
    int r = 3, c = 4, i, j, count;

    int** arr = (int**)malloc(r * sizeof(int*));
    for (i = 0; i < r; i++)
        arr[i] = (int*)malloc(c * sizeof(int));

    // Note that arr[i][j] is same as *(*(arr+i)+j)
    count = 0;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            arr[i][j] = ++count; // OR *(*(arr+i)+j) = ++count

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            printf("%d ", arr[i][j]);

    /* Code for further processing and free the
       dynamically allocated memory */

    for (int i = 0; i < r; i++)
        free(arr[i]);

    free(arr);

    return 0;
}
