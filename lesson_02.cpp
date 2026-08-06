#include<iostream>
#include<cstdint>
#include<iomanip>
#include<vector>
#include<array>

using namespace std;

void printBuffer(const vector<uint8_t>& buffer) {
	for (uint8_t byte : buffer) {
		cout << "0x" << hex << setw(2) << setfill('0') << static_cast<int>(byte) << " ";
	}
	cout << dec << "\n";
}

int main() {
	
	uint8_t command{ 0x01 };

	vector<uint8_t> buffer;

	array<uint8_t, 16> chunkId{};

	chunkId[0] = 0xAA;
	chunkId[1] = 0xBB;
	chunkId[2] = 0xCC;
	chunkId[15] = 0xFF;

	buffer.push_back(command);

	for (uint8_t byte:chunkId) {
		buffer.push_back(byte);
	}

	cout << "Buffer size: " << buffer.size() << " bytes\n";

	printBuffer(buffer);

	std::cout << "Payload length should be: "
		<< buffer.size()
		<< "\n";



	return 0;
}	

