#include <stdio.h>
#include <stdlib.h>

void main() {

	int plaza1 = 0, plaza2 = 0, abandonar;
	char opcion;
	char matricula1[8], matricula2[8];

	while (1) {

		printf("Seleccione una de las opciones mostradas:\n");
		printf("R para reservar una plaza.\n");
		printf("A para abandonar una plaza.\n");
		printf("E para ver el estado del aparcamiento.\n");
		scanf_s("%c", &opcion);
		getchar();

		switch (opcion) {
		
		case 'R':
		case 'r':
			if (plaza1 == 0) {
				printf("Has reservado la plaza 1.\n");
				printf("Introduzca su matricula:\n");
				scanf_s("%s", &matricula1,8);
				plaza1 = plaza1 + 1;
				getchar();
			}
			else if (plaza2 == 0) {
				printf("Has reservado la plaza 2.\n");
				printf("Introduzca su matricula:\n");
				scanf_s("%s", &matricula2,8);
				plaza2 = plaza2 + 1;
				getchar();
			}
			else {
				printf("el parking esta completo.\n");
			}
			system("pause");
			system("cls");
			break;
		
		case 'A':
		case 'a':
			printf("presione 1 si desea abandonar la plaza 1.\n");
			printf("presiones 2 si desea abandonar la plaza 2.\n");
			scanf_s("%d", &abandonar);
			getchar();
			if (abandonar == 1 && plaza1==1) {
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
			if (plaza1 == 1 && plaza2 == 0) {
				printf("la plaza 1 esta ocupada y la plaza 2 esta vacia\n");
				printf("numero de matricula de la plaza 1: %s\n", matricula1,8);
			}
			else if (plaza1 == 1 && plaza2 == 1) {
				printf("las dos plazas estan ocupadas\n");
				printf("numero de matricula de la plaza 1: %s\n", matricula1,8);
				printf("numero de matricula de la plaza 2: %s\n", matricula2,8);
			}
			else if (plaza1 == 0 && plaza2 == 1) {
				printf("la plaza 2 esta ocupada y la plaza 1 esta vacia\n");
				printf("numero de matricula de la plaza 2: %s\n", matricula2,8);
			}
			else {
				printf("las dos plazas estan vacias\n");
			}
			system("pause");
			system("cls");
			break;

		default:
			printf("esa opcion no es valida.\n");
			system("cls");
			
		}
	}
}