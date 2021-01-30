#include <stdio.h> // printf
#include <stdlib.h> // rand y RAND_MAX
#include <unistd.h> // getpid
#include <time.h> //Time Null

//Declaración de variables
int saldo,banco,opcion,final,finalingreso,retiro,ingreso,conver,palabra;
int dona=100;
char salir,interr=168,a=219,aa=160,ae=130,ao=162;

//Case 4 (estado de seguridad de la cuenta por medio de arreglos) firma diseñada
int numeroAlAzar(int limiteSuperior,  int limiteInferior) //Definición de los límites del arreglo, esta función conforma el arreglo
{
	int valor =rand() % limiteSuperior + limiteInferior;
	return 0;
}
//Función encargada de la dirección de memoria del apuntador obtieneAlAzar
char *obtieneAlAzar(char *arreglo[], int tam)
{
	int indice = rand()%tam+1;//Al igual que en los valores, rand elige un valor a partir de la posición 1, no de la 0 
	char *palabra = arreglo[indice];
	return palabra;
}

// Función principal, cuerpo del programa
int main(){
    // Hay que alimentar a rand, solamente una vez (seed rand)
    srand(getpid());
    
int saldoInicial = rand()%20000,final; //El saldo es un valor aleatorio, se agrega la cantidad despues de % y toma un valor en ese intervalo

	//Mensaje de bienvenida
	printf("\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	printf("\n\t\t%c Bienvenido a HSBC  %c\n",a,a);
	printf("\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);

	//Comisión por banco ajeno
printf("\nIngresa el banco al que perteceneces: ");
printf("\n1) HSBC, 2) SANTANDER, 3) Bancomer, 4) Banamex 5) Otro \n");
scanf("%i",&banco); //Lectura de la opción seleccionada
	
	//Condicional de sentencia, se aplica una comisón al tratarse de otro banco emisor
	if (banco == 1)
		saldo = saldoInicial+0;
	else 
		saldo = saldoInicial-100; //Cobro de cantidad por banco extranjero


	//Seleccioón de opciones a realizar, aplicación de la sentencia repetitiva do-while
do{
	//Mostrar menú 
	printf("\a\n				********************************************");//Sentencia de escape aludiendo al sonido de una alarma
	printf("\n				* 1) Consulta de saldo                     *");
	printf("\n				* 2) Retiro de efectivo                    *");
	printf("\n				* 3) Ingreso de dinero                     *");
	printf("\n				* 4) Estado de seguiridad en la cuenta     *");
	printf("\n				* 5) Soporte t%ccnico                       *",ae);
	printf("\n				* 6) Salir                                 *\a\n");
	printf("				********************************************");
		//Solicitar la opción que desea
		printf("\n\tElige una opci%cn: ",ao);
		scanf("%d",&opcion);
		
	switch(opcion)
	{
		case 1: //Consulta de saldo
			printf("\n\tSu saldo actual es: %d\n",saldo);
			
				printf ("\n\t%cDesea realizar otra operaci&cn? 1)Si 2)No : ",interr,ao);
      			 scanf ("%d",&salir);
	  			 if(salir== 2) //El uso de == determina que para ese valor secumpla la condición
					exit (0); //Detener la ejecución del programa
				else
				printf("\tGracias por consultar su saldo :)\n");
			break;
			
		case 2: //Retiro de efectivo
			printf("\tBienvenido, %cCu%cnto dinero deseas retirar? $",interr,aa);
			scanf("%d",&retiro);
			
			//sentencia condicional si-de lo contrario
			if(retiro>saldo){//Operadores aritmeticos que verifican la condición
			
				printf("\t¡No cuentas con fondos suficientes!\n");
			}
			else
			{
				final = saldo - retiro; //Realización de una disminución en el saldo actual
			printf ("\tEl saldo bancario es:  %d\n\n", final);
			}
				printf ("\n\t%cDesea realizar otra operaci%cn? 1)Si 2)No : ",interr,ao);
      			 scanf ("%d",&salir);
	  			 if(salir== 2) //El uso de == determina que para ese valor secumpla la condición
					exit (0);
				else
				printf("\tGracias por retirar efectivo :) \n");
			
			break;
			
		case 3: //Ingreso de dinero
			printf("\tBienvenido. Ingrese la cantidad de dinero a ingresar $");
			scanf("%d",&ingreso); //Lectura de la cantidad solicitada
			
				if(ingreso>=100000){
					printf("\tCantidad no soportada por el sistema"); //Al ser un valor grande el cajero dicta que la operación no es posible
					}
				else{
					finalingreso=final+ingreso;
					printf ("\tEl saldo bancario es:  %d\n\n", finalingreso); //Impresión de las operaciones efectuadas o nulas
				}
			printf ("\n\t%cDesea realizar otra operaci%cn? 1)Si 2)No ",interr,ao);
      			 scanf ("%d",&salir);
	  			 if(salir== 2)
					exit (0);
				else
				printf("\tGracias por ingresar saldo a su  cuenta :) \n");
			break;
			
		case 4: //Estado de seguiridad en la cuenta
			
			srand(getpid()); //De la misma forma que el saldo inicial, se llama de nuevo a la  función de valores aleatorios
			srand(time(NULL)); //es un valor aleatorio desde el año 1970 y los segundos transcurridos hasta ahora. Nunca se repetirá
	
				char *palabras[] = {"Segura", "Insegura","Segura", "Insegura","Segura", "Insegura"}; //El arreglo de string es llamado por el apuntador *palabras
				int tam =sizeof(palabras) / sizeof(char *); // sizeof define el tamaño del  arreglo, teniendo en primer lugar las columnas y despues renglones
				char *palabra = obtieneAlAzar(palabras,tam); //Obtiene al azar es una función descrita al inicio del documento, cuyos valores son los mostrados
				printf("\tLa cuenta actualmente es: %s\n",palabra); 	
			break;
			
		case 5: //Soporte técnico
			printf("\tContacto con el creador del cajero: deibydcarranza@outlook.com \n");
			break;
			
		case 6: //Salir
			break;
			
		default: //Todo switch cuenta con una funcion por defecto en caso que no este en los intervalos descritos
			printf("\tOpci%cn no v%clida \n",ao,aa);
	}
	
  }while(opcion!=6); //Hasta no cumplirse este valor el ciclo seguira su funcionamiento 
	printf("\n\tGracias por usar el programa");

printf("\n\t%cDesea realizar alguna donaci%cn de $100 para la Facultad? 1)Si 2)No ",interr,ao);
scanf ("%d",&salir);
if(salir== 2)
final=finalingreso+0; //Operación de donación donde se retira una cierta cantidad de dinero al saldo
				else
								
					if(dona>saldo){ //En caso de ser menor a 100 no se habilita esta opción
			
						printf("\n¡No cuentas con fondos suficientes!\n");
					}
					else //De lo contrario se efectua la donación
					{
						final=finalingreso-dona;
						printf("\n\t\tGracias por su donaci%cn :)\n",ao);//ao es el acento ya que se presentan errores al compilar, este es su número en coódigo ASCII
					}
//Creación de un archivo de texto plano que recoplile los datos como saldo
FILE *a; //Se crea un apuntador "a" donde se crea un archivo al llamarse
	a=fopen("ticket.txt","w"); //fopen permite abrir un archivo y en caso de no existir lo crea, los permisos de escritura se expresan con "w"
		fprintf(a,"##########################################################");
		fprintf(a,"\nCajero automático realizado por Carranza Ochoa José David :) \n");
		fprintf(a,"------------------------------------------------------------------");
		fprintf(a,"\nSu saldo actual es $%d  ",final);
		fprintf(a,"\nEl tipo de moneda de cambio de su saldo actual es $%d dólares\n",conver=final/19);
		fprintf(a,"##########################################################"); //Al inicio de las operaciones al trabajar con archivos se debe especificar el apuntador
printf("\n\tSe ha generado su ticket de comprobante");

	fclose(a); //Conclusión de edición del archivo guardando los cambios

	return 0;
}
