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
  //00:10 personal, Speed 5
  analogWrite( ledR, personal[0] );
  analogWrite( ledG, personal[1] );
  analogWrite( ledB, personal[2] );

  // 00:15 pause
  delay( 5000 );
  // 00:25 RGB: 255, 88, 81, speed 2


  // 00:20 pause

  // 00:20 shared, speed 4 
  analogWrite( ledR, shared[0] );
  analogWrite( ledG, shared[1]);
  analogWrite( ledB, shared[2] );

  // 00:10 pause
  delay( 5000 );

  // 00:15 RGB: 255, 88, 81, speed 1

  // 00:10 pause

  // 00:20 RGB: 89, 233, 176, speed 3
  analogWrite( ledR, remembrance[0] );
  analogWrite( ledG, remembrance[1]);
  analogWrite( ledB, remembrance[2] );
  // 00:15 pause
  delay( 5000 );

  // 00:05 RGB: 91, 0, 255, speed 5
  /*analogWrite( ledR, 70 );
   analogWrite( ledG, 0);
   analogWrite( ledB, 255 );
   //00:15 pause
   delay( 9000 );*/
}









