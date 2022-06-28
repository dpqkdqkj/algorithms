#include <cstdio>
#include "DualArrayDeque.hpp"

void print_dad(myds::DualArrayDeque<int>& dad);
void print_dad(myds::DualArrayDeque<char>& dad);

int main (int argc, char *argv[])
{
    myds::DualArrayDeque<char> dad;
    dad.add(0, 'a');
    dad.add(1, 'b');
    dad.add(2, 'c');
    dad.add(3, 'd');

    print_dad(dad);

    dad.remove(0);
    dad.remove(0);

    print_dad(dad);

    return 0;
}


void print_dad(myds::DualArrayDeque<int>& dad)
{
    for (size_t i = 0; i < dad.size(); ++i)
        printf("%d ", dad.get(i));
    printf("\n");
}

void print_dad(myds::DualArrayDeque<char>& dad)
{
    for (size_t i = 0; i < dad.size(); ++i)
        printf("%c ", dad.get(i));
    printf("\n");
}

