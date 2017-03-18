#ifndef PACKET MANAGER_H
#define PACKET MANAGER_H

#include <string>
#include <vector>

class PacketManager
{
    public:
        PacketManager();
        static unsigned char getErrorState() return m_errorState; // Returns the error state.
        static void resetErrorState() // Resets the error state.
        {
            m_errorState = 0;
        }
        static bool addToPacket(char data[], unsigned char source = 2, bool clearFirst = false)
        {
            if (sizeof(data) == 0) return false; // Check if array is empty.
            if (source > 2 || source < 0) return false; // Check if source is valid.
            if (clearFirst) m_packet[source].clear();
            for (unsigned int i = 0; i < sizeof(data); i++)
            {
                m_packet[source].push_back(data[i]);
            }
        }
        static inline bool sendPacket() // Sends a packet to the driver's station with all needed updates, then waits for a response.
        {
            if (m_address == "")
            {
                m_errorState = 1;
                return false;
            }
            m_packet.clear();
        }
        static inline void setAddress(std::string address) // Sets the address
        {
            m_address = address;
        }
    protected:

    private:
        static std::string m_address;
        static unsigned char m_errorState;
        static std::vector<char> m_packet[];
};

#endif // PACKET MANAGER_H

#ifdef PMANAGER_STATIC
#undef PMANAGER_STATIC
static std::string PacketManager::m_address = "";
static unsigned char PacketManager::m_errorState = 0;
static std::vector<char> PacketManager::m_packet[3];
#endif
