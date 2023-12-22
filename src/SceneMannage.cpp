#include "SceneMannage.h"
#include <iostream>

void SceneMannage::adicionarCena(std::function<void()> cena)
{
    cenas.push_back(cena);
}
void SceneMannage::chamarCenaAtual()
{
    if (cenaAtual < cenas.size())
    {
        cenas[cenaAtual]();
    }
    else
    {
        std::cout << "Cena inexistente\n";
    }
}
void SceneMannage::setCenaAtual(int indice)
{
    if (indice >= 0 && indice < cenas.size())
    {
        cenaAtual = indice;
    }
    else
    {
        std::cout << "Índice de cena inválido\n";
    }
}
int SceneMannage::GetIndexCena()
{
    return cenaAtual;
}