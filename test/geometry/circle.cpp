#include <doctest/doctest.h>

#include <glg/geometry/circle.hpp>

TEST_CASE ("circle") {
    glg::circle c1{};
    CHECK_EQ(c1.center, glm::vec2(0.0f));
    CHECK_EQ(c1.radius, 1.0f);

    glg::dcircle c2{};
    CHECK_EQ(c2.center, glm::dvec2(0.0));
    CHECK_EQ(c2.radius, 1.0);

    glg::circle c3{glm::vec2(1.5f)};
    CHECK_EQ(c3.center, glm::vec2(1.5f));
    CHECK_EQ(c3.radius, 1.0f);

    glg::circle c4{1.5f};
    CHECK_EQ(c4.center, glm::vec2(0.0f));
    CHECK_EQ(c4.radius, 1.5f);


    glg::circle c5{glm::vec2(1.5f), 2.0f};
    CHECK_EQ(c5.center, glm::vec2(1.5f));
    CHECK_EQ(c5.radius, 2.0f);
}