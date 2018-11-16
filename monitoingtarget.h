#ifndef MONITOINGTARGET_H
#define MONITOINGTARGET_H

#include <QtCore/qglobal.h>
#include <osg/ref_ptr>
#include <osg/Referenced>
#include <iostream>

class MonitoingTarget : public osg::Referenced
{
public:
    MonitoingTarget( int _id );

protected:
    int mId;
    ~MonitoingTarget();
};

#endif // MONITOINGTARGET_H
