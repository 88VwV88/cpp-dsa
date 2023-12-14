#include "linked-list.cxx"

int main()
{
    try {
    llst::List<float> list{};
    for (int i=0; i<10; ++i)
        list.add(i);
    for (size_t i{}; i<list.size(); ++i)
        std::cout << list[i] << ' ';
    std::cout << '\n';
    } catch (std::exception& e) {
        std::cerr << "List Error: " << e.what() << " occured!\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}