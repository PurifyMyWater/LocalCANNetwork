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
    uint32_t frameAvailable() override;
    bool     readFrame(CANFrame* frame) override;
    bool     writeFrame(CANFrame* frame) override;
    bool     active() override;

    ACKResult getWriteFrameACK() override;

    [[nodiscard]] uint32_t getNodeID() const;

    LocalCANNetworkCANInterface(LocalCANNetwork* network, uint32_t nodeID,
                                const char* tag = "LocalCANNetworkCANInterface");

private:
    const char*      tag;
    LocalCANNetwork* network;
    uint32_t         nodeID;
};

#endif // DOCANTESTPROJECT_LOCALCANNETWORKCANINTERFACE_H