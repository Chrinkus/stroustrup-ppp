#include "../text_lib/std_lib_facilities.h"

// LOOKING BACK: I didn't really have much of an appetite for flexing the
// compiler's error detection..

int main()
{
    int ridic = 0.273;      // only a warning!
    char $ = "w";           // error: double quotes is const char?
    double int = 17;        // error: tries to combine int with double
}
