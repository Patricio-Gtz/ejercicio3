/*
 * @author  [Diego Patricio Gutierrez]
 * @file    [tarea3.c]
 * @date    [7-feb-2018]
 * @brief   [Este programa copia una imagen raw otro archivo usando un
 *          arreglo de char's]
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  // Arreglo que guarda los datos de la foto
  char imprime;
  long int largo = 0;
  int contador = 0;
  // Checa si hay muchos datos o pocos
  if(argc < 2) {
    printf("Muy pocos argumentos\n");
    return 0;
  } else if (argc > 3) {
    printf("Muchos argumentos\n");
    return 0;
  }
  // Creo archivos de entrada y salida
  FILE *file = fopen(argv[1], "r");
  FILE *file2 = fopen(argv[2], "w");
  // Asegura que los archivos esten disponibles
  if(!file || !file2) {
    printf("Error en el archivo\n");
    return 0;
  }
  // Te vas al final del archivo
  fseek(file, 0L, SEEK_END);
  // Guardas cuantos char hay en el archivo
  largo = ftell(file);
  // Regresas al inicio del archivo
  fseek(file, 0L, SEEK_SET);
  // Copia linea por linea al nuevo archivo
  while (contador != largo) {
    // imprime linea por linea
    imprime = fgetc(file);
    fprintf(file2, "%c", imprime);
    contador++;
  }
  // Cierra archivo
  fclose(file);

  return 0;
}
