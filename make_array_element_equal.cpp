// Given an array which contains integer values, we need to make all values of this array equal to some integer value with minimum cost where the cost of changing an array value x to y is abs(x-y). 

// Examples : 

// Input  : arr[] = [1, 100, 101]
// Output : 100
// We can change all its values to 100 with minimum cost,
// |1 - 100| + |100 - 100| + |101 - 100| = 100
// Input  : arr[] = [4, 6]
// Output : 2
// We can change all its values to 5 with minimum cost,
// |4 - 5| + |5 - 6| = 2

int minCostToMakeElementEqual(int a[], int n)
{
    int y;
    if (n % 2 == 1)
        y = a[n / 2];
 
    else
        y = (a[n / 2] + a[(n - 2) / 2]) / 2;
 
    int s = 0;
    for(int i = 0; i < n; i++)
        s += abs(a[i] - y);
         
    return s;
}