#include<iostream>
#include<iomanip>
#include<array>
#include<vector>
#include<cstdint>

using namespace std;	

void printBytes(const std::vector<uint8_t>& buffer) {
	for(uint8_t byte:buffer){
		std::cout << "0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
	}
	return;
}


void pushU32BigEndian(vector<uint8_t> &buffer,uint32_t payloadLength) {
	buffer.push_back((payloadLength >> 24) & 0xFF);
	buffer.push_back((payloadLength >> 16) & 0xFF);
	buffer.push_back((payloadLength >> 8) & 0xFF);
	buffer.push_back(payloadLength & 0xFF);
	return;
}

int main_03() {
	
	/*task one is to create a buffer that contains the following data in order :
	1. Payload Length : 4 bytes
	2. Command Type : 1 byte
	3. Chunk ID : 16 bytes*/
	vector<uint8_t> buffer;
	vector<uint8_t>body;
	vector<uint8_t> payloadLengthBytes(4);

	uint8_t commandType = 1;
	array<uint8_t, 16>chunkId{};
	chunkId[0] = 0xAA;
	chunkId[1] = 0xBB;
	chunkId[2] = 0xCC;
	chunkId[15] = 0xFF;
    
	body.push_back(commandType);

	for(uint8_t byte:chunkId){
		body.push_back(byte);
	}

	uint32_t payloadLength = static_cast<uint32_t>(body.size());

	pushU32BigEndian(buffer, payloadLength);

	for (uint8_t byte:body){
		buffer.push_back(byte);
	}

	std::cout << "Payload length decimal: "
		<< payloadLength
		<< "\n";

	std::cout << "Full buffer size: "
		<< buffer.size()
		<< " bytes\n";

	std::cout << "Full buffer bytes:\n";
	printBytes(buffer);

	// Now parse the payload length back from the first 4 bytes.
	uint32_t receivedLength =
		(static_cast<uint32_t>(buffer[0]) << 24) |
		(static_cast<uint32_t>(buffer[1]) << 16) |
		(static_cast<uint32_t>(buffer[2]) << 8) |
		(static_cast<uint32_t>(buffer[3]));

	std::cout << "\nParsed payload length: "
		<< dec << receivedLength
		<< "\n";

	return 0;

}

