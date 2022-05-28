#pragma once

#include<vector>

template <typename T>
class quick_sort
{
public:
	quick_sort() = default;

	void sort(std::vector<T> & vec)
	{
		this->divide(vec, 0, vec.size() - 1);
	}

private:
	void divide(std::vector<T>& vec, int left, int right)
	{
		if (left < right)
		{
			auto pos = this->partition(vec, left, right);
			divide(vec, left, pos-1);
			divide(vec, pos + 1, right);
		}
	}

	int partition(std::vector<T>& vec, int left, int right)
	{
		auto pivot = vec[left];

		int i = left+1;
		int j = right;

		while (i < j)
		{
			while (i < right && vec[i] <= pivot)
			{
				i++;
			};

			while (j > left && pivot<vec[j])
			{
				j--;
			}

			if (i < j)
			{
				swap(vec, i, j);
			}
		}

		if(vec[left]>vec[j])
			swap(vec, left, j);
		return j;
	}

	void swap(std::vector<T>& vec, int i, int j)
	{
		if (i >= 0 && j >= 0 && i < vec.size() && j < vec.size()) 
		{
			auto temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
		}
	}
};