#include <catch2/catch_all.hpp>
#include "calculator.h"

TEST_CASE("Тестирование функции evaluate", "[calculator]") {
    REQUIRE(evaluate("1 + 1") == 2);
    REQUIRE(evaluate("5 - 3") == 2);
    REQUIRE(evaluate("10 + 20 - 5") == 25);
}
