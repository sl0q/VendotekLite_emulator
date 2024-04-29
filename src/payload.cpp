#include "payload.h"

Payload::Payload()
{
}

Payload::Payload(google::protobuf::Message *newResponceData)
{
    this->responceMsg = newResponceData;
    this->data.resize(newResponceData->ByteSizeLong());
    int buf_size = this->data.size();
    this->responceMsg->SerializeToArray(this->data.data(), buf_size);
    this->debugString = newResponceData->DebugString();
}

Payload::Payload(const Payload &otherPayload)
{
    this->debugString = otherPayload.debugString;
    this->data = otherPayload.data;

    if (this->responceMsg != nullptr)
        delete this->responceMsg;
    this->responceMsg = nullptr;

    if (otherPayload.responceMsg != nullptr) //  check if otherPayload is empty
    {
        this->responceMsg = otherPayload.responceMsg->New();
        this->responceMsg->CopyFrom(*otherPayload.responceMsg);
    }
}

Payload::~Payload()
{
    if (responceMsg != nullptr)
        delete responceMsg;
}

const std::string &Payload::get_debug_string() const
{
    return this->debugString;
}

const std::vector<uint8_t> &Payload::get_data() const
{
    return this->data;
}

const google::protobuf::Message *Payload::get_responce_msg() const
{
    return this->responceMsg;
}
