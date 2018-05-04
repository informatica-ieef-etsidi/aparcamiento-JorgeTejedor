#include <stdio.h>
#include <stdlib.h>
#define NPLAZAS 5

struct plaza {
	int estado;
	char tipo;
	char matricula[8];
};


void main() {

	int plazaN[NPLAZAS], abandonar, comparacion1, comparacion2, i = 0;
	char opcion, usuario[50] = "admin", contrasena[50] = "1234", usuario1[50], contrasena1[50];
	char buscador[8];
	struct plaza aparcar[NPLAZAS];

	while (i < 3) {
		printf("intoduzca el nombre de usuario:\n");
		gets(usuario1);
		printf("introduzca la contrasena:\n");
		gets(contrasena1);

		comparacion1 = strcmp(usuario1, usuario);
		comparacion2 = strcmp(contrasena1, contrasena);

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
	for (i = 0; i < NPLAZAS; i++) {
		aparcar[i].estado = 0;
	}

	i = 0;

	while (opcion != 'S' && opcion != 's') {
		printf("Seleccione una de las opciones mostradas:\n");
		printf("R para reservar una plaza.\n");
		printf("A para abandonar una plaza.\n");
		printf("E para ver el estado del aparcamiento.\n");
		printf("S para salir del programa.\n");
		printf("B para buscar matricula\n");
		scanf_s("%c", &opcion);
		getchar();

		i = 0;
		while (aparcar[i].estado != 0 && i < NPLAZAS) {
			i++;
		}

		switch (opcion) {

		case 'B':
		case'b':
			printf("intruzca la matricula que desee comprobar\n");
			gets(buscador);
			for (i = 0; i < NPLAZAS; i++) {
				comparacion1 = strcmp(buscador, aparcar[i].matricula);

				if (comparacion1 == 0)
					printf("el coche buscado esta situado en la plaza %d.\n", i+1);
			}

			if(i == NPLAZAS)
				printf("no existe ninguna coincidencia\n");

			system("pause");
			system("cls");
			break;

		case 'R':
		case 'r':
			if (i > NPLAZAS)
				printf("el parking esta completo.\n");

			else {

				printf("pulse C si desea reservar la plaza para un coche o M si es para una moto\n");
				getchar();
				scanf_s("%c", &aparcar[i].tipo);

				while (aparcar[i].tipo != 'C' && aparcar[i].tipo != 'c' && aparcar[i].tipo != 'M' && aparcar[i].tipo != 'm') {
					printf("la opcion no es correcta.\n");
					printf("pulse C si desea reservar la plaza para un coche o M si es para una moto\n");
					scanf_s("%c", &aparcar[i].tipo);
				}
				getchar();
				printf("Has reservado la plaza %d.\n", i + 1);
				printf("Introduzca su matricula:\n");
				getchar();
				gets(aparcar[i].matricula);
				aparcar[i].estado = 1;
			}

			system("pause");
			system("cls");
			break;

		case 'A':
		case 'a':

			printf("marque el numero de plaza que desea abandonar.\n");
			scanf_s("%d", &abandonar);
			getchar();

			if (abandonar > NPLAZAS)
				printf("no existe la plaza que seleccioado.\n");

			else if (aparcar[abandonar - 1].estado == 1) {
				printf("ha abandonado la plaza %d.\n", abandonar);
				aparcar[abandonar - 1].estado = 0;
			}
			else
				printf("la plaza que ha seleccionado ya esta vacia.\n");
			
			system("pause");
			system("cls");
			break;
	
		case 'E':
		case 'e':

			for (i = 0; i < NPLAZAS; i++) {
				printf("plaza %d:\n", i + 1);
				if (aparcar[i].estado == 0)
					printf("estado: vacia\n");
				else if (aparcar[i].estado == 1)
					printf("estado: ocupada\n");

				if (aparcar[i].tipo == 'C')
					printf("tipo de vehiculo: coche\n");
				else if (aparcar[i].tipo == 'M')
					printf("tipo de vehiculo: moto\n");
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