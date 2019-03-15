#include <iostream>
#include "Thanos.h"

using namespace std;

int main(int argc, char *argv[]) {
    string codefile = argv[1]; // get filename

    Thanos thanos(codefile); // Loading infinity stones

    thanos.snapFinger(); // The Hardest Choice Requires the Strongest Wills

    return 0;
}