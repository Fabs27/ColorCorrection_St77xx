#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include "ColorCorrection_St77xx.h" // Inclua a biblioteca ColorCorrection_St77xx

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

// Instancia o conversor e corrige as cores automaticamente ao incluir a biblioteca
ColorCorrection_St77xx converter(colors, sizeof(colors) / sizeof(colors[0]));

void drawBuddha() {
    const char* buddha[] = {
        "      _       ",
        "   _ooOoo_    ",
        "  o8888888o   ",
        "  88\" . \"88   ",
        "  (| -_- |)   ",
        "  O\\  =  /O   ",
        "____/`---'\\____",
        ".  \\|     |//  `.",
        "/  \\|||  :  |||//  \\",
        "/  _||||| -:- |||||-  \\",
        "|   | \\\\\\  -  /// |   |",
        "| \\_|  ''\\---/''  |   |",
        "\\  .-\\__  `-`  ___/-. /",
        " ___`. .'  /--.--\\  `. . __",
        ".\"\" '<  `.___\\_<|>_/___.'  >'\"\".",
        "| | :  `- \\`.;`\\ _ /`;.`/ - ` : | |",
        "\\  \\ `-.   \\_ __\\ /__ _/   .-` /  /",
        " `-.____`-.___\\_____/___.-`____.-'",
        "  `=---='",
        "~~~~~~~~~",
        "\"sabedoria forca e honra\""
    };

    int yStart = 160; // Ajusta a posição y inicial para abaixar o Buda
    tft.fillScreen(converter.getColorByName("Black"));
    tft.setTextColor(converter.getColorByName("Green")); // Define o texto do Buda na cor verde convertida
    tft.setTextSize(1);

    for (int i = 0; i < sizeof(buddha) / sizeof(buddha[0]); i++) {
        int xStart = (240 - strlen(buddha[i]) * 6) / 2; // Calcula a posição x inicial para centralizar horizontalmente
        tft.setCursor(xStart, yStart + i * 8); // Define a posição do cursor
        tft.println(buddha[i]);
    }
}

void drawColorSquares() {
    int squareSize = 20;
    int offsetX = 10;
    int offsetY = 30;
    int startX = (240 - ((sizeof(colors) / sizeof(colors[0])) * (squareSize + offsetX) - offsetX)) / 2; // Centraliza horizontalmente

    for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++) {
        int x = startX + i * (squareSize + offsetX);
        int y = 0;

        // Desenha quadrados coloridos
        tft.fillRect(x, y, squareSize, squareSize, colors[i].color);

        // Desenha linhas ao redor dos quadrados
        tft.drawRect(x, y, squareSize, squareSize, converter.getColorByName("White"));

        // Desenha o código hexadecimal abaixo do quadrado colorido
        int yTextStart = squareSize + offsetY;
        for (int j = 0; j < strlen(colors[i].hexCode); j++) {
            tft.setCursor(x + (squareSize - 6) / 2, yTextStart + j * 8);
            tft.setTextColor(converter.getColorByName("White"));
            tft.setTextSize(1);
            tft.write(colors[i].hexCode[j]);
        }

        // Desenha o nome da cor abaixo do código hexadecimal
        yTextStart += strlen(colors[i].hexCode) * 8 + 2;
        for (int j = 0; j < strlen(colors[i].name); j++) {
            tft.setCursor(x + (squareSize - 6) / 2, yTextStart + j * 8);
            tft.setTextColor(converter.getColorByName("White"));
            tft.setTextSize(1);
            tft.write(colors[i].name[j]);
        }
    }
}

void setup() {
    tft.init(240, 320); // Inicializa o display com a resolução 240x320
    tft.setRotation(0); // Define a orientação do display
    drawBuddha(); // Desenha o Buda na tela
    drawColorSquares(); // Desenha quadrados coloridos na borda
}

void loop() {
    // Deixe o loop vazio
}
