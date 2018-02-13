#include <iostream>
#include <string>

using std::ostream;
using std::string;

namespace Library_lib {

    struct ISBN {
        ISBN(int g, int p, int t, char c);
        int group;
        int publisher;
        int title;
        char check;
    };

    ostream& operator<<(ostream& os, const ISBN& I);
    bool operator==(const ISBN& a, const ISBN& b);
    bool operator!=(const ISBN& a, const ISBN& b);

    enum class Genre {
        fiction, nonfiction, periodical, biography, children
    };

    ostream& operator<<(ostream& os, const Genre g);

    class Book {
        public:
            Book(string t, string a, int c, ISBN I, Genre g);
            bool is_avail() { return available; }
            void check_in() { available = true; }
            void check_out() { available = false; }

            // getters
            string  get_title()     const { return title; }
            string  get_author()    const { return author; }
            int     get_copy()      const { return copyright; }
            ISBN    get_ISBN()      const { return isbn; }
            Genre   get_genre()     const { return genre; }
        private:
            string title;
            string author;
            int copyright;
            ISBN isbn;
            Genre genre;
            bool available = true;
    };
    
    ostream& operator<<(ostream& os, const Book& b);
    bool operator==(const Book& a, const Book& b);
    bool operator!=(const Book& a, const Book& b);
}
