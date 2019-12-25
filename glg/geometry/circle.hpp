#ifndef GLG_CIRCLE_HPP
#define GLG_CIRCLE_HPP

#include "nsphere.hpp"

namespace glg {
    template <typename T>
    using tcircle = nsphere<2, T>;

    using circle = tcircle<float>;
    using dcircle = tcircle<double>;
}

#endif //GLG_CIRCLE_HPP
