#pragma once
#include <Arduino.h>

class LcdDisplay {
private:
	
	const uint8_t filledSigment[8] = { 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111 };
	const uint8_t emptySigment[8] = { 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000 };

	int _rows;
	int _columns;
	int _displayAdress;
	uint8_t _dataSmoothingDegree = 8;

	uint8_t getFilledSigment();
	uint8_t getEmptySigment();

	double filterByMass(uint8_t& counter_elements, double* filter_array);
	double get_procent(double minVal, double maxVal, double inputData);

public:
	LcdDisplay();
	LcdDisplay(int rows, int columns, int displayAdress);

	void setDiaplayParameters(int rows, int columns, int displayAdress);
	void setDataSmoothingDegree(uint8_t dataSmoothingDegree);
	void getFillLine(double minVal, double maxVal, double inputData);
};

class LcdDisplayAnimations : public LcdDisplay {
	LcdDisplayAnimations() : LcdDisplay() {}
	LcdDisplayAnimations(int rows, int columns, int displayAdress) : LcdDisplay(rows, columns, displayAdress) {}

};


