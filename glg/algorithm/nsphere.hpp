#ifndef GLG_ALGORITHM_NSPHERE_HPP
#define GLG_ALGORITHM_NSPHERE_HPP

#include <glm/gtc/constants.hpp>
#include "../geometry/nsphere.hpp"
#include "../geometry/circle.hpp"
#include "../geometry/sphere.hpp"

namespace glg {
    template<int Size, typename T>
    T circumference(nsphere<Size, T> const &nsphere) {
        return nsphere.radius * glm::two_pi<T>();
    }

    template<typename T>
    T area(tcircle<T> const& circle) {
        return glm::pi<T>() * circle.radius * circle.radius;
    }

    template<typename T>
    T area(tsphere<T> const& sphere) {
        return static_cast<T>(4.0) * glm::pi<T>() * sphere.radius * sphere.radius;
    }

    template<typename T>
    T volume(tsphere<T> const& sphere) {
        return static_cast<T>(4.0 / 3.0) * glm::pi<T>() * sphere.radius * sphere.radius * sphere.radius;
    }
}

#endif // GLG_ALGORITHM_NSPHERE_HPP
