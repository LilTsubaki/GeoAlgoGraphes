#include <QCoreApplication>
#include "terrainimage.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QImage qi("C:/Users/etu/Desktop/Heightmap.png", 0);
    TerrainImage ti(qi, 255 ,0, Vector2D(0,0), Vector2D(1000,1000));

    std::cout << ti.getHauteur(Vector2D(2,2))<< std::endl;

    return a.exec();
}

