#include <stdio.h>
#include <string.h>

// Limpar
void limparTeclado() {
  while (getchar() != '\n')
    ;
}

// Cabeçalho
void mostrarCabecalho() {
  printf("─▄█▀█▄──▄███▄─\n"
         "▐█░██████████▌\n"
         "─██▒█████████─\n"
         "──▀████████▀──\n"
         "─────▀██▀─────-\n");
  printf("====================================================================="
         "===========\n");
  printf("        Calculadora IMC - Índice de Massa Corporal                   "
         "           \n");
  printf(" Data de criação [25/10/23]                                          "
         "           \n"
         " Autor : Sabrina Vidal Oliveira                                      "
         "              \n"
         " Curso : Análise e Desenvolvimento de Sistemas                       "
         "              \n"
         " Disciplina : Coding: Algoritmo e estrutura de dados                 "
         "              \n"
         " Descrição : Este programa calcula o Índice de Massa Corporal (IMC) "
         "de um paciente,\n"
         " classifica o resultado e exibe as informações em um formato fácil "
         "de entender.    \n");
  printf("====================================================================="
         "===========\n");
}

// Calcular o IMC
float calcularIMC(float peso, float altura) { return peso / (altura * altura); }

// Informações do IMC
void mostrarInfoIMC(char *nome, float peso, float altura, float imc) {
  printf("\nNome: %s\n", nome);
  printf("Peso: %.2f kg\n", peso);
  printf("Altura: %.2f m\n", altura);
  printf("IMC: %.2f\n", imc);
  if (imc < 18.5) {
    printf("abaixo do peso\n");
  } else if (imc < 25) {
    printf("Peso normal\n");
  } else if (imc < 30) {
    printf("Sobrepeso\n");
  } else if (imc < 35) {
    printf("Obesidade grau 1\n");
  } else if (imc < 40) {
    printf("Obesidade grau 2\n");
  } else {
    printf("Obesidade grau 3\n");
  }
  // Dados da tabela de referência
  printf("\n"
         "\n"
         "Tabela de referência\n"
         "\n");
  printf("Abaixo do peso: abaixo de 18.5\n");
  printf("Peso normal: entre 18.5 e 24.9 \n");
  printf("Sobrepeso: entre 25 e 29.9\n");
  printf("Obesidade grau 1: entre 30 e 34.9\n");
  printf("Obesidade grau 2: entre 35 e 39.9\n");
  printf("Obesidade grau 3: acima de 40\n");
}

// Função principal
int main() {
  char nome[200];
  float peso, altura, imc;

  mostrarCabecalho();

  printf("Digite o nome do paciente: ");
  scanf("%s", nome);

  printf("Digite o peso do paciente em kg: ");
  scanf("%f", &peso);

  printf("Digite a altura do paciente em metros use (.): ");
  scanf("%f", &altura);

  if (peso > 0 && altura > 0) {
    imc = calcularIMC(peso, altura);
    mostrarInfoIMC(nome, peso, altura, imc);
  } else {
    printf("Valor inválido. Tente novamente.\n");
    limparTeclado();
  }

  printf("\n\nClassificação do IMC: ");
  if (imc < 16.0) {
    printf("Magreza grave\n");
  } else if (imc >= 16.0 && imc < 16.9) {
    printf("Magreza moderada\n");
  } else if (imc >= 17.0 && imc < 18.4) {
    printf("Magreza leve\n");
  } else if (imc >= 18.5 && imc < 24.9) {
    printf("Saudável\n");
  } else if (imc >= 25.0 && imc < 29.9) {
    printf("Sobrepeso\n");
  } else if (imc >= 30.0 && imc < 34.9) {
    printf("Obesidade Grau I\n");
  } else if (imc >= 35.0 && imc < 39.9) {
    printf("Obesidade Grau II (severa)\n");
  } else {
    printf("Obesidade Grau III (mórbida)\n");
  }
}
