#include "LocalCANNetworkCANInterface.h"

LocalCANNetworkCANInterface::LocalCANNetworkCANInterface(LocalCANNetwork* network, uint32_t nodeID, const char* tag)
{
    this->tag     = tag;
    this->network = network;
    this->nodeID  = nodeID;
}

uint32_t LocalCANNetworkCANInterface::frameAvailable()
{
    return network->frameAvailable(nodeID);
}

bool LocalCANNetworkCANInterface::readFrame(CANFrame* frame)
{
    // OSInterfaceLogDebug(tag, "Reading frame");
    return network->readFrame(nodeID, frame);
}

bool LocalCANNetworkCANInterface::writeFrame(CANFrame* frame)
{
    // OSInterfaceLogDebug(tag, "Writing frame with N_AI=%s: ", nAiToString(frame->identifier));
    return network->writeFrame(nodeID, frame);
}

bool LocalCANNetworkCANInterface::active()
{
    return network->active();
}

ACKResult LocalCANNetworkCANInterface::getWriteFrameACK()
{
    // OSInterfaceLogVerbose(tag, "Getting write frame ACK for node ID %" PRIu8, nodeID);
    return network->getWriteFrameACK(nodeID);
}

uint32_t LocalCANNetworkCANInterface::getNodeID() const
{
    return nodeID;
}
