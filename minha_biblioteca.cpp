#include "minha_biblioteca.h"
#include <stdexcept>

int somar(int a, int b)
{
    return a + b;
}

int subtrair(int a, int b)
{
    return a - b;
}

int multiplicar(int a, int b)
{
    return a * b;
}

int dividir(int a, int b)
{
    if (b == 0)
    {
        throw std::invalid_argument("Divisão por zero não é permitida.");
    }
    return a / b;
}

int potencia(int base, int expoente)
{
    if (expoente < 0)
    {
        throw std::invalid_argument("Expoente negativo não é permitido.");
    }
    int resultado = 1;
    for (int i = 0; i < expoente; ++i)
    {
        resultado *= base;
    }
    return resultado;
}

int raiz_quadrada(int numero)
{
    if (numero < 0)
    {
        throw std::invalid_argument("Raiz quadrada de número negativo não é permitida.");
    }
    int resultado = 0;
    while (resultado * resultado <= numero)
    {
        resultado++;
    }
    return resultado - 1; // Retorna o maior inteiro cuja raiz quadrada é menor ou igual ao número
}

int fatorial(int numero)
{
    if (numero < 0)
    {
        throw std::invalid_argument("Fatorial de número negativo não é permitido.");
    }
    int resultado = 1;
    for (int i = 2; i <= numero; ++i)
    {
        resultado *= i;
    }
    return resultado;
}