# 📖 ¿Qué es get_next_line?
get_next_line es una función que:

- Permite leer un archivo línea por línea (¡incluso desde la entrada estándar si lo deseas!).
- Administra memoria como un verdadero ninja: ágil, eficiente y sin fugas.
- Soporta cualquier tamaño de buffer (¡tú decides cuánto quieres leer a la vez!).

## Prototipo de la función

```bash
char *get_next_line(int fd);
```
- fd: El file descriptor del archivo que quieres leer.
- Devuelve un puntero al contenido de la línea leída, incluyendo el salto de línea (\n), si existe.

## 🛠️ Herramientas y Conceptos Clave
Este proyecto utiliza:

- Lectura con read(): La función de bajo nivel para acceder a los datos del archivo.
- Buffers dinámicos: Porque un buen programador no teme enfrentarse a los límites de memoria.
- Almacenamiento estático y dinámico: Para manejar datos entre múltiples llamadas a la función.
- Protección de memoria: Porque los segmentation faults no tienen cabida aquí.

## 🚀 Instrucciones de Uso
1. Copia los archivos de get_next_line en tu proyecto.
Asegúrate de incluir:
- get_next_line.c
- get_next_line_utils.c
- -get_next_line.h
  
Ejemplo:
```bash
cc get_next_line.c get_next_line_utils.c get_next_line.h
```
2. Compila los archivos con tu código.

3. Prueba la función con un archivo.
```bash
#include "get_next_line.h"

int main(void)
{
    int fd = open("archivo.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

