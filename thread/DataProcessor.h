#pragma once
#include <vector>
#include <iostream>
#include <windows.h>


class DataProcessor
{
private: 
	std::vector<int> _tablica;
	int _start;
	int _end;
	int sum;
public:
	DataProcessor(const std::vector<int>& tablica, int start, int end);
	void process();
	int getResult() const;
};