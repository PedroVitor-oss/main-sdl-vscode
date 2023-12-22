#ifndef SCENEMANNAGE_H
#define SCENEMANNAGE_H

#include <vector>
#include <functional>

class SceneMannage
{
public:
    void adicionarCena(std::function<void()> cena); // Adiciona uma cena ao controlador
    void chamarCenaAtual();                         // Chama a cena atual
    void setCenaAtual(int indice);                  // Define a cena atual
    int GetIndexCena();                             // Retorna o index da sena atual
private:
    std::vector<std::function<void()>> cenas;
    size_t cenaAtual = 0;
};

#endif
