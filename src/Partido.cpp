#include "Partido.h"

Partido::Partido()
{
    //ctor
}

Partido::~Partido()
{

}

Partido::Partido(int equipo_a, int equipo_b)
{
    this->equipo_a = equipo_a;
    this->equipo_b = equipo_b;
}

int Partido::obtener_primer_equipo() const
{
    return this->equipo_a;
}

int Partido::obtener_segundo_equipo() const
{
    return this->equipo_b;
}

void Partido::agregar_arbitro(int id)
{
    this->arbitro = id;
}

int Partido::obtener_arbitro() const
{
    return this->arbitro;
}

void Partido::modificar_arbitro(int id)
{
    this->arbitro = id;
}

void Partido::agregar_primer_equipo(int id)
{
    this->equipo_a = id;
}

void Partido::agregar_segundo_equipo(int id)
{
    this->equipo_b = id;
}

