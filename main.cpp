#include "terrainimage.h"

int main(int argc, char *argv[])
{

    QImage qi("C:/Users/etu/Desktop/Heightmap.png", 0);
    TerrainImage ti(qi, 255 ,0, Vector2D(0,0), Vector2D(1000,1000));

    std::cout << qi.width() << "   " << qi.height() << std::endl;
    QImage newqi = ti.drawImage(qi.width(),qi.height());

    QVector<Vector2D> list=Vector2D::randSquare(Vector2D(0,0), Vector2D(1000,1000),10,50);

    std::cout << "fin rand " <<list.size()<< std::endl;
    ti.addVille(newqi,list,25);


    newqi.save("C:/Users/etu/Desktop/new.png");

    std::cout << "fin" << std::endl;
    return 0;
}

