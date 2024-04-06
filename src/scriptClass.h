#pragma once

#include <iostream>
#include <vector>
#include <string>

class Device;

#include "messageClass.h"
#include "deviceClass.h"

class Script
{
private:
    std::string title = "Untitled script";
    std::vector<std::string> messages;

public:
    Script();
    Script(std::string new_title);
    Script(std::string new_title, std::vector<std::string> new_messages);
    ~Script();

    void setTitle(std::string newTitle);
    const std::string getTitle();
    void addMessage(std::string newMessage);
    const std::vector<std::string> getMessages();
    const std::string toString(); // return script data as a string to print

    void execute_script(Device &myDevice);
    // void deserializeMessage();
};
