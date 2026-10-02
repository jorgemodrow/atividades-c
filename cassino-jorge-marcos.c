#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int valorcarteira(float apat, float carteira) { // Valida a aposta feita pelo usuário em relação ao saldo disponível na carteira
    int k3;
    char r;
    float dep;

    if(apat>carteira || apat<=0){
        printf("Você não tem esse valor disponivel na sua carteira! ou está apostando um valor inválido!\nDeseja fazer mais um deposito?[S/N] ");
        k3=1;
        while(k3!=0){
            scanf(" %c",&r);
            if(r=='S'||r=='s'){
                printf("\nQue ótimo! Digite quanto você deseja depositar: R$");
                scanf("%f",&dep);
                carteira+=dep;
                k3=0;
            }
            else if(r=='N'||r=='n'){
                printf("                      Aposte um valor menor \n");
                k3=0;
            }
            else{
                printf("\nResposta inválida! Tente novamente\nDeseja fazer mais um deposito?[S/N] ");
            }
        }
    }
    return carteira;
}

float resultado(int val0, int val1, int val2) { // Avalia os 3 números gerados pelo caça níquel para determinar se o jogador ganhou, quase ganhou ou perdeu, retornando o multiplicador da aposta
    float mult;

    if((val0==val1)&&(val0==val2)){
        mult = 3;
        printf("\n--------------------------------------\n");
        printf("              GANHOU! 2x");
        printf("\n--------------------------------------\n");
    } else if((val0==val1||val0==val2||val1==val2)){
        mult = 0.5;
        printf("\n--------------------------------------\n");
        printf("             QUASE! 0.5x");
        printf("\n--------------------------------------\n");
    } else {
        mult=0;
        printf("\n--------------------------------------\n");
        printf("            PERDEUUUUUU!!!!");
        printf("\n--------------------------------------\n");
    }
    return mult;
}
void main(){
    float dep=0,carteira=0,numx=0,res=0,apat=0,valapostado,mult;
    int cassino[3],i,k=1,k1=1,k2=1;
    char r;
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    printf("\n------------------------------------------------------------------\n");
    printf("            Seja bem vindo(a) ao Cassino da Fortuna!");
    printf("\n------------------------------------------------------------------\n");
    printf("    Deposite um valor inicial:           |            R$");
    scanf(" %f",&carteira);

    while(k!=0){
        k1=1;
        k2=1;

        while(k2!=0){
            printf("------------------------------------------------------------------\n");
            printf(" Valor disponivel na carteira: %.2f     | Aposta:    R$",carteira);
            scanf(" %f",&apat);
            printf("------------------------------------------------------------------\n");

            carteira = valorcarteira(apat, carteira);

            if (apat <= carteira && apat > 0) {
                k2 = 0;
            }
        }
        valapostado=apat;
        carteira-=apat;
        system("cls");
        printf("\n--------------------------------------\n");
        printf("              RESULTADO");
        printf("\n--------------------------------------\n");
        printf("\n\n    ---------|---------|---------\n");
        for(i=0;i<=2;i++){
            cassino[i]=rand()%3;
        }
        for(i=0;i<=2;i++){
            printf("        %d ",cassino[i]);
        }
        printf("\n    ---------|---------|---------\n\n");

        mult = resultado(cassino[0], cassino[1], cassino[2]);
        apat = apat*mult;
        carteira+=apat;
        if(carteira<0.01){
            carteira=0;
        }
        printf("  Valor apostado    |    R$%.2f",valapostado);
        printf("\n--------------------------------------\n");
        printf("     Resultado      |    R$%.2f",(apat-valapostado));
        printf("\n--------------------------------------\n");
        printf("      Carteira      |    R$%.2f",carteira);
        printf("\n--------------------------------------\n");
        printf("\n\n    Deseja apostar novamente? [S/N]\n\n");
        printf("\n--------------------------------------\n");
        while(k1!=0){
            scanf(" %c",&r);
            if(r=='N'||r=='n'){
                k=0;
                k1=0;
            }
            else if(r=='S'||r=='s'){
                system("cls");
                k1=0;
            }
            else{
                printf("Opção inválida!Deseja apostar novamente? [S/N]");
            }
        }
    }
    system("cls");
    printf("\n--------------------------------------\n");
    printf("        ATÉ LOGO, VOLTE SEMPRE!");
    printf("\n--------------------------------------\n");
}

