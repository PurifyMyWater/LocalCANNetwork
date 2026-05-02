#ifndef DOCANTESTPROJECT_LOCALCANNETWORKCANINTERFACE_H
#define DOCANTESTPROJECT_LOCALCANNETWORKCANINTERFACE_H

#include <list>
#include <queue>
#include <vector>
#include "CANInterface.h"

/**
 * @brief A CANInterface implementation that uses a LocalCANNetwork to simulate a CAN bus
 */
class LocalCANNetworkCANInterface : public CANInterface
{
public:
    CANEvent getEvent(uint32_t maxTimeToWait_ms);
    bool     sendFrame(const CANFrame& frame, int32_t maxTimeToWait_ms);
    bool     disable();
    bool     enable();
    bool     recoverFromBusOff();

    [[nodiscard]] uint32_t getNodeID() const;

    LocalCANNetworkCANInterface(LocalCANNetwork* network, uint32_t nodeID,
                                const char* tag = "LocalCANNetworkCANInterface");

private:
    const char*      tag;
    LocalCANNetwork* network;
    uint32_t         nodeID;
};

#endif // DOCANTESTPROJECT_LOCALCANNETWORKCANINTERFACE_H