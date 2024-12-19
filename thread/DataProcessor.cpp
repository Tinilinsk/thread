#include "DataProcessor.h"

DataProcessor::DataProcessor(const std::vector<int>& tablica, int start, int end): _tablica(tablica), _start(start), _end(end)
{
	sum = 0;
}

void DataProcessor::process()
{
	for (int i = _start; i <= _end && i < _tablica.size(); i++) {
		//std::cout << _tablica[i] << "\n";
		sum = sum + _tablica[i];
	}
}

int DataProcessor::getResult() const
{
	return sum;
}
