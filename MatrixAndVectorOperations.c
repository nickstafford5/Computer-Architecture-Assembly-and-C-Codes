

/* 
Nicholas Stafford
V01044119 
Sun, Oct 29 2023
*/
// This program performs a variety of different matrix and vector operations with any given matrix or vector
/* All of the code is mine, but the comments describing the functions were written by my professor 
as instructions for what I should program each function to do*/ 
#include "matrix_and_vector.h"
#include <stdio.h>
#include <math.h>

/* set_vector(n, V, s)
   Given an integer n, a vector V with n elements, and a scalar s,
   copy the value of s into every element of the vector V.
   When this function completes, every element of V will equal
   the value of s.

   Parameters: n (integer), V (array of double), s (double)
   Return value: None
*/
void set_vector(int n, double V[n], double s){
    
    int i = 0;
   
    while ( i < n ){
        V[i] = s;
        i = i + 1;
    }
}

/* mul_vector_by_scalar(n, Vin, Vout, s)
   Given an integer n, an input vector Vin (with size n), an output vector
   Vout (with size n) and a scalar value s, set the vector Vout to contain
   the result of multiplying the vector Vin by the scalar s.

   Do not modify any elements of the input vector Vin.

   Parameters: n (integer), Vin (array of double), Vout (array of double), s (double)
   Return value: None
*/

void mul_vector_by_scalar(int n, double Vin[n], double Vout[n], double s){
    
    int i = 0;
    
    while ( i < n ){
        Vout[i] = Vin[i] * s;
        i = i + 1;
    }
}
    
/* dot_product(n, V1, V2)
   Given an integer n and two n-element vectors V1 and V2, compute and return
   the dot product of V1 and V2. See Section 2.1 of the specification PDF for
   more information.

   Do not modify any elements of the input vectors V1 and V2.

   Parameters: n (integer), V1 (array of double), V2 (array of double)
   Return value (double): Dot product of V1 and V2
*/
double dot_product(int n, double V1[n], double V2[n]){
    int i = 0;
    double dot_product = 0;
    
    while (i < n ){
        dot_product = dot_product + V1[i] * V2[i];
        i = i + 1;
    }
    
    return dot_product;
}

/* norm(n, V)
   Given an integer n and a vector V of size n, return the norm (length) of V.

   Recall that the length of a vector V is the square root of the dot product 
   of V with itself. See Section 2.2 of the specification PDF for more 
   information.

   Do not modify any elements of the input vector V.

   Parameters: n (integer), V (array of double)
   Return value (double): Norm (length) of the vector V
*/
double norm(int n, double V[n]){
    double norm = 0;
    double dotproduct = 0;
    
    dotproduct = dot_product(n, V, V);
    norm = sqrt(dotproduct);
    
    return norm;
}

/* angle_between_vectors(n, V1, V2)
   Given an integer n and two n-element vectors V1 and V2, compute and return
   the angle between the two vectors.

   If either (or both) of the vectors has a length of zero, return -1.

   Otherwise, return the angle between the two vectors. See Section 2.3 of the
   specification PDF for more information.

   Do not modify any elements of the input vector V.

   Parameters: n (integer), V1 (array of double), V2 (array of double)
   Return value (double): 
     - If both V1 and V2 have non-zero length: Return the angle between V1 and V2
     - Otherwise: Return -1
*/
double angle_between_vectors(int n, double V1[n], double V2[n]){
 
    double angle = 0;
    
    if ( norm(n, V1) == 0 || norm(n, V2) == 0 ){
        angle = -1;
    }
    else{
        angle = acos( dot_product(n, V1, V2) / (norm(n, V1)*norm(n, V2)));
    }
    return angle;
}

/* add_vectors(n, V1, V2, Vout)
   Given an integer n, two input vectors V1 and V2 (of size n) and an output 
   vector Vout (also of size n), compute the (elementwise) vector sum V1 + V2 
   and store the result into Vout.

   Do not modify any elements of the input vectors V1 and V2.

   Parameters: n (integer), V1 (array of double), V2 (array of double), Vout (array of double)
   Return value: None
*/
void add_vectors(int n, double V1[n], double V2[n], double Vout[n]){
    int i = 0;
    
    while ( i < n ){
        Vout[i] = V1[i] + V2[i];
        i = i + 1;
    }
}
/* identity(size, M)
   Given an integer n and an n x n output matrix M, set M to be the n x n
   identity matrix.

   Parameters: n (integer), M (2d array of double)
   Return value: None
*/
void identity(int n, double M[n][n]){
    int clm = 0;
    int row = 0;
    
    M[0][0] = 1;
    
    while ( clm < n && row < n ){
        if ( clm == row ){
            M[row][clm] = 1;
        }
        else{
            M[row][clm] = 0;
        }
        clm = clm + 1;
        if( clm == n ){
            clm = 0;
            row = row + 1;
        }
    }
    
}

/* matrices_equal(rows, cols, A, B)
   Given two input matrices A and B (both with the number of rows/columns provided),
   return 1 if they are equal and 0 otherwise.

   (As a simplification, you may assume that two matrices are equal if their elements are
    exactly the same. In practice, matrices would normally be considered equal if elements
    were within some small tolerance value to account for things like rounding errors).

   Parameters: rows (integer), cols (integer), A (2d array of double), B (2d array of double)
   Return value (integer):
     - Return 1 if the two matrices are equal (that is, if each element of A is equal to the corresponding element of B)
     - Return 0 otherwise 
*/
int matrices_equal(int rows, int cols, double A[rows][cols], double B[rows][cols]){
    
    int clm = 0;
    int row = 0;
    
    while ( clm < cols && row < rows ){
        
        if ( A[row][clm] != B[row][clm] ){
            return 0;
        }
        
        clm = clm + 1;
        if( clm == cols ){
            clm = 0;
            row = row + 1;
        }
    }
    return 1;
    
}

/* add_matrices(rows, cols, A, B, C)
   Given two input matrices A and B (both with the number of rows/columns provided),
   set C to be the elementwise sum of A and B.
   Do not modify any elements of the input matrices A and B.

   Parameters: rows (integer), cols (integer), A (2d array of double), B (2d array of double), C (2d array of double)
   Return value: None
*/
void add_matrices(int rows, int cols, double A[rows][cols], double B[rows][cols], double C[rows][cols]){
    
    int clm = 0;
    int row = 0;
    
    while ( clm < cols && row < rows ){
        
        C[row][clm] = A[row][clm] + B[row][clm];
        
        clm = clm + 1;
        if( clm == cols ){
            clm = 0;
            row = row + 1;
        }
    }
}

/* trace(n, A)
   Given an integer n and a matrix A with n rows and n columns, compute the 
   trace of A.

   The trace of a matrix is the sum of the entries along the forward diagonal.
   For example, consider the matrix
          7 -1 -2 
     A =  6 10 17
          9 20 111
   the trace of A is 7 + 10 + 111 = 128

   Parameters: n (integer), A (2d array of double)
   Return value (double): The trace of A
*/

double trace(int n, double A[n][n]){
    double trace = 0;
    int clm = 0;
    int row = 0;
    
    while ( clm < n && row < n ){
        
        if ( clm == row ){
            trace = trace + A[row][clm];
        }
        
        clm = clm + 1;
        
        if( clm == n ){
            clm = 0;
            row = row + 1;
        }
    }
    return trace;
}
/* transpose(n, k, A, T)
   Given integers n and k, along with an n x k input matrix A
   and a k x n output matrix T, set T to be the transpose of A. 

   Do not modify any elements of the input matrix A.

   Parameters: n (integer), k (integer), A (2d array of double), T (2d array of double)
   Return value: None
*/
void transpose(int n, int k, double A[n][k], double T[k][n]){
    int row = 0;
    int clm = 0;
    
    while ( clm < n && row < k ){
        
        T[row][clm] = A[clm][row];
        
        clm = clm + 1;
        
        if( clm == n ){
            clm = 0;
            row = row + 1;
        }
    } 
}

/* omit_row(n, k, A, B, omit_idx)
   Given integers n and k, along with an n x k input matrix A, an (n-1) x k
   output matrix B and an integer omit_idx, copy the elements of A into B, 
   completely omitting the row with index omit_idx (and shifting the remaining
   rows to fill in the empty space in B created by the omission).
   
   Notice that the dimensions of B has one fewer row than A, since the omitted
   row will not be present in B.

   Do not modify any elements of the input matrix A.

   You may assume that omit_idx is a valid row index. Your code will not be 
   tested on cases where omit_idx is invalid.

   Parameters: n (integer), k (integer), A (2d array of double), 
               B (2d array of double), omit_idx (integer)
   Return value: None
*/
void omit_row(int n, int k, double A[n][k], double B[n-1][k], int omit_idx){
    
    int row = 0;
    int clm = 0;
    
    while ( clm < k && row < omit_idx ){
        
        B[row][clm] = A[row][clm];
        
        clm = clm + 1;
        
        if( clm == k ){
            clm = 0;
            row = row + 1;
        }
    }
    
    while (clm < k && row < n-1 ){
        B[row][clm] = A[row + 1][clm];
        
        clm = clm + 1;
        
        if( clm == k ){
            clm = 0;
            row = row + 1;
        }
    }
    
}
/* omit_column(n, k, A, B, omit_idx)
   Given integers n and k, along with an n x k input matrix A, an n x (k-1)
   output matrix B and an integer omit_idx, copy the elements of A into B, 
   completely omitting the column with index omit_idx (and shifting the 
   remaining columns to fill in the empty space in B created by the omission).
   
   Notice that the dimensions of B has one fewer column than A, since the 
   omitted column will not be present in B.

   Do not modify any elements of the input matrix A.

   You may assume that omit_idx is a valid column index. Your code will not be 
   tested on cases where omit_idx is invalid.

   Parameters: n (integer), k (integer), A (2d array of double), 
               B (2d array of double), omit_idx (integer)
   Return value: None
*/
void omit_column(int n, int k, double A[n][k], double B[n][k-1], int omit_idx){
    int row = 0;
    int clm = 0;
    
    while ( clm < n-1 && row < k){
        
        if ( clm >= omit_idx){
        B[row][clm] = A[row][clm+1];
        }
        else{
            B[row][clm] = A[row][clm];
        }
        
        clm = clm + 1;
        
        if( clm == n - 1 ){
            clm = 0;
            row = row + 1;
        }
    }
}
