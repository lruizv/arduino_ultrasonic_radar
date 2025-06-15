#include <lcd.h>

// Forward declaration for cls
void cls(Ucglib_ST7735_18x128x160_HWSPI *ucg);
void lcd_setup(Ucglib_ST7735_18x128x160_HWSPI *ucg);

/**
 * Function Name:
 *
 * Description:
 *
 * @param void
 * @return none
 */
void lcd_setup(Ucglib_ST7735_18x128x160_HWSPI *ucg)
{
    ucg->begin(UCG_FONT_MODE_SOLID); //initialization screen
    ucg->setRotate90();              //Set to horizontal screen If the screen display direction is reversed, you can modify the function setRotate90 or setRotate270

    //screen startup interface
    ucg->setFontMode(UCG_FONT_MODE_TRANSPARENT);
    ucg->setColor(0, 0, 100, 0);
    ucg->setColor(1, 0, 100, 0);
    ucg->setColor(2, 20, 20, 20);
    ucg->setColor(3, 20, 20, 20);
    ucg->drawGradientBox(0, 0, 160, 128);
    ucg->setPrintDir(0);
    ucg->setColor(0, 5, 0);
    ucg->setPrintPos(27, 42);
    ucg->setFont(ucg_font_logisoso18_tf);
    ucg->print("Mini Radar Kit");
    ucg->setColor(0, 255, 0);
    ucg->setPrintPos(25, 40);
    ucg->print("Mini Radar");
    ucg->setFont(ucg_font_helvB08_tf);
    ucg->setColor(0, 255, 0);
    ucg->setPrintPos(40, 100);
    ucg->print("Initializing...");

    ucg->setColor(0, 255, 0);

    ucg->print("OK!");
    delay(500);
    ucg->setColor(0, 0, 0, 0);
    ucg->setColor(1, 0, 0, 0);
    ucg->setColor(2, 0, 0, 0);
    ucg->setColor(3, 0, 0, 0);

    //clear screen
    //ucg->clearScreen();
    cls(ucg);

    ucg->setFont(ucg_font_orgv01_hr);
    ucg->setFontMode(UCG_FONT_MODE_SOLID);
}

/**
 * Function Name:
 *
 * Description:
 *
 * @param void
 * @return none
 */
void cls(Ucglib_ST7735_18x128x160_HWSPI *ucg)
{
    //clear screen
    ucg->setColor(0, 0, 0, 0);

    for (int s = 0; s < 128; s += 8)
        for (int t = 0; t < 160; t += 16)
        {
            ucg->drawBox(t, s, 16, 8);
            // delay(1);
        }
}