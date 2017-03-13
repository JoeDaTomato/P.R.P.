#ifndef OPMODE_H
#define OPMODE_H

#include <vector>
#include <ctime>
#include <string>

#include "OpModeClasses/Telemetry.h"

class OpMode
{
public:
    ~OpMode();
    virtual void init() = 0;
    virtual void start() = 0;
    virtual void loop() = 0;
protected:
    OpMode();
private:
};

#endif // OPMODE_H
