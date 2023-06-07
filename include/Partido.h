#ifndef PARTIDO_H
#define PARTIDO_H


class Partido
{
    public:
        Partido();
        Partido(int equipo_a, int equipo_b); //O(1)
        void agregar_primer_equipo(int id); //O(1)
        void agregar_segundo_equipo(int id); //O(1)
        void modificar_primer_equipo(int id); //O(1)
        void modificar_segundo_equipo(int id); //O(1)
        int obtener_primer_equipo() const; //O(1)
        int obtener_segundo_equipo() const; //O(1)
        void agregar_arbitro(int id); //O(1)
        void modificar_arbitro(int id); //O(1)
        int obtener_arbitro() const;

        virtual ~Partido();

    protected:

    private:
        int equipo_a;
        int equipo_b;
        int arbitro;
};

#endif // PARTIDO_H
