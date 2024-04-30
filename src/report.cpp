#include "report.h"

Report::Report()
{
    this->msg = new Msg();
}

//  construct with copy of Msg
Report::Report(const Msg &newMsg)
{
    this->msg = new Msg(newMsg);
}

//  construct with allocated Msg
Report::Report(const Msg *newMsg)
{
    this->msg = newMsg;
}

Report::~Report()
{
    for (auto &entry : logEntries)
        delete entry;
    delete msg;
}

const std::vector<const LogEntry *> &Report::get_log() const
{
    return logEntries;
}

const Msg &Report::get_msg() const
{
    return *msg;
}

void Report::append_log_entry(const std::string &logText, bool visible)
{
    this->logEntries.push_back(new LogEntry(logText, visible));
}

void Report::clear_log()
{
    for (auto &entry : logEntries)
        delete entry;
    this->logEntries.clear();
}

void Report::set_allocated_msg(const Msg *newMsg)
{
    this->msg = newMsg;
}

LogEntry::LogEntry()
{
}

LogEntry::LogEntry(const std::string &newText, bool visible)
{
    this->text = newText;
    this->visible = visible;
}

LogEntry::~LogEntry()
{
}

bool LogEntry::is_visible() const
{
    return visible;
}

void LogEntry::set_text(const std::string &newText)
{
    this->text = newText;
}

const std::string &LogEntry::get_text() const
{
    return text;
}
