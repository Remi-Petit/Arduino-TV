#include <IRremote.h> // Déclaration de librairie IR
int RECV_PIN = 11; // Déclaration de la broche 11
IRrecv irrecv (RECV_PIN);
decode_results results;
void setup ()
{
Serial.begin (9600);
irrecv.enableIRIn ();
}
void loop () {
if (irrecv.decode (& results)) {
Serial.println (results.value, HEX);
irrecv.resume ();
}
}