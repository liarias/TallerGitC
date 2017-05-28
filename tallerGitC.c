#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LONG 125

void cifrar(char palabra[],int llave);

char abc[27] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
		       'o','p','q','r','s','t','u','v','w','x','y','z',' '};

char morseLetra[27][5]={".-","-...","-.-.","-..",".","..-.","--.",
                "....","..",".---","-.-",".-..","--","-.",
                "---",".--.","--.-",".-.","...","-","..-",
                "...-",".--","-..-","-.--","--..",,"/"};


char morseNum[11][5]={"-----",".----","..---","...--","....-",".....",
"-....","--...","---..","----.","/"};

int main(int argc, char *argv[]) {
	
	if (argc == 1) {	
		char pal[LONG];
		
		int num;
		printf("Cifrado ciclico \n");
        	printf("Ingrese mensaje a cifrar: ");
        	scanf("%[^\n]s",pal);
	
        	printf("Ingrese la llave numerica: ");
        	scanf("%d", &num);
		cifrar(pal,num);
		
		
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
	printf("Mensaje cifrado: %s",nPalabra);
	printf("\n");

}

void cifrar (char palabra[]){
	
}

