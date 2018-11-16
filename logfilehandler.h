#ifndef LOGFILEHANDLER_H
#define LOGFILEHANDLER_H

#include <QtCore/qglobal.h>

#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <fstream>

class LogFileHandler : public osg::NotifyHandler
{
public:
    LogFileHandler(const std::string& file);

    virtual ~LogFileHandler();

    virtual void notify( osg::NotifySeverity severity , const char* msg);


protected:
    std::ofstream _log;
};

#endif // LOGFILEHANDLER_H
