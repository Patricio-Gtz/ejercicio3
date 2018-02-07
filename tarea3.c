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
// Define el largo de la linea para imprimir en terminal
#define LENGTH 180

int main(int argc, char const *argv[]) {

  // Arreglo que guarda los datos de la foto
  char imprime[LENGTH] = {0};
  // Checa si hay muchos datos o pocos
  if(argc < 2) {
    printf("Muy pocos argumentos\n");
    return 0;
  } else if (argc > 2) {
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
  // Copia linea por linea al nuevo archivo
  while (fgets(imprime, LENGTH, file)) {
    fprintf(file2, "%s", imprime);
  }
  // Cierra archivo
  fclose(file);

  return 0;
}
