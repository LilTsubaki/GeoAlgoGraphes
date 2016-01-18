#include <QCoreApplication>
#include "terrainimage.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QImage qi("C:/Users/etu/Desktop/Heightmap.png", 0);
    TerrainImage ti(qi, 0 ,255, Vector2D(0,0), Vector2D(1000,1000));

    std::cout << qi.width() << "   " << qi.height() << std::endl;
    QImage newqi = ti.drawImage(qi.width(),qi.height());


    newqi.save("C:/Users/etu/Desktop/new.png");

    std::cout << "fin" << std::endl;
    return a.exec();
}

