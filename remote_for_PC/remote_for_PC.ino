/**** Define Remote control keys ****/
// FOR NEW REMOTE use arduino where is availible serial
//  //если пакет успешно принят
//  if (ir.available()) {
//    // вывести команду (8 бит)
//    Serial.print("0x");
//    Serial.println(ir.readCommand());
//  }

//#define Power     162
//#define key_1     48
//#define key_2     24
//#define key_3     122
//#define key_4     16
//#define key_5     56
//#define key_6     90
//#define key_7     66
//#define key_8     74
//#define key_9     82
//#define eq        224
//#define mode      98
//#define USD       152
//#define RPT       176

#define vol_up    144
#define vol_down  168
#define mute      226
#define next      194
#define prev      2
#define playpause 34
#define key_0     104

/************************************/

#include "TrinketHidCombo.h"
#include <NecDecoder.h>

NecDecoder ir;

void irIsr() {
  ir.tick();
}

void setup(void) {
  /* Use INT0(P2) on the Digispark */
  attachInterrupt(0, irIsr, FALLING);

  pinMode(1, OUTPUT);
  digitalWrite(1, LOW);
  TrinketHidCombo.begin();
}

void loop(void) {
  if (ir.available()) {
    switch (ir.readCommand()) {
      case mute: TrinketHidCombo.pressMultimediaKey(MMKEY_MUTE); break;
      case vol_down: TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_DOWN); break;
      case vol_up: TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_UP); break;
      case playpause: TrinketHidCombo.pressMultimediaKey(MMKEY_PLAYPAUSE); break;
      
      case next: TrinketHidCombo.pressMultimediaKey(MMKEY_SCAN_NEXT_TRACK); break;
      case prev: TrinketHidCombo.pressMultimediaKey(MMKEY_SCAN_PREV_TRACK); break;

      case key_0: TrinketHidCombo.pressKey(0, KEYCODE_F); TrinketHidCombo.pressKey(0, 0); break;  // full screen
    }
  }
  TrinketHidCombo.poll();
} 
