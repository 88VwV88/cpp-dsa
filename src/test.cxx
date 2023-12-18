#include "array-list.cxx"
#include <iostream>

int main()
{
    try 
    {
        list::List<int> stack{};
        int N{ 15 };
        for (int i=1; i<=N; ++i)
            stack.push(i);
        for (int i=0; i<=N; ++i)
            stack.append(i);

        for (int i{}; i<N*2; ++i)
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