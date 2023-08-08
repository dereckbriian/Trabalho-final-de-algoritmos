#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct
{
  char nome[50];
  char login[50];
  char senha[50];
  char cpf[12];
  float saldo;
} Pessoa;

void exibirCabecalho()
{
  printf("                                                                                          \n");
  printf("\n$$$$$$$\\                                           $$\\                 $$\\           \n");
  usleep(500000);
  printf("$$  __$$\\                                          \\__|                $$ |          \n");
  printf("$$ |  $$ | $$$$$$\\  $$$$$$\\$$$$\\        $$\\    $$\\ $$\\ $$$$$$$\\   $$$$$$$ | $$$$$$\\  \n");
  usleep(500000);
  printf("$$$$$$$\\ |$$  __$$\\ $$  _$$  _$$\\       \\$$\\  $$  |$$ |$$  __$$\\ $$  __$$ |$$  __$$\\ \n");
  printf("$$  __$$\\ $$$$$$$$ |$$ / $$ / $$ |       \\$$\\$$  / $$ |$$ |  $$ |$$ /  $$ |$$ /  $$ |\n");
  usleep(500000);
  printf("$$ |  $$ |$$   ____|$$ | $$ | $$ |        \\$$$  /  $$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |\n");
  printf("$$$$$$$$ |\\$$$$$$$\\ $$ | $$ | $$ |         \\$  /   $$ |$$ |  $$ |\\$$$$$$$ |\\$$$$$$  |\n");
  usleep(500000);
  printf("\\________/  \\_______|\\__| \\__| \\__|          \\_/    \\__|\\__|  \\__| \\_______| \\______/ \n");
  printf("                         $$$$$$\\                                                      \n");
  printf("                        $$  __$$\\                                                     \n");
  usleep(500000);
  printf("                        $$ /  $$ | $$$$$$\\                                            \n");
  printf("                        $$$$$$$$ |$$  __$$\\                                           \n");
  usleep(500000);
  printf("                        $$  __$$ |$$ /  $$ |                                          \n");
  printf("                        $$ |  $$ |$$ |  $$ |                                          \n");
  printf("$$$$$$$\\                $$ |  $$ |\\$$$$$$  |            $$$$$$\\ $$$$$$$$\\  $$$$$$\\   \n");
  usleep(500000);
  printf("$$  __$$\\               \\__|  \\__| \\______/             \\_$$  _|$$  _____|$$  __$$\\  \n");
  printf("$$ |  $$ | $$$$$$\\  $$$$$$$\\   $$$$$$$\\  $$$$$$\\          $$ |  $$ |      $$ /  \\__| \n");
  printf("$$$$$$$\\ | \\____$$\\ $$  __$$\\ $$  _____|$$  __$$\\         $$ |  $$$$$\\    $$ |$$$$\\  \n");
  usleep(500000);
  printf("$$  __$$\\  $$$$$$$ |$$ |  $$ |$$ /      $$ /  $$ |        $$ |  $$  __|   $$ |\\_$$ | \n");
  printf("$$ |  $$ |$$  __$$ |$$ |  $$ |$$ |      $$ |  $$ |        $$ |  $$ |      $$ |  $$ | \n");
  printf("$$$$$$$  |\\$$$$$$$ |$$ |  $$ |\\$$$$$$$\\ \\$$$$$$  |      $$$$$$\\ $$ |      \\$$$$$$  | \n");
  usleep(500000);
  printf("\\_______/  \\_______|\\__|  \\__| \\_______| \\______/       \\______|\\__|       \\______/  \n");
  printf("                                                                                    \n");
  printf("                                                                                    \n");
  printf("\n");

  printf("\nPRESSIONE ENTER PARA CONTINUAR");
  getchar();
  system("cls");
}

void exibirCabecalho1()
{
  printf("\t==================================\n");
  printf("\t+ Bem-vindo ao Banco IFG          +\n");
  printf("\t+---------------------------------+\n");
  printf("\t+ Instituto Federal de Goias      +\n");
  printf("\t+ Campus Formosa                  +\n");
  printf("\t==================================\n\n\n\n");
}

void teladeinicio()
{
  printf("=================== MENU INICIAL ===================\n");
  printf("1 - Fazer login\n");
  printf("2 - Cadastrar nova conta\n");
  printf("3 - Sair\n");
  printf("===================================================\n");
}

void salvarDados(Pessoa contas[], int numContas)
{
  FILE *arquivo = fopen("contas.csv", "w");

  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }
  int i;
  fprintf(arquivo, "Nome,CPF,Login,Senha,Saldo\n");
  for (i = 0; i < numContas; i++)
  {
    fprintf(arquivo, "%s,%s,%s,%s,%.2f\n", contas[i].nome, contas[i].cpf, contas[i].login, contas[i].senha, contas[i].saldo);
  }

  fclose(arquivo);
  printf("\nDados salvos com sucesso!\n");
  getchar();
}

void recuperarDados(Pessoa *contas, int *numContas)
{
  FILE *arquivo = fopen("contas.csv", "r");

  if (arquivo == NULL)
  {
    printf("Arquivo não encontrado!\n");
    return;
  }

  *numContas = 0;

  while (!feof(arquivo) && *numContas < 100)
  {
    fscanf(arquivo, "%s %d %lf\n", contas[*numContas].nome, &contas[*numContas].cpf, &contas[*numContas].login, &contas[*numContas].senha, &contas[*numContas].saldo);
    (*numContas)++;
  }

  fclose(arquivo);
  exibirCabecalho();
}

int registrar(Pessoa *conta, int *numContas)
{
  int i, valido = 0;

  if (*numContas >= 100)
  {
    printf("Limite máximo de contas atingido!\n");
  }

  printf("\n=================== CADASTRO DE CONTA ===================\n");

  printf("\nPreencha os requisitos para registro\n");

  printf("\nDigite seu nome: \n");
  scanf("%s", conta[*numContas].nome);

  while (valido == 0)
  {
    printf("\nDigite seu CPF (apenas numeros): \n");
    scanf("%s", conta[*numContas].cpf);
    fflush(stdin);

    valido = 1;

    for (i = 0; conta[*numContas].cpf[i] != '\0'; i++)
    {
      if (!isdigit(conta[*numContas].cpf[i]))
      {
        valido = 0;
        break;
      }
    }

    if (valido == 0)
    {
      printf("CPF invalido !! digite apenas numeros\n");
    }
  }

  printf("\nEscolha um login: \n");
  scanf("%s", conta[*numContas].login);

  printf("\nEscolha uma senha: \n");
  scanf("%s", conta[*numContas].senha);

  conta[*numContas].saldo = 0.0;

  (*numContas)++;

  printf("==============================\n");
  printf("| Registro feito com sucesso! |\n");
  printf("==============================\n");
  printf("\nPRESSIONE ENTER PARA CONTINUAR");
  getchar();
  getchar();
  system("cls");
}
int Login(Pessoa conta[], int numContas)
{
  char login[50], senha[50];
  int i, posicao = -1;

  if (numContas == 0)
  {
    printf("Nenhuma conta cadastrada!\n");
  }

  printf("\n=================== LOGIN ===================\n");

  printf("\nColoque seus dados para login:\n");

  printf("\nLogin: ");
  scanf("%s", login);
  printf("\nSenha: ");
  fflush(stdin);
  scanf("%s", senha);

  printf("\n=============================================\n");
  getchar();

  for (i = 0; i < numContas; i++)
  {
    if (strcmp(conta[i].login, login) == 0 && strcmp(conta[i].senha, senha) == 0)
    {
      posicao = i;
    }
  }
  if (posicao != -1)
  {
    return posicao;
  }
  else
  {
    return -1;
    system("cls");
  }
}

void Salvar(Pessoa *conta, int numContas)
{
  FILE *arquivo = fopen("contas.txt", "w");
  int i;

  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }

  for (i = 0; i < numContas; i++)
  {
    fprintf(arquivo, "%s %s %s %s %.2lf\n", conta[i].nome, conta[i].cpf, conta[i].login, conta[i].senha, conta[i].saldo);
  }

  fclose(arquivo);
  printf("\nDados salvos com sucesso!\n");
  getchar();
}
void recuperar(Pessoa conta[], int *numContas)
{
  FILE *arquivo = fopen("contas.csv", "r");

  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  char linha[200];
  *numContas = 0;

  // Ignorar a primeira linha (cabeçalho)
  fgets(linha, 200, arquivo);

  while (fgets(linha, 200, arquivo) != NULL)
  {
    char *token = strtok(linha, ",");

    if (token == NULL)
    {
      continue;
    }

    strcpy(conta[*numContas].nome, token);

    token = strtok(NULL, ",");

    if (token == NULL)
    {
      continue;
    }
    strcpy(conta[*numContas].cpf, token);

    token = strtok(NULL, ",");

    if (token == NULL)
    {
      continue;
    }
    strcpy(conta[*numContas].login, token);

    token = strtok(NULL, ",");

    if (token == NULL)
    {
      continue;
    }
    strcpy(conta[*numContas].senha, token);

    token = strtok(NULL, ",");

    if (token == NULL)
    {
      continue;
    }

    conta[*numContas].saldo = atof(token);

    (*numContas)++;
  }

  fclose(arquivo);
}


int main()
{
  int saque, deposito, op, po, tamanho = 0;
  double saldo = 0.00;
  Pessoa contas[100];

  int numContas = 0, numcontas2 = 0, log;

  recuperar(contas, &numContas);

  exibirCabecalho();
  exibirCabecalho1();

  do
  {
    system("cls");
    exibirCabecalho1();
    teladeinicio();
    printf("Escolha uma das alternativas: ");
    scanf("%d", &po);
    system("cls");

    switch (po)
    {


    case 1:

      log = Login(contas, numContas);
      if (log != -1)
      {

        printf("\n==============================\n");
        printf("|   Login feito com sucesso! |\n");
        printf("==============================\n");
        getchar();

        do
        {

          system("cls");
          exibirCabecalho1();
          printf("=================== MENU LOGADO ===================\n");
          printf("\nCliente: %s", contas[log].nome);
          printf("\nCPF: %s", contas[log].cpf);
          printf("\nDigite:\n\n1.Saldo\n2.Saque\n3.Desposito\n4.Dados da conta\n5.Cartao\n6.Salvar e voltar ao menu\n\nEscolha: \t");
          printf("\n===================================================\n");
          scanf("%d", &op);

          switch (op)
          {

          case 1:
            system("cls");
            printf("\nCliente: %s", contas[log].nome);
            printf("\nCPF: %s", contas[log].cpf);
            printf("\nVoce tem %.2f nesse banco\n", contas[log].saldo);
            printf("\nPREESIONE ENTER PARA VOLTAR AO MENU!");
            getchar();
            getchar();
            break;

          case 2:
          saldo = contas[log].saldo;

            system("cls");
            printf("\n=================== SAQUE ===================\n");
            printf("\nCliente: %s", contas[log].nome);
            printf("\nCPF: %s", contas[log].cpf);
            printf("\nDigite o valor que voce quer sacar: \n");
            scanf("%d", &saque);

            do
            {

              if (saque <= saldo && saque >= 0)
              {
                saldo = saldo - saque;
                printf("Saque feito com sucesso!");
                printf("\nPREESIONE ENTER PARA VOLTAR AO MENU!");
                getchar();
                getchar();
              }
              else
              {
                printf("Valor invalido ou saldo insuficiente.\n");
                getchar();
                getchar();
                break;
              }

            } while (saque > saldo || saque < 0);
            contas[log].saldo = saldo;

            break;

          case 3:
            system("cls");
            printf("\n=================== DEPÓSITO ===================\n");
            printf("\nCliente: %s", contas[log].nome);
            printf("\nCPF: %s", contas[log].cpf);
            printf("\nEscolha um valor para deposito:\t");
            scanf("%d", &deposito);

            do
            {

              if (deposito <= 0)
              {
                printf("Digite um valor coerente para depositar\n");
                scanf("%d", &deposito);
                getchar();
              }
            } while (deposito <= 0);

            contas[log].saldo = contas[log].saldo + deposito;
            printf("Deposito feito com sucesso!");
            printf("\nPREESIONE ENTER PARA VOLTAR AO MENU!");
            getchar();
            getchar();
            break;

          case 4:
            system("cls");
            printf("\n=================== DADOS DA CONTA ===================\n");
            printf("\nCliente: %s", contas[log].nome);
            printf("\nCPF: %s", contas[log].cpf);
            printf("\nLogin: %s", contas[log].login);
            printf("\nSenha: %s", contas[log].senha);
            printf("\nSaldo: %.2f\n", saldo);
            printf("======================================================\n");
            printf("\nPRESSIONE ENTER PARA VOLTAR AO MENU!");
            getchar();
            getchar();

            break;

          case 5:
            system("cls");

            printf("Carregando");
            usleep(500000);
            system("cls");
            printf("Carregando.");
            usleep(500000);
            system("cls");
            printf("Carregando..");
            usleep(500000);
            system("cls");
            printf("Carregando...");
            usleep(500000);
            system("cls");
            printf("Carregando");
            usleep(500000);
            system("cls");
            printf("Carregando.");
            usleep(500000);
            system("cls");
            printf("Carregando..");
            usleep(500000);
            system("cls");
            printf("Carregando...");
            usleep(500000);
            system("cls");
            printf("Carregando");
            usleep(500000);
            system("cls");
            printf("Carregando.");
            usleep(500000);
            system("cls");
            printf("Carregando..");
            usleep(500000);
            system("cls");
            printf("Carregando...");
            usleep(500000);
            system("cls");
            printf("Carregando");
            usleep(500000);
            system("cls");
            printf("Carregando.");
            usleep(500000);
            system("cls");
            printf("Carregando..");
            usleep(500000);
            system("cls");
            printf("Carregando...");
            usleep(500000);
            system("cls");
            printf("Carregando");

            system("cls");
            printf(" ___________________________________________\n");
            printf("|                                           |\n");
            usleep(500000);
            printf("|   IF BANK                                 |\n");
            printf("|                                           |\n");
            usleep(500000);
            printf("|         Nome do cartao: %s            |\n", contas[log].nome);
            printf("|         Numero do cartao: 1234 5678       |\n");
            usleep(500000);
            printf("|         Validade: 12/25                   |\n");
            printf("|                                           |\n");
            usleep(500000);
            printf("|___________________________________________|\n");
            printf("\nPRESSIONE ENTER PARA VOLTAR AO MENU!");
            getchar();
            getchar();
            system("cls");

            break;

          case 6:
            salvarDados(contas, numContas);
            getchar();
            break;
          }

        } while (op != 6);
      }
      else
      {
        printf("Login senha incorretos ou dados nao cadastrado");
        getchar();
      }
      break;


    case 2:

      registrar(contas, &numContas);
      salvarDados(contas, numContas);
      log = Login(contas, numContas);

      if (log != -1)
      {
        do
        {

          system("cls");
          exibirCabecalho1();
          printf("=================== MENU LOGADO ===================\n");
          printf("\nCliente: %s", contas[log].nome);
          printf("\nCPF: %s", contas[log].cpf);
          printf("\nDigite:\n\n1.Saldo\n2.Saque\n3.Desposito\n4.Dados da conta\n5.Cartao\n6.Salvar e voltar ao menu\n\nEscolha: \t");
          printf("\n===================================================\n");
          scanf("%d", &op);

          switch (op)
          {

          case 1:
            system("cls");
            printf("\nCliente: %s", contas[log].nome);
            printf("\nCPF: %s", contas[log].cpf);
            printf("\nVoce tem %.2f nesse banco\n", saldo);
            printf("\nPREESIONE ENTER PARA VOLTAR AO MENU!");
            getchar();
            getchar();
            break;

          case 2:

            saldo = contas[log].saldo;

            system("cls");
            printf("\n=================== SAQUE ===================\n");
            printf("\nCliente: %s", contas[log].nome);
            printf("\nCPF: %s", contas[log].cpf);
            printf("\nDigite o valor que voce quer sacar: \n");
            scanf("%d", &saque);

            do
            {

              if (saque <= saldo && saque >= 0)
              {
                saldo = saldo - saque;
                printf("Saque feito com sucesso!");
                printf("\nPREESIONE ENTER PARA VOLTAR AO MENU!");
                getchar();
                getchar();
              }
              else
              {
                printf("Valor invalido ou saldo insuficiente.\n");
                getchar();
                getchar();
                break;
              }

            } while (saque > saldo || saque < 0);
            contas[log].saldo = saldo;
            break;

          case 3:
            system("cls");
            printf("\n=================== DEPÓSITO ===================\n");
            printf("\nCliente: %s", contas[log].nome);
            printf("\nCPF: %s", contas[log].cpf);
            printf("\nEscolha um valor para deposito:\t");
            scanf("%d", &deposito);

            do
            {

              if (deposito <= 0)
              {
                printf("Digite um valor coerente para depositar\n");
                scanf("%d", &deposito);
                getchar();
              }
            } while (deposito <= 0);

            contas[log].saldo = contas[log].saldo + deposito;
            printf("Deposito feito com sucesso!");
            printf("\nPREESIONE ENTER PARA VOLTAR AO MENU!");
            getchar();
            getchar();
            break;

          case 4:
            system("cls");
            printf("\n=================== DADOS DA CONTA ===================\n");
            printf("\nCliente: %s", contas[log].nome);
            printf("\nCPF: %s", contas[log].cpf);
            printf("\nLogin: %s", contas[log].login);
            printf("\nSenha: %s", contas[log].senha);
            printf("\nSaldo: %.2f\n", saldo);
            printf("======================================================\n");
            printf("\nPRESSIONE ENTER PARA VOLTAR AO MENU!");
            getchar();
            getchar();

            break;

          case 5:
            system("cls");

            printf("Carregando");
            usleep(500000);
            system("cls");
            printf("Carregando.");
            usleep(500000);
            system("cls");
            printf("Carregando..");
            usleep(500000);
            system("cls");
            printf("Carregando...");
            usleep(500000);
            system("cls");
            printf("Carregando");
            usleep(500000);
            system("cls");
            printf("Carregando.");
            usleep(500000);
            system("cls");
            printf("Carregando..");
            usleep(500000);
            system("cls");
            printf("Carregando...");
            usleep(500000);
            system("cls");
            printf("Carregando");
            usleep(500000);
            system("cls");
            printf("Carregando.");
            usleep(500000);
            system("cls");
            printf("Carregando..");
            usleep(500000);
            system("cls");
            printf("Carregando...");
            usleep(500000);
            system("cls");
            printf("Carregando");
            usleep(500000);
            system("cls");
            printf("Carregando.");
            usleep(500000);
            system("cls");
            printf("Carregando..");
            usleep(500000);
            system("cls");
            printf("Carregando...");
            usleep(500000);
            system("cls");
            printf("Carregando");

            system("cls");
            printf(" ___________________________________________\n");
            printf("|                                           |\n");
            usleep(500000);
            printf("|   IF BANK                                 |\n");
            printf("|                                           |\n");
            usleep(500000);
            printf("|         Nome do cartao: %s            |\n", contas[log].nome);
            printf("|         Numero do cartao: 1234 5678       |\n");
            usleep(500000);
            printf("|         Validade: 12/25                   |\n");
            printf("|                                           |\n");
            usleep(500000);
            printf("|___________________________________________|\n");
            printf("\nPRESSIONE ENTER PARA VOLTAR AO MENU!");
            getchar();
            getchar();
            system("cls");

            break;

          case 6:
            salvarDados(contas, numContas);
            getchar();
            break;
          }

        } while (op != 6);
      }
      else
      {
        printf("Login senha incorretos ou dados não cadastrado");
      }
      break;

      break;

    case 3:
      system("cls");
      printf("Muito obrigado por usar o banco do IFG Tenha um bom dia.");
      return 0;
    }
  } while (op != 3);
  return 0;
}