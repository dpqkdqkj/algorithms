#include "Array.hpp"
#include "ArrayStack.hpp"
#include "FastArrayStack.hpp"
#include "ArrayQueue.hpp"
#include "ArrayDeque.hpp"

#include <iostream>

using namespace myds;

class Test {
    int *ptr;
    
public:
    Test() { 
        std::cout << "created " << "\n"; 
        //ptr = new int[64];
        ptr = nullptr;
    }
    ~Test() { 
        std::cout << "deleted " << "\n";
        if (ptr != nullptr)
            delete [] ptr;
    }
};

int main()
{
    ArrayDeque<char> myDeque;
    myDeque.add(0, 'a');
    myDeque.add(1, 'b');
    myDeque.add(2, 'c');
    myDeque.add(3, 'd');
    myDeque.add(4, 'e');
    myDeque.add(5, 'f');
    myDeque.add(6, 'g');
    myDeque.add(7, 'h');
    std::cout << myDeque.get_first_idx() << "\n";
    //myDeque.add(5, 'x');
    //myDeque.add(0, 'y');
    myDeque.remove(2);
    std::cout << myDeque.get_first_idx() << "\n";
    myDeque.add(4, 'x');
    std::cout << myDeque.get_first_idx() << "\n";
    myDeque.add(3, 'y');
    std::cout << myDeque.get_first_idx() << "\n";
    myDeque.add(3, 'z');
    std::cout << myDeque.get_first_idx() << "\n";

    for (size_t i = 0; i < myDeque.array_size(); ++i)
    {
        std::cout << myDeque.array[i] << " ";
    }
    std::cout << "\n";
    for (size_t i = 0; i < myDeque.array_size(); ++i)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 1;


    {
    Test checkdestroy;
    }

    Array<char> charA(8, 'a');

    charA[0] = 'H';
    charA[1] = 'e';
    charA[2] = 'l';
    charA[3] = 'l';
    charA[4] = 'o';


    for (size_t i = 0; i < charA.size(); ++i)
    {
        std::cout << charA[i];
    }
    std::cout << "\n";
    std::cout << *(charA + 2);
    std::cout << "\n";


    /*
    myds::Array<int> test_array2;
    myds::Array<int> test_array(4);
    test_array[0] = 3;
    std::cout << test_array[0] << "\n";


    myds::Array<int> test_equal(3, 23);
    std::cout << test_equal[1] << "\n";
    test_array = test_equal;

    std::cout << test_array[0] << "\n";
    std::cout << test_equal[1] << "\n";
    std::cout << test_equal.length << "\n";

    myds::Array<int> test_3(test_equal);
    std::cout << test_3.length << "\n";
    std::cout << test_3[2] << "\n";
    */

    //myds::ArrayStack<char> t_as_1(4);
    FastArrayStack<char> t_as_1;
    t_as_1.add('b');
    t_as_1.add('r');
    t_as_1.add('e');
    t_as_1.add('d');
    t_as_1.add(2, 'e');
    t_as_1.add(5, 'r');
    t_as_1.add(5, 'e');
    t_as_1.remove(4);
    t_as_1.remove(4);
    t_as_1.remove(4);
    t_as_1.set(2, 'i');

    for (size_t i = 0; i < t_as_1.size(); ++i)
    {
        std::cout << t_as_1.get(i) << " ";
    }
    std::cout << "\n";

    return 0;

}

