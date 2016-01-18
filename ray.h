#ifndef RAY_H
#define RAY_H
#include "vector3d.h"
/**
 * @brief The Ray class
 */
class Ray
{
protected:
    static double pas;/**< The length used for Ray Marching of the Terrains*/
    Vector3D origine; /**< The origin of the Ray*/
    Vector3D direction;/**< The direction of the Ray, normalized*/
public:


    /**
     * Constructor of a Ray
     * @param[in] o the origin of the Ray
     * @param[in] d the direction of the Ray, is normalized by the constructor
     */
    Ray(const Vector3D &o, const Vector3D &d);

    /**
     * Gets the point corresponding to f times the direction vector from the origin, is inlined
     * @param[in] f the factor of the direction vector
     * @return origine + f * direction
     */
    Vector3D getPoint(double f) const;

    /**
     * Tries to intersect the Ray with a plane, described by two vectors, ab and ac
     * @param[in] a the first point on the plane
     * @param[in] b the second point on the plane
     * @param[in] c the third point on the plane
     * @param[out] out the point at the intersection of the Ray and the plane
     * @return true if the Ray intersects the plane, false else
     */
    bool intersects(const Vector3D& a, const Vector3D& b, const Vector3D& c, Vector3D& out) const;

    /**
     * Counts the intersections of the Ray with a box
     * @param[in] a the first corner describing the box
     * @param[in] b the second corner describing the box
     * @param[out] in the point on the box where the Ray enters
     * @param[out] out the point on the box where the Ray exits
     * @see intersects()
     * @return the number of intersections of the ray with the box. If 1, in will be the origin of the Ray and out the only intersection. If 0, do not consider in and out are reliable.
     */
    int intersectsBox(const Vector3D& a, const Vector3D& b, Vector3D& in, Vector3D& out) const;

    Vector3D getOrigine() const;

    Vector3D getDirection() const;

};

    inline Vector3D Ray::getPoint(double f) const{
        return origine+direction*f;
    }

    inline Vector3D Ray::getOrigine() const{
        return origine;
    }

    inline Vector3D Ray::getDirection() const{
        return direction;
    }

#endif // RAY_H
