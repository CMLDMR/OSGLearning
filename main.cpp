#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>

#include <QDir>

#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

#include <iostream>


using namespace std;


#include "monitoingtarget.h"



MonitoingTarget* createMonitoringTarger( int index )
{
    osg::ref_ptr<MonitoingTarget> ref = new MonitoingTarget(index);
    return ref.release();
}

int main(int argc, char *argv[])
{


    osg::ref_ptr<MonitoingTarget> target = new MonitoingTarget(0);

    std::cout << "Referenced count before reffering: " << target.get()->referenceCount() << std::endl;

    osg::ref_ptr<MonitoingTarget> anothertarget = target;

    std::cout << "Referenced count before reffering: " << anothertarget.get()->referenceCount() << std::endl;



    for( int i = 0 ; i < 5 ; i++ )
    {
        osg::ref_ptr<MonitoingTarget> subTarget = new MonitoingTarget(i);
    }

    for( int i = 5 ; i < 10 ; i++ )
    {
        osg::ref_ptr<MonitoingTarget> subTarget = createMonitoringTarger(i);
    }



//    osg::ref_ptr<osg::Node> root = osgDB::readNodeFile("cessna.osg");



//    osgViewer::Viewer viewer;



//    viewer.setSceneData( root.get() );

//    viewer.setUpViewOnSingleScreen(0);

//    return viewer.run();



}
