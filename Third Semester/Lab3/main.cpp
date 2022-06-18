#include "HandlingFunctions.h"
#include "SortingAlgorithms.h"

int main(int argc, char *argv[])
{
    bool valid = handleCmdArguments(argc,argv);
    if (valid) cout << '\n';
    else cout << "Invalid command!\n";
    return 0;
}
