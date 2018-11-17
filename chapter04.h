#ifndef CHAPTER04_H
#define CHAPTER04_H




#include <osg/Geometry>
#include <osg/Geode>
#include <osgViewer/Viewer>



void coloredQuad(osgViewer::Viewer* viewer){


    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;

    vertices->push_back( osg::Vec3( 0.0,0.0,0.0) );
    vertices.get()->push_back( osg::Vec3(1.0,0.0,0.0));
    vertices.get()->push_back( osg::Vec3(1.0,0.0,1.0));
    vertices.get()->push_back( osg::Vec3(0.0,0.0,1.0));

    osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
    normals.get()->push_back( osg::Vec3( 0.0 , -1.0 , 0.0 ) );


    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
    colors->push_back( osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f) );
    colors->push_back( osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) );
    colors->push_back( osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f) );
    colors->push_back( osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f) );

    osg::ref_ptr<osg::Geometry> quad = new osg::Geometry;
    quad->setVertexArray( vertices.get() );
    quad->setNormalArray( normals.get() );
    quad->setNormalBinding( osg::Geometry::BIND_OVERALL );
    quad->setColorArray( colors.get() );
    quad->setColorBinding( osg::Geometry::BIND_PER_VERTEX );

    quad->addPrimitiveSet( new osg::DrawArrays(GL_QUADS, 0, 4) );


    osg::ref_ptr<osg::Geode> root = new osg::Geode;
    root->addDrawable( quad.get() );

    viewer->setSceneData(root.get());

}


#include <osgUtil/SmoothingVisitor>
void octohedron(osgViewer::Viewer *viewer)
{


    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(6);
    (*vertices)[0].set( 0.0f, 0.0f, 1.0f);
    (*vertices)[1].set(-0.5f,-0.5f, 0.0f);
    (*vertices)[2].set( 0.5f,-0.5f, 0.0f);
    (*vertices)[3].set( 0.5f, 0.5f, 0.0f);
    (*vertices)[4].set(-0.5f, 0.5f, 0.0f);
    (*vertices)[5].set( 0.0f, 0.0f,-1.0f);

    osg::ref_ptr<osg::DrawElementsUInt> indices =
    new osg::DrawElementsUInt(GL_TRIANGLES, 24);
    (*indices)[0] = 0; (*indices)[1] = 1; (*indices)[2] = 2;
    (*indices)[3] = 0; (*indices)[4] = 2; (*indices)[5] = 3;
    (*indices)[6] = 0; (*indices)[7] = 3; (*indices)[8] = 4;
    (*indices)[9] = 0; (*indices)[10]= 4; (*indices)[11]= 1;
    (*indices)[12]= 5; (*indices)[13]= 2; (*indices)[14]= 1;
    (*indices)[15]= 5; (*indices)[16]= 3; (*indices)[17]= 2;
    (*indices)[18]= 5; (*indices)[19]= 4; (*indices)[20]= 3;
    (*indices)[21]= 5; (*indices)[22]= 1; (*indices)[23]= 4;


    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
    geom->setVertexArray( vertices.get() );
    geom->addPrimitiveSet( indices.get() );
    osgUtil::SmoothingVisitor::smooth( *geom );

    osg::ref_ptr<osg::Geode> root = new osg::Geode;
    root->addDrawable( geom.get() );

    viewer->setSceneData(root.get());

}



#include <osgUtil/Tessellator>

void tessellation(osgViewer::Viewer* viewer)
{

    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array ();

    vertices.get()->push_back( osg::Vec3 ( 0.0 , 0.0 , 0.0 ) );
    vertices.get()->push_back( osg::Vec3 ( 2.0 , 0.0 , 0.0 ) );
    vertices.get()->push_back( osg::Vec3 ( 2.0 , 0.0 , 1.0 ) );
    vertices.get()->push_back( osg::Vec3 ( 1.0 , 0.0 , 1.0 ) );
    vertices.get()->push_back( osg::Vec3 ( 1.0 , 0.0 , 2.0 ) );
    vertices.get()->push_back( osg::Vec3 ( 2.0 , 0.0 , 2.0 ) );
    vertices.get()->push_back( osg::Vec3 ( 2.0 , 0.0 , 3.0 ) );
    vertices.get()->push_back( osg::Vec3 ( 1.0 , 0.0 , 3.0 ) );

    osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
    normals.get()->push_back( osg::Vec3 ( 0.0 , -1.0 , 0.0 ) );


    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

    geom.get()->setVertexArray(vertices.get());
    geom.get()->setColorArray(normals.get());

    geom.get()->setNormalBinding(osg::Geometry::BIND_OVERALL);

    geom.get()->addPrimitiveSet(new osg::DrawArrays( GL_POLYGON , 0 , 8 ) );

    osgUtil::Tessellator tessellator;

    tessellator.retessellatePolygons(*geom.get());


    osg::ref_ptr<osg::Geode> root = new osg::Geode;
    root->addDrawable( geom.get() );


    viewer->setSceneData(root.get());

}

#endif // CHAPTER04_H
