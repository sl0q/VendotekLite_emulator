#pragma once

#include <string>

namespace ex
{
    class JsonParsingException
    {
    private:
        std::string msg_;

    public:
        JsonParsingException(const std::string &msg) : msg_(msg) {}
        JsonParsingException() {}

        std::string what() const { return (msg_); }
    };

    class CantOpenFile
    {
    private:
        std::string msg_;

    public:
        CantOpenFile(const std::string &msg) : msg_(msg) {}
        CantOpenFile() {}

        std::string what() const { return (msg_); }
    };

    class FailedExecution
    {
    private:
        std::string msg_;

    public:
        FailedExecution(const std::string &msg) : msg_(msg) {}
        FailedExecution() {}

        std::string what() const { return (msg_); }
    };

    class InvalidMessageIR
    {
    private:
        std::string msg_;

    public:
        InvalidMessageIR(const std::string &msg) : msg_(msg) {}
        InvalidMessageIR() {}

        std::string what() const { return (msg_); }
    };

    class BadType
    {
    private:
        std::string msg_;

    public:
        BadType(const std::string &msg) : msg_(msg) {}
        BadType() {}

        std::string what() const { return (msg_); }
    };

}