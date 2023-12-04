#include <iostream>
using namespace std;

void display_array(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " " << endl;
    }
}
void insert_element(int *a, int s)
{

    cout << "INSERT ELEMENTS OF THE ARRAY" << endl;
    for (int i = 0; i < s; i++)
    {
        cin >> a[i];
    }
}
//  23  45 2 7 435 43
void insertion_sort(int *a , int s)
{
    // int j = 0 , i = j + 1 ; 
    
    for(int i = 1; i < s ; i++)
    {
        int current = a[i];
        int j = i - 1 ;
        while(j >=  0 && current < a[j])
        {
            int temp;
            a[j + 1] = a[j] ;
            j--;    
        }
        a[j + 1]  = current; 


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

    insertion_sort(arr, size);

    cout << "AFTER SORTING" << endl;
    display_array(arr, size);

    delete arr;
}