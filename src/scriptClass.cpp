#include "scriptClass.h"

Script::Script()
{
}

Script::Script(std::string new_title)
{
    this->title = new_title;
}

Script::Script(std::string new_title, std::vector<std::string> new_messages)
{
    this->title = new_title;
    this->messages = new_messages;
}

Script::~Script()
{
}

void Script::setTitle(std::string newTitle)
{
    this->title = newTitle;
}

const std::string Script::getTitle()
{
    return this->title;
}

void Script::addMessage(std::string newMessage)
{
    this->messages.push_back(newMessage);
}

const std::vector<std::string> Script::getMessages()
{
    return this->messages;
}

const std::string Script::toString()
{
    std::string s = this->title + "\n";
    //s.append("\n");
    for (auto &m : this->messages)
        s += m + "\n";
        //s.append(m);
        //s.append("\n")

    return s;
}

void Script::execute_script(Device &myDevice)
{
    std::cout << "Starting to execute [" << this->title << "]..." << std::endl;

    for(std::string &strMessage : this->messages)
    {
        MessageIR currentMessage(strMessage);
        if(currentMessage.is_command())
            currentMessage.execute_message(myDevice);
    }

    std::cout << "Script [" << this->title << "] has been executed.\n\n";

}
