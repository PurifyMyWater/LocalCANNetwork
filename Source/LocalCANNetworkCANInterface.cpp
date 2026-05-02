#include "LocalCANNetworkCANInterface.h"

LocalCANNetworkCANInterface::LocalCANNetworkCANInterface(LocalCANNetwork* network, uint32_t nodeID, const char* tag)
{
    this->tag     = tag;
    this->network = network;
    this->nodeID  = nodeID;
}

CANEvent LocalCANNetworkCANInterface::getEvent(uint32_t maxTimeToWait_ms)
{
    return nullptr;
}

bool LocalCANNetworkCANInterface::sendFrame(const CANFrame& frame, int32_t maxTimeToWait_ms)
{
    // OSInterfaceLogDebug(tag, "Writing frame with N_AI=%s: ", nAiToString(frame->identifier));
    return network->writeFrame(nodeID, frame);
}

bool LocalCANNetworkCANInterface::disable()
{
    return network->active();
}

bool LocalCANNetworkCANInterface::enable()
{
    return network->active();
}

bool LocalCANNetworkCANInterface::recoverFromBusOff()
{
    return network->active();
}

uint32_t LocalCANNetworkCANInterface::getNodeID() const
{
    return nodeID;
}
