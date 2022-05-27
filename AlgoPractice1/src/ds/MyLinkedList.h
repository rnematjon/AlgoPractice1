#pragma once
#include <iostream>
#include <exception>

template <typename T>
struct node
{
	T data;
	node<T>* next;
};

template <typename T>
class my_linked_list
{
	node<T>* head;
	int size;
public:
	my_linked_list()
	{
		this->head = nullptr;
		this->size = 0;
	}

	~my_linked_list()
	{
		while (this->head)
		{
			auto trav = this->head;
			this->head = this->head->next;
			delete trav;
		}
	}

	void insert(T t)			// at the end
	{
		this->insert(t, size);
	}

	void insert(T t, int pos)  // by position
	{
		if (!this->head)
		{
			this->head = new node<T>();
			this->head->data = t;
			this->head->next = nullptr;
			this->size++;
			return;
		}

		auto nod = new node<T>();
		nod->data = t;
		nod->next = nullptr;

		auto trav = this->head;
		if (pos == 0)
		{
			this->head = nod;
			this->head->next = trav;
			this->size++;
			return;
		}
		else
		{
			for (int i = 0; i < pos-1; i++)
			{
				if (!trav->next) // before pos
				{
					trav->next = nod;
					this->size++;
					return;
				}
				else trav = trav->next;
			}

			auto tmp = trav->next;
			trav->next = nod;
			nod->next = tmp;
			this->size++;
		}
	}

	T remove(int pos)
	{
		if(pos<0 || pos>=size)
			throw new std::exception("invalid index!");

		if (pos == 0)
		{
			// remove head;
			if (this->head)
			{
				auto tmp = this->head->next;
				auto data = this->head->data;
				delete this->head;
				this->head = tmp;
				this->size--;
				return data;
			}

			throw new std::exception("list is empty!");
		}

		auto trav = this->head;
		auto prev = this->head;
		for (int i = 0; i < pos - 1; i++)
		{
			if (trav->next)
			{
				prev = trav;
				trav = trav->next;
			}
			else break;

		}

		auto data = trav->data;
		prev->next = trav->next;
		delete trav;
		this->size--;
		return data;
	}

	void reverse()
	{
		// (1) -> (2) -> (3) -> ....  ->(n);
		auto trav = this->head;
		node<T>* next = nullptr;
		node<T>* res = nullptr;
		while (trav)
		{		
			// remember next
			next = trav->next;
			
			// Link trav next to previous node
			trav->next = res;

			res = trav; // previous node
			trav = next; // traverse to next 
		}

		this->head = res;
	}

	void print()
	{
		std::cout << "[";
		auto trav = this->head;
		while (trav)
		{
			std::cout << trav->data;
			if (trav->next)
			{
				std::cout << ",";
			}
			trav = trav->next;
		}
		std::cout << "]" << std::endl;
	}
	
	int get_size()const
	{
		return this->size;
	}
};

