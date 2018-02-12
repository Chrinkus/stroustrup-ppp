#include "../text_lib/std_lib_facilities.h"

char get_comp_choice(char user_choice, int random_k)
{
    int input = int(user_choice) + random_k;

    vector<char> choices = { 'r', 'p', 's' };

    return choices[(input % 3)];
}

int main()
{
    // Rock, Paper, Scissors
    char user_choice = ' ';
    char comp_choice = ' ';
    char result = ' ';

    int randomizer = 48;
    int user_wins = 0;
    int comp_wins = 0;

    cout << "Lets play rock, paper, scissors. What is your choice?(r/p/s)\n";

    while (cin >> user_choice) {
        comp_choice = get_comp_choice(user_choice, randomizer);

        switch (user_choice) {
            case 'r':
                if (comp_choice == 'r')
                    result = 't';
                else if (comp_choice == 'p')
                    result = 'l';
                else if (comp_choice == 's')
                    result = 'w';
                break;
            case 'p':
                if (comp_choice == 'r')
                    result = 'w';
                else if (comp_choice == 'p')
                    result = 't';
                else if (comp_choice == 's')
                    result = 'l';
                break;
            case 's':
                if (comp_choice == 'r')
                    result = 'l';
                else if (comp_choice == 'p')
                    result = 'w';
                else if (comp_choice == 's')
                    result = 't';
                break;
            default:
                // bad input
                break;
        }

        cout << "Player chose: " << user_choice
             << " Computer chose: " << comp_choice << '\n';

        switch (result) {
            case 'w':
                cout << "Player wins!\n";
                user_wins += 1;
                break;
            case 'l':
                cout << "Player loses..\n";
                comp_wins += 1;
                break;
            case 't':
                cout << "Tie game, everyone loses!\n";
                break;
            default:
                // no default
                break;
        }

        cout << "Score: Player " << user_wins
             << " Computer " << comp_wins << '\n'
             << "Wanna play again?(r/p/s)\n";

        ++randomizer;
    }
}
