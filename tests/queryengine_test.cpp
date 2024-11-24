#include "queryengine.h"
#include <vector>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Parse query string") {
	QueryEngine qe;

	SUBCASE("Simple input with two words") {
		std::vector<std::string> result = qe.parse_query("Hello Tests");
		CHECK(result.size() == 2);
	}
}
