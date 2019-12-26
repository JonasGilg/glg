#ifndef GLG_ALGORITHM_NSPHERE_HPP
#define GLG_ALGORITHM_NSPHERE_HPP

#include <glm/gtc/constants.hpp>
#include <glm/trigonometric.hpp>

#include "../geometry/nsphere.hpp"
#include "../geometry/circle.hpp"
#include "../geometry/sphere.hpp"

namespace glg {
    /// The length of the longest arc surrounding the n-sphere.
    template<int L, typename T>
    T circumference(glg::nsphere<L, T> const &ns) {
        return ns.radius * glm::two_pi<T>();
    }

    /// The area enclosed by the circle.
    template<typename T>
    T area(glg::tcircle<T> const &c) {
        return glm::pi<T>() * c.radius * c.radius;
    }

    /// The surface area of the sphere.
    template<typename T>
    T area(glg::tsphere<T> const &s) {
        return static_cast<T>(4.0) * glm::pi<T>() * s.radius * s.radius;
    }

    /// The volume enclosed by the sphere.
    template<typename T>
    T volume(glg::tsphere<T> const &s) {
        return static_cast<T>(4.0 / 3.0) * glm::pi<T>() * s.radius * s.radius * s.radius;
    }

    /// The distance from the n-sphere center to the given position.
    template<int L, typename T>
    T centerDistance(glg::nsphere<L, T> const &ns, glm::vec<L, T> const &pos) {
        return glm::distance(ns.center, pos);
    }

    /// The shortest distance between the surface of the n-sphere and the given position.
    template<int L, typename T>
    T surfaceDistance(glg::nsphere<L, T> const &ns, glm::vec<L, T> const &pos) {
        return glm::distance(ns.center, pos) - ns.radius;
    }

    /// The angular L of the n-sphere as seen from the given position.
    template<int L, typename T>
    T angularRadius(glg::nsphere<L, T> const &ns, glm::vec<L, T> const &pos) {
        return static_cast<T>(2.0) * glm::asin(ns.radius / glg::centerDistance(ns, pos));
    }

    /// Distance between two n-sphere centers.
    template<int L, typename T>
    T centerDistance(glg::nsphere<L, T> const &ns1, glg::nsphere<L, T> const &ns2) {
        return glm::distance(ns1.center, ns2.center);
    }

    /// Distance between two n-sphere surfaces.
    template<int L, typename T>
    T surfaceDistance(glg::nsphere<L, T> const &ns1, glg::nsphere<L, T> const &ns2) {
        return glm::distance(ns1.center, ns2.center) - ns1.radius - ns2.radius;
    }

    /// True if the given n-spheres intersect.
    template<int L, typename T>
    bool isIntersecting(glg::nsphere<L, T> const &ns1, glg::nsphere<L, T> const &ns2) {
        return glg::centerDistance(ns1, ns2) <= ns1.radius + ns2.radius;
    }

    /// True if the given position is inside the n-sphere.
    template<int L, typename T>
    bool contains(glg::nsphere<L, T> const& ns, glm::vec<L, T> const& pos) {
        return glm::distance(ns.center, pos) < ns.radius;
    }

    /// True if the second n-sphere is completely inside the first n-sphere.
    template<int L, typename T>
    bool contains(glg::nsphere<L, T> const& ns1, glg::nsphere<L, T> const& ns2) {
        return glm::distance(ns1.center, ns2.center) + ns2.radius < ns1.radius;
    }
}

#endif // GLG_ALGORITHM_NSPHERE_HPP
