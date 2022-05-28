#include <iostream>
#include "src/util/random_generator.h"
#include "src/util/print_vector.h"
#include "src/algo/merge_sort.h"
#include "src/algo/quick_sort.h"

void test_merge_sort()
{
	typedef int64_t mytype;

	//std::vector<mytype> vec{9,7,2,1,6,5,8,4,4,4,5,6,7};
	auto vec = generate_random<mytype>(20, 1, 1000);
	print_vector<mytype>(vec);

	merge_sort<mytype> ms(vec);
	ms.sort();
	print_vector<mytype>(ms.get_sorted_vector());
}

void test_quick_sort()
{
	typedef int mytype;

	//std::vector<mytype2> vec{6,10,2,13,5,8,1,7,9};
	auto vec = generate_random<mytype>(20, 1, 1000);
	print_vector<mytype>(vec);

	quick_sort<mytype> qs;
	qs.sort(vec);
	print_vector<mytype>(vec);
}

int main()
{
	test_quick_sort();
	return 0;
}

