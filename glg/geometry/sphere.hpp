#ifndef GLG_SPHERE_HPP
#define GLG_SPHERE_HPP

#include "nsphere.hpp"

namespace glg {
    template <typename T>
    using tsphere = nsphere<3, T>;

    using sphere = tsphere<float>;
    using dsphere = tsphere<double>;
}

#endif //GLG_SPHERE_HPP
