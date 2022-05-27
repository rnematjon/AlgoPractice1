#include <iostream>
#include "random_generator.h"
#include "print_vector.h"
#include "merge_sort.h"

int main()
{
	typedef int64_t mytype;

	auto vec = generate_random<mytype>(20,1,1000);
	//std::vector<mytype> vec{9,7,2,1,6,5,8,4,4,4,5,6,7};
	print_vector<mytype>(vec);


	merge_sort<mytype> ms(vec);
	ms.handle();
	print_vector<mytype>(ms.get_sorted_vector());

	return 0;
}
