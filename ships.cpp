#include <iostream>
#include <vector>
#include <string>

using namespace std;

size_t get_ship_size(vector<string> &m, size_t i, size_t j) {
	if (m[i][j] == '.') // not a ship
		return 0;

	m[i][j] = '.';
	size_t size = 1;

	if (j + 1 < m[i].size())
		size += get_ship_size(m, i, j + 1);
	if (i + 1 < m.size())
		size += get_ship_size(m, i + 1, j);
	if (j > 0)
		size += get_ship_size(m, i, j - 1);
	if (i > 0)
		size += get_ship_size(m, i - 1, j);

	return size;
}

vector<size_t> get_ships(vector<string> &m, int max_size) {
	vector<size_t> ships(max_size);
	
	for (size_t i = 0; i < m.size(); i++) {
		for (size_t j = 0; j < m[i].size(); j++) {
			if (size_t size = get_ship_size(m, i, j); size > 0) { // ship detected
				ships[size - 1]++;
			}
		}
	}

	return ships;
}

int main(int argc, const char * argv[]) {
	vector<string> sea {
		"....x..x"s,
		".x.xx..x"s,
		".......x"s,
		".xx.xx.."s,
		"..x....x"s
	};

	for (auto &s: sea) {
		cout << s << endl;
	}

	auto ships = get_ships(sea, 3);

	for (size_t i = 0; i < ships.size(); i++) {
		cout << (i + 1) << ": " << ships[i] << endl;
	}

	return 0;
}
