```markdown
# ColorCorrection_St77xx

The `ColorCorrection_St77xx` library for Arduino automatically corrects the colors defined for Adafruit ST77xx displays, ensuring that the colors and names are accurate as specified.

## Description

This library allows automatic color correction upon initialization, using names and hexadecimal codes. It is ideal for projects using Adafruit ST7735, ST7789, and similar displays.

## Installation

1. Download the ZIP file of the library.
2. Open the Arduino IDE.
3. Go to **Sketch** > **Include Library** > **Add .ZIP Library...**.
4. Select the downloaded ZIP file.
5. The library will be added to the Arduino IDE.

## Usage

### Include the Library

Include the library at the beginning of your sketch:

```cpp
#include "ColorCorrection_St77xx.h"
```

### Instantiate and Use the Library

Example usage with automatic color correction:

```cpp
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include "ColorCorrection_St77xx.h"

#define TFT_CS    5
#define TFT_RST   4
#define TFT_DC    2

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

ColorCorrection colors[] = {
    {ST77XX_BLACK, "0x0000", "Black"},
    {ST77XX_BLUE, "0x001F", "Blue"},
    {ST77XX_RED, "0xF800", "Red"},
    {ST77XX_GREEN, "0x07E0", "Green"},
    {ST77XX_CYAN, "0x07FF", "Cyan"},
    {ST77XX_MAGENTA, "0xF81F", "Magenta"},
    {ST77XX_YELLOW, "0xFFE0", "Yellow"},
    {ST77XX_WHITE, "0xFFFF", "White"}
};

ColorCorrection_St77xx converter(colors, sizeof(colors) / sizeof(colors[0]));

void setup() {
    tft.init(240, 320);
    tft.setRotation(0);
    tft.fillScreen(converter.getColorByName("Black"));
    tft.setTextColor(converter.getColorByName("Green"));
    tft.setTextSize(1);

    // Your drawing code here
}

void loop() {
    // Leave the loop empty
}
```

### Features

- Automatic color correction for ST77xx displays.
- Use of names and hexadecimal codes for color matching.
- Easy integration with existing Arduino projects.

## Copyright

© 2024, fabs27. All rights reserved.

## Donations

If you find this library useful, consider making a donation to support continuous development:

[![Donate via Pix]

Pix Key: **14996403691**

## Contribution

Contributions are welcome! Feel free to open an issue or submit a pull request with improvements or fixes.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.