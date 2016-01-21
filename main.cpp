#include "terrainimage.h"

int main(int argc, char *argv[])
{

    QImage qi("C:/Users/etu/Desktop/GrandCanyon2.png", 0);
    TerrainImage ti(qi, 1000 ,0, Vector2D(0,0), Vector2D(1000,1000));

    std::cout << qi.width()*4 << "   " << qi.height()*4 << std::endl;
    QImage newqi = ti.drawImage(qi.width()*4,qi.height()*4);
    QImage newqi2 = ti.drawImage(qi.width()*4,qi.height()*4);

    QImage newqi3 = ti.drawImage(qi.width()*4,qi.height()*4);
    QImage newqi4 = ti.drawImage(qi.width()*4,qi.height()*4);

    QImage newqi5 = ti.drawImage(qi.width()*4,qi.height()*4);
    QImage newqi6 = ti.drawImage(qi.width()*4,qi.height()*4);

    QImage newqi7 = ti.drawImage(qi.width()*4,qi.height()*4);
    QImage newqi8 = ti.drawImage(qi.width()*4,qi.height()*4);

    QImage newqi9 = ti.drawImage(qi.width()*4,qi.height()*4);
    QImage newqi10 = ti.drawImage(qi.width()*4,qi.height()*4);

    QImage newqi11 = ti.drawImage(qi.width()*4,qi.height()*4);
    QImage newqi12 = ti.drawImage(qi.width()*4,qi.height()*4);
    QImage newqi13= ti.drawImage(qi.width()*4,qi.height()*4);
    QImage newqi14 = ti.drawImage(qi.width()*4,qi.height()*4);
    QImage newqi15 = ti.drawImage(qi.width()*4,qi.height()*4);


    QVector<Vector2D> list=Vector2D::randSquare(Vector2D(0,0), Vector2D(1000,1000),75,50);

    std::cout << "fin rand " <<list.size()<< std::endl;


    QVector<Vector2D> roads;

    /*ti.addVille(newqi,list,15);
    roads = Vector2D::getBetaSquel(list, 1.5);
    ti.drawRoad(roads, newqi);

    ti.addVille(newqi2,list,15);
    roads = ti.getBetaSquelTerrain(list, 1.5);
    ti.drawRoad(roads, newqi2);

    ti.addVille(newqi3,list,15);
    roads = Vector2D::getBetaSquel(list, 2);
    ti.drawRoad(roads, newqi3);

    ti.addVille(newqi4,list,15);
    roads = ti.getBetaSquelTerrain(list, 2);
    ti.drawRoad(roads, newqi4);

    ti.addVille(newqi7,list,15);
    roads = Vector2D::getBetaSquel(list, 4);
    ti.drawRoad(roads, newqi7);

    ti.addVille(newqi8,list,15);
    roads = ti.getBetaSquelTerrain(list, 4);
    ti.drawRoad(roads, newqi8);

    ti.addVille(newqi5,list,15);
    roads = Vector2D::getBetaSquel(list, 8);
    ti.drawRoad(roads, newqi5);

    ti.addVille(newqi6,list,15);
    roads = ti.getBetaSquelTerrain(list, 8);
    ti.drawRoad(roads, newqi6);

    ti.addVille(newqi9,list,15);
    roads = Vector2D::getBetaSquel(list, 16);
    ti.drawRoad(roads, newqi9);

    ti.addVille(newqi10,list,15);
    roads = ti.getBetaSquelTerrain(list, 16);
    ti.drawRoad(roads, newqi10);

    ti.addVille(newqi11,list,15);
    roads = ti.getBetaSquelPente(list, 1.5);
    ti.drawRoad(roads, newqi11);
    ti.addVille(newqi12,list,15);
    roads = ti.getBetaSquelPente(list, 2);
    ti.drawRoad(roads, newqi12);
    ti.addVille(newqi13,list,15);
    roads = ti.getBetaSquelPente(list, 4);
    ti.drawRoad(roads, newqi13);
    ti.addVille(newqi14,list,15);
    roads = ti.getBetaSquelPente(list, 8);
    ti.drawRoad(roads, newqi14);*/
    ti.addVille(newqi15,list,15);
    roads = ti.getBetaSquelPente(list, 16);
    ti.drawRoad(roads, newqi15);


    /*newqi.save("C:/Users/etu/Desktop/1dist.png");
    newqi2.save("C:/Users/etu/Desktop/1DistMont.png");
    newqi3.save("C:/Users/etu/Desktop/2dist.png");
    newqi4.save("C:/Users/etu/Desktop/2DistMont.png");
    newqi7.save("C:/Users/etu/Desktop/4dist.png");
    newqi8.save("C:/Users/etu/Desktop/4DistMont.png");
    newqi5.save("C:/Users/etu/Desktop/8dist.png");
    newqi6.save("C:/Users/etu/Desktop/8DistMont.png");
    newqi9.save("C:/Users/etu/Desktop/16dist.png");
    newqi10.save("C:/Users/etu/Desktop/16DistMont.png");

    newqi11.save("C:/Users/etu/Desktop/1DistPente.png");
    newqi12.save("C:/Users/etu/Desktop/2DistPente.png");
    newqi13.save("C:/Users/etu/Desktop/4DistPente.png");
    newqi14.save("C:/Users/etu/Desktop/8DistPente.png");*/
    newqi15.save("C:/Users/etu/Desktop/16DistPenteV3.png");

    std::cout << "fin" << std::endl;
    return 0;
}

