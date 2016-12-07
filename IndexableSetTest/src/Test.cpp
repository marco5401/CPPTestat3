#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <set>

void testEmptyConstructor() {
	std::set<int> mySet{};
	ASSERT_EQUAL(0, mySet.size());
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(testEmptyConstructor));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner { cute::makeRunner(lis, argc, argv) };
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
