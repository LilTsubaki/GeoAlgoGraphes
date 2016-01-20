#include "terrainimage.h"
#include <QColor>
#include <iostream>
#include <cmath>
#include <QPixmap>
#include <QPainter>

TerrainImage::TerrainImage(const QImage& i, double bl, double no, const Vector2D& a, const Vector2D& b):Terrain(a,b), blanc(bl), noir(no)
{

    h=i.height();
    w=i.width();
    mat.resize(h*w);
    for(int j=0;j<h;j++){
        for(int k=0;k<w;k++){
            QRgb p=i.pixel(k,h-j-1);
            quint8 c=(quint8)qGray(p);
            mat[k+w*j] = c;
        }
    }

}

double TerrainImage::getHauteur(const Vector2D &p) const
{
    Vector2D pTmp=p-a;
    pTmp.setX(pTmp.x()/(b.x()-a.x()));
    pTmp.setY(pTmp.y()/(b.y()-a.y()));
    double u=pTmp.x();
    double v=pTmp.y();
    double rx = (u*(w-1));
    double ry=(v*(h-1));
    int i =(int) rx;
    rx-=i;
    int j = (int) ry;
    ry -= j;

    if(i<0||j<0||i>w-1||j>h-1){
        return 0;
    }

    double z=(1-rx)*(1-ry)*((double)mat[j*w+i])+
                rx*(1-ry)*((double)mat[j*w+i+1])+
                (1-rx)*ry*((double)mat[(j+1)*w+i])+
                rx*ry*((double)mat[(j+1)*w+i+1]);

    return noir +(z*(blanc-noir)/255.0);
}



double TerrainImage::getPenteMax() const
{

    double pasx=(b.x()-a.x())/w;
    double pasy=(b.y()-a.y())/h;
    double max=0;
    for(int i=0;i<h-1;i++){
        for(int j=0;j<w-1;j++){
            double tmp=abs((int)(mat[i*w+j])-(int)(mat[(i+1)*w+j]))/pasy;
            if(max<tmp){
                max=tmp;
            }
            tmp=abs((int)(mat[i*w+j])-(int)(mat[i*w+j+1]))/pasx;
            if(max<tmp){
                max=tmp;
            }
        }
    }
    return max;
}

double TerrainImage::distance(const Vector2D &p1, const Vector2D &p2,int e)
{
    double dist=0;
    for(int i=0;i<e-1;++i){
        double f1=((double)i)/(e-1);
        double f2=((double)i+1)/(e-1);
        Vector2D po1=p1*f1+p2*(1-f1);
        Vector2D po2=p1*f2+p2*(1-f2);

        double h1=getHauteur(po1);
        double h2=getHauteur(po2);
        dist+= Vector3D(po1,h1).distanceToPoint(Vector3D(po2,h2));

    }

    return dist;
}

bool TerrainImage::addVille(QImage& im,const QVector<Vector2D>& list,double rayon)
{
    int width=im.width();
    int height=im.height();
    double min = getHauteurMin();
    double max = getHauteurMax();
    Vector2D a = getA();
    Vector2D b = getB();

    for(float i = 0; i <width; i++)
    {
        for(float j = 0; j < height; j++)
        {
            Vector2D p(a.x()*((width-1-i)/width)+b.x()*(1-(width-1-i)/width),a.y()*(j/height)+b.y()*(1-j/height));
            bool isIn=false;
            for(int k=0;k<list.size();++k){
                if(list[k].distanceToPoint2DSquared(p)<=rayon*rayon){

                    isIn=true;
                    break;
                }
            }
            if(isIn)
            im.setPixel(i,j,QColor(0,255,0,255).rgba());
        }
    }
    return true;
}


QImage TerrainImage::drawImage(int width, int height)
{
    QImage im(width, height, QImage::Format_ARGB32);
    double min = getHauteurMin();
    double max = getHauteurMax();
    Vector2D a = getA();
    Vector2D b = getB();

    for(float i = 0; i <width; i++)
    {
        for(float j = 0; j < height; j++)
        {
            Vector2D p(a.x()*((width-1-i)/width)+b.x()*(1-(width-1-i)/width),a.y()*(j/height)+b.y()*(1-j/height));
            double h=getHauteur(p);
            int col=(int)((h-min)/(max-min)*255);
            //std::cout << col << std::endl;
            im.setPixel(i,j,QColor(col,col,col,255).rgba());
        }
    }
    return im;
}

void TerrainImage::drawRoad(QVector<Vector2D> cities, QImage& imgRaw)
{

    QPainter p;
    p.begin(&imgRaw);
    p.setPen (Qt::red);

    Vector2D a = getA();
    Vector2D BMoinsA = getB() - a;

    for(int i = 0; i < cities.size(); i+=2)
    {
        double x1 = (cities[i].x()-a.x())/BMoinsA.x();
        double y1 = (cities[i].y()-a.y())/BMoinsA.y();
        double x2 = (cities[i+1].x()-a.x())/BMoinsA.x();
        double y2 = (cities[i+1].y()-a.y())/BMoinsA.y();

        x1 *= imgRaw.width();
        y1 = (1-y1)*imgRaw.height();
        x2 *= imgRaw.width();
        y2 = (1-y2)*imgRaw.height();

        p.drawLine (x1, y1, x2, y2);

    }
    p.end ();
}
