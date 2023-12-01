#include <string.h>
#include <stdio.h>

//Definicao das structs
struct Data
{
    int dia;
    int mes;
    int ano;
};

struct Cliente
{
    char nome_do_cliente[50];
    char telefone_do_cliente[15];
};

struct Animal
{
    struct Cliente cliente;
    char nome_do_animal[50];
    int especie;
    struct Data data_nascimento;
    char agressivo;
};

struct Servico
{
    int identificador;
    struct Data data_servico;
    struct Animal pet;
    int tipo_de_servico;
    char pago;

};

//Retorna se a data é valida ou não, 0 para caso for valida e 1 para caso não seja
int validarData(struct Data dataValidada){

    struct Data dAtual;

    printf("\nInforme a data de hoje (d/m/a): ");
    scanf(" %d/%d/%d", &dAtual.dia, &dAtual.mes, &dAtual.ano);

    //validar ano:
    if(dataValidada.ano <= dAtual.ano){
        //validar mês:
        if((dataValidada.ano == dAtual.ano && dataValidada.mes <= dAtual.mes) || (dataValidada.ano != dAtual.ano && dataValidada.mes <= 12)){
            //validar dia (mês comercial):
            if((dataValidada.mes == dAtual.mes && dataValidada.dia <= dAtual.dia) || (dataValidada.mes != dAtual.mes && dataValidada.dia <= 30)){   
                printf("\nData válida.");
                return 0;
            }
        }
    } 
    printf("\nData inválida.");
    return 1;

}

//Retorna se o nome é valido ou não, 0 para caso for valido e 1 para caso não seja
int validarnome(char nome[50]){

    if(nome[0] == ' '){
        return 1;
    }

    else if(strlen(nome) < 4){
        return 1;
    }

    for (int i = 0; nome[i] != '\0'; i++)
    {
        if(nome[i] > 47 && nome[i] < 57){
            return 1;
        }
    }
    
    return 0;
}

//Retorna se o telefone é valido ou não, 0 para caso seja valido e 1 caso não seja
int validartelefone(char telefone[15]){
    if(telefone[0] != '0'){
        return 1;
    }
    else if(strlen(telefone) != 11 && strlen(telefone) != 12){
        return 1;
    }

    return 0;
}

int cadastrarclientes(struct Cliente *clientes,int cont){
    
    char nometemp[50],telefonetemp[15];



    while(1){
   
    printf("\e[1;1H\e[2J");

    printf("Por favor digite o nome do Cliente: ");
    scanf(" %[^\n]",nometemp);

    printf("\e[1;1H\e[2J");

    if(validarnome(nometemp) == 0){
        strcpy(clientes[cont].nome_do_cliente, nometemp);
        break;
    }

    else{
        printf("Nome invalido\n");
        getchar();
        getchar();
    }
    }

    while (1)
    {
            printf("\e[1;1H\e[2J");

            printf("Por Favor digite o telefone do Cliente: ");
            scanf(" %[^\n]",telefonetemp);

            printf("\e[1;1H\e[2J");

            if(validartelefone(telefonetemp) == 0){
                strcpy(clientes[cont].telefone_do_cliente,telefonetemp);
                break;    
            }
            else{
                printf("Telefone invalido\n");
                getchar();
                getchar();
            }
    }
    

    return 0;
}

int cadstrarPet(struct Animal *animais, int cont){

    char nometemp[50],nomeclientetemp[50];
    struct Data temp;

    while(1){
   
    printf("\e[1;1H\e[2J");

    printf("Por favor digite o nome do Animal: ");
    scanf(" %[^\n]",nometemp);

    printf("\e[1;1H\e[2J");

    if(validarnome(nometemp) == 0){
        strcpy(animais[cont].nome_do_animal, nometemp);
        break;
    }

    else{
        printf("Nome invalido\n");
        getchar();
        getchar();
    }
    }

    printf("Por favor informe o codigo da especie\n1 - Cachorro\n2 - Gato\n3 - Passaro\n 4 - Outros\n");
    scanf(" %d",&animais[cont].especie);

    printf("Por favor digite se o animal é agressivo ou não (S/N): ");
    scanf(" %c",&animais[cont].agressivo);

    while(1){
    printf("Por favor digite a data de nascimento do animal no formato(Dia/Mes/Ano):\n");
    scanf( "%d/%d/%d",&temp.dia,&temp.mes,&temp.ano);

    if (1);
    {
        /* code */
    }
    
    }


     while(1){
   
    printf("\e[1;1H\e[2J");

    printf("Por favor digite o nome do Cliente dono do animal: ");
    scanf(" %[^\n]",nometemp);

    printf("\e[1;1H\e[2J");

    if(validarnome(nometemp) == 0){
        strcpy(animais[cont].cliente.nome_do_cliente, nometemp);
        break;
    }

    else{
        printf("Nome invalido\n");
        getchar();
        getchar();
    }
    }

return 0;
}


int main(){


    struct Cliente clientes[50];
    int numClientes = 0;

    cadastrarclientes(clientes,numClientes);
    numClientes++;

    int op;
    scanf("%d", &op);

    do{

        if(op == 1){

        } else if(op == 2){

        }
        else if (op == 3){
        }
        else if (op == 4){
            //validarData();
        }

    }while (op != 11);


    return 0;
}