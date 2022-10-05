#pragma once
void lengthTo4Byte(int length, char out[]) {
	for (int i = 3; i >= 0; i--) {
		out[i] = length % 128;
		length = length / 128;
	}
	out[4] = 0;
}

void createMess(LPPER_IO_OPERATION_DATA perIoData, int opcode, int lengthData, char  data[]) {
	lengthTo4Byte(lengthData, (perIoData->buffer + perIoData->bufferLen + 1));
	perIoData->buffer[perIoData->bufferLen] = opcode;
	memcpy(perIoData->buffer + perIoData->bufferLen + 5, data, lengthData);
	perIoData->bufferLen = perIoData->bufferLen + 5 + lengthData;
}

void createMessSendFile(int opcode, int lengthData, char  data[], char buffSend[]) {
	buffSend[0] = opcode;
	lengthTo4Byte(lengthData, buffSend + 1);
	memcpy(buffSend + 5, data, lengthData);

}