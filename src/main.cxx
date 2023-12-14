#include "array-list.cxx"
#include <iostream>

int main()
{
    try 
    {
        list::List<int> stack{};
        for (int i=1; i<=1000; ++i)
            stack.push(i);

        auto N = stack.size();
        for (size_t i{}; i<N; ++i)
            std::cout << stack.pop() << ' ';
        std::cout << std::endl;

    } 
    catch (std::exception& e) 
    {
        std::cerr << "List Error: " << e.what() << " occured!\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}