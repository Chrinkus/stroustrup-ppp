#include <iostream>
#include <stdexcept>
#include <string>

/*
std::string cat_dot(const std::string& s1, const std::string& s2)
{
    return s1 + "." + s2;
}

std::string cat_dot(const std::string& s1, const std::string& s2,
        const std::string& s3)
{
    return s1 + s3 + s2;
}
*/

char* cat_dot(const char* s1, const char* s2, char c = '.')
{
    int n1 = 0;
    while (s1[n1]) ++n1;

    int n2 = 0;
    while (s2[n2]) ++n2;

    int n3 = n1 + 1 + n2 + 1;

    char* p = new char[n3];

    for (int i = 0; i < n1; ++i)
        p[i] = s1[i];

    p[n1] = c;

    for (int i = 0; i < n2; ++i)
        p[n1 + 1 + i] = s2[i];

    p[n3 - 1] = s2[n2];

    return p;
}

int main()
{
    /*
    std::cout << cat_dot("Jacob", "Schick") << '\n';
    std::cout << cat_dot("Chris", "Schick", "-") << '\n';
    */
    char str1[] = "Nora";
    char str2[] = "Schick";

    char* str3 = cat_dot(str1, str2);
    char* str4 = cat_dot(str2, str1, '*');

    std::cout << str3 << '\n';
    std::cout << str4 << '\n';

    delete[] str3;
    delete[] str4;
}
