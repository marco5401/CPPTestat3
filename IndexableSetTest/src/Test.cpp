#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "IndexableSet.h"

void test_empty_constructor() {
	/*
	 * Constructs an empty container, with no elements.
	 */
	indexable_set::indexable_set<int> set{};
	ASSERT_EQUAL(0, set.size());
}

void test_range_constructor() {
	/*
	 * Constructs a container with as many elements as the range [first,last),
	 * with each element emplace-constructed from its corresponding element in that range.
	 */

	int my_range[] = {1,2,3,4,5};
	indexable_set::indexable_set<int> set{my_range, my_range+5};

	ASSERT_EQUAL(5, set.size());
}

void test_copy_constructor() {
	/*
	 * Constructs a container with a copy of each of the elements in x.
	 */
	int my_range[] = {1,2,3,4,5};
	indexable_set::indexable_set<int> first_set{my_range, my_range+5};

	indexable_set::indexable_set<int> second_set{first_set};
	ASSERT_EQUAL(5, second_set.size());
}

void test_move_constructor() {
	/*
	 * Constructs a container that acquires the elements of x.
	 * If alloc is specified and is different from x's allocator, the elements are moved.
	 * Otherwise, no elements are constructed (their ownership is directly transferred).
	 * x is left in an unspecified but valid state.
	 */
	ASSERT(true);
}

void test_initializer_list_constructor() {
	/*
	 * Constructs a container with a copy of each of the elements in il.
	 */
	ASSERT(true);
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(test_empty_constructor));
	s.push_back(CUTE(test_range_constructor));
	s.push_back(CUTE(test_copy_constructor));
	s.push_back(CUTE(test_move_constructor));
	s.push_back(CUTE(test_initializer_list_constructor));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner { cute::makeRunner(lis, argc, argv) };
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
