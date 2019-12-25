#ifndef GLG_GEOMETRY_CIRCLE_HPP
#define GLG_GEOMETRY_CIRCLE_HPP

#include "nsphere.hpp"

namespace glg {
    template <typename T>
    using tcircle = nsphere<2, T>;

    using circle = tcircle<float>;
    using dcircle = tcircle<double>;
}

#endif // GLG_GEOMETRY_CIRCLE_HPP
