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