#include "lcdDisplayAnimations.h"

LcdDisplay::LcdDisplay() {
	setDiaplayParameters(4, 20, 0x27); // default params for LCD display 2004A
}

LcdDisplay::LcdDisplay(int rows, int columns, int displayAdress) {
	setDiaplayParameters(rows, columns, displayAdress);
}

void LcdDisplay::setDiaplayParameters(int rows, int columns, int displayAdress) {
	_rows = rows;
	_columns = columns;
	_displayAdress = displayAdress;
}

void LcdDisplay::setDataSmoothingDegree(uint8_t dataSmoothingDegree) {
	_dataSmoothingDegree = dataSmoothingDegree;
}

void LcdDisplay::getFillLine(double minVal, double maxVal, double inputData) {

}


uint8_t LcdDisplay::getFilledSigment() {

}

uint8_t LcdDisplay::getEmptySigment() {

}

double LcdDisplay::filterByMass(uint8_t& counter_elements, double* filter_array) {

	if (counter_elements == dataSmoothingDegree_)
		counter_elements = 0;

	filter_array[counter_elements] = analogRead(REOSTAT_PIN);
	counter_elements++;

	double summ = 0;
	for (int i = 0; i < dataSmoothingDegree_; i++)
		summ += filter_array[i];


	return (double)summ / dataSmoothingDegree_;
}

double LcdDisplay::get_procent(double minVal, double maxVal, double inputData) {
	double delta = maxVal - minVal;
	if (delta < 0) delta = -delta;

	return (double)(inputData * 100) / delta;
}