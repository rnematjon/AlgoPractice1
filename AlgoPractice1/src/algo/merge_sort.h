#pragma once

#include <vector>

template <typename T>
class merge_sort
{
	std::vector<T> vec;

	merge_sort() = delete;									// default ctor
	merge_sort(const merge_sort&) = delete;					// copy ctor
	merge_sort& operator=(const merge_sort&) = delete;		// assigment operator

public:
	merge_sort(const std::vector<T>& vec)
	{
		this->vec = vec;
	}

	const std::vector<T> get_sorted_vector() const
	{
		return this->vec;
	}

	void sort()
	{
		this->divide(this->vec, 0, this->vec.size() - 1);
	}

private:
	void divide(std::vector<T>& vec, int left, int right)
	{
		if (left >= right)
			return;
		
		int mid = (left + right) / 2;
		divide(vec, left, mid);
		divide(vec, mid + 1, right);

		merge(vec, left, right);
	}

	void merge(std::vector<T>& vec, int left, int right)
	{
		int mid = (left + right) / 2;
		int j = mid+1;

		if (vec[mid] <= vec[j])
			return;

		while (left <= mid && j<= right)
		{
			if (vec[left] <= vec[j])
			{
				left++;
			}
			else
			{
				T temp = vec[j];
				int idx = j;
				while (left != idx)
				{
					vec[idx] = vec[idx - 1];
					idx--;
				}

				vec[left] = temp;
				left++;
				mid++;
				j++;
			}
		}
	}
};