#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define LONG 300
#define MORSE 1000

void cifrar(char palabra[],int llave);
void cifrarMorse(char palabra[], int llave);

char abc[27] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
		       'o','p','q','r','s','t','u','v','w','x','y','z',' '};

char morseLetra[27][6]={".- ","-... ","-.-. ","-.. ",". ","..-. ","--. ",
                ".... ",".. ",".--- ","-.- ",".-.. ","-- ","-. ",
                "--- ",".--. ","--.- ",".-. ","... ","- ","..- ",
                "...- ",".-- ","-..- ","-.-- ","--.. ","/"};


char morseNum[11][6]={"----- ",".---- ","..--- ","...-- ","....- ","..... ",
"-.... ","--... ","---.. ","----. ","/"};
char mor[MORSE];
int main(int argc, char *argv[]) {
	
	if (argc == 1) {	
		char pal1[LONG];

		int num;
		printf("Cifrado ciclico \n");
        	printf("Ingrese mensaje a cifrar: ");
        	scanf("%[^\n]s",pal1);

        	printf("Ingrese la llave numerica: ");
        	scanf("%d", &num);
		cifrar(pal1,num);
		cifrarMorse(pal1,num);		
	}

	return 0;
}

void cifrar(char palabra[],int llave){
	int i,desp;
	char nPalabra[LONG];	
	for(i=0;i<strlen(palabra);i++){
		if(palabra[i]==' '){
			nPalabra[i]=' ';
						
		}
		
		else{
			int ind;
			for(int j=0;j<27;j++){				
				if(palabra[i]==abc[j])
					ind = j;
			}		
			desp = ind + llave;

			if(desp<0 || desp>=26){
				desp=desp%26;
			}
		
			nPalabra[i]=abc[desp];	
		}
		
	}
	printf("Mensaje cifrado:%s",nPalabra);
	printf("\n");

}

void cifrarMorse (char palabra[],int llave){
	int i,n;
	int m;

	for(i=0;i<strlen(palabra);i++){
		if(isdigit(palabra[i])){
			n=palabra[i]-48;
printf("%d",n);
			strcat(mor,morseNum[n]);			
		}
		else{
			if(palabra[i]==' '){
				strcat(mor,morseNum[10]);
						
			}
		
			else{
				m=palabra[i]-97+llave;
printf("%d",m);
				strcat(mor,morseLetra[m]);	
			}
		
		}
	}
	printf("Mensaje cifrado en Morse:%s",mor);
	printf("\n");
}

