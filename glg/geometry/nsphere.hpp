#ifndef GLG_GEOMETRY_NSPHERE_HPP
#define GLG_GEOMETRY_NSPHERE_HPP

#include <glm/glm.hpp>

namespace glg {
    template<int Size, typename T>
    struct nsphere {
        nsphere() : center(static_cast<T>(0.0)), radius(static_cast<T>(1.0)) {}

        nsphere(glm::vec<Size, T> const &center) : center(center), radius(static_cast<T>(1.0)) {}

        nsphere(T radius) : center(static_cast<T>(0.0)), radius(radius) {}

        nsphere(glm::vec<Size, T> const &center, T radius) : center(center), radius(radius) {}

        glm::vec<Size, T> center;
        T radius;
    };
}

#endif // GLG_GEOMETRY_NSPHERE_HPP
