/*
============================================================
  Fichero: zxou.h
  Creado: 18-10-2025
  Ultima Modificacion: dissabte, 8 de novembre de 2025, 09:07:40
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

//MEMORY

//CONSTANTES

//dimensiones de la pantalla
#define SCRWC 32 //ancho en caracteres
#define SCRHC 32 //alto en caracteres
#define SCRWP (SCRWC*8) //ancho en pixeles
#define SCRHP (SCRHC*8) //alto en pixeles

//dimenion del pixel
#define DPIX 3 //definicion del tamaño del pixel

//numero de teclas guardadas
#define DKPL 5

//direcciones de la memoria
#define OSCR 0 //inicio de la pantalla
#define DSCR (SCRWP*SCRHP/8) //dimension de la pantalla
#define OKEY (OSCR+DSCR) //inicio del guardado de las teclas
#define DKEY DKPL //dimension de memoria dedicada a guardar las teclas pulsadas
#define OASC (OKEY+DKEY) //inicio de la memoria donde se guardan los caracteres
#define DASC (256*8) //dimension de la memoria dedicada a los ASCII
#define OROM (OASC+DASC) //rom, dedicada a guardar diferentes valores que no conviene cambiar
#define DROM 3 //dimension de la rom
#define ORAM (OROM+DROM) //ram, a disposicion del usuario
#define DRAM 1024 //dimension de la ram

//dimension total de la memoria
#define DMEM (DSCR+DKEY+DASC+DROM+DRAM)

//TIPOS

typedef unsigned char byte;
typedef unsigned short address;

//VARIABLES

extern byte memory[DMEM];

//FUNCIONES

void m_output();
//salida por pantalla de la memoria de dibujo

void m_input();
//habilita el listener para escuchar al teclado

//ZX81

//CONSTANTES

//valores de modo
#define NORMAL 0
#define INVERSE 1

//valores de conexion
#define OFF 0
#define ON 1

//direcciones de la rom
#define CURSX (OROM) //direccion de memoria donde se guarda el cursor x
#define CURSY (OROM+1) //direccion de memoria donde se guarda el cursor y
#define FLAG (OROM+2) //direccion de memoria rom donde se guardan las banderas

//banderas
#define FINV 1


//METODOS (ordenes que se podran utilizar directamente)
//no estan presentes, pero se pueden utilizar todas las funciones matematicas

#define circle(X,Y,R) z_circle((X),(Y),(R))
#define cls z_cls()
#define flip(D,O) z_flip((D),(O))
#define gdu(I,A,B,C,D,E,F,G,H) z_gdu((I),(A),(B),(C),(D),(E),(F),(G),(H))
#define inkey(C) z_inkey((C))
#define line(A,B,C,D) z_line((A),(B),(C),(D))
#define locate(X,Y) z_locate((X),(Y))
#define normal z_mode(NORMAL)
#define inverse z_mode(INVERSE)
#define pause(S) z_pause((S))
#define peek(D) memory[(D)] //consigue el valor de la direccion de memoria D
#define plot(X,Y) z_plot((X),(Y),1)
#define plotted(X,Y) z_plotted((X),(Y))
#define poke(D,V) memory[(D)]=(V) //asigna a la direccion D el valor V
#define pointer(D) memory+(D) //puntero a la direccion de memoria D
#define printc(C) z_printc((C))
#define printn(N) z_printn((N))
#define prints(S) z_prints((S))
#define randomize(S) z_randomize((S))
#define reverse(D,O) z_reverse((D),(O))
#define rnd(A,B) z_rnd((A),(B))
#define times z_time(1) //inicia el crono
#define timeg z_time(0) //da el tiempo del crono
#define unplot(X,Y) z_plot((X),(Y),0)
#define show m_output()
#define listen m_input()
#define begin void z_program() {
#define end }

void z_circle(byte cx,byte cy,byte radium);
//dibuja un circulo centrado en cx,cy con radio radium

void z_cls();
//limpiamos la memoria, se coloca el mode en normal y el cursor en el origen (el modo se mantiene)

byte z_flip(byte gdu_destiny,byte gdu_origin);
//hace una simetria vertical del origin y lo guarda en el destiny. Devuelve el destiny.

void z_gdu(byte code,byte a,byte b,byte c,byte d,byte e,byte f,byte g,byte h);
//definicion de un gdu en el caracter c

byte z_inkey(char c);
//verifica que el caracter ha sido pulsado

void z_line(byte ox,byte oy,byte fx,byte fy);
//crea una linea de origen ox,oy y final fx,fy

void z_locate(byte x,byte y);
//colocamos el cursor en la posicion marcada

void z_mode(byte m);
//definimos el modo NORMAL o INVERSE, desde la posicion del locate hasta el final de pantalla

void z_pause(double seconds);
//hacer una pausa de un determinado numero de segundos

void z_plot(byte x,byte y,byte stat);
//dibuja/quita el punto en una posicion de la pantalla (stat==ON pone, stat==OFF quita)

byte z_plotted(byte x,byte y);
//dice el estado de un punto de la pantalla

void z_printc(byte chr);
//impresion de un caracter

void z_prints(char* str);
//impresion de una cadena

void z_printn(double num);
//impresion de un numero

void z_randomize(int a);
//establecimiento de la semilla del numero aleatorio, si a negativa, en funcion del tiempo

byte z_reverse(byte gdu_destiny,byte gdu_origin);
//hace una simetria horizontal del origin y la deposita en el destiny. Devuelve el destiny.

int z_rnd(int a,int b);
//nuemero aleatorio entre dos valores dados

double z_time(byte start);
//da el valor del tiempo desde el momento que empieza el start.

void z_program();
//aqui se introduciran todas las instrucciones del programa


