#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int ***MakeBook(int ***book, int K, int M, int N)
{
    // allocate the array
    book = new int **[K];
    // 3D with all values of 0
    for (int i = 0; i < K; i++)
    {
        book[i] = new int *[M];
        for (int j = 0; j < M; j++)
        {
            book[i][j] = new int[N];
            for (int k = 0; k < N; k++)
            {
                book[i][j][k] = 0;
            }
        }
    }
    return book;
}
// get random values
int RandomValue(int max, int min)
{
    return rand() % (max - min + 1) + min;
}
// fill all the random values into the book
void FillBookWithRandomValues(int ***book, int K, int M, int N, int max, int min)
{
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < N; k++)
            {
                book[i][j][k] = RandomValue(max, min);
            }
        }
    }
}
// display the book
void DisplayBook(int ***book, int *page, int K, int M, int N)
{
    for (int i = 0; i < K; i++)
    {
        int p = page[i];
        cout << "Page " << p << endl;
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < N; k++)
            {
                cout << book[p][j][k] << "\t";
            }
            // Go to a new line after finishing displaying words in a line
            cout << endl;
        }
        // Go to a new line after finishing displaying lines in a page
        cout << endl;
    }
}
// Display the order of pages
void DisplayPages(int *page, int K)
{
    cout << "The order of pages is: ";
    for (int i = 0; i < K; i++)
    {
        cout << page[i] << " ";
    }
    cout << endl;
}
// get the sum of each page in the book
int *GetPageSum(int ***book, int *sumOfPage, int K, int M, int N)
{
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < N; k++)
            {
                sumOfPage[i] += book[i][j][k];
            }
        }
    }
    return sumOfPage;
}
// Display sum of each page
void DisplaySumOfPages(int *sumOfPage, int *page, int K)
{
    for (int i = 0; i < K; i++)
    {
        cout << "The sum of page " << page[i] << " is: " << sumOfPage[i] << " " << endl;
    }
    cout << endl;
}
// Swap pages
void SwapPages(int *sumOfPage, int *page, int K)
{
    for (int i = 0; i < K - 1; i++)
    {
        // set the smallest value to the first index
        int smallest = i;
        for (int j = i + 1; j < K; j++)
        {
            // find the smallest index in the array
            if (sumOfPage[smallest] > sumOfPage[j])
                smallest = j;
        }
        // swap the value of current index with the value of the smallest index
        int temp = sumOfPage[i];
        sumOfPage[i] = sumOfPage[smallest];
        sumOfPage[smallest] = temp;
        // swap pages in ascending order
        int tp = page[i];
        page[i] = page[smallest];
        page[smallest] = tp;
    }
}
// delete the book
void CleanBook(int ***book, int *page, int K, int M, int N)
{
    for (int i = 0; i < K; i++)
    {
        page[i] = i;
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < N; k++)
            {
                book[i][j][k] = 0;
            }
        }
    }
}
int main()
{
    // 3D arrays of book
    //  K how many pages
    //  M how many lines in a page
    //  N how many words in a line
    srand(time(0));
    int K, M, N;
    cout << "How many pages do you want? ";
    cin >> K;
    cout << "How many lines do you want? ";
    cin >> M;
    cout << "How many words you do want? ";
    cin >> N;
    cout << endl;

    // allocate the array
    int ***book;
    book = MakeBook(book, K, M, N);
    // The max and min values of the random function
    int max = 55;
    int min = 5;
    // Create an array that contains page numbers from 0 to K
    int *page = new int[K];
    for (int i = 0; i < K; i++)
    {
        page[i] = i;
    }
    // Fill random numbers from 5 to 55 into the array
    FillBookWithRandomValues(book, K, M, N, max, min);
    // 3D array after assigning values
    DisplayBook(book, page, K, M, N);

    int *sumOfPage = new int[K];
    sumOfPage = GetPageSum(book, sumOfPage, K, M, N);

    // Display pages and sum of pages before sorting
    cout << "Before sorting: " << endl;
    DisplayPages(page, K);
    DisplaySumOfPages(sumOfPage, page, K);

    // Swap pages in ascending order based on the sum of all the integers
    SwapPages(sumOfPage, page, K);
    // Display pages and sum of the pages after sorting
    cout << "After sorting: " << endl;
    DisplayPages(page, K);
    DisplaySumOfPages(sumOfPage, page, K);

    DisplayBook(book, page, K, M, N);
    CleanBook(book, page, K, M, N);
    //DisplayBook(book, page, K, M, N);

    // deallocate the arrays
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < M; j++)
        {
            delete[] book[i][j];
            book[i][j] = nullptr;
        }
        delete[] book[i];
        book[i] = nullptr;
    }
    delete[] book;
    book = nullptr;
    delete[] sumOfPage;
    sumOfPage = nullptr;
    delete[] page;
    page = nullptr;

    return 0;
}