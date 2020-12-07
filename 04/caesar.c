#include <stdio.h>
#include <stdlib.h>

/*
 * Bekommt ein beliebiges Zeichen zeichen und einen Wert shift uebergeben.
 * Shiftet alle Zeichen aus dem Bereich a-z und A-Z um den Wert Shift. 
 * An den Wertebereichsgrenzen findet ein Umlauf statt (Beispielsweise:
 * nach Z folgt A, vor A liegt Z, nach z folgt a und vor a liegt z).
 * Zahlen ausserhalb des Bereichs werden unveraendert zurueckgegeben.
 * Gibt das kalkulierte Zeichen zurueck.
 */
char shiftChar(char zeichen, int shift){  //mit ascii und modulo
  //upper case
  if ((zeichen >= 65) && (zeichen <= 90)){
    return ((zeichen + shift - 15) % 25) + 65;  //rotations mathe
  }
  //lower case
  if ((zeichen >= 97) && (zeichen <= 122)){
    return ((zeichen + shift - 22) % 25) + 97;  //nochmal rotations mathe
  }
  //other case
  return zeichen;
}

/*
 * Bekommt einen beliebigen C-String uebergeben. 
 * Fuehrt auf jedem Zeichen des Strings die shiftChar-Funktion aus.
 * Der uebergebene originale String wird dabei veraendert.
 */
void cipher(char str[], int shift)
{
  int i = 0;
  while (str[i] != 0){  //bis str zuende ist
    str[i] = shiftChar(str[i], shift);  //werte unter pointer austauschen
    i++;
  }
}

/*
 * Testprogramm, das Strings mit dem Caesar-Chiffre chiffrieren kann. 
 * Es benutzt dazu die cipher-Funktion.
 */
int main(void)
{
	char str[25] = "Das ist der Originaltext"; 	// Originaltext
	int shift = 5;
	printf("Original: ");
	printf("%s\n", str);
	
	// Verschluesseln
	cipher(str, shift);
	printf("Verschluesselt: ");
	printf("%s\n", str);
	
	// Entschluesseln
	cipher(str, -shift);
	printf("Entschluesselt: ");
	printf("%s\n", str);
}
