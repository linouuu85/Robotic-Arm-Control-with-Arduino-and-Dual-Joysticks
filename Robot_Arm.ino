#include <Servo.h>

// Définition des 4 servos
Servo base, bras, avantBras, pince;

// Positions initiales
int pBase = 90, pBras = 90, pAvantBras = 90, pPince = 80;

void setup() {
  // On utilise les pins standards des Shields Joystick
  base.attach(11);      // Base
  bras.attach(10);      // Bras
  avantBras.attach(9);   // Avant-bras
  pince.attach(5);      // Pince

  // Initialisation rapide
  base.write(pBase);
  bras.write(pBras);
  avantBras.write(pAvantBras);
  pince.write(pPince);
}

void loop() {
  // Lecture des 2 Joysticks (A0, A1 = Gauche | A2, A3 = Droite)
  int lx = analogRead(A0); 
  int ly = analogRead(A1);
  int rx = analogRead(A2); 
  int ry = analogRead(A3);

  // --- VITESSE AUGMENTÉE (+5 au lieu de +2) ---
  
  // Joystick Gauche : Base et Pince
  if(lx < 400) pBase = min(180, pBase + 5); 
  else if(lx > 600) pBase = max(0, pBase - 5);
  
  if(ly < 400) pPince = min(150, pPince + 6); 
  else if(ly > 600) pPince = max(60, pPince - 6);

  // Joystick Droite : Bras et Avant-bras
  if(rx < 400) pBras = min(170, pBras + 5); 
  else if(rx > 600) pBras = max(10, pBras - 2); // Moins vite en descente pour la sécurité

  if(ry < 400) pAvantBras = min(170, pAvantBras + 5); 
  else if(ry > 600) pAvantBras = max(10, pAvantBras - 5);

  // Envoi immédiat des ordres
  base.write(pBase);
  pince.write(pPince);
  bras.write(pBras);
  avantBras.write(pAvantBras);

  // DÉLAI RÉDUIT (20ms au lieu de 40ms ou 50ms)
  delay(20); 
}