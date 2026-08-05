#include <cstdint>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	//	Payload Length : 4 bytes
	//	Command Type : 1 byte
	//	Chunk ID : 16 bytes
	//	Raw Data : variable

	uint32_t payloadLength = 0x12345678;
	uint8_t commandType = 1;

	std::cout << "sizeof(uint32_t)"<<sizeof(payloadLength)<<"bytes\n";
	std::cout << "sizeof(uint8_t)" << sizeof(commandType) << "bytes\n";

	std::cout << "\nMemory bytes of payloadLength : \n";

	const unsigned char* bytes = reinterpret_cast<const unsigned char*>(&payloadLength);
	for (size_t i = 0; i < sizeof(payloadLength); ++i) {
		std::cout << "Byte " << i << ": " << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[i]) <<" "<< "\n";
	}

	/*uint32_t test = 0x12345678;
	cout << "test : " << test << endl;
	const unsigned char* bytes = reinterpret_cast<const unsigned char*>(&test);
	cout << "bytes : " << *(bytes) << endl;
	cout << "bytes[0] : " << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[0]) << endl;
	cout << "bytes[1] : " << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[1]) << endl;
	cout << "bytes[3] : " << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[2]) << endl;
	cout << "bytes[4] : " << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[3]) << endl;*/

	// Pointers & References
	//int a = 10;
	//int* b = &a; // pointer to a
	//cout << "Value of a: " << *b << endl;
	//int arr[] = { 10, 20, 30 };
	//int* p = arr;

	//std::cout << *p << '\n';       // 10
	//std::cout << *(p + 1) << '\n'; // 20
	//std::cout << *(p + 2) << '\n'; // 30

	std::cout << "\n";
	return 0;
}