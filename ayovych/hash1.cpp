#include <iostream>
#include <string>
#include <functional>
 
int main()
{
    std::string s1 = "Answer to the Ultimate Question of Life, the Universe, and Everything";
    std::string s2 = "answer to the Ultimate Question of Life, the Universe, and Everything";
    std::string s3 = "42";
 
    std::cout << std::hash<std::string>{}(s1) << '\n';
    std::cout << std::hash<std::string>{}(s2) << '\n';
    std::cout << std::hash<std::string>{}(s3) << '\n';
}