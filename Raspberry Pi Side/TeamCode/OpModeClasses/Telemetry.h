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
    inline bool addData(const char* label, float data) // Adds data to Telemetry
    {
        for (unsigned int i = 0; i < m_dataLabels.size(); i++)
        {
            if (m_dataLabels[i] == label)
            {
                m_data[i] = &data;
                m_dataType[i] = FLOAT;
                return true;
            }
        }
        m_dataLabels.push_back(label);
        m_data.push_back(&data);
        m_dataType.push_back(FLOAT);
        return false;
    }
    inline bool addData(const char* label, double data) // Overridden function
    {
        for (unsigned int i = 0; i < m_dataLabels.size(); i++)
        {
            if (m_dataLabels[i] == label)
            {
                m_data[i] = &data;
                m_dataType[i] = DOUBLE;
                return true;
            }
        }
        m_dataLabels.push_back(label);
        m_data.push_back(&data);
        m_dataType.push_back(DOUBLE);
        return false;
    }
    inline bool addData(const char* label, int data) // Overridden function
    {
        for (unsigned int i = 0; i < m_dataLabels.size(); i++)
        {
            if (m_dataLabels[i] == label)
            {
                m_data[i] = &data;
                m_dataType[i] = INT;
                return true;
            }
        }
        m_dataLabels.push_back(label);
        m_data.push_back(&data);
        m_dataType.push_back(INT);
        return false;
    }
    inline bool addData(const char* label, unsigned int data) // Overridden function
    {
        for (unsigned int i = 0; i < m_dataLabels.size(); i++)
        {
            if (m_dataLabels[i] == label)
            {
                m_data[i] = &data;
                m_dataType[i] = UINT;
                return true;
            }
        }
        m_dataLabels.push_back(label);
        m_data.push_back(&data);
        m_dataType.push_back(UINT);
        return false;
    }
    inline bool addData(const char* label, char data) // Overridden function
    {
        for (unsigned int i = 0; i < m_dataLabels.size(); i++)
        {
            if (m_dataLabels[i] == label)
            {
                m_data[i] = &data;
                m_dataType[i] = CHAR;
                return true;
            }
        }
        m_dataLabels.push_back(label);
        m_data.push_back(&data);
        m_dataType.push_back(CHAR);
        return true;
    }
    inline bool addData(const char* label, unsigned char data) // Overridden function
    {
        for (unsigned int i = 0; i < m_dataLabels.size(); i++)
        {
            if (m_dataLabels[i] == label)
            {
                m_data[i] = &data;
                m_dataType[i] = UCHAR;
                return true;
            }
        }
        m_dataLabels.push_back(label);
        m_data.push_back(&data);
        m_dataType.push_back(UCHAR);
        return false;
    }
    inline bool addData(const char* label, long data) // Overridden function
    {
        for (unsigned int i = 0; i < m_dataLabels.size(); i++)
        {
            if (m_dataLabels[i] == label)
            {
                m_data[i] = &data;
                m_dataType[i] = LONG;
                return true;
            }
        }
        m_dataLabels.push_back(label);
        m_data.push_back(&data);
        m_dataType.push_back(LONG);
        return false;
    }
    inline bool addData(const char* label, unsigned long data) // Overridden function
    {
        for (unsigned int i = 0; i < m_dataLabels.size(); i++)
        {
            if (m_dataLabels[i] == label)
            {
                m_data[i] = &data;
                m_dataType[i] = ULONG;
                return true;
            }
        }
        m_dataLabels.push_back(label);
        m_data.push_back(&data);
        m_dataType.push_back(ULONG);
        return false;
    }
    inline bool addData(const char* label, bool data) // Overridden function
    {
        for (unsigned int i = 0; i < m_dataLabels.size(); i++)
        {
            if (m_dataLabels[i] == label)
            {
                m_data[i] = &data;
                m_dataType[i] = BOOL;
                return true;
            }
        }
        m_dataLabels.push_back(label);
        m_data.push_back(&data);
        m_dataType.push_back(BOOL);
        return false;
    }
    inline bool addData(const char* label, char* data) // Overridden function
    {
        for (unsigned int i = 0; i < m_dataLabels.size(); i++)
        {
            if (m_dataLabels[i] == label)
            {
                m_data[i] = &data;
                m_dataType[i] = CSTR;
                return true;
            }
        }
        m_dataLabels.push_back(label);
        m_data.push_back(&data);
        m_dataType.push_back(CSTR);
        return false;
    }
    inline bool addData(const char* label, const char* data) // Overridden function
    {
        for (unsigned int i = 0; i < m_dataLabels.size(); i++)
        {
            if (m_dataLabels[i] == label)
            {
                m_data[i] = &data;
                m_dataType[i] = CSTR;
                return true;
            }
        }
        m_dataLabels.push_back(label);
        m_data.push_back(&data);
        m_dataType.push_back(CSTR);
        return false;
    }
    inline bool clearData() // Clears data
    {
        m_dataLabels.clear();
        m_data.clear();
        m_dataType.clear();
        return (!m_dataLabels.size() || !m_data.size() || !m_dataType.size()); // Returns if all vectors are empty
    }
    inline void* getData(const char* label) // Returns the data from telemetry.
    {
        for (unsigned int i = 0; i < m_dataLabels.size(); i++)
        {
            if (m_dataLabels[i] == label) return m_data[i];
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
