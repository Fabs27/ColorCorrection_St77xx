```markdown
# ColorCorrection_St77xx

A biblioteca `ColorCorrection_St77xx` para Arduino corrige automaticamente as cores definidas para displays Adafruit ST77xx, garantindo que as cores e nomes estejam corretos conforme especificado.

## Descrição

Esta biblioteca permite a correção automática das cores ao inicializar, utilizando nomes e códigos hexadecimais. É ideal para projetos que utilizam displays Adafruit ST7735, ST7789 e similares.

## Instalação

1. Baixe o arquivo ZIP da biblioteca.
2. Abra o Arduino IDE.
3. Vá para **Sketch** > **Incluir Biblioteca** > **Adicionar Biblioteca .ZIP...**.
4. Selecione o arquivo ZIP baixado.
5. A biblioteca será adicionada ao Arduino IDE.

## Uso

### Incluir a Biblioteca

Inclua a biblioteca no início do seu sketch:

```cpp
#include "ColorCorrection_St77xx.h"
```

### Instanciar e Usar a Biblioteca

Exemplo de uso com correção automática de cores:

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

    // Seu código para desenhar
}

void loop() {
    // Deixe o loop vazio
}
```

### Funcionalidades

- Correção automática de cores para displays ST77xx.
- Uso de nomes e códigos hexadecimais para correspondência de cores.
- Fácil integração com projetos existentes de Arduino.

## Direitos Autorais

© 2024, fabs27. Todos os direitos reservados.

## Doações

Se você achar esta biblioteca útil, considere fazer uma doação para apoiar o desenvolvimento contínuo:

[![Doar via Pix]

Chave Pix: **14996403691**

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir uma issue ou enviar um pull request com melhorias ou correções.

## Licença

Este projeto está licenciado sob a licença MIT - consulte o arquivo [LICENSE](LICENSE) para obter mais detalhes.