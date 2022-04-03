#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double epsilon = 0.0000001;


typedef struct matrix
{
    double **body;
    int dim;

} matrix_t;



void print_matrix(matrix_t A)
{
    int i, j;

    for (i = 0; i < A.dim; i++)
    {
        printf("|| ");

        for (j = 0; j < A.dim; j++)
            printf("%6.2lf ", A.body[i][j]);

        printf("||\n");
    }

    printf("\n");
}

matrix_t init_matrix(int n)
{

    matrix_t A;
    int i;

    A.dim = n;

    A.body = calloc(n, sizeof(double *));

    for (i = 0; i < n; i++)
    {
        A.body[i] = calloc(n, sizeof(double));
    }

    return A;
}

void delete_matrix(matrix_t A)
{

    int i;

    for (i = 0; i < A.dim; i++)
        free(A.body[i]);

    free(A.body);
}

matrix_t input_matrix()
{

    matrix_t A;
    int n, i, j;

    scanf("%d", &n);

    A = init_matrix(n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%lf", &A.body[i][j]);

    return A;
}

void swap_elem(double *arr, int e1, int e2)
{
    double temp;

    temp = arr[e1];
    arr[e1] = arr[e2];
    arr[e2] = temp;
}

void swap_lines(matrix_t A, int l1, int l2)
{
    double *temp;

    temp = A.body[l1];
    A.body[l1] = A.body[l2];
    A.body[l2] = temp;
}

void swap_collumnes(matrix_t A, int c1, int c2)
{
    int n, i;

    n = A.dim;

    for (i = 0; i < n; i++)
        swap_elem(A.body[i], c1, c2);
}

void eliminate(matrix_t A, int curr)
{
    int i;

    int *temp;

    for (i = curr + 1; i < A.dim; i++)
    {
        int j;
        double k;

        k = -A.body[i][curr] / A.body[curr][curr];

        for (j = curr; j < A.dim; j++)
            A.body[i][j] = A.body[i][j] + k * A.body[curr][j];
    }
}

void max_submatrix_element(matrix_t A, int curr, double *max, int *line, int *col)
{

    int i, j;

    *max = 0;

    for (i = curr; i < A.dim; i++)
        for (j = curr; j < A.dim; j++)
            if (fabs(A.body[i][j]) > fabs(*max))
            {
                
                *max = A.body[i][j];
                *line = i;
                *col = j;
                
            }
}

double det(matrix_t A)
{

    int i, j, sign;
    double determinant;
    sign = 0;
    for (i = 0; i < A.dim - 1; i++)
    {
        int line, col;
        double pivot;
        line = 0;
        col = 0;
        pivot = 0;
        max_submatrix_element(A, i, &pivot, &line, &col);
        if (pivot == 0){
            //printf("pivot = %lf line = %d col = %d\n", pivot, line, col);
            return 0;
        }
        swap_lines(A, i, line);
        if (i != line)
            sign++;
        swap_collumnes(A, i, col);
        if (i != col)
            sign++;

        
        //print_matrix(A);
        eliminate(A, i);

        //print_matrix(A);
    }

    determinant = A.body[0][0];
    //printf("%lf\n", determinant);
    for (i = 1; i < A.dim; i++)
    {

        determinant = determinant * A.body[i][i];
        //printf("%lf\n", determinant);
    }


    return(sign % 2)? -determinant : determinant;
}

int main()
{
    matrix_t A;

    A = input_matrix();
    //print_matrix(A);
    printf("%.0lf\n", det(A));
}