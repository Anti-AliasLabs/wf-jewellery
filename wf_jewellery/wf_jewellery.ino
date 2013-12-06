/*
  WF Jewellery
 
 Concept jewellery for Wearables Futures. Designed by Stephanie
 Posavec, technology by Becky Stewart.
 
 Colour A: Personal: Red/Orange
 Colour B: Shared: Blue/Purple
 Colour C: Remembrance: Green/Turquoise
 
 ATtiny45 (internal 8Mz)
 RGB LED with common cathode 
 */

int ledR = 0;           
int ledG = 2;
int ledB = 1;

int personal[] = {
  255, 120, 0};

int shared[] = {
  91, 0, 255 };

int remembrance[] = { 
  89, 233, 176
};

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pins for LED to be outputs:
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
} 

// the loop routine runs over and over again forever:
void loop()  { 
  //00:10 personal, speed 5
  fade( personal, 5, 10000 );

  // 00:15 pause
  delay( 15000 );

  // 00:25 personal, speed 2
  fade( personal, 2, 25000 );

  // 00:20 pause
  delay( 20000 );

  // 00:20 shared, speed 4 
  fade( shared, 4, 20000 );

  // 00:10 pause
  delay( 10000 );

  // 00:15 personal, speed 1
  fade( personal, 1, 15000 );

  // 00:10 pause
  delay( 10000 );

  // 00:20 remembrance, speed 3
  fade( remembrance, 3, 20000 );

  // 00:15 pause
  delay( 15000 );

}

// blink at given colour (int []), speed and duration (ms)
void blink(int* c, int sp, int duration) {
  int i;
  // calculate speed of blinking
  int pause = (6-sp) * 200;
  // calculate how many repetitions for given duration
  int reps = duration/(pause*2);

  for( i=0; i<reps; i++) {
    analogWrite( ledR, c[0] );
    analogWrite( ledG, c[1] );
    analogWrite( ledB, c[2] );

    delay( pause );

    analogWrite( ledR, 0 );
    analogWrite( ledG, 0 );
    analogWrite( ledB, 0 );
    delay( pause );
  }
}

// fade on and off
// at given colour (int []), speed and duration (ms)
void fade(int* c, int sp, int duration) {
  int i, j;
  // calculate speed of blinking
  int pause = (6-sp) * 200;
  // calculate how many repetitions for given duration
  int reps = duration/(pause*2);

  for( i=0; i<reps; i++) {
    for( j=0; j<255; j++) {
      int r = map( j, 0, 255, 0, c[0] );
      int g = map( j, 0, 255, 0, c[1] );
      int b = map( j, 0, 255, 0, c[2] );

      analogWrite( ledR, r );
      analogWrite( ledG, g );
      analogWrite( ledB, b );
    }
    delay( pause );
    for( j=255; j>0; j--) {
      int r = map( j, 0, 255, 0, c[0] );
      int g = map( j, 0, 255, 0, c[1] );
      int b = map( j, 0, 255, 0, c[2] );

      analogWrite( ledR, r );
      analogWrite( ledG, g );
      analogWrite( ledB, b );
    }
    analogWrite( ledR, 0 );
    analogWrite( ledG, 0 );
    analogWrite( ledB, 0 );
    delay( pause/2 );
  }
}



