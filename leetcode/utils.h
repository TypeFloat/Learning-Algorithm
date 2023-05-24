#include <iostream>


template <typename T>
void check(const T &value1, const T &value2)
{
    static int calledTime = 0;
    calledTime += 1;
    std::cout << "Case " << calledTime << ": " << (value1 == value2 ? "true" : "false") << std::endl;
}