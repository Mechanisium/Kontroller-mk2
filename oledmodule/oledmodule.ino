#include <Arduino.h>

#include <U8g2lib.h>

 /* we are using u8g2 library here , 
 constructor format for it is as follows 
 U8G2_[Controller][Resolution][Variant]_ [Buffer] _ [Communication] _ [Rotation and Pins] 
 */
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(  // we are using hardware i2c communication since software i2c was super slow and taking >1s for each buffer to bitbang.
  U8G2_R0,                  // Rotation: R0 = normal, R1=90°, R2=180°, R3=270°,MIRROR=flips,MIRROR_VERTICAL= flips vertically
  /* clock=*/  22,    // Your SCL pin (e.g., 22)
  /* data=*/   21,    // Your SDA pin (e.g., 21)
  /* reset=*/  U8X8_PIN_NONE // Usually no reset pin needed
);

auto& dis = u8g2;



// functions to draw stuff

//void dis.drawArc(u8g2_uint_t x0, u8g2_uint_t y0, u8g2_uint_t rad, int start, int end)
//void dis.drawBox(u8g2_uint_t x, u8g2_uint_t y, u8g2_uint_t w, u8g2_uint_t h)
//void dis.drawButtonUTF8(u8g2_uint_t x, u8g2_uint_t y, u8g2_uint_t flags, u8g2_uint_t width, u8g2_uint_t padding_h, u8g2_uint_t padding_v, const char *text)

//void dis.drawCircle(u8g2_uint_t x0, u8g2_uint_t y0, u8g2_uint_t rad, int opt = U8G2_DRAW_ALL)
//void dis.drawDisc(u8g2_uint_t x0, u8g2_uint_t y0, u8g2_uint_t rad, int opt = U8G2_DRAW_ALL)
//void dis.drawEllipse(u8g2_uint_t x0, u8g2_uint_t y0, u8g2_uint_t rx, u8g2_uint_t ry, int opt)
//void dis.drawFilledEllipse(u8g2_uint_t x0, u8g2_uint_t y0, u8g2_uint_t rx, u8g2_uint_t ry, int opt)
//void dis.drawFrame(u8g2_uint_t x, u8g2_uint_t y, u8g2_uint_t w, u8g2_uint_t h)
//u8g2_uint_t dis.drawGlyph(u8g2_uint_t x, u8g2_uint_t y, uint16_t encoding)
//u8g2_uint_t dis.drawGlyphX2(u8g2_uint_t x, u8g2_uint_t y, uint16_t encoding)
//  void dis.drawHLine(u8g2_uint_t x, u8g2_uint_t y, u8g2_uint_t w)
//void dis.drawLine(u8g2_uint_t x0, u8g2_uint_t y0, u8g2_uint_t x1, u8g2_uint_t y1)
//void dis.drawPixel(u8g2_uint_t x, u8g2_uint_t y)
//void dis.drawRBox(u8g2_uint_t x, u8g2_uint_t y, u8g2_uint_t w, u8g2_uint_t h, u8g2_uint_t r)
//void dis.drawRFrame(u8g2_uint_t x, u8g2_uint_t y, u8g2_uint_t w, u8g2_uint_t h, u8g2_uint_t r)
//u8g2_uint_t dis.drawStr(u8g2_uint_t x, u8g2_uint_t y, const char *s)    
//u8g2_uint_t dis.drawStrX2(u8g2_uint_t x, u8g2_uint_t y, const char *s)    
// void dis.drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2)
//  void dis.drawVLine(u8g2_uint_t x, u8g2_uint_t y, u8g2_uint_t h)
//void u8g2_DrawXBM(u8g2_t *u8g2, u8g2_uint_t x, u8g2_uint_t y, u8g2_uint_t w, u8g2_uint_t h, const int *bitmap)
//void u8g2_DrawXBMP(u8g2_t *u8g2, u8g2_uint_t x, u8g2_uint_t y, u8g2_uint_t w, u8g2_uint_t h, const int *bitmap)


//function to read your screen

//int8_t dis.getAscent(void)
//int8_t dis.getDescent(void)
//u8g2_uint_t getDisplayHeight(void)
//u8g2_uint_t getDisplayWidth(void)
//int8_t dis.getMenuEvent(void)
//u8g2_uint_t dis.getStrWidth(const char *s)
//void dis.print(...)
//void dis.setContrast(int value)
//void dis.setCursor(u8g2_uint_t x, u8g2_uint_t y)
//void dis.setDrawColor(int color)
//void dis.setFontDirection(int dir)
//void dis.setFontMode(int is_transparent)
//void dis.setPowerSave(int is_enable)
//void dis.updateDisplay(void)
//void dis.updateDisplayArea(int  tx, int ty, int tw, int th)
//int dis.userInterfaceMessage(const char *title1, const char *title2, const char *title3, const char *buttons)
//int dis.userInterfaceInputValue(const char *title, const char *pre, int *value, int lo, int hi, int digits, const char *post) 
//int dis.userInterfaceSelectionList(const char *title, int start_pos, const char *sl)

void loading1(){
  dis.clearBuffer();
  dis.setFont(u8g2_font_profont29_mr);  //huge fonts;P
  dis.drawStr(25,40,"(OwO)");
  dis.sendBuffer();
  delay(1000);
  
  dis.clearBuffer();
  dis.drawStr(25,40,"(TwT)"); //these are called kaomojis:D
  dis.sendBuffer();
  delay(1000);

  dis.clearBuffer();
  dis.drawStr(25,40,"(^w^)");
  dis.sendBuffer();
  delay(1000);

  dis.clearBuffer();
  dis.drawStr(25,40,"(UwU)");
  dis.sendBuffer();
  delay(1000);

  dis.clearBuffer();
  dis.drawStr(25,40,"(>w<)");
  dis.sendBuffer();
  delay(1000);

  dis.clearBuffer();
  dis.drawStr(25,40,"(=w=)");
  dis.sendBuffer();
  delay(1000);
  
}


void drawniggadraw(){
  
  for(int i=30;i>1;i--){
    dis.clearBuffer();
    dis.drawArc(dis.getDisplayWidth()/2,dis.getDisplayHeight()/2,i,0,256);
    dis.sendBuffer();
  
    if(i == 2){
      for(int i=2;i<30;i++){
        dis.clearBuffer();
        dis.drawArc(dis.getDisplayWidth()/2,dis.getDisplayHeight()/2,i,0,256);
        dis.sendBuffer();
        
        
        }
    }

  }
}


void bootAnimation() {
  dis.setFont(u8g2_font_tom_thumb_4x6_tr);  // Small retro font

  const char* texts[] = {"LOADING", "LOADING.", "LOADING..", "LOADING..."};
  
  
    for (int j = 0; j < 4; j++) {
      dis.clearBuffer();
      
      // Center the text horizontally
      int textWidth = dis.getStrWidth(texts[j]);
      dis.drawStr((128 - textWidth) / 2, 32, texts[j]);  // y=32 for middle of screen
      delay(400);
      dis.sendBuffer();
        // Visible but not too slow (~1.6s per cycle)
    }
  
}





void setup(){
  /*
  bool dis.begin(
   int menu_select_pin,
   int menu_next_pin,
   int menu_prev_pin,
   int menu_up_pin = U8X8_PIN_NONE,
   int menu_down_pin = U8X8_PIN_NONE, 
   int menu_home_pin = U8X8_PIN_NONE
   )
  */
  dis.begin( );
  bootAnimation();

  
}

void loop(){
 
 drawniggadraw();


  
  
}