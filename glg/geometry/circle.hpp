#ifndef GLG_CIRCLE_HPP
#define GLG_CIRCLE_HPP

#include <glm/vec2.hpp>

namespace glg {
    template <typename T>
    struct tcircle {
        glm::tvec2<T> center;
        T radius;
    };

    using circle = tcircle<float>;
    using dcircle = tcircle<double>;
}

#endif //GLG_CIRCLE_HPP
