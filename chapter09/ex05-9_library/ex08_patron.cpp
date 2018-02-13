#include<string>

class Patron {
    public:
        Patron(string n, int c);
        void inc_fees(double incFee);
        void set_fees(double newFee);
        bool owes_fees();

        string get_name() const { return name; }
        int get_card_num() const { return card_num; }
        double get_fees() const { return fees; }

    private:
        string name;
        int card_num;
        double fees;
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Patron::Patron(string n, int c)
    :name{n}, card_num{c}
{
    fees = 0;
}

void Patron::inc_fees(double incFee)
{
    fees += incFee;
}

void Patron::set_fees(double newFee)
{
    fees = newFee;
}

bool Patron::owes_fees()
{
    return fees > 0;
}
