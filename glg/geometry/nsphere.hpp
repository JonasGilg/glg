#ifndef GLG_GEOMETRY_NSPHERE_HPP
#define GLG_GEOMETRY_NSPHERE_HPP

#include <glm/glm.hpp>

namespace glg {

    /// An n-sphere is a class of geometric shapes defined by an n-dimensional point and a radius. Common shapes in this
    /// class are circles and spheres.
    template<int L, typename T>
    struct nsphere {
        nsphere() : center(static_cast<T>(0.0)), radius(static_cast<T>(1.0)) {}

        nsphere(glm::vec<L, T> const &center) : center(center), radius(static_cast<T>(1.0)) {}

        nsphere(T radius) : center(static_cast<T>(0.0)), radius(radius) {}

        nsphere(glm::vec<L, T> const &center, T radius) : center(center), radius(radius) {}

        glm::vec<L, T> center;
        T radius;
    };
}

#endif // GLG_GEOMETRY_NSPHERE_HPP
