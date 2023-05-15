#include <iostream>
#include <vector>
#include <string>

using namespace std;

const unsigned int cRightDirection = 1;
const unsigned int cBottomDirection = 2;
const unsigned int cAnyDirection = cRightDirection + cBottomDirection;

size_t get_ship_size(vector<string> &m, size_t i, size_t j, unsigned int direction) {
	if (m[i][j] == '.') // not a ship
		return 0;

	m[i][j] = '.';

	if ((direction & cRightDirection) && j + 1 < m[i].size() && m[i][j + 1] != '.') // right
		return get_ship_size(m, i, j + 1, cRightDirection) + 1;
	if ((direction & cBottomDirection) && i + 1 < m.size() && m[i + 1][j] != '.') // bottom
		return get_ship_size(m, i + 1, j, cBottomDirection) + 1;

	return 1;
}

vector<size_t> get_ships(vector<string> &m, size_t max_ship_size) {
	vector<size_t> ships(max_ship_size);

	for (size_t i = 0; i < m.size(); i++) {
		for (size_t j = 0; j < m[i].size(); j++) {
			if (size_t size = get_ship_size(m, i, j, cAnyDirection); size > 0) { // ship detected
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

	const size_t cMaxShipSize = 3;
	vector<size_t> ships = get_ships(sea, cMaxShipSize);

	for (size_t i = 0; i < ships.size(); i++) {
		cout << (i + 1) << ": " << ships[i] << endl;
	}

	return 0;
}
