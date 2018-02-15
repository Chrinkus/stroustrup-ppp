//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Exercise 2
//
// List every standard library algorithm. Possibly give examples?
//

/* <algorithm>
 * all_of       test condition on all elements in range
 * any_of       test if any element in range fulfills condition
 * none_of      test if no elements fulfill condition
 * for_each     apply a function to a range
 * find         find a value in a range
 * find_if      find element in range
 * find_if_not
 * find_end
 * find_first_of
 * adjacent_find
 * count
 * count_if
 * mismatch
 * equal
 * is_permutation
 * search
 * search_n
 *
 * copy
 * copy_n
 * copy_if
 * copy_backward
 * move
 * move_backward
 * swap
 * swap_ranges
 * iter_swap
 * transform
 * replace
 * replace_if
 * replace_copy
 * replace_copy_if
 * fill
 * fill_n
 * generate
 * generate_n
 * remove
 * remove_if
 * remove_copy
 * remove_copy_if
 * unique
 * unique_copy
 * reverse
 * reverse_copy
 * rotate
 * rotate_copy
 * random_shuffle
 * shuffle
 *
 * is_partitioned
 * partition
 * stable_partition
 * partition_copy
 * partition_point
 *
 * sort
 * stable_sort
 * partial_sort
 * partial_sort_copy
 * is_sorted
 * is_sorted_until
 * nth_element
 *
 * lower_bound
 * upper_bound
 * equal_range
 * binary_search
 *
 * merge
 * inplace_merge
 * includes
 * set_union
 * set_intersection
 * set_difference
 * set_symmetric_difference
 *
 * push_heap
 * pop_heap
 * make_heap
 * sort_heap
 * is_heap
 * is_heap_until
 *
 * min
 * max
 * minmax
 * min_element
 * max_element
 * minmax_element
 *
 * lexicographical_compare
 * next_permutation
 * prev_permutation 
 */

#include <iostream>
#include <stdexcept>

int main()
try {
    // code
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

