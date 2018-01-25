//====   TRABAJO FINAL DE PROGRAMACIÓN:   ===================================================================================================================================================================
//===========================================================================================================================================================================================================
//==============                                                                                                                                                                  ===========================
//============   HHH   HHH  UUU   UUU  NNNN     NNN  DDDDDDDDD   III  RRRRRRRRR        LLLL         AAAAAAAAA       FFFFFFFFFF  LLL          OOOOOOOOOO   TTTTTTTTTTT   AAAAAAAAA   =========================
//============   HHH   HHH  UUU   UUU  NNNNN    NNN  DDD    DDD  III  RRR    RRR        LLL        AAA     AAA       FFF        LLL         OOO      OOO      TTT      AAA     AAA   ========================
//===========   HHHHHHHHH  UUU   UUU  NNN NNN  NNN  DDD     DDD III  RRRRRRRRR         LLL        AAAAAAAAAAA       FFFFFF     LLL         OOO      OOO      TTT      AAAAAAAAAAA   =========================
//==========   HHH   HHH  UUU   UUU  NNN  NNN NNN  DDD     DDD III  RRR   RRR         LLL        AAA     AAA       FFF        LLL         OOO      OOO      TTT      AAA     AAA   ==========================
//=========   HHH   HHH  UUU   UUU  NNN    NNNNN  DDD    DDD  III  RRR    RRR        LLL        AAA     AAA       FFF        LLL         OOO      OOO      TTT      AAA     AAA   ===========================
//========   HHH   HHH   UUUUUUU   NNN     NNNN  DDDDDDDDD   III  RRR     RRR       LLLLLLLLL  AAA     AAA       FFF        LLLLLLLLL    OOOOOOOOOO       TTT      AAA     AAA   ============================
//=========                                                                                                                                                                     === VER_1.0 =================
//===========================================================================================================================================================================================================
//===========================================================================================================================================================================================================

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define FALSE 0
#define TRUE 1
#define CORRECTO 1
#define ERROR 0

//FUNCIONES DEL MENU ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void menu_principal();
void historia();
void creditos();
void pre_juego();
void juego();
void instrucciones();

//FUNCIONES DEL PRE-JUEGO -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void ini_matrices();
void editor_pos();
void generador_matrices_de_juego();
void mostrar_Tablero();
void mostrar_Tablero1();
void mostrar_Tablero2();
void mensaje_de_error ();
void mod_file_matriz_ia();

// Para comprobar que los barcos esten dentro de la matriz.

int comprobador_de_barcos2 ( int fila, int columna , char c );
int comprobador_de_barcos3 ( int fila, int columna , char c );
int comprobador_de_barco4  ( int fila, int columna , char c );

// Para comprobar que no se repitan las elecciones de las posiciones de los barcos.
int comprobador_de_repeticion ( int fila, int columna, char m[12][12], char orientacion, int longitud);
int comprobador_de_matriz_ia ( int fila, int columna, char m[12][12], char orientacion, int longitud);

// Para camprobar la tirada en el juego.
int comprobador_de_tirada ( int fila, int columna, char a[12][12], char jugada[12][12] );

// Para comprobar si ha puesto RECORD de puntuación.
void comp_hscore ( long int );
void carga_hscore();

//Generacion de matrices.
int comp_m_ia();
void generador_de_matriz_IA ();
int comprobador_de_barcos2ia  ( int fila, int columna , char c );
int comprobador_de_barcos3ia ( int fila, int columna , char c );
int comprobador_de_barco4ia  ( int fila, int columna , char c );

/*==============================================================================================================================================================================================================
                                                                                -FUNCIONES DEL JUEGO-                                               
==============================================================================================================================================================================================================*/

int main (){

    menu_principal();
   
return 0;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------       Funciones prejuego.       ----------------------------------------------------------------------------------------------------                                             
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void menu_principal(){
   
   int eleccion;
   char aux;
   
   system("color 70");//Fondo: Blanco, Letras: Negras.
   
    do{
	   
	   carga_hscore();
	   printf("  Bienvenidos al juego de hundir la flota!!!\n Esperemos que disfrutes del Minijuego\n\n Pulse:\n  1:: Si quieres jugar.\n  2:: Si quieres conocer la historia\n  3:: Creditos\n  4:: Salir\n\n   Tu seleccion: ");
	   scanf("%d", &eleccion);
	
	   if (eleccion == 1){
		   printf("preparando juego....");
		   system("cls");
		   instrucciones();
		   system("cls");
		   pre_juego();
        }else if (eleccion == 2){
    	   printf("preparando historia....");
    	   system("cls");
    	   historia();
	    }else if (eleccion == 3){
		   printf("preparando creditos....");
		   system("cls");
		   creditos();
        }else{
	       printf("Saliendo...");
	    
		}//if else
		
		system("cls");		
    }while (eleccion != 1 && eleccion != 2 && eleccion != 3 && eleccion != 4);//do
}
void creditos(){
	 
	printf("Creacion: \n Jose M. Zamora Batista.\n\n\n ");

system("pause");
system("cls");

menu_principal();

}
void historia(){
	
    printf("Año: 2065.\n\n Durante centenares de siglos el ser humano ha intentado contactar con vida extraterrestre, enviando mensajes a traves de ondas hacia el espacio esperando ser escuchadas.\n\n");
	printf(" Lamentablemente nuestras ondas fueron escuchadas por una alianza extraterrestre hostil ''Los Katch-Aclan'', quienes mal interpretando las ondas terrestres deciden declarar la guerra a la raza humana.\n\n");
	printf(" Es entonces cuando las Organizaciones Mundiales intentan hacer un pacto mutuo, pero que, al ser rechazado por los Katch-Aclan deciden llamar a los estrategas mas experimentados de la tierra.\n ");
	printf("\n\nCon el fin de HUNDIR SU FLOTA!!! \n\n");
    printf("\n Pulse cualquier tecla para Volver.");
    
system("pause>nul");
system("cls");

menu_principal();
	
}
void pre_juego (){
	
	int  seleccion1;
	int  aux = 0, aux1, elec, elec1;
	char mPlayer[12][12];
	char matrizIa[12][12];
    char namePlayer[20];
    
    ini_matrices( mPlayer );  //inicializa las matrices.
    ini_matrices( matrizIa );
    
 do{
   
      system ("cls");
   
      printf(" Decida contra que matriz desea jugar.\n  Pulse: \n\n 1:: Para cargar el fichero matrizia.txt.\n 2:: Para generar una matriz rival aleatoria");
      printf("\n\n   Tu seleccion: ");
      scanf("%i", &elec);
   
      if( elec == 1 ){
   	    
		   mod_file_matriz_ia( matrizIa );
   
      }else if( elec == 2){
   	  
	    while(aux != 20){
		    
			ini_matrices( matrizIa );
			generador_de_matriz_IA ( matrizIa );
	        aux = comp_m_ia( matrizIa );

        }	     
    }else{
   	    printf("Dato erroneo.\n");
    }  
  
  }while(elec != 1 && elec != 2);
    
    system("cls");
	printf("\n\n Como deberiamos llamarte: ");
    fflush(stdin);
    scanf ("%s" , &namePlayer);
  
   do{ 
      printf("Decida con que matriz desea jugar.\n");
      printf("  Pulse:\n  1:: Para colocar tus barcos en el editor de Posiciones\n  2:: Para generar una matriz aleatoria.\n");
      scanf("%d", &elec1);
   
      if( elec1 == 1 ){
   	    
		 editor_pos(mPlayer, namePlayer);
   
      }else if( elec1 == 2){
   	 
		 while(aux != 20){
		    
		    ini_matrices( mPlayer ); 
			generador_de_matriz_IA ( mPlayer );
	        aux = comp_m_ia( mPlayer );
  
        }
        
      }else{
   	    printf("Dato erroneo.\n");
   	    system("pause");
   } 
    
  }while(elec1 != 1 && elec1 != 2);

	printf("\nPulse cualquier tecla para JUGAR!!!\n\n");
	system ("pause>nul");
	system("cls");
	juego ( mPlayer, matrizIa, namePlayer);	           
    system("cls");
	menu_principal();
}
void instrucciones(){
	
	printf("                           INSTRUCCIONES\n");
	printf("                           =============\n");
	printf(" Este juego es muy sencillo, primeramente tendras que colocar los barcos comenzando por los de longitud 1 hasta el de longitud 4, pasando por los de 2 y de 3.\n");
	printf(" La colocacion de los barcos de longitud mayor que 1, se realizara indicando las coordenadas donde se colocara la proa de la nave y a continuacion ");
	printf("se colocaran en el tablero las continuaciones de los mismos.\n");
	printf(" Por ejemplo: Vas a colocar un barco de longitud 3. Despues de introducir las coordenadas de la proa y haber seleccionado H(horizontal) la direccion del barco...\n\n");
	printf("                         |   | + | + | + |   |\n");
	printf(" El barco habra quedado: | + | 3 | 3 | 3 | + |\n");
	printf("                         |   | + | + | + |   |\n\n");
	printf(" -Los 1(unos) representan los barcos de longitud 1.\n");
	printf(" -Los 2(dos) representan los barcos de longitud 2.\n");
	printf(" -Los 3(tres) representan los barcos de longitud 3.\n");
	printf(" -Los 4(cuatros) representa el barco de longitud 4.\n");
	printf(" -Los simbolos de suma (+), representan las ondas que generan los barcos en a su alrededor, por lo que no podras colocar barcos en dichas zonas.\n\n");
	printf(" Posteriormente comenzara la batalla y jugaras lanzando ataques seleccionando coordenadas.\n");
	printf(" Dichas coordenadas se colocaran en el tablero de dos formas: \n  -La primera sera en forma de O(agua), indicando que has fallado.\n");
	printf("  -La segunda en forma de X, que indicara que has acertado en el ataque y por consiguiente jugarás de nuevo-\n");
	printf(" La partida acaba si destruyes los 10 barcos enemigos o, si pierdes los tuyos.\n");
	printf("Y ahora.... A JUGAR!!!\n");
	
	system("pause");
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------     Funciones modificadoras de Matrices y de comprobación.    ------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

// Funcion que inicializa las matrices
void ini_matrices ( char a[12][12]){  

int i,j;

    for(i=0;i<12;i++){
	    for(j=0;j<12;j++){
		   a[i][j] = ' ';
	    }
    }
}

//Funciones para mostrar el tablero en pantalla de determinadas maneras.

void mostrar_Tablero (char a [12][12] ){

int i,j;

printf("%c%c%c%c%c%c%c%c%c%c%c%c%c||Jugadas Realizadas||%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n" ,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);

printf("%c-------------------------------------------------%c\n", 219,219);
for(i=0;i<12;i++){
	for(j=0;j<12;j++){
		
        if( a[i][j] == '0'){
			a[i][j] = ' ';
		}
		if( a[i][j] == '1' || a[i][j] == '2' || a[i][j] == '3' || a[i][j] == '4'){
			a[i][j] = 'X';
		}
        
		a[0][0] = '#';
		a[0][11] = '#';
		a[i][11] = '#';
		a[11][j] = '#';
		
		a[0][1] = '0';
		a[0][2] = '1';
		a[0][3] = '2';
		a[0][4] = '3';
		a[0][5] = '4';
		a[0][6] = '5';
		a[0][7] = '6';
		a[0][8] = '7';
		a[0][9] = '8';
		a[0][10] = '9';
		
		a[1][0] = 'a';
		a[2][0] = 'b';
		a[3][0] = 'c';
		a[4][0] = 'd';
		a[5][0] = 'e';
		a[6][0] = 'f';
		a[7][0] = 'g';
		a[8][0] = 'h';
		a[9][0] = 'i';
		a[10][0] = 'j';
		
		if(j == 0) printf("%c",219);
		printf("|");
		if(j < 11) printf(" %c ", a[i][j] );
	    if(j == 11) printf(" %c |%c\n", a[i][j] , 219 );
	}
	printf("%c-------------------------------------------------%c\n" ,219,219);
 }printf("%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219);
  printf("%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219);
  printf("%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219);
  printf("%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219);
  printf("%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219);
}	
void mostrar_Tablero1 (char a [12][12] ){

int i,j;

printf("%c%c%c%c%c%c%c%c%c%c%c%c%c||||TABLERO ACTUAL||||%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n" ,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);

printf("%c-------------------------------------------------%c\n", 219,219);
for(i=0;i<12;i++){
	for(j=0;j<12;j++){
		
        a[0][0] = '#';
		a[0][11] = '#';
		a[i][11] = '#';
		a[11][j] = '#';
		
		a[0][1] = '0';
		a[0][2] = '1';
		a[0][3] = '2';
		a[0][4] = '3';
		a[0][5] = '4';
		a[0][6] = '5';
		a[0][7] = '6';
		a[0][8] = '7';
		a[0][9] = '8';
		a[0][10] = '9';
		
		a[1][0] = 'a';
		a[2][0] = 'b';
		a[3][0] = 'c';
		a[4][0] = 'd';
		a[5][0] = 'e';
		a[6][0] = 'f';
		a[7][0] = 'g';
		a[8][0] = 'h';
		a[9][0] = 'i';
		a[10][0] = 'j';
		
		if(j == 0) printf("%c",219);
		printf("|");
		if(j < 11) printf(" %c ", a[i][j] );
	    if(j == 11) printf(" %c |%c\n", a[i][j] , 219 );
	}
	printf("%c-------------------------------------------------%c\n" ,219,219);
 }printf("%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219);
  printf("%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219);
  printf("%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219);
  printf("%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219);
  printf("%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219);
}	
void mostrar_Tablero2 (char a [12][12] ){
	
	int i,j;

printf("%c%c%c%c%c%c%c%c%c%c%c%c%c||Tablero del Jugador||%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n" ,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);

printf("%c-------------------------------------------------%c\n", 219,219);
for(i=0;i<12;i++){
	for(j=0;j<12;j++){
		
        if( a[i][j] == '0'){
			a[i][j] = ' ';
		}
        
		a[0][0] = '#';
		a[0][11] = '#';
		a[i][11] = '#';
		a[11][j] = '#';
		
		a[0][1] = '0';
		a[0][2] = '1';
		a[0][3] = '2';
		a[0][4] = '3';
		a[0][5] = '4';
		a[0][6] = '5';
		a[0][7] = '6';
		a[0][8] = '7';
		a[0][9] = '8';
		a[0][10] = '9';
		
		a[1][0] = 'a';
		a[2][0] = 'b';
		a[3][0] = 'c';
		a[4][0] = 'd';
		a[5][0] = 'e';
		a[6][0] = 'f';
		a[7][0] = 'g';
		a[8][0] = 'h';
		a[9][0] = 'i';
		a[10][0] = 'j';
		
		if(j == 0) printf("%c",219);
		printf("|");
		if(j < 11) printf(" %c ", a[i][j] );
	    if(j == 11) printf(" %c |%c\n", a[i][j] , 219 );
	}
	printf("%c-------------------------------------------------%c\n" ,219,219);
 }printf("%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219);
  printf("%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219);
  printf("%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219);
  printf("%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219);
  printf("%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219);
}

//Funcion para introducir los barcos por parte del Jugador.

void editor_pos( char a[12][12], char namePlayer[20]){
	
    
	char dir;
    int barco;  // longitud del barco;
	int varDcomprobacion = 0;
	int varDcomprobacionRep = 0;
    int cantBarco;
	int i, j;
	char c;

    system("cls");


    printf("Comenzaremos por los barcos de longitud 1...\n\n");

    cantBarco = 4;
	dir = 'a';
    barco = 1;
	  
	  do{
       do{
        do {
            
            mostrar_Tablero2 (a);
            printf("\n\n");
            
            printf("Diga en que fila quiere colocarlo(a-j)\n>");
            scanf("%s", &c);
            
			if ( c != 'a' && c != 'b' && c != 'c' && c!='d' && c!='e' && c!='f' && c!= 'g' && c!= 'h' && c!='i' && c!='j') {
                printf("Dato erroneo\n");
				system("pause>nul");
				system("cls");}
        }while( c != 'a' && c != 'b' && c != 'c' && c!='d' && c!='e' && c!='f' && c!= 'g' && c!= 'h' && c!='i' && c!='j');


        do {

            printf("Diga en que columna quiere colocarlo(0-9)\n>");
            scanf("%d", &j);
            
			if ( j < 0 || j > 9 ) {
                printf("Dato erroneo\n");
				system("pause>nul");
				system("cls");}
        }while( j < 0 || j > 9);
 
        switch (c){
        	case 'a': i = 1;
        		break;
        	case 'b': i = 2;
        		break; 
        	case 'c': i = 3;
        		break;
        	case 'd': i = 4;
        		break; 
        	case 'e': i = 5;
				break;
        	case 'f': i = 6;
        		break;
        	case 'g': i = 7;
        		break;
        	case 'h': i = 8;
        		break; 
        	case 'i': i = 9;
        		break;
        	case 'j': i = 10;
        		break;
		}
		 
		j = j + 1;
		
		varDcomprobacionRep = comprobador_de_repeticion ( i, j, a , dir, barco);

	  }while (varDcomprobacionRep ==  TRUE );
    
        a[i][j] = '1';

        a[i][j-1] = '+';
        a[i][j+1] = '+';
        a[i-1][j] = '+';
        a[i+1][j] = '+';

        system("cls");

        cantBarco = cantBarco - 1;

        printf ("Faltan por colocar: %d barcos de longitud 1\n\n", cantBarco);
        

    } while (cantBarco > 0 );

    
	system("cls");

    printf ("Es hora de colocar los barcos de longitud 2...\n\n");

    cantBarco = 3;
    barco = 2;
    
	
	while (cantBarco > 0){    
       
	   do{
        	
        do {

            mostrar_Tablero2(a);
            printf("\n\n");

            printf("Diga en que fila quiere colocarlo(a-j)\n>");
            fflush(stdin);
            scanf("%c", &c);
            
			if (  c != 'a' && c != 'b' && c != 'c' && c!='d' && c!='e' && c!='f' && c!= 'g' && c!= 'h' && c!='i' && c!='j' ) {
                printf("Dato erroneo\n");
				
				system("pause>nul");
				system("cls");}

        }while(  c != 'a' && c != 'b' && c != 'c' && c!='d' && c!='e' && c!='f' && c!= 'g' && c!= 'h' && c!='i' && c!='j' );

        do{

            printf("Diga en que columna quiere colocarlo(0-9)\n>");
            
            scanf("%d", &j);

            if ( j < 0 || j > 9 ) {
                printf("Dato erroneo\n");
				system("pause>nul");
				system("cls");}


        }while( j < 0 || j > 9 );

        do{

            printf("Diga en la orientacion (V= Vertical y H= Horizontal)\n>");
            fflush(stdin);
            scanf("%c", &dir);

            if( dir != 'V' && dir != 'H' && dir != 'v' && dir != 'h'){
                printf ("Introduce letra de direccion valida\n"); }

        } while( dir != 'V' && dir != 'H' && dir != 'v' && dir != 'h');
     
        switch (c){
        	
			case 'a': i = 1;
        		break;
        	case 'b': i = 2;
        		break; 
        	case 'c': i = 3;
        		break;
        	case 'd': i = 4;
        		break; 
        	case 'e': i = 5;
        		break;
        	case 'f': i = 6;
        		break;
        	case 'g': i = 7;
        		break;
        	case 'h': i = 8;
        		break; 
        	case 'i': i = 9;
        		break;
        	case 'j': i = 10;
        		break;
		}
		 
		j = j + 1;
     
	 varDcomprobacion = comprobador_de_barcos2 ( i, j, dir );
     varDcomprobacionRep = comprobador_de_repeticion ( i, j, a , dir, barco);
	
    
	 }while(varDcomprobacion == ERROR || varDcomprobacionRep == TRUE);

        if( varDcomprobacion == CORRECTO && varDcomprobacionRep == FALSE ){
		
		if (dir == 'V' || dir == 'v'){

            a[i][j] = '2';
            a[i+1][j] = '2';

            a[i-1][j] = '+';
            a[i+2][j] = '+';
            a[i][j-1] = '+';
            a[i][j+1] = '+';
            a[i+1][j-1] = '+';
            a[i+1][j+1] = '+';

        }else{

            a[i][j] = '2';
            a[i][j+1] = '2';

            a[i][j-1] = '+';
            a[i][j+2] = '+';
            a[i-1][j] = '+';
            a[i+1][j] = '+';
            a[i-1][j+1] = '+';
            a[i+1][j+1] = '+';

        }
      }
        system("cls");

        cantBarco = cantBarco - 1;
        printf ("Faltan por colocar: %d barcos de longitud 2\n\n", cantBarco);

    }

    system("cls");
    
    printf ("Y ahora coloca los barcos de longitud 3...\n\n");

    cantBarco = 2;
    barco = 3;
   while(cantBarco > 0 ){ 
	 
	 do{

        do {
            
			mostrar_Tablero2(a);
            printf("\n\n");
			
			printf("Diga en que fila quiere colocarlo(a-j)\n>");
            fflush(stdin);
            scanf("%s", &c);
            if (  c != 'a' && c != 'b' && c != 'c' && c!='d' && c!='e' && c!='f' && c!= 'g' && c!= 'h' && c!='i' && c!='j' ) {
                printf("Dato erroneo\n");
				
				system("pause>nul");
				system("cls");}
				
        }while(  c != 'a' && c != 'b' && c != 'c' && c!='d' && c!='e' && c!='f' && c!= 'g' && c!= 'h' && c!='i' && c!='j' );

        do {
            printf("Diga en que columna quiere colocarlo(0-9)\n>");
            scanf("%d", &j);
            if ( j < 0 || j > 9 ) {
                printf("Dato erroneo\n");
				system("pause>nul");
				system("cls");}
				
        }while(j > 9 || j < 0);

        do{
               printf("Diga en la orientacion (V= Vertical y H= Horizontal)\n>");
               fflush(stdin);
               scanf("%c", &dir);

               if( dir != 'V' && dir != 'H' && dir != 'v' && dir != 'h'){
                   printf ("Introduce letra de direccion valida\n");}

           } while ( dir != 'V' && dir != 'H' && dir != 'v' && dir != 'h');
     
	    switch (c){
        	
			case 'a': i = 1;
        		break;
        	case 'b': i = 2;
        		break; 
        	case 'c': i = 3;
        		break;
        	case 'd': i = 4;
        		break; 
        	case 'e': i = 5;
        		break;
        	case 'f': i = 6;
        		break;
        	case 'g': i = 7;
        		break;
        	case 'h': i = 8;
        		break; 
        	case 'i': i = 9;
        		break;
        	case 'j': i = 10;
        		break;
		}
		 
		j = j + 1;
	 
	 varDcomprobacion = comprobador_de_barcos3( i, j, dir );      
	 varDcomprobacionRep = comprobador_de_repeticion ( i, j, a , dir, barco);
    }while(varDcomprobacion == ERROR || varDcomprobacionRep == TRUE);
        
          if( varDcomprobacion == CORRECTO && varDcomprobacionRep == FALSE ){
          
		       if(dir == 'V' || dir == 'v'){

                 a[i][j] = '3';
                 a[i+1][j] = '3';
                 a[i+2][j] = '3';

                 a[i-1][j] = '+';
                 a[i][j-1] = '+';
                 a[i][j+1] = '+';
                 a[i+1][j-1] = '+';
                 a[i+1][j+1] = '+';
                 a[i+2][j-1] = '+';
                 a[i+2][j+1] = '+';
                 a[i+3][j] = '+';


                 } else {

                 a[i][j] = '3';
                 a[i][j+1] = '3';
                 a[i][j+2] = '3';

                 a[i][j-1] = '+';
                 a[i-1][j] = '+';
                 a[i+1][j] = '+';
                 a[i-1][j+1] = '+';
                 a[i+1][j+1] = '+';
                 a[i-1][j+2] = '+';
                 a[i+1][j+2] = '+';
                 a[i][j+3] = '+';
               }
           }
           
        system("cls");
        
	    cantBarco = cantBarco - 1;
        
		printf ("Faltan por colocar: %d barcos de longitud 3\n\n", cantBarco);

    }
 
    system("cls");

    printf("Por ultimo coloca el barco longitud 4...\n\n");

    barco = 4;
    do{ 
         do {
             
			 mostrar_Tablero2(a);
             printf("\n\n");
			 
			 printf("Diga en que fila quiere colocarlo\n>");
             fflush(stdin);
             scanf("%s", &c);
             if ( c != 'a' && c != 'b' && c != 'c' && c!='d' && c!='e' && c!='f' && c!= 'g' && c!= 'h' && c!='i' && c!='j' ) {
                 printf("Dato erroneo\n");

				system("pause>nul");
				system("cls");}
            }while (  c != 'a' && c != 'b' && c != 'c' && c!='d' && c!='e' && c!='f' && c!= 'g' && c!= 'h' && c!='i' && c!='j');

         do {
             printf("Diga en que columna quiere colocarlo\n>");
             scanf("%d", &j);
             if ( j < 0 || j > 9 ) {
                 printf("Dato erroneo\n");
				 
				 system("pause>nul");
				 system("cls");}
            }while( j > 9 || j < 0 );

         do {
              printf("Diga en la orientacion (V= Vertical y H= Horizontal)\n>");
              fflush(stdin);
              scanf("%c", &dir);

              if( dir != 'V' && dir != 'H' && dir != 'v' && dir != 'h'){
                  printf ("Introduce letra de direccion valida\n");}

        } while ( dir != 'V' && dir != 'H' && dir != 'v' && dir != 'h');
        
       switch (c){
        	case 'a': i = 1;
        		break;
        	case 'b': i = 2;
        		break; 
        	case 'c': i = 3;
        		break;
        	case 'd': i = 4;
        		break; 
        	case 'e': i = 5;
        		break;
        	case 'f': i = 6;
        		break;
        	case 'g': i = 7;
        		break;
        	case 'h': i = 8;
        		break; 
        	case 'i': i = 9;
        		break;
        	case 'j': i = 10;
        		break;
		}
		 
		j = j + 1;
	
	varDcomprobacion = comprobador_de_barco4 ( i, j, dir );
    varDcomprobacionRep = comprobador_de_repeticion ( i, j, a , dir, barco);
    
    }while( varDcomprobacion == ERROR || varDcomprobacionRep == TRUE );
    
		if( varDcomprobacion == CORRECTO && varDcomprobacionRep == FALSE ){
		
		if( dir == 'V' ||  dir == 'v' ){

            a[i][j] = '4';
            a[i+1][j] = '4';
            a[i+2][j] = '4';
            a[i+3][j] = '4';

            a[i-1][j] = '+';
            a[i][j-1] = '+';
            a[i][j+1] = '+';
            a[i+1][j-1] = '+';
            a[i+1][j+1] = '+';
            a[i+2][j-1] = '+';
            a[i+2][j+1] = '+';
            a[i+3][j-1] = '+';
            a[i+3][j+1] = '+';
            a[i+4][j] = '+';

        }else{ 

            a[i][j] = '4';
            a[i][j+1] = '4';
            a[i][j+2] = '4';
            a[i][j+3] = '4';

            a[i][j-1] = '+';
            a[i-1][j] = '+';
            a[i+1][j] = '+';
            a[i-1][j+1] = '+';
            a[i+1][j+1] = '+';
            a[i-1][j+2] = '+';
            a[i+1][j+2] = '+';
            a[i-1][j+3] = '+';
            a[i+1][j+3] = '+';
            a[i][j+4] = '+';

        }
     }
       
	   system ("cls");
	   
	   mostrar_Tablero2(a);
	   
	   printf("\n\n");
}

//Funciones que comprueban los valores introducidos por el Jugador.

int comprobador_de_barcos2 ( int fila, int columna , char c ){
	
	int aux;
	
	if ( c == 'H' || c == 'h') {
		
		if (columna + 1 > 10 ){
	        
			printf("Tu barco se sale de la Matriz por la fila: %i.\n", fila);
	        system("pause>nul");
	        aux = ERROR;
	     }else{aux = CORRECTO;
	   }
	 }
	
    if ( c == 'V' || c == 'v' ){
		
		if(fila + 1 > 10 ){
	         
			 printf("Tu barco se sale de la Matriz por la columna: %i.\n", columna);
		     system("pause>nul");
		     aux = ERROR;
	     }else{
		 aux = CORRECTO;
	   }
     }
	
	return aux;  
	
}
int comprobador_de_barcos3 ( int fila, int columna , char c ){
	
	int aux;
	
	if ( c == 'H' || c == 'h') {
		
		if (columna + 2 > 10 ){	        
	        
			printf("Tu barco se sale de la Matriz por la fila: %i.\n", fila - 1);
	        system("pause>nul");
	        aux = ERROR;
	     }else{
		 aux = CORRECTO;}
		 
		if (columna + 1 > 10 ){
	        
			printf("Tu barco se sale de la Matriz por la fila: %i.\n", fila - 1);
	        system("pause>nul");
	        aux = ERROR;
	     }else{aux = CORRECTO;
	   }
	 }
	
    if ( c == 'V' || c == 'v' ){
		
		if(fila + 2 > 10 ){
	         
			 printf("Tu barco se sale de la Matriz por la columna: %i.\n", columna -1);
		     system("pause>nul");
		     aux = ERROR;
	     }else{
		 aux = CORRECTO;}
		 
		if(fila + 1 > 10 ){
	         
			 printf("Tu barco se sale de la Matriz por la columna: %i.\n", columna - 1);
		     system("pause>nul");
		     aux = ERROR;
	     }else{
		 aux = CORRECTO;
	   }
     }
	
	return aux;  
	
}
int comprobador_de_barco4 ( int fila, int columna , char c ){
	
	int aux;
	
	if ( c == 'H' || c == 'h') {
		
		if (columna + 3 > 10 ){
	        
			printf("Tu barco se sale de la Matriz por la fila: %i.\n", fila - 1);
	        system("pause>nul");
	        aux = ERROR;
	     }else{
		 aux = CORRECTO;}
		 
		 if (columna + 2 > 10 ){	        
	        
			printf("Tu barco se sale de la Matriz por la fila: %i.\n", fila - 1);
	        system("pause>nul");
	        aux = ERROR;
	     }else{
		 aux = CORRECTO;}
		 
		if (columna + 1 > 10 ){
	        
			printf("Tu barco se sale de la Matriz por la fila: %i.\n", fila - 1);
	        system("pause>nul");
	        aux = ERROR;
	     }else{aux = CORRECTO;
	   }
	 }
	
    if ( c == 'V' || c == 'v' ){
		
		if(fila + 3 > 10 ){
	         
			 printf("Tu barco se sale de la Matriz por la columna: %i.\n", columna - 1);
		     system("pause>nul");
		     aux = ERROR;
	     }else{
		 aux = CORRECTO;}
		 
		if(fila + 2 > 10 ){
	         
			 printf("Tu barco se sale de la Matriz por la columna: %i.\n", columna - 1);
		     system("pause>nul");
		     aux = ERROR;
	     }else{
		 aux = CORRECTO;}
		 
		if(fila + 1 > 10 ){
	         
			 printf("Tu barco se sale de la Matriz por la columna: %i.\n", columna - 1);
		     system("pause>nul");
		     aux = ERROR;
	     }else{
		 aux = CORRECTO;
	   }
     }
		
	return aux;  
	
}	
int comprobador_de_repeticion ( int fila, int columna, char m[12][12], char orientacion, int longitud){
	
	int aux = FALSE; 
	
    //TRUE -------> se repite , FALSE ---------> no se repite.
    
     switch ( m[fila][columna] ){
		       
		       case '0' :  
		           	     aux = FALSE;
		           	    
						   if ( orientacion == 'h' || orientacion == 'H' ) {
						   	   
						   	   if(longitud == 2){
						   	   	   if (m[fila][columna + 1] != '0'){
						   	   	   	   aux = TRUE;
						   	   	   	   mensaje_de_error;
						   	   	   	   return aux;
								   }
							  }
							   if(longitud == 3){
						   	   	   if (m[fila][columna + 1] != '0'){
						   	   	   	   aux = TRUE;
						   	   	   	   mensaje_de_error;
						   	   	   	   return aux;
						   	   	   	   
						   	   	   	   if (m[fila][columna + 2] != '0'){
						   	   	   	       aux = TRUE;
						   	   	   	       mensaje_de_error;
						   	   	   	       return aux;
									     }
								   }
							  }
							  if(longitud == 4){
						   	   	   if (m[fila][columna + 1] != '0'){
						   	   	   	   aux = TRUE;
						   	   	   	   mensaje_de_error;
						   	   	   	   return aux;
						   	   	   	   if (m[fila][columna + 2] != '0'){
						   	   	   	       aux = TRUE;
						   	   	   	       mensaje_de_error;
						   	   	   	       return aux;
						   	   	   	       if (m[fila][columna + 3] != '0'){
						   	   	   	       aux = TRUE;
						   	   	   	       mensaje_de_error;
						   	   	   	       return aux;
										   }
						               }
						   	   	   }
							   }
					       }else if ( orientacion == 'V' || orientacion == 'v' ) {
						   	   
						   	   if(longitud == 2){
						   	   	   if (m[fila + 1][columna] != '0'){
						   	   	   	   aux = TRUE;
						   	   	   	   mensaje_de_error;
						   	   	   	   return aux;
								   }
							  }
							   if(longitud == 3){
						   	   	   if (m[fila +1][columna] != '0'){
						   	   	   	   aux = TRUE;
						   	   	   	   mensaje_de_error;
						   	   	   	   return aux;
						   	   	   	   if (m[fila + 2][columna] != '0'){
						   	   	   	       aux = TRUE;
						   	   	   	       mensaje_de_error;
						   	   	   	       return aux;
									     }
								   }
							  }
							  if(longitud == 4){
						   	   	   if (m[fila + 1][columna] != '0'){
						   	   	   	   aux = TRUE;
						   	   	   	   mensaje_de_error;
						   	   	   	   return aux;
						   	   	   	   if (m[fila + 2][columna] != '0'){
						   	   	   	       aux = TRUE;
						   	   	   	       mensaje_de_error;
						   	   	   	       return aux;
						   	   	   	       if (m[fila + 3][columna] != '0'){
						   	   	   	       aux = TRUE;
						   	   	   	       mensaje_de_error;
						   	   	   	       return aux;
										   }
						               }
						   	   	   }
							   }
					     }else{
					     	aux = FALSE;
						 }
						return aux;
						break;
			   case '1' : 
		           	     aux = TRUE;		           	        	        
						 printf("Casilla en uso.\n");
						 system("pause>nul");
		           	     system("cls");
		           	     return aux;										
						break;
			   case '+' : 
		           	     aux = TRUE;
		           	     printf("Barco adyacente\n");
		           	     system("pause>nul");
		           	     system("cls");
		           	     return aux;
						break;
			   case '2':
			   	        aux = TRUE;		           	        	        
						 printf("Casilla en uso.\n");
						 system("pause>nul");
		           	     system("cls");
		           	     return aux;										
						break;
			   case '3':
			   	        aux = TRUE;		           	        	        
						 printf("Casilla en uso.\n");
						 system("pause>nul");
		           	     system("cls");
		           	     return aux;										
						break;
			   			   
			   default: aux = FALSE;
					    break;
					    }
return aux;
}

//Función que muestra un mensaje de error.

void mensaje_de_error (){  
  
  system("color 34");
  printf("ERROR");
  system("pause>nul");
  system("cls");
}

//Función que busca la matriz de la Inteligencia Artificial en un fichero en la dirección donde se encuetra alojado el ejecutable .exe.

void mod_file_matriz_ia(char a[12][12]){
	
	int cont = 0;
	char aux;
	int i,j;
	
	FILE * f;
	
	f = fopen ("matrizia.txt", "r");
	
	if (f == NULL){
		printf("ERROR a la hora de Abrir el Fichero");
		system("pause");
		exit(1);
	}
    
    for(i = 0; !feof(f); i++){
    	
		aux = '0';
		
		for( j = 0; j < 13; j++){
			aux = fgetc(f);
			
			if(aux != '\n'){
				a[i][j] = aux;
			}
		}
	}
	
    fclose(f);
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------       Funciones del Juego.         -----------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//Función donde se producen el sistema de turnos, jugadas del Jugador y jugadas de la IA dotada de habilidad de jugar en casillas adyacentes a casillas aleatoriamente acertadas.

void juego ( char mPlayer[12][12], char mIa[12][12] , char name[20]){
	
	int a, b1 = 0, b1Ia = 0, b2 = 0, b2Ia = 0, b3 = 0, b3Ia = 0, b4 = 0, b4Ia = 0;	
	int filaAtaque , columnaAtaque;
	int turno = 0;
	long int numJugadas = 0;
	long int hscore = 0;
	long int score = 0;
	int barcosHundidos = 0;
	int barcosHundidosIa = 0;
    int resultadoDeJugada;
	int i,j,l,r;
	char c;
	char d;
	char mjugadashumano[12][12];
	char mjugadasia[12][12];
	char mjugadashumanovisible[12][12];
	char mjugadasiavisible[12][12];
	int aux, aux1; 
	int final = FALSE;
	int acierto = FALSE;
	int auxTam;
	
	ini_matrices (mjugadashumano);
	ini_matrices (mjugadasia);
	ini_matrices (mjugadashumanovisible);
	ini_matrices (mjugadasiavisible);
	
    turno = 0;
    
	do{ 
	
		if ( turno == 0 ){
	    	
	       numJugadas = numJugadas + 1;
		   
		   mostrar_Tablero( mjugadashumanovisible);
		   
		   printf("\n\n Numero de Jugada: %i\n", numJugadas);
		   printf("\n SCORE: %d", score);      
	       printf("\n Es tu turno de atacar...\n");
	       printf(" Te faltan por hundir: %d barcos\n", 10 - barcosHundidos);
		    		   
		   do{
		       printf(" Introduce fila para el ataque(a-j): ");
	           fflush(stdin);		   
		       scanf("%c", &c);
	       }while( c != 'a' && c != 'b' && c != 'c' && c!='d' && c!='e' && c!='f' && c!= 'g' && c!= 'h' && c!='i' && c!='j');
	       
	       printf("\n");
		   
		   do{
		      printf(" Introduce columna para el ataque(0-9): ");
	          scanf("%i", &columnaAtaque);
	         
			 
	      }while(columnaAtaque < 0 || columnaAtaque > 9 );
	       
		   switch (c){
        	case 'a': filaAtaque = 1;
        		break;
        	case 'b': filaAtaque = 2;
        		break; 
        	case 'c': filaAtaque = 3;
        		break;
        	case 'd': filaAtaque = 4;
        		break; 
        	case 'e': filaAtaque = 5;
        		break;
        	case 'f': filaAtaque = 6;
        		break;
        	case 'g': filaAtaque = 7;
        		break;
        	case 'h': filaAtaque = 8;
        		break; 
        	case 'i': filaAtaque = 9;
        		break;
        	case 'j': filaAtaque = 10;
        		break;
		}
		 
		columnaAtaque = columnaAtaque + 1;
	       
	
		   mjugadashumano[filaAtaque][columnaAtaque] = mIa[filaAtaque][columnaAtaque];
		   
		   resultadoDeJugada =  comprobador_de_tirada ( filaAtaque, columnaAtaque, mIa, mjugadashumano);
	       
	       switch  (resultadoDeJugada){
	            
	            case 0: printf("HAS ACERTADO EL DISPARO\n");
	                    score = score + 100;
	                    hscore = score;
	                    mjugadashumanovisible[filaAtaque][columnaAtaque] = 'X';
						system("pause>nul");
						system("cls");
	                    turno = 0;
	                    break;
	            
				case 1: printf("HAS HUNDIDO UNA NAVE DE LONGITUD 1\n");
	                    barcosHundidos = barcosHundidos + 1;
	                    score = score + 150;
	                    hscore = score;
	                    b1++ ;
	                    mjugadashumanovisible[filaAtaque][columnaAtaque] = 'X';
						system("pause>nul");
						system("cls");
						turno = 0;
						break;
						
				case 2: printf("HAS HUNDIDO UNA NAVE DE LONGITUD 2\n");
	                    barcosHundidos = barcosHundidos + 1;
	                    score = score + 150;
	                    hscore = score;
	                    b2++ ;
	                    mjugadashumanovisible[filaAtaque][columnaAtaque] = 'X';
						system("pause>nul");
						system("cls");
						turno = 0;
						break;
				
				case 3: printf("HAS HUNDIDO UNA NAVE DE LONGITUD 3\n");
	                    barcosHundidos = barcosHundidos + 1;
	                    score = score + 150;
	                    hscore = score;
	                    b3++ ;
	                    mjugadashumanovisible[filaAtaque][columnaAtaque] = 'X';
						system("pause>nul");
						system("cls");
						turno = 0;
						break;
				
				case 4: printf("HAS HUNDIDO UNA NAVE DE LONGITUD 4\n");
	                    barcosHundidos = barcosHundidos + 1;
	                    score = score + 150;
	                    hscore = score;
	                    b4++ ;
	                    mjugadashumanovisible[filaAtaque][columnaAtaque] = 'X';
						system("pause>nul");
						system("cls");
						turno = 0;
						break;
	            
				default: printf("HAS FALLADO...PIERDES TURNO\n");
	                     mjugadashumanovisible[filaAtaque][columnaAtaque] = 'O';
						 turno = 1;
						 system("cls");
						 break;         
				}
				
			if(barcosHundidos >= 10){
		   	   final = TRUE;
		   } 
			
	    }
      
        if ( turno == 1 ){
	    	
	       
		   numJugadas = numJugadas + 1;  
		   
		 if(acierto == TRUE ){
			
		   aux1 = 0;
		   srand(time(NULL));
           
           aux1 = rand()%4;
           
           switch (aux1){
           	
           	case 0: filaAtaque = l + 1;
           	        columnaAtaque = r;
           	        break;
           	case 1: filaAtaque = l - 1;
           	        columnaAtaque = r;
           	        break;
           	case 2: columnaAtaque = r + 1;
           	        filaAtaque = l;
           	        break;
           	case 3: columnaAtaque = r - 1;
			        filaAtaque = l;
					break;
				}
			    
		   }else{    
		   
             do{
                      	    
				   filaAtaque = 0;
		           columnaAtaque = 0;
				   
				   srand(time(NULL));
				   
				   filaAtaque = 1 + rand() % 10;
		           columnaAtaque = 1 + rand() % 10;
		   	 
				}while ( mjugadasiavisible[filaAtaque][columnaAtaque] != ' ');
		      
			     if ( mjugadasia[filaAtaque][columnaAtaque] == ' ' ){
		      	       mjugadasiavisible[filaAtaque][columnaAtaque] = 'X';
		      	       mjugadasia[filaAtaque][columnaAtaque] = mPlayer[filaAtaque][columnaAtaque];
		      	       
		         switch (filaAtaque){
		   	
			         case 1:   d = 'a' ;
			             break;
		   	         case 2:   d = 'b' ;
			             break;
		   	         case 3:   d = 'c' ;
			             break;
		   	         case 4:   d = 'd' ;
			             break;
		   	         case 5:   d = 'e' ;
			             break;
		   	         case 6:   d = 'f' ;
			             break;
		   	         case 7:   d = 'g' ;
			             break;
		             case 8:   d = 'h' ;
			             break;
		   	         case 9:   d = 'i' ;
			             break;
		   	         case 10:  d = 'j' ;
			             break;
		          }
			    
				columnaAtaque = columnaAtaque - 1;
				
				}
	      
	     }
	  
		   printf("\nNumero de Jugada: %d , Turno del Ordenador.\n", numJugadas);
		   printf("Fila disparada: %c.    Columna Disparada: %d.\n", d,columnaAtaque);
		   
		   resultadoDeJugada =  comprobador_de_tirada ( filaAtaque, columnaAtaque, mPlayer, mjugadasia);
	       
	       switch  (resultadoDeJugada){
	            
	            case 0: turno = 1;
				        printf ("TE HAN DADO.\n") ;
				        system("pause");
						mjugadasiavisible[filaAtaque][columnaAtaque] = 'X';
				        acierto = TRUE;
				        l = filaAtaque;
				        r = columnaAtaque;
				        
				break;
	            		
	            case 1: turno = 1; 
						printf ("TE HAN HUNDIDO UN BARCO DE LONGITUD 1.\n") ;
				        system("pause");
						mjugadasiavisible[filaAtaque][columnaAtaque] = 'X';
	                    acierto = TRUE;
	                    barcosHundidosIa = barcosHundidosIa ++;
	                    b1Ia++ ;
	                    l = filaAtaque;
				        r = columnaAtaque;
	                    
	                break;
	            case 2: turno = 1; 	                    
	                    printf ("TE HAN HUNDIDO UN BARCO DE LONGITUD 2.\n") ;
				        system("pause");
						mjugadasiavisible[filaAtaque][columnaAtaque] = 'X';
	                    acierto = TRUE;
	                    barcosHundidosIa = barcosHundidosIa ++;
						b2Ia++ ;
						l = filaAtaque;
				        r = columnaAtaque;
						
	                break;
	            case 3: turno = 1; 
	                    printf ("TE HAN HUNDIDO UN BARCO DE LONGITUD 3.\n") ;
				        system("pause");
						mjugadasiavisible[filaAtaque][columnaAtaque] = 'X';
	                    acierto = TRUE;
	                    barcosHundidosIa = barcosHundidosIa ++;
						b3Ia++ ;
						l = filaAtaque;
				        r = columnaAtaque;
	                    
	                break;
	            case 4: turno = 1; 
	                    printf ("TE HAN HUNDIDO UN BARCO DE LONGITUD 4.\n") ;
				        system("pause");
						mjugadasiavisible[filaAtaque][columnaAtaque] = 'X';
	                    acierto = TRUE;
	                    barcosHundidosIa = barcosHundidosIa++;
						b4Ia++ ;
						l = filaAtaque;
				        r = columnaAtaque;
	                    
	                break;
	            
	            
	            
	            default:
				       acierto = FALSE;
					   printf ("HA FALLADO, has tenido suerte.\n") ;
				       system("pause");
					   turno = 0;
				}
	
		   if(barcosHundidosIa >= 10){
		   	   final = TRUE;
		   } 
      }
	} while ( final == FALSE);
	
	
	system("cls");
	
	
	
	if (barcosHundidos == 10){
		
		printf("ENHORABUENA %s, HAS GANADO!!!!\n", name);
		printf("AL ORDENADOR LE HAN FALTADO POR DESTRUIR:\n");
		printf("%i Barcos de longitud 1\n", 4 - b1Ia);
		printf("%i Barcos de longitud 2\n", 3 - b2Ia);
		printf("%i Barcos de longitud 3\n", 2 - b3Ia);
		printf("%i Barcos de longitud 4\n\n", 1 - b4Ia);
	}
	if (barcosHundidosIa == 10){
		printf("QUE MALA SUERTE %s, HAS PERDIDO", name);
		printf("TE HAN FALTADO POR DESTRUIR:\n");
		printf("%i Barcos de longitud 1\n", 4 - b1);
		printf("%i Barcos de longitud 2\n", 3 - b2);
		printf("%i Barcos de longitud 3\n", 2 - b3);
		printf("%i Barcos de longitud 4\n\n", 1 - b4);
	}
      
    comp_hscore (hscore);
	   
}

//Función que comprueba los resultados de las tiradas producidas por los jugadores.

int comprobador_de_tirada ( int fila, int columna, char a[12][12], char jugada[12][12] ){

   int resultado;
   
   jugada[fila][columna] = a[fila][columna];
   
   switch (a[fila][columna]){
   
         case '0': resultado = 5; break;
		 case ' ': resultado = 5; break;
         case '+': resultado = 5; break;
         
		 case '1': resultado = 1;
         	break;
         	
         case '2': resultado = 0;
                  
                   	if( jugada[fila][columna+1] == '2'){                   	  	
                   	  	       resultado = 2;                  	       
                    }
					if( jugada[fila][columna-1] == '2'){                   	  	   
                   	  	       resultado = 2;                  	       
				    }
					if( jugada[fila-1][columna] == '2'){                   	  	   
                   	  	       resultado = 2;					        
                    }
					if( jugada[fila+1][columna] == '2'){
                   	  	       resultado = 2;
					} 
			break;
         	
         case '3': resultado = 0;
                  
                   	if( jugada[fila][columna+1] == '3' && jugada[fila][columna+2] == '3' ){
                   	  	       resultado = 3;
                   	}
                    if( jugada[fila][columna-1] == '3' && jugada[fila][columna-2] == '3' ){
                   	  	       resultado = 3;
                   	}
				    if( jugada[fila-1][columna] == '3' && jugada[fila-2][columna] == '3' ){
                   	  	       resultado = 3;
					} 
                    if( jugada[fila+1][columna] == '3' && jugada[fila+2][columna] == '3' ){
                   	  	       resultado = 3;
					}
					if( jugada[fila][columna-1] == '3' && jugada[fila][columna+1] == '3' ){
                   	  	       resultado = 3;
					}
					if( jugada[fila+1][columna] == '3' && jugada[fila-1][columna] == '3' ){
                   	  	       resultado = 3;
					}
			break;         
         
		 case '4': resultado = 0;
		 
            
                   	if( jugada[fila][columna+1] == '4' && jugada[fila][columna+2] == '4' && jugada[fila][columna+3] == '4' ){
							   resultado = 4;
                   	}
                   	if( jugada[fila][columna-1] == '4' && jugada[fila][columna-2] == '4' && jugada[fila][columna-3] == '4' ){
                   	  	       resultado = 4;
                   	}
					if( jugada[fila-1][columna] == '4' && jugada[fila-2][columna] == '4' && jugada[fila-3][columna] == '4' ){
                   	  	       resultado = 4;
					}
                    if( jugada[fila+1][columna] == '4' && jugada[fila+2][columna] == '4' && jugada[fila+3][columna] == '4' ){
                   	  	       resultado = 4;
					}
					if( jugada[fila-1][columna] == '4' && jugada[fila+1][columna] == '4' && jugada[fila+2][columna] == '4' ){
			                   resultado = 4;
				    }
					if( jugada[fila+1][columna] == '4' && jugada[fila-1][columna] == '4' && jugada[fila-2][columna] == '4' ){			           	   
			                   resultado = 4;							 						   
					}
					if( jugada[fila][columna-1] == '4' && jugada[fila][columna+1] == '4' && jugada[fila][columna+2] == '4' ){
					   	       resultado = 4;
                    }
					if( jugada[fila][columna+1] == '4' && jugada[fila][columna-1] == '4' && jugada[fila][columna-2] == '4' ){
                               resultado = 4;
					}
				
			break;
	} 

   return resultado;
}

//Función que comprueba la puntuación obtenida en el juego con una contenida en un fichero.txt, y remplaza el fichero en caso de superar dicha puntuacion.

void comp_hscore ( long int score ){
	
	char aux [10];
	
    long int hscore;
    char newscore;
    int j;
	
	FILE * f;
    
	f = fopen( "hscore.txt", "r");
    
    if( f == NULL){
    	printf("No se pude abrir.");
	}

	
	for( j = 0; !feof(f); j++){
		aux[j] = fgetc(f);
    }
	printf("\n");
	
    hscore = atoi(aux);
    
    fclose(f);
    
    FILE * g;
    
    g = fopen("hscore.txt", "w");
    
	if( g == NULL){
    	printf("No se pude abrir.");
    	system("pause");
	}
    
	if( hscore > score ){
    	printf("No has roto el record de puntuacion.\n Te he faltado: %d.", hscore - score);
		system("pause>nul");
	}
    if( hscore < score ){
    	
		system("color 3F");//Fondo: Aguamarina, Letras: Blacas.
		printf("HAS IMPLANTADO RECORD CON %d PUNTOS!!!\n", score);
    	fprintf(g, "%d", score);
		system("pause>nul");  	
	}
	if( hscore == score){
		printf("HAS IGUALADO EL RECORD CON %d PUNTOS!!!\n", score);
	}
	
	fclose(g);
	
}

//Función que carga la máx puntuación obtenida en el juego desde un fichero.txt.
void carga_hscore(){
	
    char aux [10];
    int j;
	
	FILE * fp;
	FILE * q;
    
	fp = fopen( "hscore.txt", "r");
    
    printf("            HIHGSCORE: ");
	
	if( fp == NULL){
		
    	fclose(fp);
    	
		q = fopen("hscore.txt", "w");
    	
		fprintf(q, "0");
    	printf("0");
    	
		fclose(q);
    
    	
	}else{
		
	    for( j = 0; !feof(fp); j++){
		   aux[j] = fgetc(fp);
		   printf("%c", aux[j]);
        }
        fclose(fp);
	}
    

   
    printf(".\n");
	 
    
}

//Función que genera matrices con los barquitos bien colocados.

void generador_de_matriz_IA ( char a[12][12]){
	
	int barco;  // longitud del barco;
	int varDcomprobacion = 0;
	int varDcomprobacionRep = 0;
    int cant_barco;
	int i, j, k;
	char dir;
    char direcciones[2] = {'V', 'H'};
    
    srand (time (NULL));
    
	
	cant_barco = 1;

    do{
        do{
           barco = 4;
	      
		  
		   
		   i = rand()%10 + 1;
           j = rand()%10 + 1;
	         	   
		   k = rand()%2;
		   dir = direcciones[k];                             //orientacion
           
           
           varDcomprobacionRep = comprobador_de_matriz_ia ( i, j, a, dir, barco);
           varDcomprobacion = comprobador_de_barco4ia ( i, j, dir);
		} while( varDcomprobacionRep == TRUE || varDcomprobacion == ERROR );
         
		if( varDcomprobacionRep == FALSE && varDcomprobacion == CORRECTO ){      
		
	      if (dir == 'V'){                            //vertical

            a[i][j] = '4';
            a[i+1][j] = '4';
            a[i+2][j] = '4';
            a[i+3][j] = '4';

            a[i-1][j] = '+';
            a[i][j-1] = '+';
            a[i][j+1] = '+';
            a[i+1][j-1] = '+';
            a[i+1][j+1] = '+';
            a[i+2][j-1] = '+';
            a[i+2][j+1] = '+';
            a[i+3][j-1] = '+';
            a[i+3][j+1] = '+';
            a[i+4][j] = '+';

        }else{ 

            a[i][j] = '4';
            a[i][j+1] = '4';
            a[i][j+2] = '4';
            a[i][j+3] = '4';

            a[i][j-1] = '+';
            a[i-1][j] = '+';
            a[i+1][j] = '+';
            a[i-1][j+1] = '+';
            a[i+1][j+1] = '+';
            a[i-1][j+2] = '+';
            a[i+1][j+2] = '+';
            a[i-1][j+3] = '+';
            a[i+1][j+3] = '+';
            a[i][j+4] = '+';
        }

        cant_barco = cant_barco - 1;
      }
    }while (cant_barco > 0 );
	
	
	cant_barco = 2;

    do{
       do{
        
		barco = 3;
	    
		   i = rand()%10 + 1;
           j = rand()%10 + 1;
        
	       k = rand()%2;
		   dir = direcciones[k];                             //orientacion
           
        
        varDcomprobacion = comprobador_de_barcos3ia ( i, j, dir);
		varDcomprobacionRep = comprobador_de_matriz_ia ( i, j, a, dir, barco);
        
		} while( varDcomprobacionRep == TRUE || varDcomprobacion == ERROR );
         
		if( varDcomprobacionRep == FALSE && varDcomprobacion == CORRECTO ){                            //orientacion

           if (dir == 'V'){                            //vertical

                 a[i][j] = '3';
                 a[i+1][j] = '3';
                 a[i+2][j] = '3';

                 a[i-1][j] = '+';
                 a[i][j-1] = '+';
                 a[i][j+1] = '+';
                 a[i+1][j-1] = '+';
                 a[i+1][j+1] = '+';
                 a[i+2][j-1] = '+';
                 a[i+2][j+1] = '+';
                 a[i+3][j] = '+';

          }else{                                      //horizontal

                 a[i][j] = '3';
                 a[i][j+1] = '3';
                 a[i][j+2] = '3';

                 a[i][j-1] = '+';
                 a[i-1][j] = '+';
                 a[i+1][j] = '+';
                 a[i-1][j+1] = '+';
                 a[i+1][j+1] = '+';
                 a[i-1][j+2] = '+';
                 a[i+1][j+2] = '+';
                 a[i][j+3] = '+';
            }

        cant_barco = cant_barco - 1;
      }
      
	}while (cant_barco > 0 );

  
   srand (time (NULL));
   
    cant_barco = 3;
    
	do{

           barco = 2;
		   
		 do{ 
		   
		   i = rand()%10 + 1;
           j = rand()%10 + 1;
           
		   k = rand()%2;
		   dir = direcciones[k];                             //orientacion
           
           
           varDcomprobacion = comprobador_de_barcos2ia ( i, j, dir);
		   varDcomprobacionRep = comprobador_de_matriz_ia ( i, j, a, dir, barco);
           
          }while( varDcomprobacionRep == TRUE || varDcomprobacion == ERROR );
         
		 if( varDcomprobacionRep == FALSE && varDcomprobacion == CORRECTO ){
		  
		  if (dir == 'V'){                            //vertical

            a[i][j] = '2';
            a[i+1][j] = '2';

            a[i-1][j] = '+';
            a[i+2][j] = '+';
            a[i][j-1] = '+';
            a[i][j+1] = '+';
            a[i+1][j-1] = '+';
            a[i+1][j+1] = '+';

        }else{

            a[i][j] = '2';
            a[i][j+1] = '2';

            a[i][j-1] = '+';
            a[i][j+2] = '+';
            a[i-1][j] = '+';
            a[i+1][j] = '+';
            a[i-1][j+1] = '+';
            a[i+1][j+1] = '+';;
        }

            cant_barco = cant_barco - 1;
        } 
    }while (cant_barco > 0 );
    
     srand (time (NULL));
	
	 
	
	
	 srand (time (NULL));
	cant_barco = 4;
    
	do{

       do{
		dir = 'a';
		barco = 1;
		
		   
		   i = rand()%10 + 1;
           j = rand()%10 + 1;
        
	       
        
		varDcomprobacionRep = comprobador_de_matriz_ia ( i, j, a, dir, barco);
        
		}while(varDcomprobacionRep == TRUE );
        
		if ( varDcomprobacionRep == FALSE ){
		
		a[i][j] = '1';

        a[i][j-1] = '+';
        a[i][j+1] = '+';
        a[i-1][j] = '+';
        a[i+1][j] = '+';

        cant_barco = cant_barco - 1;
        }
    } while (cant_barco > 0 );
	
	
		
}
int comp_m_ia(char a [12][12] ){

int i,j,aux,aux1;

for(i=0;i<12;i++){
	for(j=0;j<12;j++){
		
		if( a[i][j] == '+' ){
			a[i][j] == ' ';	
		}
		if(a[i][j] == '2'){
			aux++;
		}
		if(a[i][j] == '1'){
			aux++;
		}
		if(a[i][j] == '3'){
			aux++;
		}
		if(a[i][j] == '4'){
			aux++;
		}
	
	}

  }
  return aux;
  }	    
int comprobador_de_barcos2ia ( int fila, int columna , char c ){
	
	int aux;
	
	if ( c == 'H' || c == 'h') {
		
		if (columna + 1 > 9 ){
	        aux = ERROR;
	     }else{aux = CORRECTO;
	   }
	 }
	
    if ( c == 'V' || c == 'v' ){
		
		if(fila + 1 > 9 ){
		     aux = ERROR;
	     }else{
		 aux = CORRECTO;
	   }
     }
	
	return aux;  
	
}
int comprobador_de_barcos3ia ( int fila, int columna , char c ){
	
	int aux;
	
	if ( c == 'H' || c == 'h') {
		
		if (columna + 2 > 9 ){	        
	        aux = ERROR;
	     }else{
		 aux = CORRECTO;}
		 
		if (columna + 1 > 9 ){
	        aux = ERROR;
	     }else{aux = CORRECTO;
	   }
	 }
	
    if ( c == 'V' || c == 'v' ){
		
		if(fila + 2 > 9 ){
		     aux = ERROR;
	     }else{
		 aux = CORRECTO;}
		 
		if(fila + 1 > 9 ){
		     aux = ERROR;
	     }else{
		 aux = CORRECTO;
	   }
     }
	
	return aux;  
	
}
int comprobador_de_barco4ia ( int fila, int columna , char c ){
	
	int aux;
	
	if ( c == 'H' || c == 'h') {
		
		if (columna + 3 > 9 ){
	        aux = ERROR;
	     }else{
		 aux = CORRECTO;}
		 
		 if (columna + 2 > 9 ){
	        aux = ERROR;
	     }else{
		 aux = CORRECTO;}
		 
		if (columna + 1 > 9 ){
	        aux = ERROR;
	     }else{aux = CORRECTO;
	   }
	 }
	
    if ( c == 'V' || c == 'v' ){
		
		if(fila + 3 > 9 ){
		     aux = ERROR;
	     }else{
		 aux = CORRECTO;}
		 
		if(fila + 2 > 9){

		     aux = ERROR;
	     }else{
		 aux = CORRECTO;}
		 
		if(fila + 1 > 9 ){
		     aux = ERROR;
	     }else{
		 aux = CORRECTO;
	   }
     }
		
	return aux;  
	
}	
int comprobador_de_matriz_ia ( int fila, int columna, char m[12][12], char orientacion, int longitud){
	
	int aux = FALSE; 
	
    //TRUE -------> se repite , FALSE ---------> no se repite.
    
     switch ( m[fila][columna] ){
		       
		       case ' ' :  
		           	     aux = FALSE;
		           	    
						   if ( orientacion == 'h' || orientacion == 'H' ) {
						   	   
						   	   if(longitud == 2){
						   	   	   if (m[fila][columna + 1] != ' '){
						   	   	   	   aux = TRUE;
						   	   	   	   
						   	   	   	   return aux;
								   }
							  }
							   if(longitud == 3){
						   	   	   if (m[fila][columna + 1] != ' '){
						   	   	   	   aux = TRUE;
						   	   	   	
						   	   	   	   return aux;
						   	   	   	   
						   	   	   	   if (m[fila][columna + 2] != ' '){
						   	   	   	       aux = TRUE;
						   	   	   	       
						   	   	   	       return aux;
									     }
								   }
							  }
							  if(longitud == 4){
						   	   	   if (m[fila][columna + 1] != ' '){
						   	   	   	   aux = TRUE;
						   	   	   	   
						   	   	   	   return aux;
						   	   	   	   if (m[fila][columna + 2] != ' '){
						   	   	   	       aux = TRUE;
						   	   	   	       
						   	   	   	       return aux;
						   	   	   	       if (m[fila][columna + 3] != ' '){
						   	   	   	       aux = TRUE;
						   	   	   	       
						   	   	   	       return aux;
										   }
						               }
						   	   	   }
							   }
					       }else if ( orientacion == 'V' || orientacion == ' ' ) {
						   	   
						   	   if(longitud == 2){
						   	   	   if (m[fila + 1][columna] != ' '){
						   	   	   	   aux = TRUE;
						   	   	   	   
						   	   	   	   return aux;
								   }
							  }
							   if(longitud == 3){
						   	   	   if (m[fila +1][columna] != ' '){
						   	   	   	   aux = TRUE;
						   	   	   	   
						   	   	   	   return aux;
						   	   	   	   if (m[fila + 2][columna] != ' '){
						   	   	   	       aux = TRUE;
						   	   	   	       
						   	   	   	       return aux;
									     }
								   }
							  }
							  if(longitud == 4){
						   	   	   if (m[fila + 1][columna] != ' '){
						   	   	   	   aux = TRUE;
						   	   	   	   
						   	   	   	   return aux;
						   	   	   	   if (m[fila + 2][columna] != ' '){
						   	   	   	       aux = TRUE;
						   	   	   	       
						   	   	   	       return aux;
						   	   	   	       if (m[fila + 3][columna] != ' '){
						   	   	   	       aux = TRUE;
						   	   	   	       
						   	   	   	       return aux;
										   }
						               }
						   	   	   }
							   }
					     }else{
					     	aux = FALSE;
						 }
						return aux;
						break;
			   case '1' : 
		           	     aux = TRUE;		           	        	        
					
		           	     return aux;										
						break;
			   case '+' : 
		           	     aux = TRUE;
		           	   
		           	     return aux;
						break;
			   case '2':
			   	        aux = TRUE;		           	        	        
						
		           	     return aux;										
						break;
			   case '3':
			   	        aux = TRUE;		           	        	        
					
		           	     return aux;										
						break;
			   case '4':
			   	        aux = TRUE;		           	        	        
					
		           	     return aux;										
						break;
			   			   
			   
			   
			   default: aux = FALSE;
					    break;
					    }
return aux;
}
//====================================================================================================================================================================================================== Fin ====
