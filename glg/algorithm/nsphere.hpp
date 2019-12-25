#ifndef GLG_ALGORITHM_NSPHERE_HPP
#define GLG_ALGORITHM_NSPHERE_HPP

#include <glm/gtc/constants.hpp>
#include <glm/trigonometric.hpp>

#include "../geometry/nsphere.hpp"
#include "../geometry/circle.hpp"
#include "../geometry/sphere.hpp"

namespace glg {
    /// The length of the longest arc surrounding the n-sphere.
    template<int Size, typename T>
    T circumference(nsphere<Size, T> const& ns) {
        return ns.radius * glm::two_pi<T>();
    }

    /// The area enclosed by the circle.
    template<typename T>
    T area(tcircle<T> const& c) {
        return glm::pi<T>() * c.radius * c.radius;
    }

    /// The surface area of the sphere.
    template<typename T>
    T area(tsphere<T> const& s) {
        return static_cast<T>(4.0) * glm::pi<T>() * s.radius * s.radius;
    }

    /// The volume enclosed by the sphere.
    template<typename T>
    T volume(tsphere<T> const& s) {
        return static_cast<T>(4.0 / 3.0) * glm::pi<T>() * s.radius * s.radius * s.radius;
    }

    /// The distance from the n-sphere center to the given position.
    template<int Size, typename T>
    T centerDistance(nsphere<Size, T> const& ns, glm::vec<Size, T> const& pos) {
        return glm::length(ns.center, pos);
    }

    /// The shortest distance between the surface of the n-sphere and the given position.
    template<int Size, typename T>
    T surfaceDistance(nsphere<Size, T> const& ns, glm::vec<Size, T> const& pos) {
        return glm::length(ns.center, pos) - ns.radius;
    }

    /// The angular size of the n-sphere as seen from the given position.
    template<int Size, typename T>
    T angularRadius(nsphere<Size, T> const& ns, glm::vec<Size, T> const& pos) {
        return static_cast<T>(2.0) * glm::asin(ns.radius / centerDistance(ns, pos));
    }
}

#endif // GLG_ALGORITHM_NSPHERE_HPP
