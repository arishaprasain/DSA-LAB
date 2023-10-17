// An Abstract Data Type (ADT) is a high-level description of a set of operations or behaviors that a data structure should support, without specifying how those operations are implemented.
//  In essence, it defines what a data structure should do rather than how it should do it. An ADT provides a clear and abstract interface to the user while hiding the internal details of the implementation.

#include <iostream>
using namespace std;

template <class T>
class Array
{
    private:
        int size;   //size of array
        T *array;   //'T *array' to represent a dynamic array

    public:
        Array(){};   // default constructor
        Array(int i )       //parameterised constructor for creating i size array
        {   
            size = i;
            array = new T[size];
        }

        // template <class T>;
        void initialize_array(int size)
        {
            for(int i = 0 ; i < size ; i++)
            {
                cin >> array[i];
                 
            }

        }

        T get(int i) //gets ith element from the array
        {
            return array[i];
        }

         // Destructor 
        {
            delete[] array; // Release the memory when the object is destroyed
        }
    

};


int main()
{
    Array<int > a1(2);
    a1.initialize_array(4);
    cout<< "printing ...." << endl;
    for( int i =0 ; i < 4 ; i++)
    {
        cout<< "The element"<< i + 1 << "is "<< a1.get(i) <<endl;;
    }
   
    
    getchar();
    return 0;
}