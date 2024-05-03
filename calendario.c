#include <stdio.h>

// Función para determinar si un año es bisiesto
int esBisiesto(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1; // Es bisiesto
    else
        return 0; // No es bisiesto
}

// Función para obtener el día de la semana para un día dado
int obtenerDiaSemana(int year, int month, int day) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int k = year % 100;
    int j = year / 100;
    int h = (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    return (h + 5) % 7; // 0 es sábado, 1 es domingo, 2 es lunes, ..., 6 es viernes
}

// Función para imprimir el calendario de un mes y año dado
void imprimirCalendario(int year, int month) {
    int diasEnMes[] = {31, 28 + esBisiesto(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *nombreMes[] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    int primerDia = obtenerDiaSemana(year, month, 1);
    
    printf("     %s %d\n", nombreMes[month - 1], year);
    printf("Dom Lun Mar Mie Jue Vie Sab\n");
    
    // Imprimir espacios para el primer día
    for (int i = 0; i < primerDia; i++)
        printf("    ");
    
    // Imprimir los días del mes
    for (int i = 1; i <= diasEnMes[month - 1]; i++) {
        printf("%3d ", i);
        if ((i + primerDia) % 7 == 0 || i == diasEnMes[month - 1])
            printf("\n");
    }
}

int main() {
    int year, month;
    
    // Solicitar año y mes al usuario
    printf("Ingrese el año (entre 1601 y 3000): ");
    scanf("%d", &year);
    printf("Ingrese el mes (1-12): ");
    scanf("%d", &month);
    
    // Validar entrada del usuario
    if (year < 1601 || year > 3000 || month < 1 || month > 12) {
        printf("Año o mes no válido.\n");
        return 1;
    }
    
    // Imprimir calendario
    imprimirCalendario(year, month);
    
    return 0;
}
