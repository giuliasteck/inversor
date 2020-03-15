/* Data de submissao: 14/03/2020
 * Nome: Giulia Steck
 * RA: 173458
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int tam_buffer=100;

void reverse(char *buffer){
	
	char tmp;
	int i, j, k, len;
	len = strlen(buffer);

	for(i=0, j =0; j<len; j++){
		if (!isalnum(buffer[j])|| (j == len-1)){
			if (j<len-1){
				k = j-1;
			}else{
				k = j;
			}

		
		while (i<k){
			tmp = buffer[i];
			buffer[i] = buffer[k];
			buffer[k] = tmp;
			i++;
			k--;
		}

		i = j + 1;
	}
  }

	//printf("%s", buffer);
}

int main() {
  char buffer[tam_buffer];
  fgets(buffer, tam_buffer, stdin);
  //scanf("%[^\n]", &buffer);
  reverse(buffer);
  printf("%s", buffer);
  return 0;
}
