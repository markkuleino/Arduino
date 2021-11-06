#include <FastLED.h>

//https://cod3v.info/index.php?title=Arduino_Led_Matrix_8x7_WS2811

unsigned char A[8] = {0b00111000,0b01101100,0b11000110,0b11000110,0b11111110,0b11000110,0b11000110,'\0'};
unsigned char B[8] = {0b11111100,0b11000110,0b11000110,0b11111100,0b11000110,0b11000110,0b11111100,'\0'};
unsigned char C[8] = {0b00111100,0b01100110,0b11000000,0b11000000,0b11000000,0b01100110,0b00111100,'\0'};
unsigned char D[8] = {0b11111000,0b11001100,0b11000110,0b11000110,0b11000110,0b11001100,0b11111000,'\0'};
unsigned char E[8] = {0b11111110,0b11000000,0b11000000,0b11111100,0b11000000,0b11000000,0b11111110,'\0'};
unsigned char F[8] = {0b11111110,0b11000000,0b11000000,0b11111100,0b11000000,0b11000000,0b11000000,'\0'};
unsigned char G[8] = {0b00111110,0b01100000,0b11000000,0b11001110,0b11000110,0b01100110,0b00111110,'\0'};
unsigned char H[8] = {0b11000110,0b11000110,0b11000110,0b11111110,0b11000110,0b11000110,0b11000110,'\0'};
unsigned char I[8] = {0b00111100,0b00011000,0b00011000,0b00011000,0b00011000,0b00011000,0b00111100,'\0'};
unsigned char J[8] = {0b00000110,0b00000110,0b00000110,0b00000110,0b00000110,0b11000110,0b01111100,'\0'};
unsigned char K[8] = {0b11000110,0b11001100,0b11011000,0b11110000,0b11111000,0b11011100,0b11001110,'\0'};
unsigned char L[8] = {0b01100000,0b01100000,0b01100000,0b01100000,0b01100000,0b01100000,0b01111110,'\0'};
unsigned char M[8] = {0b11000110,0b11101110,0b11111110,0b11111110,0b11010110,0b11000110,0b11000110,'\0'};
unsigned char N[8] = {0b11000110,0b11100110,0b11110110,0b11111110,0b11011110,0b11001110,0b11000110,'\0'};
unsigned char O[8] = {0b01111100,0b11000110,0b11000110,0b11000110,0b11000110,0b11000110,0b01111100,'\0'};
unsigned char P[8] = {0b11111100,0b11000110,0b11000110,0b11000110,0b11111100,0b11000000,0b11000000,'\0'};
unsigned char Q[8] = {0b01111100,0b11000110,0b11000110,0b11000110,0b11011110,0b11001100,0b01111010,'\0'};
unsigned char R[8] = {0b11111100,0b11000110,0b11000110,0b11001110,0b11111000,0b11011100,0b11001110,'\0'};
unsigned char S[8] = {0b01111000,0b11001100,0b11000000,0b01111100,0b00000110,0b11000110,0b01111100,'\0'};
unsigned char T[8] = {0b01111110,0b00011000,0b00011000,0b00011000,0b00011000,0b00011000,0b00011000,'\0'};
unsigned char U[8] = {0b11000110,0b11000110,0b11000110,0b11000110,0b11000110,0b11000110,0b01111100,'\0'};
unsigned char V[8] = {0b11000110,0b11000110,0b11000110,0b11101110,0b01111100,0b00111000,0b00010000,'\0'};
unsigned char W[8] = {0b11000110,0b11000110,0b11010110,0b11111110,0b11111110,0b11101110,0b11000110,'\0'};
unsigned char X[8] = {0b11000110,0b11101110,0b01111100,0b00111000,0b01111100,0b11101110,0b11000110,'\0'};
unsigned char Y[8] = {0b01100110,0b01100110,0b01100110,0b00111100,0b00011000,0b00011000,0b00011000,'\0'};
unsigned char Z[8] = {0b11111110,0b00001110,0b00011100,0b00111000,0b01110000,0b11100000,0b11111110,'\0'};


#define NUM_LEDS 7*8
#define DATA_PIN 13
#define DELAY 190

CRGB leds[NUM_LEDS];
uint8_t max_bright = 40; 

bool is_bit_set(unsigned value, unsigned bitindex){
//https://stackoverflow.com/questions/127027/how-can-i-check-my-byte-flag-verifying-that-a-specific-bit-is-at-1-or-0#127062
    return (value & (1 << bitindex)) != 0;
}


void setup(){
   delay(1000);                          // Power-up safety delay.
   FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
   FastLED.setBrightness( max_bright );
}

void loop() {
    
    FastLED.clear();
    scrollMatrix(M, DELAY);
    scrollMatrix(A, DELAY);
    scrollMatrix(R, DELAY);
    scrollMatrix(K, DELAY);
    scrollMatrix(K, DELAY);
    scrollMatrix(U, DELAY);
    scrollMatrix(O, DELAY);
    scrollMatrix(P, DELAY);
    scrollMatrix(E, DELAY);
}


bool  drawMatrix(byte letter[], int dilation){ 
  FastLED.clear();
  FastLED.setBrightness( max_bright );
  for (int i = 0; i < 7; i++){
    for (unsigned int j = 0; j < 8; j++){
        if (is_bit_set(letter[i], 7-j)){
          //Need to reverse the bit
            leds[i*8+j] = CRGB::Blue;
        }
    }
  }
  FastLED.show();
  FastLED.delay( dilation );
  return true;
} 

bool  scrollMatrix(byte letter[], int dilation){ 
  byte scrolledLetter[7];

  for (int shift=8; shift > 0; shift--){
    //Copy and shift the matrix
    for (int i = 0; i < 7; i++){
      scrolledLetter[i] = letter[i]>>shift;
    }   
    drawMatrix( scrolledLetter, dilation); 
  }
  
  for (int shift=0; shift < 8; shift++){
    //Copy and shift the matrix
    for (int i = 0; i < 7; i++){
      scrolledLetter[i] = letter[i]<<shift;
    }    
    drawMatrix( scrolledLetter, dilation); 
  }
  return true;
}
