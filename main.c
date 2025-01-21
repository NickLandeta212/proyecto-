#include <stdio.h>

int main() {
    int opcion;
    float distancia, costoBoleto, montoPagado, cambio;
    int monedas5 = 0, monedas2 = 0, monedas1 = 0;
    float tarifaPorKilometro = 5.0;

    do {
        printf("\n=== Menu de la Maquina de Boletos ===\n");
        printf("1. Comprar boleto\n");
        printf("2. Salir\n");
        printf("Selecciona una opcion: ");

        while (1) {
            if (scanf("%d", &opcion) != 1) {
                printf("Error: Por favor ingresa un numero entero valido.\n");
                while (getchar() != '\n'); 
            } else {
                break;
            }
        }

        switch(opcion) {
            case 1:
                printf("Introduce la distancia del viaje en kilometros: ");
      
                while (1) {
                    if (scanf("%f", &distancia) != 1) {
                        printf("Error: Por favor ingresa un numero valido.\n");
                        while (getchar() != '\n');
                    } else {
                        break;
                    }
                }

                costoBoleto = distancia * tarifaPorKilometro;
                printf("El costo del boleto es: %.2f pesos.\n", costoBoleto);


                do {
                    printf("Introduce el monto que pagas: ");
                    while (1) {
                        if (scanf("%f", &montoPagado) != 1) {
                            printf("Error: Por favor ingresa un numero valido.\n");
                            while (getchar() != '\n');
                        } else {
                            break;
                        }
                    }

                    if (montoPagado < costoBoleto) {
                        printf("El monto pagado es insuficiente. Intenta de nuevo.\n");
                    }
                } while (montoPagado < costoBoleto);

                cambio = montoPagado - costoBoleto;

                printf("\n=== Resumen ===\n");
                printf("Costo del boleto: %.2f pesos.\n", costoBoleto);
                printf("Monto pagado: %.2f pesos.\n", montoPagado);
                printf("Cambio a devolver: %.2f pesos.\n", cambio);

            
                monedas5 = cambio / 5;
                cambio = cambio - (monedas5 * 5);

                monedas2 = cambio / 2;
                cambio = cambio - (monedas2 * 2);

                monedas1 = cambio / 1;
                cambio = cambio - (monedas1 * 1);

                printf("Cambio: %d monedas de 5 pesos, %d monedas de 2 pesos, %d monedas de 1 peso.\n",
                       monedas5, monedas2, monedas1);

                break;

            case 2:
                printf("Gracias por usar la maquina de boletos.Hasta pronto!\n");
                break;

            default:
                printf("Opcion no valida. Por favor, selecciona una opcion valida.\n");
        }

    } while(opcion != 2);

    return 0;
}