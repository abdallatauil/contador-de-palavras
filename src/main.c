/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 *
 */

#include <stdio.h>

int main() {

  char c, ultima;         //chaar digitado e char anterior
  int count_palavras = 0, //contador de palavras
      verifica_flutuante = 0; //flag de ponto flutuante
  c = 1;
  ultima = 0;

  while (c != '\n') {
    scanf("%c", &c);
    if( (c == '!') || (c == '.') || (c == '?') || (c == ',') || (c == ':') ||(c == ';')||(c == '-')||(c == ' ')||(c == '\n')){

      if((ultima >= 'a' && ultima <= 'z') ||(ultima >= 'A' && ultima <= 'Z')){   //letra seguida de ponto ou espaço => é palavra
          count_palavras++;
      }
     if((ultima >= '0') && (ultima <= '9')){
        if(c == ',' || c == '.'){              //ṕode ser um ponto flutuante
            verifica_flutuante = 1;
        }
        else{
            verifica_flutuante = 0;
        }
        count_palavras++;                      //numero seguido de ponto ou virgula
     }
   }
    //Verificar se for um ponto flutuante e retirar. [Numero (ponto/virgula) Numero]
    if(verifica_flutuante == 1 && (c >= '0' && c <= '9')){
      count_palavras--;
      verifica_flutuante = 0;
    }
    ultima = c;
  }
  printf("%d\n", count_palavras);
  return 0;
}
 