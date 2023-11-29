#include <string.h>
#include <stdio.h>

//Definicao das structs
struct Data
{
    int data;
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


//Retorna se o nome é valido ou não, 0 para caso for valido e 1 para caso não seja
int validarnome(char nome[50]){

    if(nome[0] == ' '){
        return 1;
    }

    else if(strlen(nome) < 3){
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
    else if(strlen(telefone) != 11 || strlen(telefone) != 12){
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
            scanf(" %[^\n]",clientes->telefone_do_cliente);

            printf("\e[1;1H\e[2J");

            if(validartelefone(telefonetemp)){
                strcpy(clientes[cont].telefone_do_cliente,telefonetemp);
                break;
                
            }
            else{
                printf("Telefone invalido\n");
            }
    }
    

    return 0;
}

int cadstrarPet();


int main(){


    struct Cliente clientes[50];
    int numClientes = 0;



    cadastrarclientes(clientes,numClientes);
    numClientes++;



    return 0;
}