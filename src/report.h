#pragma once

#include "msg.h"

class LogEntry
{
private:
    std::string text;
    bool visible; //  print this on textbox or not

public:
    LogEntry();
    LogEntry(const std::string &newText, bool visible = false);
    ~LogEntry();

    bool is_visible() const;

    void set_text(const std::string &newText);

    const std::string &get_text() const;
};

class Report
{
private:
    const Msg *msg = nullptr;

    std::vector<const LogEntry *> logEntries;

public:
    Report();
    Report(const Msg &newMsg);
    Report(const Msg *newMsg);
    ~Report();

    const std::vector<const LogEntry *> &get_log() const;
    const Msg &get_msg() const;

    void append_log_entry(const std::string &logText, bool visible = false);
    void clear_log();
    void set_allocated_msg(const Msg *newMsg);
};
