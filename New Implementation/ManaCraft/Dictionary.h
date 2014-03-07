#pragma once
#include "Includes.h"

template<class T>
class Dictionary
{
private:
	std::vector<std::string> keys;
	std::vector<T> values;
public:
	Dictionary()
	{
		keys = new std::vector<std::string>{};
		values = new std::vector<T>{};
	}

	~Dictionary()
	{
		delete[] keys;
		delete[] values;
	};

	std::vector* Values() { return &values; };
	std::vector* Keys() { return &keys; };

	size_t size() { return keys.size(); }

	void Add(std::string _key, T value)
	{
		keys.push_back(_key);
		values.push_back(value);
	};
	void Remove(std::string _key)
	{
		for (size_t i = 0; i < keys.size(); i++)
		{
			if (keys.at(i) == _key)
			{
				keys.erase(keys.begin() + i);
				values.erase(values.begin() + i);
				break;
			}
		}
	};
	T Get(std::string _key)
	{
		for (size_t i = 0; i < keys.size(); i++)
		{
			if (keys.at(i) == _key)
			{
				return values.at(i);
			}
		}
		return nullptr;
	};
};

