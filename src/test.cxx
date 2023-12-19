#include "array-list.cxx"
#include <iostream>

int main()
{
    try 
    {
        list::List<int> stack{1, 2, 3, 4, 5, 6};
        int N{ 15 };
        // for (int i=1; i<=N; ++i)
        //     stack.push(i);
        for (int i=7; i<=N; ++i)
            stack.add(i, i-1);
        for (auto it: stack)
            std::cout << it << " ";
        std::cout << std::endl;

    }
    catch (std::exception &e) 
    {
        std::cerr << "List Error: " << e.what() << " occured!\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}