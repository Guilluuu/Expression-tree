# Nombre del compilador
CC = gcc

# Opciones de compilación
CFLAGS = -Wall -g

# Archivos de cabecera
HEADERS = abin.h FuncionesExpresion.h pilaOperadores.h pilaOperandos.h recorridos.h

# Archivos fuente
SRC = abin.c FuncionesExpresion.c main.c pilaOperadores.c pilaOperandos.c recorridos.c

# Archivos objeto
OBJ = abin.o FuncionesExpresion.o main.o pilaOperadores.o pilaOperandos.o recorridos.o

# Nombre del ejecutable
TARGET = programa

# Regla principal para compilar todo
all: $(TARGET)

# Regla para enlazar los archivos objeto en el ejecutable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Regla para compilar los archivos fuente en objetos
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpia los archivos generados
clean:
	rm -f $(OBJ) $(TARGET)

# Regla para limpiar los archivos objeto pero dejar el ejecutable
clean_obj:
	rm -f $(OBJ)

# Ejecutar el programa
run: $(TARGET)
	./$(TARGET)