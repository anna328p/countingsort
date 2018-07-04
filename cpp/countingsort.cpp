#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

std::vector<int> sort(std::vector<int> input) {
	auto it = max_element(std::begin(input), std::end(input));
	std::vector<int> counts(*it + 1, 0);
	std::vector<int> output;
	for (auto i : input) {
		counts[i]++;
	}
	for (size_t i = 0; i < input.size(); i++) {
		for (int j = 0; j < counts[i]; j++) {
			output.push_back(i);
		}
	}
	return output;
}

int main(int argc, char** argv) {
	std::vector<int> inputs;
	for (int i = 1; i < argc; i++) {
		inputs.push_back(atoi(argv[i]));
	}
	for (auto i : inputs) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	auto outputs = sort(inputs);
	for (auto i : outputs) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
}
