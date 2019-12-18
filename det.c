/* Find the determinant of square matrix
*  of max size 10
*/
#include <stdio.h>
#include <math.h>
#define MAX 10

void enter (float arr[][MAX], int size){
    for (int j = 0; j < size; j++)
    {
        printf("Enter %d row\n", j);

        for (int i = 0; i < size; i++)
        {
            scanf("%f", &arr[i][j]);
        }
    }
}
float determinant (float arr[][MAX],int size){
    float det=0;
    if(size==1)
    {
        det = arr[0][0];
    }
    else
    {
        //co-factor expansion along first row
        for (int i = 0; i < size; i++)
        {
            float small[size-1][size-1];
            //initialise minor matrix
            //n:column
            for (int n = 0; n < size-1; n++)
            {
                int r=0;
                //m:row
                for (int m = 0; m < size-1; m++)
                {   
                    //if same col as index jump to the next
                    if(m==i)
                    {
                        r+=1;
                    } 
                small[m][n]=arr[r][n+1];
                r++;
                }
            }
            //find determinant recursively
            det+=(pow(-1,i))*(arr[i][0])*(determinant(small,size-1));
        }
    }
    return det;
}
int main (void){
    int size;
    float det;
    float matrix[MAX][MAX];
    printf("Enter size of matrix:");
    scanf("%d", &size);
    enter(matrix, size);
    det=determinant(matrix,size);
    printf("Det:%.2f\n", det);
    return 0;
}
