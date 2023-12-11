#include <SimpleServo.h>

SimpleServo servoMoteur;  // Création de l'objet SimpleServo
int Capteur = 1;  // Le capteur PIR 
int pinLED = 2; // Led
bool premierMouvement = true;  // Suivre le premier mouvement détecté
unsigned long tempsDernierMouvement = 0;  // Temps du dernier mouvement détecté (compteur)

void setup() {
  servoMoteur.attach(0);  // Attache le servomoteur au pin 0 
  pinMode(Capteur, INPUT); // Capteur en tant que pin d'entrée
  pinMode(pinLED, OUTPUT); // Led en tant que sortie
}

void loop() {
  if (digitalRead(Capteur) == HIGH) {
    // Si le capteur détecte un mouvement
    if (premierMouvement) {
      // Si c'est le premier mouvement détecté
      servoMoteur.write(90);  // Déplace le servomoteur à 90 degrés
      digitalWrite(pinLED, HIGH);  // Allume la LED
      delay(1000);
      servoMoteur.write(0);   // Déplace le servomoteur à 0 degré
      digitalWrite(pinLED, LOW);  // Éteint la LED
      delay(1000);
      premierMouvement = false;  // Met à jour premierMouvement pour indiquer que le premier mouvement a été détecté
      tempsDernierMouvement = millis();  // Enregistre le temps du dernier mouvement détecté
    } else {
      // Si un mouvement est détecté après le premier mouvement
      servoMoteur.write(0);  // Arrête le servomoteur
      tempsDernierMouvement = millis();  // Enregistre le temps du dernier mouvement détecté
    }
  } else if (!premierMouvement && millis() - tempsDernierMouvement >= 6 * 1000) {
    // Si aucun mouvement n'est détecté pendant plus de 6 secondes après le dernier mouvement
    servoMoteur.write(90);  // Active le servomoteur à 90 degré
    digitalWrite(pinLED, HIGH); //Allume la LED
    delay(1000);
    servoMoteur.write(0);   // Ramène le servomoteur à 0 degré
    digitalWrite(pinLED, LOW); // Éteint la LED
    delay(1000);
    premierMouvement = true;  // Réinitialise premierMouvement pour le prochain premier mouvement
    tempsDernierMouvement = millis();  // Enregistre le temps du dernier mouvement détecté
  }
 
}