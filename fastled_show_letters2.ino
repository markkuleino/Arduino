#include <FastLED.h>

// FONTS: https://create.arduino.cc/projecthub/SAnwandter1/programming-8x8-led-matrix-23475a

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
#define DELAY 3000

CRGB leds[NUM_LEDS];
uint8_t max_bright = 40;

bool is_bit_set(unsigned value, unsigned bitindex){
//https://stackoverflow.com/questions/127027/how-can-i-check-my-byte-flag-verifying-that-a-specific-bit-is-at-1-or-0#127062
return (value & (1 << bitindex)) != 0;
}

void setup(){
delay(1000); // Power-up safety delay.
FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
FastLED.setBrightness( max_bright );

Serial.begin(9600); // open the serial port at 9600 bps:

}

void loop() {

Serial.print("T");
drawMatrix(C, DELAY);

Serial.print("A");
drawMatrix(A, DELAY);

Serial.print("R");
drawMatrix(R, DELAY);

Serial.print("K");
drawMatrix(K, DELAY);

Serial.print("K");
drawMatrix(K, DELAY);

Serial.print("U");
drawMatrix(U, DELAY);

Serial.print("O");
drawMatrix(O, DELAY);

Serial.print("P");
drawMatrix(P, DELAY);

Serial.print("E");
drawMatrix(E, DELAY);

FastLED.clear();

}

bool drawMatrix(byte letter[], int dilation){

// Get the indices:
int len = 0;
int ledsOn[ NUM_LEDS ];
for (int i = 0; i < 7; i++){
for (unsigned int j = 0; j < 8; j++){
if (is_bit_set(letter[i], 7-j)){
//Need to reverse the bit
ledsOn[len] = i*8+j;
len++;

        Serial.print(" "); 
        Serial.print(i*8+j);
        Serial.print(" = (" );
        Serial.print(i);
        Serial.print(",");
        Serial.print(j);
        Serial.print(")");
        
    }
}

}
Serial.print( len );
Serial.print("\n");
Serial.print("\n");

for (int a=0; a<len; a++){
//https://forum.arduino.cc/t/solved-shuffle-an-array/43536
int r = random16(a,len-1); // The simplest method found on the page
int temp = ledsOn[a];
ledsOn[a] = ledsOn[r];
ledsOn[r] = temp;
}

FastLED.clear();
FastLED.setBrightness( max_bright );

for (int i = 0; i < len; i++){
leds[ledsOn[i]] = CRGB::Blue;
//Serial.print( ledsOn[i] );
//Serial.print(" ");
delay(10);
FastLED.show();
}
FastLED.show();
delay( dilation );

return true;
}
