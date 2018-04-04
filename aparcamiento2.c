#include <stdio.h>
#include <stdlib.h>

void main() {

	int plaza1 = 0, plaza2 = 0, abandonar, comparacion1, comparacion2;
	char opcion, vehiculo1, vehiculo2;
	char matricula1[8], matricula2[8], buscador[8];

	do {
		printf("Seleccione una de las opciones mostradas:\n");
		printf("R para reservar una plaza.\n");
		printf("A para abandonar una plaza.\n");
		printf("E para ver el estado del aparcamiento.\n");
		printf("S para salir del programa.\n");
		printf("B para buscar matricula\n");
		scanf_s("%c", &opcion);
		getchar();

		switch (opcion) {

		case 'B':
		case'b':
			printf("intruzca la matricula que desee comprobar\n");
			scanf_s("%s", &buscador, 8);
			comparacion1 = strcmp(buscador, matricula1);
			comparacion2 = strcmp(buscador, matricula2);
			getchar();
			if (comparacion1 == 0)
				printf("el coche buscado esta situado en la plaza 1\n");
			else if (comparacion2 == 0)
				printf("el coche buscado esta situado en la plaza 2\n");
			else
				printf("no existe ninguna coincidencia\n");
			system("pause");
			system("cls");
			break;

		case 'R':
		case 'r':
			if (plaza1 == 0 || plaza2 == 0) {
				printf("pulse C si desea reservar la plaza para un coche o M si es para una moto\n");
				if (plaza1 == 0)
					scanf_s("%c", &vehiculo1);
				else if (plaza1 == 1 && plaza2 == 0)
					scanf_s("%c", &vehiculo2);
			}
			 if (plaza1 == 0) {
				printf("Has reservado la plaza 1.\n");
				printf("Introduzca su matricula:\n");
				scanf_s("%s", &matricula1, 8);
				plaza1 = plaza1 + 1;
				getchar();
			}
			else if (plaza2 == 0) {
				printf("Has reservado la plaza 2.\n");
				printf("Introduzca su matricula:\n");
				scanf_s("%s", &matricula2, 8);
				plaza2 = plaza2 + 1;
				getchar();
			}
			else
				printf("el parking esta completo.\n");

			system("pause");
			system("cls");
			break;

		case 'A':
		case 'a':
			printf("presione 1 si desea abandonar la plaza 1.\n");
			printf("presiones 2 si desea abandonar la plaza 2.\n");
			scanf_s("%d", &abandonar);
			getchar();
			if (abandonar == 1 && plaza1 == 1) {
				printf("has abandonado la plaza 1\n");
				plaza1 = 0;
			}
			else if (abandonar == 2 && plaza2 == 1) {
				printf("has abandonado la plaza 2\n");
				plaza2 = 0;
			}
			else {
				printf("opcion incorrecta.\n");
			}
			system("pause");
			system("cls");
			break;

		case 'E':
		case 'e':
			if (plaza1 == 1 && plaza2 == 0 && vehiculo1 == 'C') {
				printf("la plaza 1 esta ocupada por un coche y la plaza 2 esta vacia\n");
				printf("numero de matricula de la plaza 1: %s\n", matricula1, 8);
			}
			else if (plaza1 == 1 && plaza2 == 0 && vehiculo1 == 'M') {
				printf("la plaza 1 esta ocupada por una moto y la plaza 2 esta vacia\n");
				printf("numero de matricula de la plaza 1: %s\n", matricula1, 8);
			}
			else if (plaza1 == 0 && plaza2 == 1 && vehiculo2 == 'C') {
				printf("la plaza 2 esta ocupada por un coche y la plaza 1 esta vacia\n");
				printf("numero de matricula de la plaza 2: %s\n", matricula2, 8);
			}
			else if (plaza1 == 0 && plaza2 == 1 && vehiculo2 == 'M') {
				printf("la plaza 2 esta ocupada por una moto y la plaza 1 esta vacia\n");
				printf("numero de matricula de la plaza 2: %s\n", matricula2, 8);
			}
			else if (plaza1 == 1 && plaza2 == 1 && vehiculo1 == 'C' && vehiculo2 == 'C') {
				printf("las dos plazas estan ocupadas por dos coches\n");
				printf("numero de matricula de la plaza 1: %s\n", matricula1, 8);
				printf("numero de matricula de la plaza 2: %s\n", matricula2, 8);
			}
			else if (plaza1 == 1 && plaza2 == 1 && vehiculo1 == 'M' && vehiculo2 == 'M') {
				printf("las dos plazas estan ocupadas por dos motos\n");
				printf("numero de matricula de la plaza 1: %s\n", matricula1, 8);
				printf("numero de matricula de la plaza 2: %s\n", matricula2, 8);
			}
			else if (plaza1 == 1 && plaza2 == 1 && vehiculo1 == 'C' && vehiculo2 == 'M') {
				printf("la plaza 1 esta ocupada por un coche y la 2 por una moto\n");
				printf("numero de matricula de la plaza 1: %s\n", matricula1, 8);
				printf("numero de matricula de la plaza 2: %s\n", matricula2, 8);
			}
			else if (plaza1 == 1 && plaza2 == 1 && vehiculo1 == 'M' && vehiculo2 == 'C') {
				printf("las la plaza 1 esta ocupada por una moto y la 2 por un coche\n");
				printf("numero de matricula de la plaza 1: %s\n", matricula1, 8);
				printf("numero de matricula de la plaza 2: %s\n", matricula2, 8);
			}
			else {
				printf("las dos plazas estan vacias\n");
			}
			system("pause");
			system("cls");
			break;
		
		case 'S':
		case's':
			break;
		
		default:
			printf("esa opcion no es valida.\n");
			system("pause");
			system("cls");
		}
	}
	while (opcion != 'S' && opcion != 's');
}