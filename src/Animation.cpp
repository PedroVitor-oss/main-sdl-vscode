#include "Animation.h"

#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <Engine.h>

SpriteGame Animation::GetSprite()
{
	return sprites[frames[frame].iSprite];
}
SDL_Texture *Animation::GetTexture()
{
	return textures[frames[frame].iTexture];
}

void Animation::SetTimeUpdate(int time)
{
	timeUpdate = time;
}

void Animation::Update()
{
	temp++;
	if (temp % timeUpdate == 0)
	{
		frame++;
		temp = 0;
		if (frame == frames.size())
		{
			frame = 0;
		}
	}
}

int Animation::GetLength()
{
	return frames.size();
}

void Animation::LoadAniamtion(std::string pathAnimation, Engine &engine)
{
	std::ifstream animation(pathAnimation);
	std::string line;
	if (animation.is_open())
	{
		std::cout << "animation is open\n";
		while (std::getline(animation, line))
		{
			std::string type; // pode ser : frames / textures / sprites
			int i = 0;
			for (; i < line.length(); i++)
			{
				if (line[i] == ':')
				{
					break;
				}
				else
				{
					type += line[i];
				}
			}
			if (type == "frames")
			{
				// std::cout << "tipo de dados : frames\n";
				//  Variáveis temporárias para armazenar temporariamente os valores
				char leftBrace, comma, rightBrace;
				int iSprite, iTexture;
				line = line.substr(i + 2, line.length());
				// std::cout << "input: " + line << '\n';
				std::istringstream iss(line);

				// Loop para processar cada par de chaves
				while (iss >> leftBrace >> iSprite >> comma >> iTexture >> rightBrace)
				{
					// Verifica se os caracteres lidos são válidos
					if (leftBrace == '{' && comma == ',' && rightBrace == '}')
					{
						// Cria um objeto Frame e adiciona ao vetor
						frames.push_back({iSprite, iTexture});
						// std::cout << "add frame -> sprite: " << iSprite << " texture: " << iTexture << '\n';
					}
					else
					{
						std::cerr << "Erro ao processar os caracteres!" << std::endl;
						break; // Indica um erro
					}
					// Ignora até o próximo espaço em branco
					iss.ignore();
				}
			}
			if (type == "textures")
			{

				// std::cout << "tipo de dados : texture\n";
				// Variáveis temporárias para armazenar temporariamente os valores
				char comma;
				std::string path;

				line = line.substr(i + 2, line.length());
				// std::cout << "input: " + line << '\n';
				std::istringstream iss(line);
				while (std::getline(iss, path, ','))
				{
					// Remove as aspas do início e do final do caminho
					path.erase(0, path.find_first_of("\"") + 1);
					path.erase(path.find_last_of("\""));

					// Remove espaços em branco do início e do final do caminho
					path.erase(0, path.find_first_not_of(" \t\n\r\f\v"));
					path.erase(path.find_last_not_of(" \t\n\r\f\v") + 1);

					// Cria textura a partir do caminho
					SDL_Texture *texture = engine.CreateTexture(path);

					// Adiciona informações sobre a textura ao vetor
					textures.push_back(texture);
					// if (texture == NULL)
					//  std::cout << "textura nula foi criada\n";
					//  std::cout << "Textura criada: " << path << '\n';
				}
			}
			if (type == "sprites")
			{
				char leftBrace, comma, rightBrace;
				int x, y, w, h;
				line = line.substr(i + 2, line.length());
				std::cout << "input: " + line << '\n';
				std::istringstream iss(line);

				while (iss >> leftBrace >> x >> comma >> y >> comma >> w >> comma >> h)
				{
					// Verifica se os caracteres lidos são válidos
					if (leftBrace == '{' && comma == ',')
					{
						// Cria um objeto SpriteGame e adiciona ao vetor
						sprites.push_back({x, y, w, h});
						std::cout << "add sprite -> x: " << x << ", y: " << y << ", w: " << w << ", h: " << h << '\n';
					}
					else
					{
						std::cerr << "Erro ao processar os caracteres!" << std::endl;
						break; // Indica um erro
					}

					// Verifica se há uma vírgula após o conjunto de chaves
					if (!(iss >> comma))
					{
						break; // Sai do loop se não houver mais vírgulas
					}
				}
			}
		}
	}
	else
	{
		std::cout << "animation not is open\n";
	}
	animation.close();
	for (const auto &sprite : sprites)
	{
		std::cout << "x: " << sprite.x << ", y: " << sprite.y << ", w: " << sprite.w << ", h: " << sprite.h << std::endl;
	}
}
void Animation::LoadAniamtion(std::string pathAnimation, std::string pathTextures, Engine &engine)
{
	std::ifstream animation(pathAnimation);
	std::string line;
	if (animation.is_open())
	{
		std::cout << "animation is open\n";
		while (std::getline(animation, line))
		{
			std::string type; // pode ser : frames / textures / sprites
			int i = 0;
			for (; i < line.length(); i++)
			{
				if (line[i] == ':')
				{
					break;
				}
				else
				{
					type += line[i];
				}
			}
			if (type == "frames")
			{
				// std::cout << "tipo de dados : frames\n";
				//  Variáveis temporárias para armazenar temporariamente os valores
				char leftBrace, comma, rightBrace;
				int iSprite, iTexture;
				line = line.substr(i + 2, line.length());
				// std::cout << "input: " + line << '\n';
				std::istringstream iss(line);

				// Loop para processar cada par de chaves
				while (iss >> leftBrace >> iSprite >> comma >> iTexture >> rightBrace)
				{
					// Verifica se os caracteres lidos são válidos
					if (leftBrace == '{' && comma == ',' && rightBrace == '}')
					{
						// Cria um objeto Frame e adiciona ao vetor
						frames.push_back({iSprite, iTexture});
						// std::cout << "add frame -> sprite: " << iSprite << " texture: " << iTexture << '\n';
					}
					else
					{
						std::cerr << "Erro ao processar os caracteres!" << std::endl;
						break; // Indica um erro
					}
					// Ignora até o próximo espaço em branco
					iss.ignore();
				}
			}
			if (type == "textures")
			{

				// std::cout << "tipo de dados : texture\n";
				// Variáveis temporárias para armazenar temporariamente os valores
				char comma;
				std::string path;

				line = line.substr(i + 2, line.length());
				// std::cout << "input: " + line << '\n';
				std::istringstream iss(line);
				while (std::getline(iss, path, ','))
				{
					// Remove as aspas do início e do final do caminho
					path.erase(0, path.find_first_of("\"") + 1);
					path.erase(path.find_last_of("\""));

					// Remove espaços em branco do início e do final do caminho
					path.erase(0, path.find_first_not_of(" \t\n\r\f\v"));
					path.erase(path.find_last_not_of(" \t\n\r\f\v") + 1);

					// Cria textura a partir do caminho
					SDL_Texture *texture = engine.CreateTexture(pathTextures + path);

					// Adiciona informações sobre a textura ao vetor
					textures.push_back(texture);
					// if (texture == NULL)
					//  std::cout << "textura nula foi criada\n";
					//  std::cout << "Textura criada: " << path << '\n';
				}
			}
			if (type == "sprites")
			{
				char leftBrace, comma, rightBrace;
				int x, y, w, h;
				line = line.substr(i + 2, line.length());
				std::cout << "input: " + line << '\n';
				std::istringstream iss(line);

				while (iss >> leftBrace >> x >> comma >> y >> comma >> w >> comma >> h)
				{
					// Verifica se os caracteres lidos são válidos
					if (leftBrace == '{' && comma == ',')
					{
						// Cria um objeto SpriteGame e adiciona ao vetor
						sprites.push_back({x, y, w, h});
						std::cout << "add sprite -> x: " << x << ", y: " << y << ", w: " << w << ", h: " << h << '\n';
					}
					else
					{
						std::cerr << "Erro ao processar os caracteres!" << std::endl;
						break; // Indica um erro
					}

					// Verifica se há uma vírgula após o conjunto de chaves
					if (!(iss >> comma))
					{
						break; // Sai do loop se não houver mais vírgulas
					}
				}
			}
		}
	}
	else
	{
		std::cout << "animation not is open\n";
	}
	animation.close();
	for (const auto &sprite : sprites)
	{
		std::cout << "x: " << sprite.x << ", y: " << sprite.y << ", w: " << sprite.w << ", h: " << sprite.h << std::endl;
	}
}