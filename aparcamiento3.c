#include <stdio.h>
#include <stdlib.h>

struct plaza {
	int estado;
	char tipo;
	char matricula[8];
};


void main() {

	int plaza1 = 0, plaza2 = 0, abandonar, comparacion1, comparacion2, i = 0;
	char opcion, usuario[50] = "admin", contrasena[50] = "1234", usuario1[50], contrasena1[50];
	char buscador[8];
	struct plaza aparcar[2];

	while (i < 3) {
		printf("intoduzca el nombre de usuario:\n");
		scanf_s("%s", usuario1, 50);
		printf("introduzca la contrasena:\n");
		scanf_s("%s", contrasena1, 50);
		getchar();

		comparacion1 = strcmp(usuario, usuario1);
		comparacion2 = strcmp(contrasena, contrasena1);

		if (comparacion1 == 0 && comparacion2 == 0) {
			opcion = 'R';
			break;
		}
		else {
			printf("usuario o contrasena incorrectas.\n");
			i++;
			opcion = 'S';
			system("pause");
			system("cls");
		}
	}
	aparcar[0].estado = 0;
	aparcar[1].estado = 0;

	while (opcion != 'S' && opcion != 's'){
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
			comparacion1 = strcmp(buscador, aparcar[0].matricula);
			comparacion2 = strcmp(buscador, aparcar[1].matricula);
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
			aparcar[1].tipo = 'C';

			if (plaza1 == 0 || plaza2 == 0) {
				printf("pulse C si desea reservar la plaza para un coche o M si es para una moto\n");
				if (plaza1 == 0) {
					scanf_s("%c", &aparcar[0].tipo);
				getchar();
				}
				else if (plaza1 == 1 && plaza2 == 0) {
					scanf_s("%c", &aparcar[1].tipo);
					getchar();
				}

				while ((aparcar[0].tipo!= 'C' && aparcar[0].tipo != 'c' && aparcar[0].tipo != 'M' && aparcar[0].tipo != 'm') || (aparcar[1].tipo != 'C' && aparcar[1].tipo != 'c' && aparcar[1].tipo != 'M' && aparcar[1].tipo != 'm')) {
					printf("opcion incorrecta.\n");
					printf("pulse C si desea reservar la plaza para un coche o M si es para una moto\n");
					if (plaza1 == 0) {
						scanf_s("%c", &aparcar[0].tipo);
						getchar();
					}
					else if (plaza1 == 1 && plaza2 == 0) {
						scanf_s("%c", &aparcar[1].tipo);
						getchar();
					}
				}
			}
			if (plaza1 == 0) {
				printf("Has reservado la plaza 1.\n");
				printf("Introduzca su matricula:\n");
				getchar();
				gets(aparcar[0].matricula);
				plaza1 = plaza1 + 1;
				aparcar[0].estado = 1;
			}
			else if (plaza2 == 0) {
				printf("Has reservado la plaza 2.\n");
				printf("Introduzca su matricula:\n");
				gets(aparcar[1].matricula);
				plaza2 = plaza2 + 1;
				aparcar[1].estado = 1;
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
				aparcar[0].estado = 0;
				aparcar[0].tipo = 0;
			}
			else if (abandonar == 2 && plaza2 == 1) {
				printf("has abandonado la plaza 2\n");
				plaza2 = 0;
				aparcar[1].estado = 0;
				aparcar[1].tipo = 0;
			}
			else {
				printf("opcion incorrecta.\n");
			}
			system("pause");
			system("cls");
			break;

		case 'E':
		case 'e':

			for (i = 0; i < 2; i++) {
				printf("plaza %d:\n", i+1);
				if (aparcar[i].estado == 0)
					printf("estado: vacia\n");
				else if (aparcar[i].estado == 1)
					printf("estado: ocupada\n");

				if (aparcar[i].tipo == 'C')
					printf("tipo de vehiculo: coche\n");
				else if (aparcar[i].tipo == 'M')
					printf("tipo de vehiculo: coche\n");
				else
					printf("tipo de vehiculo: ninguno\n");

				if (aparcar[i].estado == 1)
					printf("matricula: %s\n", aparcar[i].matricula);
				else
					printf("matricula: ninguna\n");
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
}