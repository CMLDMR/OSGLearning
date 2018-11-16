#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>

#include <QDir>

#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

#include <iostream>


using namespace std;


int main(int argc, char *argv[])
{




    osg::ref_ptr<osg::Node> root = osgDB::readNodeFile("cessna.osg");



    osgViewer::Viewer viewer;



    viewer.setSceneData( root.get() );

    viewer.setUpViewOnSingleScreen(0);

    return viewer.run();



}
