#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *archivo;
    char caracter, estado;
    char palabra_reservada[][30] ={"si","sino","hacer","finsi","definir","mientras","repetir","hasta","leer","imprimir","cursor"};
    char tipo_dato[][10] ={"entero","decimal","cadena"};
    char *token;
    estado=0;

    archivo = fopen("entrada.prg","r");
    if (archivo==NULL){
        fputs("No se encuentra el archivo",stderr);
        exit(1);
    }
         while ((caracter=fgetc(archivo))!=EOF) {
            printf("%c",caracter);
            switch(caracter){
                case 1: //instrucciones
                    if(estado==0){
                        estado=1;
                    }
                break;
                case 2: //sentencias
                    if(estado==1 || estado==2 || estado==20){
                    estado=2;
                    }
                break;
                case 3: //declaraciones
                    if(estado==2 || estado==3){
                        estado=3;
                    }
                break;
                case 4: //variable
                    if (estado==3 || estado==4 || estado==8){
                        estado=4;
                    }
                break;
                case 5: //identificador
                    if (estado==4 || estado==9){
                        estado=5;
                    }
                    else if (estado==21 || estado==22 || estado==23 || estado==24 || estado==28){
                        estado=27;
                    }
                    else if (estado==36 || estado==37){
                        estado=42;
                    }
                break;
                case 6: //tipo_dato
                    if (estado==5){
                        estado=6;
                    }
                break;
                case 7: //lectura
                    if(estado==2 || estado==3 || estado==36){
                        estado=36;
                    }
                break;
                case 8: //impresion
                    if(estado==2 || estado==3 || estado==37){
                        estado=37;
                    }
                break;
                case 9: //puntero
                    if(estado==2 || estado==3 || estado==38){
                        estado=38;
                    }
                break;
                case 10: //punto
                    if(estado==38){
                        estado=39;
                    }
                break;
                case 11: //bloque
                    if(estado==2 || estado==7){
                        estado=7;
                    }
                break;
                case 12: //seleccion
                    if(estado==7 || estado==17){
                        estado=17;
                    }
                break;
                case 13: //ciclo_mientras
                    if(estado==7 || estado==18){
                        estado=18;
                    }
                break;
                case 14: //ciclo_repetir
                    if(estado==7 || estado==19){
                        estado=19;
                    }
                break;
                case 15: //condicion
                    if(estado==17 || estado==18 || estado==19 || estado==20 || estado==25){
                        estado=20;
                    }
                break;
                case 16: //condicion_expmath
                    if(estado==20){
                        estado=21;
                    }
                break;
                case 17: //condicion_identificador
                    if(estado==20){
                        estado=22;
                    }
                break;
                case 18: //condicion_decimal
                    if(estado==20){
                        estado=23;
                    }
                break;
                case 19: //condicion_entero
                    if(estado==20){
                        estado=24;
                    }
                break;
                case 20: //operador_relacional
                    if(estado==27){
                        estado=28;
                    }
                break;
                case 21: //operador_aritmetico
                    if(estado==12 || estado==13){
                        estado=26;
                    }
                break;
                case 22: //operador_logico
                    if(estado==21 || estado==22 || estado==23 || estado==24){
                        estado=25;
                    }
                break;
                case 23: //expresion_matematica
                    if(estado==28){
                        estado=29;
                    }
                    else if (estado==2 || estado==4 || estado==8){
                        estado=8;
                    }
                break;
                case 24: //decimal
                    if(estado==8 || estado==4 || estado==26 || estado==11 || estado==13){
                        estado=13;
                    }
                    else if (estado==28){
                        estado=31;
                    }
                break;
                case 25: //entero
                    if(estado==8 || estado==4 || estado==26 || estado==11 || estado==12){
                        estado=12;
                    }
                    else if (estado==28){
                        estado=30;
                    }
                    else if (estado==39 || estado==41){
                        estado=40;
                    }
                break;
                case 26: //asignacion
                    if(estado==2){
                        estado=9;
                    }
                break;
                case 27: //cadena
                    if(estado==4 || estado==10){
                        estado=10;
                    }
                break;
                case 28: //caracter
                    if(estado==10 || estado==11){
                        estado=11;
                    }
                break;
                case 29: //letra_mayuscula
                    if(estado==5 || estado==11 || estado==14){
                        estado=14;
                    }
                break;
                case 30: //letra_minuscula
                    if(estado==11 || estado==14 || estado==15){
                        estado=15;
                    }
                break;
                case 31: //numero
                    if(estado==14 || estado==11 || estado==13 || estado==32 || estado==16){
                        estado=16;
                    }
                break;
                case 32: //signo
                    if(estado==16){
                        estado=32;
                    }
                break;
                case 33: //digito
                    if(estado==16 || estado==34 || estado==33){
                        estado=33;
                    }
                break;
                case 34: //coma
                    if(estado==40){
                        estado=41;
                    }
                    else if (estado==33){
                        estado=34;
                    }
                break;
            }


            if (estado==5 || estado==27 || estado==42){
                token="Tkn_identificador";
            }
            if (estado==6){
                token="Tkn_tipo_dato";
            }
            if (estado==36){
                token="Tkn_lectura";
            }
            if (estado==37){
                token="Tkn_impresion";
            }
            if (estado==38){
                 token="Tkn_puntero";
            }
            if (estado==13 || estado==31){
                 token="Tkn_decimal";
            }
            if (estado==12 || estado==30 || estado==40){
                token="Tkn_entero";
            }
            if (estado==28){
                token="Tkn_operador_relacional";
            }
            if (estado==26){
                token="Tkn_operador_aritmetico";
            }
            if (estado==25){
                token="Tkn_operador_logico";
            }
            if (estado==14){
                token="Tkn_letra_mayuscula";
            }
            if (estado==15){
                token="Tkn_letra_minuscula";
            }
            if (estado==32){
                token="Tkn_signo";
            }
            if (estado==34 || estado==41){
                token="Tkn_coma";
            }

        }

    fclose(archivo);
    return 0;
}

    
                
                  
               
