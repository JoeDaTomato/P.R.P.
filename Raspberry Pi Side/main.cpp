#include <fstream>
#include <vector>
#include <ctime>

int main()
{
    std::ofstream log("log.txt", std::ios::app); // Open Log
    std::time_t startTime;
    time(&startTime); // Set start time
    log << "Program started at " << startTime << ".\nBeginning initialization...\n";

    return 0;
}
