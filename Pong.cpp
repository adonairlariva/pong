#include <iostream>
#include <conio.h>
#include <windows.h>


using namespace std;

int main(){
    //Definimos variables de verdadero o falso,  jugar = nos indica si el juego a comenzado o terminado, gameover = para indicar si el jugador a perdido y desea volver a jugar, ganador = para indicar si el jugador a ganado y desea volver a jugar, xp = nos indica si el valor de la pelota en las filas es positivo o negativo, yp = nos indica si el valor de la pelota en la columnas es positivo o negativo.
    bool jugar = true, gameover = false, ganador = false, terminar = false, xp = true, yp = true;

    int actualizar = 1;  //nos indica cada cuanto tiempo se actualizaran los datos mostrados por pantalla.
    int puntaje = 0; //Llevar el conteo de puntos del jugador
    //variables para definir el alto y el ancho del tablero de juego.
    int altoV = 11, anchoV = 16; 

    //variables para asignar un valor de la posicion de la pelota en el tablero bposicionX = para la posicion de la pelota en las filas y bposicionY = para la posicion de la pelota en las columnas , variables para asignar un valor de la posicion de la raqueta constara de 2 puntos en el tablero rposicionX y rposicionY para el primer punto, rposicionX2 y rposicionY2 para el segundo punto de la raqueta.

    int bPosicionX, bPosicionY,  rPosicionX, rPosicionY, rPosicionX2, rPosicionY2;
    char res; //Variable para consultar al jugador si desea volver al juego o finalizar

    //Definimos los valores de la posicion inicial de la raqueta.
    rPosicionX = 1;
    rPosicionX2 = rPosicionX;
    rPosicionY = 5;
    rPosicionY2 = 6;

    //les asignamos un valor a la posicion de la pelota en X y Y para comenzar el juego
    bPosicionX = 5;
    bPosicionY = 5;

    do{ //abrimos un ciclo while que se ejecutara mientras la variable jugar = true, este valor puede cambiar si el jugador desea salir del juego.

        if((ganador && gameover) == false){
 
            if(actualizar ==  1){ //comprobamos si el valor de actualizar es igual a 1 actualizamos los datos de la pantalla.
                system("cls"); //comando para borrar la pantalla anterior y mostrar la nueva.

                cout<<"Movimientos Raqueta"<<endl;
                cout<<"Arriba: Letra W"<<endl;
                cout<<"Abajo: Letra S"<<endl;
        
                cout<<"                 "<<"Puntaje: "<<puntaje<<"                         "<<endl;

                //Comprobacion de la direccion de la pelota hacia las paredes
                if(xp == true){ 
                    //si xp es verdadero el valor de la posicion de la pelota en las filas aumentar 1 cada vez que se actualice la pantalla.
                    bPosicionX++;
                }else{
                    //en caso de ser falso el valor de la posicion de la pelota en las filas reducira 1 cada vez que se actualice la pantalla.
                    bPosicionX--;
                }
                //Fin Comprobacion de la direccion de la pelota hacia las paredes

                //Comprobacion de la direccion de la pelota hacia el techo y el suelo
                if(yp == true){
                    //si yp es verdadero el valor de la posicion de la pelota en las columnas aumentar 1 cada vez que se actualice la pantalla.
                    bPosicionY++;
                }else{
                    //en caso de ser falso el valor de la posicion de la pelota en las columnas reducira 1 cada vez que se actualice la pantalla.
                    bPosicionY--;
                }
                //Fin Comprobacion de la direccion de la pelota hacia el techo y el suelo

                //Comprobacion de la direccion de la pelota hacia la paredes y rebotes
                if((bPosicionX + 1) == (anchoV - 1)){
                    //comprobamos si la siguiente posicion de la pelota en las filas es igual al ancho final de la ventana en caso de ser verdadero cambiamos el valor de xp a falso para que su valor empiece a retroceder.

                    xp = false;
                }else if(bPosicionX -1 == 0){

                    //Si la posicion de la pelota es igual a la posicon de un bloque de la pared izquierda significa que el jugador a perdido al no detenerla con la raqueta. 
                    gameover = true;
                }
                //Fin Comprobacion de la direccion de la pelota hacia la paredes y rebotes

                //Comprobacion de la direccion de la pelota hacia el techo o el suelo y rebote
                if((bPosicionY - 1) == 0){
                    //comprobamos si la siguiente posicion de la pelota en las columnas es igual al inicio de la ventana en caso de ser verdadero cambiamos el valor de yp a verdadero para que su valor empiece a aumentar.

                    yp = true;
                }else if(bPosicionY + 1 == (altoV - 1)){

                    //comprobamos si la siguiente posicion de la pelota en las columnas es igual al filnal del alto de la ventana en caso de ser verdadero cambiamos el valor de yp a falso  para que su valor empiece a reducir.

                    yp = false;
                }
                 //Fin Comprobacion de la direccion de la pelota hacia el techo o el suelo y rebote   

                //Verificando choque de pelota con la raqueta
                if(yp){
                    //si yp el verdadero indica que la pelota esta bajando.
                    //Ahora comprobaremos si la pelota choca con la raqueta cambie de direccion
                    if( rPosicionX == (bPosicionX - 1) && rPosicionY  == (bPosicionY + 1)){

                        //si la siguiente posicion de la pelota en X es igual a la posicion del primer punto de la raqueta en X y la siguiente posicion de la pelota en Y bajando es igual al primer punto de la raqueta en Y significa que han chocado, por ende cambiaremos el valor  de XP a verdadero para que la pelota cambie su direccion a la derecha aumentando su valor en la posicion X.
                        xp = true;
                        puntaje += 25; //Sumamos un puntaje de 25 al jugador al haber detenido la pelota.
                    }

                    if( rPosicionX2 == (bPosicionX - 1) && rPosicionY2  == (bPosicionY + 1)){
                        //si la siguiente posicion de la pelota en X es igual a la posicion del segundo punto de la raqueta en X y la siguiente posicion de la pelota en Y bajando es igual al segundo punto de la raqueta en Y significa que han chocado, por ende cambiaremos el valor  de XP a verdadero para que la pelota cambie su direccion a la derecha aumentando su valor en la posicion X.
                        xp = true;
                        puntaje += 25; //Sumamos un puntaje de 25 al jugador al haber detenido la pelota.
                    }
                }else{
                    //si yp el falso indica que la pelota esta subiendo.
                    //Ahora comprobaremos si la pelota choca con la raqueta cambie de direccion.

                    if( rPosicionX == (bPosicionX - 1) && rPosicionY  == (bPosicionY - 1)){
                        //si la siguiente posicion de la pelota en X es igual a la posicion del segundo punto de la raqueta en X y la siguiente posicion de la pelota en Y subiendo es igual al segundo punto de la raqueta en Y significa que han chocado, por ende cambiaremos el valor  de XP a verdadero para que la pelota cambie su direccion a la derecha aumentando su valor en la posicion X.
                        xp = true;
                        puntaje += 25; //Sumamos un puntaje de 25 al jugador al haber detenido la pelota.
                    }

                    if( rPosicionX == (bPosicionX - 1) && rPosicionY2  == (bPosicionY - 1)){
                        //si la siguiente posicion de la pelota en X es igual a la posicion del segundo punto de la raqueta en X y la siguiente posicion de la pelota en Y subiendo es igual al segundo punto de la raqueta en Y significa que han chocado, por ende cambiaremos el valor  de XP a verdadero para que la pelota cambie su direccion a la derecha aumentando su valor en la posicion X.
                        xp = true;
                        puntaje += 25; //Sumamos un puntaje de 25 al jugador al haber detenido la pelota.
                    }
                }
                //Fin Verificando choque de pelota con la raqueta.

                if(puntaje == 150){ //Si el jugador a acumulado un puntaje de 150 significa que ha ganado.
                    ganador = true;
                }

                
                //Dibujamos el tablero y la posicion de la pelota
                for (int y = 0; y < altoV; y ++){
                    for (int x = 0; x < anchoV; x++){

                        if(x == 0 || (x+1) == anchoV){
                            cout<<"|"; //Dibujamos el margen izquierdo y derecho  de la ventana.

                        }else if(y == 0 || (y+1) == altoV ){
                            cout<<"---"; //Dibujamos el margen superior e inferior de la ventana.

                        }else if(x == rPosicionX && y == rPosicionY){
                            cout<<" X ";
                        }else if(x == rPosicionX && y == rPosicionY2){
                            cout<<" X ";
                        }
                        else if(x == bPosicionX && y == bPosicionY){
                            cout<<" o "; //dibujamos la pelota en la posicion de inicio definida.

                        }else{
                            cout<<"   "; //Rellenamos los espacios restantes en blanco dentro del rectangulo de la ventana.
                        }
                    }
                    cout<<"\n";
                }
                //Fin Dibujamos el tablero y la posicion de la pelota

                //Seccion de reconocimiento de tecla presionada por el usuario
                if(kbhit()){//Utilizamos la funcion kbhit() para detectar si el usuario a presionado alguna tecla.
        
                    switch (getch()) //Si el usuario presiono una tecla utilizamos la funcion getch() para detectar sel codigo ascii de la tecla presionada.

                    {
                    case 115: //Si el valor devuelto es 115 que es codigo ASCII  para "s", aumentaremos en 1 el valor de la posicion de la raqueta en Y, esto hara que la raqueta se mueva hacia "Abajo".
                        rPosicionY += 1;
                        rPosicionY2 += 1;
                        break;

                    case 83: //Si el valor devuelto es 83 que es codigo ASCII  para "S", aumentaremos en 1 el valor de la posicion de la raqueta en Y, esto hara que la raqueta se mueva hacia "Abajo".
                        rPosicionY += 1;
                        rPosicionY2 += 1;
                        break;

                    case 119: //Si el valor devuelto es 119 que es codigo ASCII  para "w", disminuimos en 1 el valor de la posicion de la raqueta en Y, esto hara que la raqueta se mueva hacia "Arriba".
                        rPosicionY -= 1;
                        rPosicionY2 -= 1;
                        break;

                    case 87: //Si el valor devuelto es 87 que es codigo ASCII  para "W", disminuimos en 1 el valor de la posicion de la raqueta en Y, esto hara que la raqueta se mueva hacia "Arriba".
                        rPosicionY -= 1;
                        rPosicionY2 -= 1;
                        break;
                    
                    default:
                        break;
                    }
                }
                //Fin Seccion de reconocimiento de tecla presionada por el usuario

                actualizar = 0; // establecemos el valor de actualizar en 0 para volver a contar.
            }
        }
        if(gameover){
            //Si el jugador a perdido, limpiamos la pantalla y escribimos la pantalla de game over.
            system("cls");
            cout<<"|-----------------------------------------------------|\n";
            cout<<"|                                                     |\n";
            cout<<"|                                                     |\n";
            cout<<"|                       GAME OVER                     |\n";
            cout<<"|                                                     |\n";
            cout<<"|                                                     |\n";
            cout<<"|-----------------------------------------------------|\n";

            cout<<"Quieres volver a jugar ?? s/n\n"; //Le preguntamos al jugador si desea volver a jugar.
            cin>>res;

            if(res == 's' || res == 'S'){
                //Si la respuesta es si, reiniciamos los valores del juego
                rPosicionX = 1;
                rPosicionX2 = rPosicionX;
                rPosicionY = 5;
                rPosicionY2 = 6;

                xp = true;
                yp = true; 
                bPosicionX++;
                bPosicionY++;
             
                bPosicionX = 5;
                bPosicionY = 5;

                puntaje = 0;

                ganador = false;
                gameover = false;
            }else{
                jugar = false;
            }

        }
        if(ganador){
            system("cls");
            cout<<"|-----------------------------------------------------|\n";
            cout<<"|                                                     |\n";
            cout<<"|                                                     |\n";
            cout<<"|                      HAS GANADO  !!                 |\n";
            cout<<"|                                                     |\n";
            cout<<"|                                                     |\n";
            cout<<"|-----------------------------------------------------|\n";
            
            cout<<"Quieres volver a jugar ?? s/n\n";
            cin>>res;

            if(res == 's' || res == 'S'){
                //Si la respuesta es si, reiniciamos los valores del juego
                rPosicionX = 1;
                rPosicionX2 = rPosicionX;
                rPosicionY = 5;
                rPosicionY2 = 6;

                //les asignamos un valor a la posicion de la pelota en X y Y para comenzar el juego
                bPosicionX = 5;
                bPosicionY = 5;

                puntaje = 0;
                ganador = false;
                gameover = false;
            }else{
                jugar = false;
            }
        }
        
        Sleep(100); //esta funcion hace que el codigo se pare por un tiempo determiando, en esta caso se frena por 0.5 segundos.

        actualizar++; // aumentamos el valor de actualizar + 1 para que al volver a ejecutar el ciclo se alctualice nuevamente la pantalla.
    }while(jugar);
    
    system("PAUSE");
    return 0;
}
