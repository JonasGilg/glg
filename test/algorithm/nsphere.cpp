#include <doctest/doctest.h>

#include <glm/gtc/constants.hpp>

#include <glg/geometry/circle.hpp>
#include <glg/geometry/sphere.hpp>
#include <glg/algorithm/nsphere.hpp>

namespace glg {
    TEST_CASE("circumference(nsphere)") {
        circle c1{};
        float r1 = circumference(c1);
        CHECK_EQ(r1, doctest::Approx(glm::two_pi<float>()));

        circle c2{2.0f};
        float r2 = circumference(c2);
        CHECK_EQ(r2, doctest::Approx(2.0f * glm::two_pi<float>()));

        sphere c3{2.0f};
        float r3 = circumference(c3);
        CHECK_EQ(r3, doctest::Approx(2.0f * glm::two_pi<float>()));

        sphere c4{0.0f};
        float r4 = circumference(c4);
        CHECK_EQ(r4, doctest::Approx(0.0f));

        circle c5{0.0f};
        float r5 = circumference(c5);
        CHECK_EQ(r5, doctest::Approx(0.0f));
    }

    TEST_CASE("area(circle)") {
        circle c1{};
        float r1 = area(c1);
        CHECK_EQ(r1, doctest::Approx(glm::pi<float>()));

        circle c2{2.0f};
        float r2 = area(c2);
        CHECK_EQ(r2, doctest::Approx(4.0f * glm::pi<float>()));

        circle c3{0.0f};
        float r3 = area(c3);
        CHECK_EQ(r3, doctest::Approx(0.0f));
    }

    TEST_CASE("area(sphere)") {
        sphere c1{};
        float r1 = area(c1);
        CHECK_EQ(r1, doctest::Approx(4.0f * glm::pi<float>()));

        sphere c2{2.0f};
        float r2 = area(c2);
        CHECK_EQ(r2, doctest::Approx(16.0f * glm::pi<float>()));

        sphere c3{0.0f};
        float r3 = area(c3);
        CHECK_EQ(r3, doctest::Approx(0.0f));
    }

    TEST_CASE("volume(sphere)") {
        sphere c1{};
        float r1 = volume(c1);
        CHECK_EQ(r1, doctest::Approx((4.0f / 3.0f) * glm::pi<float>()));

        sphere c2{2.0f};
        float r2 = volume(c2);
        CHECK_EQ(r2, doctest::Approx((4.0f / 3.0f) * glm::pi<float>() * 8.0f));

        sphere c3{0.0f};
        float r3 = volume(c3);
        CHECK_EQ(r3, doctest::Approx(0.0f));
    }
}