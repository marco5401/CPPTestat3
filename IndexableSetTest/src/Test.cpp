#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "IndexableSet.h"

void test_empty_constructor() {
	IndexableSet::indexableSet<int> set{};
	ASSERT_EQUAL(0, set.size());
}

void test_range_constructor() {
	int my_range[] = {1,2,3,4,5};
	IndexableSet::indexableSet<int> set{my_range, my_range+5};

	ASSERT_EQUAL(5, set.size());
}

void test_copy_constructor() {
	int my_range[] = {1,2,3,4,5};
	IndexableSet::indexableSet<int> first_set{my_range, my_range+5};

	IndexableSet::indexableSet<int> second_set{first_set};
	ASSERT_EQUAL(5, second_set.size());
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(test_empty_constructor));
	s.push_back(CUTE(test_range_constructor));
	s.push_back(CUTE(test_copy_constructor));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner { cute::makeRunner(lis, argc, argv) };
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
