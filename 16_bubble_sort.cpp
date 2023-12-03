#include <iostream>
using namespace std;

void insert_element(int *a, int s)
{

    cout << "INSERT ELEMENTS OF THE ARRAY" << endl;
    for (int i = 0; i < s; i++)
    {
        cin >> a[i];
    }
}

void bubble_sort(int *a, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void display_array(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " " << endl;
    }
}
int main()
{
    int size;
    int *arr;

    cout << "Enter array size :" << endl;
    cin >> size;

    arr = new int[size];

    insert_element(arr, size);

    cout << "BEFORE SORTING" << endl;
    display_array(arr, size);

    bubble_sort(arr, size);

    cout << "AFTER SORTING" << endl;
    display_array(arr, size);

    delete arr;
}