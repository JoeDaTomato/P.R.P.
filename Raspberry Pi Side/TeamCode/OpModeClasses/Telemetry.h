#ifndef TELEMETRY_H
#define TELEMETRY_H

#include <vector>

enum Data_Type // Declares enum for holding datatypes.
{
    FLOAT, // float
    DOUBLE, // double
    INT, // int
    UINT, // unsigned int
    CHAR, // char
    UCHAR, // unsigned char
    LONG, // long
    ULONG, // unsigned char
    BOOL, // bool
    CSTR // char*
};

class Telemetry
{
public:
    Telemetry();
    virtual ~Telemetry();
    inline void addData(const char* lable, float data) // Adds data to Telemetry
    {
        m_dataLabels.push_back(lable);
        m_data.push_back(&data);
        m_dataType.push_back(FLOAT);
    }
    inline void addData(const char* lable, double data) // Overridden function
    {
        m_dataLabels.push_back(lable);
        m_data.push_back(&data);
        m_dataType.push_back(DOUBLE);
    }
    inline void addData(const char* lable, int data) // Overridden function
    {
        m_dataLabels.push_back(lable);
        m_data.push_back(&data);
        m_dataType.push_back(INT);
    }
    inline void addData(const char* lable, unsigned int data) // Overridden function
    {
        m_dataLabels.push_back(lable);
        m_data.push_back(&data);
        m_dataType.push_back(UINT);
    }
    inline void addData(const char* lable, char data) // Overridden function
    {
        m_dataLabels.push_back(lable);
        m_data.push_back(&data);
        m_dataType.push_back(CHAR);
    }
    inline void addData(const char* lable, unsigned char data) // Overridden function
    {
        m_dataLabels.push_back(lable);
        m_data.push_back(&data);
        m_dataType.push_back(UCHAR);
    }
    inline void addData(const char* lable, long data) // Overridden function
    {
        m_dataLabels.push_back(lable);
        m_data.push_back(&data);
        m_dataType.push_back(LONG);
    }
    inline void addData(const char* lable, unsigned long data) // Overridden function
    {
        m_dataLabels.push_back(lable);
        m_data.push_back(&data);
        m_dataType.push_back(ULONG);
    }
    inline void addData(const char* lable, bool data) // Overridden function
    {
        m_dataLabels.push_back(lable);
        m_data.push_back(&data);
        m_dataType.push_back(BOOL);
    }
    inline void addData(const char* lable, char* data) // Overridden function
    {
        m_dataLabels.push_back(lable);
        m_data.push_back(&data);
        m_dataType.push_back(CSTR);
    }
    inline void addData(const char* lable, const char* data) // Overridden function
    {
        m_dataLabels.push_back(lable);
        m_data.push_back(&data);
        m_dataType.push_back(CSTR);
    }
    inline bool clearData() // Clears data
    {
        m_dataLabels.clear();
        m_data.clear();
        m_dataType.clear();
        return (!m_dataLabels.size() || !m_data.size() || !m_dataType.size()); // Returns if all vectors are empty
    }
    inline void* getData(const char* lable) // Returns the data from telemetry.
    {
        for (unsigned int i = 0; i < m_dataLabels.size(); i++)
        {
            if (m_dataLabels[i] == lable) return m_data[i];
        }
        return nullptr;
    }
    inline void update() // Transmits data
    {
        // Add data to next outgoing packet
    }
protected:

private:
    std::vector<const char *> m_dataLabels; // Store labels
    std::vector<void*> m_data; // Stores data
    std::vector<Data_Type> m_dataType; // Stores datatypes
};

#endif // TELEMETRY_H
