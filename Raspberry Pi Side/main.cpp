#include <fstream>
#include <vector>
#include <ctime>

int main()
{
    std::ofstream log("log.txt", std::ios::app);
    std::time_t startTime;
    time(&startTime);
    log << "Program started at " << startTime << ".\nBeginning initialization...\n";

    return 0;
}
