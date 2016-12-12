#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "IndexableSet.h"

const int default_range[] = {1, 2, 3, 4, 5};
const int default_range_size = sizeof(default_range) / sizeof(int);

void test_empty_constructor() {
	/*
	 * Constructs an empty container, with no elements.
	 * Source: www.cplusplus.com/reference/set/set
	 */
	indexable_set::indexable_set<int> set{};
	ASSERT_EQUAL(0, set.size());
}

void test_range_constructor() {
	/*
	 * Constructs a container with as many elements as the range [first,last),
	 * with each element emplace-constructed from its corresponding element in that range.
	 * Source: www.cplusplus.com/reference/set/set
	 */

	indexable_set::indexable_set<int> set{default_range, default_range + default_range_size};

	ASSERT_EQUAL(5, set.size());
}

void test_copy_constructor() {
	/*
	 * Constructs a container with a copy of each of the elements in x.
	 * Source: www.cplusplus.com/reference/set/set
	 */
	indexable_set::indexable_set<int> first_set{default_range, default_range + default_range_size};

	indexable_set::indexable_set<int> second_set{first_set};
	ASSERT_EQUAL(5, second_set.size());
}


void test_copy_constructor_copies() {

	indexable_set::indexable_set<int> first_set{default_range, default_range + default_range_size};
	indexable_set::indexable_set<int> second_set{first_set};

	ASSERT_EQUAL(1, second_set[0]);
	ASSERT_EQUAL(5, second_set.size());
}

// endregion

void test_move_constructor() {
	/*
	 * Constructs a container that acquires the elements of x.
	 * If alloc is specified and is different from x's allocator, the elements are moved.
	 * Otherwise, no elements are constructed (their ownership is directly transferred).
	 * x is left in an unspecified but valid state.
	 * Source: www.cplusplus.com/reference/set/set
	 */
	ASSERT(false);
}

void test_initializer_list_constructor() {
	/*
	 * Constructs a container with a copy of each of the elements in il.
	 * Source: www.cplusplus.com/reference/set/set
	 */
	ASSERT(false);
}

void test_index_access() {
	indexable_set::indexable_set<int> my_set{default_range, default_range + default_range_size};

	ASSERT_EQUAL(2, my_set[1]);
}

void test_index_access_sorted_order() {
	const int my_array[]{3, 4, 1, 2, 5};
	indexable_set::indexable_set<int> my_set{my_array, my_array + 5};

	ASSERT_EQUAL(2, my_set[1]);
}

void test_index_access_reverse() {
	indexable_set::indexable_set<int> my_set{default_range, default_range + default_range_size};

	ASSERT_EQUAL(5, my_set[-1]);
}

void test_front() {
	indexable_set::indexable_set<int> my_set{default_range, default_range + default_range_size};

	ASSERT_EQUAL(1, my_set.front());
}

void test_back() {
	indexable_set::indexable_set<int> my_set{default_range, default_range + default_range_size};

	ASSERT_EQUAL(5, my_set.back());
}

void test_out_of_bounds() {
	indexable_set::indexable_set<int> my_set{default_range, default_range + default_range_size};

	ASSERT_THROWS(my_set[5], std::out_of_range);
}

void test_out_of_bounds_min() {
	indexable_set::indexable_set<int> my_set{default_range, default_range + default_range_size};

	ASSERT_THROWS(my_set[-6], std::out_of_range);
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(test_empty_constructor));
	s.push_back(CUTE(test_range_constructor));
	s.push_back(CUTE(test_copy_constructor));
	s.push_back(CUTE(test_copy_constructor_copies));
	s.push_back(CUTE(test_index_access));
	s.push_back(CUTE(test_index_access_reverse));
	s.push_back(CUTE(test_index_access_sorted_order));
	s.push_back(CUTE(test_front));
	s.push_back(CUTE(test_back));
	s.push_back(CUTE(test_out_of_bounds));
	s.push_back(CUTE(test_out_of_bounds_min));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner { cute::makeRunner(lis, argc, argv) };
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
