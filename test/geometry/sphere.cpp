#include <doctest/doctest.h>

#include <glg/geometry/sphere.hpp>

TEST_CASE ("sphere") {
    glg::sphere c1{};
    CHECK_EQ(c1.center, glm::vec3(0.0f));
    CHECK_EQ(c1.radius, 1.0f);

    glg::dsphere c2{};
    CHECK_EQ(c2.center, glm::dvec3(0.0));
    CHECK_EQ(c2.radius, 1.0);

    glg::sphere c3{glm::vec3(1.5f)};
    CHECK_EQ(c3.center, glm::vec3(1.5f));
    CHECK_EQ(c3.radius, 1.0f);

    glg::sphere c4{1.5f};
    CHECK_EQ(c4.center, glm::vec3(0.0f));
    CHECK_EQ(c4.radius, 1.5f);


    glg::sphere c5{glm::vec3(1.5f), 2.0f};
    CHECK_EQ(c5.center, glm::vec3(1.5f));
    CHECK_EQ(c5.radius, 2.0f);
}