// Delete an element at a given index (BASIC deletion)

#include <iostream>
using namespace std;

template <class T>
class Array
{
    private:
        int size;
        T *array;

    public:
        Array(){};
        Array(int s)
        {
            size = s;
            array = new T[size];

        }

        // template <class T>;
        void initialize_array(int s)
        {
            if (s > size)
            {
                cout<< "Can't initialise beyond the array size. Initialising first "<< s << " elements of the array"<<endl;
            }
            else if (s < size)
            {
                cout<< "Initialising first "<< s << " elements of the array"<<endl;
            }
            else 
            {
                cout<< "Initialising all the elements in the array "<<endl;
            }
            for(int i = 0 ; i < s ; i++)
            {
                cin >> array[i];
                 
            }

        }

        void delete_by_index(int index)
        {
            for (int i = index ; i <= size - index ; i++)
            {
                array[i] = array[i + 1];
            }

            //size -= 1;
        }
        T get(int i) //gets ith element from the array
        {
            return array[i];
        }

         // Destructor 
         ~Array()
        {
            delete[] array; // Release the memory when the object is destroyed
        }
    

    
};


int main()
{
    Array<int > a1(8);
    a1.initialize_array(4);
    cout<< "printing ...." << endl;
    for( int i =0 ; i < 4 ; i++)
    {
        cout<< "The element "<< i + 1 << " is "<< a1.get(i) <<endl;
    }
    a1.delete_by_index(1);
   cout<< "printing after deletion...." << endl;
    for( int i =0 ; i < 4 ; i++)
    {
        cout<< "The element "<< i + 1 << " is "<< a1.get(i) <<endl;
    }   
    getchar();
    return 0;
}



