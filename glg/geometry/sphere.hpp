#ifndef GLG_GEOMETRY_SPHERE_HPP
#define GLG_GEOMETRY_SPHERE_HPP

#include "nsphere.hpp"

namespace glg {
    template <typename T>
    using tsphere = nsphere<3, T>;

    using sphere = tsphere<float>;
    using dsphere = tsphere<double>;
}

#endif // GLG_GEOMETRY_SPHERE_HPP
