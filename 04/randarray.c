#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

/*
 * Dieses Programm erzeugt und initialisiert einen int-Array zufaellig. 
 * Anschliessend werden geometrischer Mittelwert und arithmetischer 
 * Mittelwert berechnet und auf der Konsole ausgegeben.
 */
int main(void)
{
	// Initialisiere Zufallszahlengenerator
	srand(time(0));
	
	// Deklariere und Intialisiere Variablen
	double arithm_mittelwert = 0.0;
	double geom_mittelwert = 1.0;
	
	// Array fuer Zufallszahlen anlegen
	int rnd_numbers[ 100 ];

	// Zufallszahlen erzeugen
  int i;
  for (i = 0; i < 100; ++i){
    //mit modulo 100 zahlen zwischen 0 und 99 produzieren und 1 addieren
    rnd_numbers[i] = rand() % 100 + 1; 
  }

	// Arithmetischen Mittelwert berechnen
  int sum = 0;
  for (i = 0; i < 100; ++i){
    sum += rnd_numbers[i];  //summanden summieren
  }
  arithm_mittelwert = sum / 100.0; //summanden durch anzahl dividieren

	// Geometrischen Mittelwert berechnen
  double prod = 1;
  for (i = 0; i < 100; ++i){
    prod *= rnd_numbers[i]; //produkt bilden
  }
  geom_mittelwert = pow(prod, 0.01);  //100te wurzel aus produkt ziehen

	// Ausgabe
	printf("Die arithmetische Mittelwert ist: %g\n", arithm_mittelwert);
	printf("Der geometrische Mittelwert ist: %g\n", geom_mittelwert);
}
