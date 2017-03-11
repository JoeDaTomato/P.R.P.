#ifndef OPMODE_H
#define OPMODE_H

#include <vector>
#include <ctime>
#include <string>

class OpMode
{
public:
    ~OpMode();
    virtual void init() = 0;
    virtual void start() = 0;
    virtual void loop() = 0;
    Telemetry telemetry;
protected:
    OpMode();
private:
    class Telemetry
    {
    public:
        Telemetry();
        ~Telemetry();
        void addData(const char* lable, int data)
        {

        }
        void addData(const char* lable, unsigned int data)
        {

        }
        void addData(const char* lable, float data)
        {

        }
        void addData(const char* lable, double data)
        {

        }
        void addData(const char* lable, time_t data)
        {

        }
        void clearData()
        {
            m_lables.clear();
            m_dataTypes.clear();
        }
    protected:
    private:
        std::vector<std::string> m_lables;
        std::vector<unsigned char> m_dataTypes;
    };
};

#endif // OPMODE_H
