#include "logfilehandler.h"

LogFileHandler::LogFileHandler(const std::string &file)
{

    _log.open( file.c_str() );
}

LogFileHandler::~LogFileHandler()
{
    _log.close();
}

void LogFileHandler::notify(osg::NotifySeverity severity, const char *msg)
{
    _log << msg;
}
