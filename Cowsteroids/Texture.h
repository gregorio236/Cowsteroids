#ifndef TEXTURE_H
#define TEXTURE_H

class Texture
{
public:
	Texture(bool hasAlpha);
	~Texture();

	//Cria a textura dado a imagem
	void Generate(int width, int height, unsigned char* data);

	void Use() const;
private:
	unsigned int ID;
	int width;
	int height;
	//Numero de componentes de cor da textura
	int internalFormat;
	//O formato dos dados da imagem
	int imageFormat;
	//A forma que e tratada o eixo s (x)
	int wrapS;
	//E o eixo t (y)
	int wrapT;
	//A forma que a imagem e tratada quando reduzida
	int filterMin;
	//E quando aumentada
	int filterMax;
};

#endif