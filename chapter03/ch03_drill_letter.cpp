#include "../text_lib/std_lib_facilities.h"

// Chapter 3 Drill
int main()
{
    // 1
    cout << "Enter the name of the person you want to write to:\n";
    string first_name;
    cin >> first_name;
    cout << "Dear " << first_name << ",\n"
         // 2
         << "   How are you doing? What is normal life like for you?\n"
         << "I saw the pictures of your wedding and it was nice to\n"
         << "remember such a wonderful day.\n";
    // 3
    cout << "Please enter the name of someone you both know:\n";
    string friend_name;
    cin >> friend_name;
    cout << "Have you heard from " << friend_name << " lately?\n";
    // 4
    cout << "Is this friend a male or a female?\n"
         << "(m/f)?";
    char friend_sex = '0';
    cin >> friend_sex;
    if (friend_sex == 'm')
        cout << "If you see " << friend_name
             << " please ask him to call me.\n";
    if (friend_sex == 'f')
        cout << "If you see " << friend_name
             << " please ask her to call me.\n";
    // 5
    cout << "How old is " << first_name << "?\n";
    int age;
    cin >> age;
    if (age <= 0) simple_error("you're kidding!");
    if (age > 110) simple_error("you're kidding!");
    // 6
    if (age < 12)
        cout << "Next year you will be " << age+1 << ".\n";
    if (age == 17)
        cout << "Next year you will be able to vote!\n";
    if (age > 70)
        cout << "I hope you are enjoying retirement.\n";
    // 7
    cout << "Yours sincerely,\n\n\nChris Schick\n";
}
