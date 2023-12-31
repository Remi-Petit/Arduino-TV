#include <DigiMouse.h>

int Capteur = 2;  //  le capteur PIR 
int pinLED = 1; // Led
bool premierMouvement = true;  //  suivre le premier mouvement détecté
unsigned long tempsDernierMouvement = 0;  // Temps du dernier mouvement détecté

void setup() {
  DigiMouse.begin();      // Pour controller la souris
  pinMode(Capteur, INPUT); //Capteur en tant que pin d'entrée
  pinMode(pinLED, OUTPUT); //Led e, tant que sortie
}

void loop() {
  if (digitalRead(Capteur) == HIGH) {
    // Si le capteur détecte un mouvement
    digitalWrite(pinLED, HIGH);

    /*
    if (premierMouvement) {
      // Si c'est le premier mouvement détecté
      DigiMouse.moveX(60); // Mouvement de souris
      DigiMouse.delay(200); // Attente mouvement de souris
      DigiMouse.moveX(-60); // Mouvement de souris
      DigiMouse.delay(200); // Attente mouvement de souris
      digitalWrite(pinLED, HIGH);  // Allume la LED
      delay(1000);
      digitalWrite(pinLED, LOW);  // Éteint la LED
      delay(1000);
      premierMouvement = false;  // Met à jour le premierMouvement pour indiquer que le premier mouvement a été détecté
      tempsDernierMouvement = millis();  // Enregistre le temps du dernier mouvement détecté
    } else {
      // Si un mouvement est détecté après le premier mouvement
      tempsDernierMouvement = millis();  // Enregistre le temps du dernier mouvement détecté
    }
    */
  } 
  
  else {
    digitalWrite(pinLED, LOW);
  }
  
  
  if (premierMouvement != true && millis() - tempsDernierMouvement >= 1) {
    digitalWrite(pinLED, LOW);
    delay(1000);
    // Si aucun mouvement n'est détecté pendant plus de 6 secs après le dernier mouvement
    premierMouvement = true;  // Réinitialise  pour le prochain premier mouvement
  }
  // Vous pouvez ajouter d'autres logiques ou actions ici si nécessaire
}