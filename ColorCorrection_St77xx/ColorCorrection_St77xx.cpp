#include "ColorCorrection_St77xx.h"

ColorCorrection_St77xx::ColorCorrection_St77xx(ColorCorrection upperColors[], int size) {
    for (int i = 0; i < size; i++) {
        upperColors[i].color = getColorFromHex(upperColors[i].hexCode);
        upperColors[i].name = getNameByHex(upperColors[i].hexCode);
    }
}

uint16_t ColorCorrection_St77xx::getColorFromHex(const char* hexCode) {
    for (int i = 0; i < 8; i++) {
        if (strcmp(hexCode, lowerColors[i].hexCode) == 0) {
            return lowerColors[i].color;
        }
    }
    return 0x0000; // Valor padrão caso não encontre a cor
}

const char* ColorCorrection_St77xx::getNameByHex(const char* hexCode) {
    for (int i = 0; i < 8; i++) {
        if (strcmp(hexCode, lowerColors[i].hexCode) == 0) {
            return lowerColors[i].name;
        }
    }
    return "Unknown"; // Nome padrão caso não encontre a cor
}

uint16_t ColorCorrection_St77xx::getColorByName(const char* name) {
    for (int i = 0; i < 8; i++) {
        if (strcmp(name, lowerColors[i].name) == 0) {
            return lowerColors[i].color;
        }
    }
    return 0x0000; // Valor padrão caso não encontre a cor
}
