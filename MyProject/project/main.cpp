#include <iostream>
#include <stdlib.h>     //Este include nos ayuda al momento de poner el rand() y que nos escoja numeros aleatorios. y poder usar los system() y poder limpiar la pantalla en nuestro caso.
#include <time.h>       //Este include nos ayuda al momento de utilizar el tiempo, en este caso los segundos en la funcion para pausar la pantalla.
#include <thread>       //Este include nos ayuda para cuando se esta utilizando al funcion de pause() como quien dice se utilizan juntas <thread> y <time.h> para hacer la pausa de la pantalla.
#include <iomanip>      //Este include nos ayuda para poder poner los setw que vendrian siendo lo que nos ayuda acomodar el texto mas formal se podria decir.

using namespace std;
/**
 * Devuelve una pausa en la pantalla por un tiempo determinado.
 * @param dura determina la duración de la pausa
 */
void pause(int dura);       //Funcion para pausar la pantalla por un tiempo.
/**
 * Devuelve un entero y acepta dos parámetros enteros para
 * correr una función recursiva que multiplique los dos parámetros.
 * @param tab Numero ingresado por el usuario
 * @param conta Numero del 1 al 10 a multiplicar
 * @return imprime en pantalla la multiplicacion de los parámetros y hace recursion
 */
int tablas(int, int);       //Funcion que nos ayuda para la opcion "Aprender tablas".

int main()
{
    const int NUM = 3;      //ES la constante que se utiliza en los ciclos for para hacer los calculos de matrices.
    int opcion = 0, vidas = 3, num1J = 0, num2J = 0, score = 0, respuestaJ = 0, nivel = 1, operacion = 0,
        tabla = 0, conta = 0, contaM = 1, m [NUM][NUM], ran = 0;       //Aqui estan declaradas todas las variables de tipo entero con sus respectivos nombres simbolicos.
    float num1C = 0, num2C = 0, det = 0, traza = 0;     //Aqui estan declaradas todas las variables de tipo flotante con sus respectivos nombres simbolicos.
    string nombre, tipo;

    menu:
        system("cls"); //todos los system("cls") nos ayudan a limpiar la pantalla que se esta trabajando.
        srand(time(NULL));        //Sirve para ayudar al momento de usar la funcion que detiene el la pantalla pause()
    cout<<"PROYECTO"<<endl;
    cout<<"\nIntroduzca la opcion que desea realizar."<<endl
        <<"[1] Jugar"<<endl
        <<"[2] Calculadora"<<endl
        <<"[3] Aprender Tablas"<<endl
        <<"[4] Calculadora de Matriz 3x3"<<endl
        <<"[5] Salir"<<endl;
    cin>>opcion;

    switch(opcion){         //Es el switch que nos ayuda a buscar la opcion deseada.
    case 1:
        system("cls");

        cout<<"Jugar"<<endl;
        cout<<"Introduce tu nombre: "<<endl;
        cin>>nombre;

        juego_n:
        nivel=1, score=0, vidas=3;      //Reinicia las variables a como estaban antes de comenzar el programa y poder iniciar de nuevo.
        juego:
        level:
        system("cls");
        cout<<"Nivel "<<nivel<<setw(20)<<"Puntaje: "<<score<<setw(20)<<"Vidas: "<<vidas<<endl;      //setw nos ayuda a tener un espacio entre los datos que vamos a mostrar.

        switch (nivel){     //Este switch es para cuando en el juego avanzamos de nivel vaya aumentando la dificultad.
        case 1:
            if (score >= 80){
                nivel ++;
                goto level;     //Nos manda al level para poder iniciar la variable nivel con su respectivo valor aumentandole 1.
            }else{
            num1J = (rand() % 21);
            num2J = (rand() % 21);
            cout<<"Cuanto es "<<num1J<<" sumado a "<<num2J<<": "<<endl;
            cin>>respuestaJ;
                if(respuestaJ == num1J+num2J){
                cout<<"Correcto"<<endl;
                score += 20;
                pause(1.5);     //Todos los pause() sirven para poder detener la pantalla de la consola por un momento.
                goto juego;     //Nos manda al juego de nuevo para crear nuevos numeros aleatorios.
            }else{
                cout<<"Incorrecto"<<endl;
                if (score == 0)
                    score = 0;
                else
                    score -= 5;
                vidas --;
                    if(vidas == 0){
                        system("cls");
                        cout<<"Has perdido."<<endl
                            <<nombre<<" hizo una puntuacion de " <<score<<" puntos."<<endl;
                            opcionJ:
                        cout<<"[1] Para jugar de nuevo"<<endl
                            <<"[2] Para volver al menu"<<endl;
                        cin>>opcion;
                        switch(opcion){
                        case 1:
                            goto juego_n;       //Nos manda al juego donde se reinician variables y asi poder volver a jugar con nuevo puntaje, 3 vidas y nivel 1.
                            break;
                        case 2:
                            goto menu;          //Nos manda al menu principal.
                            break;
                        default:
                            cout<<"Esa no es una opcion."<<endl;
                            goto opcionJ;       //Al momento de elegir una opcion erronea, nos manda a vovler a elegir otra opcion.
                            break;
                        }

                    }else{
                    pause(1.5);
                    goto juego;
                    }
                }
            }
            break;
        case 2:
            if (score >= 360){
                nivel ++;
                goto level;
            }else{
            num1J = (rand() % 41);
            num2J = (rand() % 41);
            cout<<"Cuanto es "<<num1J<<" sumado a "<<num2J<<": "<<endl;
            cin>>respuestaJ;
                if(respuestaJ == num1J+num2J){
                cout<<"Correcto"<<endl;
                score += 30;
                pause(1.5);
                goto juego;
            }else{
                cout<<"Incorrecto"<<endl;
                if (score == 0)
                    score = 0;
                else
                    score -= 5;
                vidas --;
                    if(vidas == 0){
                        system("cls");
                        cout<<"Has perdido."<<endl
                        <<nombre<<" hizo una puntuacion de " <<score<<" puntos."<<endl;
                        opcionJ2:
                        cout<<"[1] Para jugar de nuevo"<<endl
                            <<"[2] Para volver al menu"<<endl;
                        cin>>opcion;
                        switch(opcion){
                        case 1:
                            goto juego_n;
                            break;
                        case 2:
                            goto menu;
                            break;
                        default:
                            cout<<"Esa no es una opcion."<<endl;
                            goto opcionJ2;
                            break;
                        }
                    }else{
                    pause(1.5);
                    goto juego;
                    }
                }
            }
            break;
        case 3:
            if (score >= 900){
                nivel ++;
                goto level;
            }else{
            num1J = (rand() % 61);
            num2J = (rand() % 61);
            cout<<"Cuanto es "<<num1J<<" sumado a "<<num2J<<": "<<endl;
            cin>>respuestaJ;
                if(respuestaJ == num1J+num2J){
                cout<<"Correcto"<<endl;
                score += 50;
                pause(1.5);
                goto juego;
            }else{
                cout<<"Incorrecto"<<endl;
                if (score == 0)
                    score = 0;
                else
                    score -= 5;
                vidas --;
                    if(vidas == 0){
                        system("cls");
                        cout<<"Has perdido."<<endl
                            <<nombre<<" hizo una puntuacion de " <<score<<" puntos."<<endl;
                        opcionJ3:
                        cout<<"[1] Para jugar de nuevo"<<endl
                            <<"[2] Para volver al menu"<<endl;
                        cin>>opcion;
                        switch(opcion){
                        case 1:
                            goto juego_n;
                            break;
                        case 2:
                            goto menu;
                            break;
                        default:
                            cout<<"Esa no es una opcion."<<endl;
                            goto opcionJ3;
                            break;
                        }
                    }else{
                    pause(1.5);
                    goto juego;
                    }
                }
            }
            break;
        case 4:
            if (score >= 1860){
                nivel += 1;
                goto level;
            }else{
            num1J = (rand() % 81);
            num2J = (rand() % 81);
            cout<<"Cuanto es "<<num1J<<" sumado a "<<num2J<<": "<<endl;
            cin>>respuestaJ;
                if(respuestaJ == num1J+num2J){
                cout<<"Correcto"<<endl;
                score += 75;
                pause(1.5);
                goto juego;
            }else{
                cout<<"Incorrecto"<<endl;
                if (score == 0)
                    score = 0;
                else
                    score -= 5;
                vidas --;
                    if(vidas == 0){
                        system("cls");
                        cout<<"Has perdido."<<endl
                            <<nombre<<" hizo una puntuacion de " <<score<<" puntos."<<endl;
                        opcionJ4:
                        cout<<"[1] Para jugar de nuevo"<<endl
                            <<"[2] Para volver al menu"<<endl;
                        cin>>opcion;
                        switch(opcion){
                        case 1:
                            goto juego_n;
                            break;
                        case 2:
                            goto menu;
                            break;
                        default:
                            cout<<"Esa no es una opcion."<<endl;
                            goto opcionJ4;
                            break;
                        }
                    }else{
                    pause(1.5);
                    goto juego;
                    }
                }
            }
            break;
        case 5:
            num1J = (rand() % 101);
            num2J = (rand() % 101);
            cout<<"Cuanto es "<<num1J<<" sumado a "<<num2J<<": "<<endl;
            cin>>respuestaJ;
                if(respuestaJ == num1J+num2J){
                cout<<"Correcto"<<endl;
                score += 100;
                pause(1.5);
                goto juego;
            }else{
                cout<<"Incorrecto"<<endl;
                if (score == 0)
                    score = 0;
                else
                    score -= 5;
                vidas --;
                    if(vidas == 0){
                        system("cls");
                        cout<<"Has perdido."<<endl
                            <<nombre<<" hizo una puntuacion de " <<score<<" puntos."<<endl;
                        opcionJ5:
                        cout<<"[1] Para jugar de nuevo"<<endl
                            <<"[2] Para volver al menu"<<endl;
                        cin>>opcion;
                        switch(opcion){
                        case 1:
                            goto juego_n;
                            break;
                        case 2:
                            goto menu;
                            break;
                        default:
                            cout<<"Esa no es una opcion."<<endl;
                            goto opcionJ5;
                            break;
                        }
                    }else{
                    pause(1.5);
                    goto juego;
                    }
                }
            break;
        }
        break;
    case 2:
        calculadora:
        system("cls");
        cout<<"Calculadora"<<endl;
        cout<<"\nIntroduzca la opcion que desea realizar."<<endl
            <<"[1] Suma"<<endl
            <<"[2] Resta"<<endl
            <<"[3] Multiplicacion"<<endl
            <<"[4] Division"<<endl
            <<"[5] Regresar al menu principal"<<endl;
        cin>>operacion;

        switch(operacion){      //Este switch busca cual operacion eligió el usuario para calcular.
        case 1:
            system ("cls");
            cout<<"Suma"<<endl;
            cout<<"Introduzca el primer numero: ";
            cin>>num1C;
            cout<<"Introduzca el segundo numero: ";
            cin>>num2C;
            cout<<"El resultado es "<<num1C+num2C<<endl;
            pause(5);
            goto calculadora;       //Nos regresa a la calculadora por si queremos hacer otro calculo o salir.
            break;
        case 2:
            system("cls");
            cout<<"Resta"<<endl;
            cout<<"Introduzca el primer numero: ";
            cin>>num1C;
            cout<<"Introduzca el segundo numero: ";
            cin>>num2C;
            cout<<"El resultado es "<<num1C-num2C<<endl;
            pause(5);
            goto calculadora;
            break;
        case 3:
            system("cls");
            cout<<"Multiplicacion"<<endl;
            cout<<"Introduzca el primer numero: ";
            cin>>num1C;
            cout<<"Introduzca el segundo numero: ";
            cin>>num2C;
            cout<<"El resultado es "<<num1C*num2C<<endl;
            pause(5);
            goto calculadora;
            break;
        case 4:
            system("cls");
            cout<<"Division"<<endl;
            cout<<"Introduzca el primer numero: ";
            cin>>num1C;
            div:
            cout<<"Introduzca el segundo numero: ";
            cin>>num2C;
            if (num2C == 0){
                cout<<"\nNo se puede realizar la operacion.\nDigite otro numero distinto a 0.\n"<<endl;
                goto div;       //Nos manda a volver a introducir el segundo numero de la division.
            }else{
                cout<<"El resultado es "<<num1C/num2C<<endl;
                pause(5);
                goto calculadora;
            }
            break;
        case 5:
            goto menu;
            break;
        default:
            cout<<"Opcion no valida"<<endl;
            pause(5);
            goto calculadora;       //Nos manda a la calculadora para volver a introducir una opcion y proceder con el calculo.
        }
        break;
    case 3:
        aprender:
            system("cls");
            cout<<"Aprender Tablas"<<endl;      //Aqui se aprenderan las tablas del numero que se desee.
            cout<<"Digite el numero de la tabla que desea aprender: ";
            cin>>tabla;
            tablas(tabla, conta);       //Manda a llamar la funcion recursiva para calcular las tablas.
            opcion:
            cout<<"\n[1] Para aprender de nuevo"<<endl
                <<"[2] Para regresar al menu principal"<<endl;
            cin>>operacion;
            switch(operacion){      //Busca la opcion si queremos aprender otra tabla o regresar al menu principal.
            case 1:
                goto aprender;
                break;
            case 2:
                goto menu;
                break;
            default:
                cout<<"No es una opcion"<<endl;
                goto opcion;
                break;
            }
        break;
    case 4:
        deter:
        system ("cls");
        cout<<"Introduzca los numeros en este orden:"<<endl
            <<"[1, 2, 3]"<<endl
            <<"[4, 5, 6]"<<endl
            <<"[7, 8, 9]"<<endl;

            for (int i = 0; i<NUM; i++){      //Hace que se incremente el numero de filas en el arreglo
                for (int j = 0; j<NUM; j++){      //Hace qu se incremente el numero de columnas
                    cout<<contaM<< " = ";
                    cin>>m[i][j];
                    contaM++;
                    if (contaM == 10){      //Cuando llega a 10 lo convierte a 1, para el proximo intento de matriz
                        contaM = 1;
                    }
                }
            }
            cout<<"\n["<<setw(4)<<m[0][0]<<"] "<<"["<<setw(4)<<m[0][1]<<"] "<<"["<<setw(4)<<m[0][2]<<"]"
                <<"\n["<<setw(4)<<m[1][0]<<"] "<<"["<<setw(4)<<m[1][1]<<"] "<<"["<<setw(4)<<m[1][2]<<"]"
                <<"\n["<<setw(4)<<m[2][0]<<"] "<<"["<<setw(4)<<m[2][1]<<"] "<<"["<<setw(4)<<m[2][2]<<"]"<<endl;
            det=(m[0][0]*m[1][1]*m[2][2]+m[0][1]*m[1][2]*m[2][0]+m[0][2]*m[1][0]*m[2][1])-      //Hace las operaciones necesarias para llegar a la determinante
            (m[0][1]*m[1][0]*m[2][2]+m[0][0]*m[1][2]*m[2][1]+m[0][2]*m[1][1]*m[2][0]);
            traza=m[0][0]+m[1][1]+m[2][2];
            if (det != 0){      //Si la condición se cumple, la variable ran es igual al numero de filas o columnas y es de tipo no singular
                ran = NUM;
                tipo="No Singular";
            }else{      //Si la variable det es 0, ran es el numero de filas menos 1 y el tipo es singular
                ran = NUM-1;
                tipo="Singular";
            }
            cout<<"La determinante es: "<<det<<endl
                <<"La traza es: "<<traza<<endl
                <<"El rango es: "<<ran<<endl
                <<"Tipo: "<<tipo<<endl;
                opcionM:
            cout<<"\n[1] Resolver otra matriz"<<endl
                <<"[2] Regresar al menu principal"<<endl;
            cin>>operacion;
            switch(operacion){
            case 1:
                goto deter;      //Nos manda a deter, para reiniciar el calculo con otra matriz
                break;
            case 2:
                goto menu;
                break;
            default:
                cout<<"No es una opcion"<<endl;
                goto opcionM;      //Nos manda a las opciones válidas
                break;
            }
        break;
    case 5:
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        pause(2);
        goto menu;
        break;
    }

    return 0;
}

void pause(int dura){       //Es la funcion que ayuda a pausar la pantalla por un momento.
    int tiempo = time(NULL) + dura; /**< Se le asigna a una variable tiempo la función predeterminada time con retorno nulo
                                      y se le suma el valor de la variable dura.
                                     */
    while(tiempo > time(NULL)); /**< Mientras tiempo sea mayor a time(NULL) va a mantenerse pausado. */
}

int tablas(int tab, int conta){     //Funcion recursiva para aprender las tablas.
    conta++;
    if(conta <= 10){    /**< Mientras la variable conta sea menor o igual a 10 imprime tab, conta y la multiplicación de conta
                          y tab, al final hace una recursión para crear un ciclo.
                         */
        cout<<tab<<" x "<<setw(2)<<conta<< " = "<<conta * tab<<endl;
        return tablas(tab, conta);
    }
}
