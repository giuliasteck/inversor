/* Data de submissao: 14/03/2020
 * Nome: Giulia Steck
 * RA: 173458
 * Objetivo: o código tem como objetivo ler uma string inserida
 * pelo usuário e inverter cada palavra dela de forma separada. 
 * Por ex.: Hello World -> olleH dlroW. 
 */

#include <stdio.h>
#include <string.h>

const int tam_buffer=100;

/*Essa função é responsável por inverter um caractere
 * da string. Ela foi implementada com a ajuda de um
 * char temporário, que troca um caractere da posição
 * apontada por k com o salvo na posição de j      */
void reversewords (char *buffer, int *j, int *k){
	char temp;

		temp = buffer[*k];
		buffer[*k] = buffer[*j];
		buffer[*j] = temp;
}

/* Pecorre a string com os índices i, k e j a fim 
 * de identificar o começo e o fim das palavras ao 
 * longo dela                                   */
void findwords(char *buffer){
	int j = 0, k = 0;
	int length = strlen(buffer) - 1;

	for (int i = 0; i < length; i++){

		//Se buffer[i] for um espaço ou o fim da string
		//indica que foi encontrado o fim de uma palavra
		if (buffer[i] == ' ' || i == length - 1){
			
			if (i == length - 1)
				j = i;
			else
				j = i - 1;

			//A função é rodada até que toda a palavra seja invertida, 
			//ou seja, quando os índices que apontavam o fim e o ínicio
			//dela se igualarem
			while (k<j){
			reversewords(buffer, &j, &k);
			k ++;
			j --;
			}

		//k é setado para marcar o ínicio da palavra
		//seguinte, para percorre-la posteriormente.
		k = i + 1;

		}
	}
}

int main() {
  char buffer[tam_buffer];
  fgets(buffer, tam_buffer, stdin);
  findwords(buffer);
  printf("%s", buffer);
  return 0;
}
