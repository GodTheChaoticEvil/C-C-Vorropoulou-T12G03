#include <stdio.h>

int finde(char text[], char zuFinden[]){
  int i = 0, j = 0;

  while(1){
    if (text[i + j] == zuFinden[j]){    //passt das aktuelle i an der stelle j?
      //falls ja wird j incementiert und wenn dann zuFinden[] zuende ist haben wir i gefunden.
      if (zuFinden[++j] == 0) return i; 
    }
    //wenn das aktuelle i nicht passt...
    else{
      //i wird incrementiert und wenn text[] dann zuende ist gibt es keine i.
      if (text[++i] == 0) return -1;
      j = 0;  //ansonsten wir j noch auf 0 gesetzt und es geht mit i+1 von vorne los.
    }
  }
}

int main()
{
 	char text[] = "DieserTextistsehrsehrlang";
 	char zuFinden[] = "ist";
	int index = finde(text, zuFinden);
	printf("%s beginnt bei Index %d\n", zuFinden, index);
}
