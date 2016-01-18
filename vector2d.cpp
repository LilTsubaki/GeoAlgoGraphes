#include "vector2d.h"
#include "mathutils.h"


Vector2D Vector2D::normalized() const
{
    double invlength = 1/length();
    return (*this)*invlength;
}

void Vector2D::normalize()
{
    double invlength = 1/length();
    (*this)*=invlength;
}

double Vector2D::distanceToLine(const Vector2D &point, const Vector2D &direction) const
{
    double t = -(point*direction-(*this)*direction)/(direction*direction);
    return (*this).distanceToPoint2D(Vector2D(point + t*direction));
}

Vector3D Vector2D::toVector3D() const
{
    return (*this);
}


QVector<Vector2D> Vector2D::randSquare(const Vector2D &min, const Vector2D &max, int nbPoints, double rayon)
{
    QVector<Vector2D> points;
    bool b = false;

    for(int i = 0; i < nbPoints*50; i++)
    {
        if(points.size() == nbPoints)
            break;

        double x = MathUtils::random(min.x(), max.x());
        double y = MathUtils::random(min.y(), max.y());
        Vector2D point(x,y);

        for(int j = 0; j < points.size(); j++)
        {
            if(point.distanceToPoint2DSquared(points[j]) < rayon *rayon * 4)
            {
                b = true;
            }
        }

        if(!b)
            points.push_back(point);

        b=false;
    }

    return points;
}
