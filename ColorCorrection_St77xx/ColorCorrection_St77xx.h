#ifndef COLORCORRECTION_ST77XX_H
#define COLORCORRECTION_ST77XX_H

#include <Arduino.h>

struct ColorCorrection {
    uint16_t color;
    const char* hexCode;
    const char* name;
};

class ColorCorrection_St77xx {
public:
    ColorCorrection_St77xx(ColorCorrection upperColors[], int size);

    uint16_t getColorByName(const char* name);

private:
    ColorCorrection lowerColors[8] = {
        {0xFFFF, "0xFFFF", "Black"},
        {0xFFE0, "0xFFE0", "Blue"},
        {0x07FF, "0x07FF", "Red"},
        {0xF81F, "0xF81F", "Green"},
        {0xF800, "0xF800", "Cyan"},
        {0x07E0, "0x07E0", "Magenta"},
        {0x001F, "0x001F", "Yellow"},
        {0x0000, "0x0000", "White"}
    };
    uint16_t getColorFromHex(const char* hexCode);
    const char* getNameByHex(const char* hexCode);
};

#endif // COLORCORRECTION_ST77XX_H
