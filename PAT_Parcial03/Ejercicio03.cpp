#include "Ejercicio03.h"

TimeMap::TimeMap() {}

void TimeMap::set(string key, string value, int timestamp)
{
    map[key].emplace_back(Pair{ timestamp, value });
}

string TimeMap::get(string key, int timestamp)
{

    if (map.find(key) == map.end())
        return "";

    const vector<Pair>& values = map[key];

     int t = values.size();
     int m = 0;
     int b = 0;

    if (values[b].timestamp > timestamp)
        return "";

    if (values[t - 1].timestamp <= timestamp)
        return values[t - 1].value;

    while (b < t) {
        m = (t + b) >> 1;

        if (values[m].timestamp == timestamp)
            return values[m].value;

        if (values[m].timestamp < timestamp)
            b = m + 1;
        else
            t = m;
    }

    return values[m].value;
}

TimeMap::~TimeMap()
{
    for (auto& entry : map) {
        entry.second.clear();
    }
    map.clear();
}

//Explicacion del codigo porque costo mucho que saliera ya que de cualquier otra manera qye la hiciera siempre solo pasaba 7 pruebas y las demas me daba error, basicamente la forma en que salio fue utilizando
// la clase TimeMap creada la cual esta tenga un mapa desordenado llamado "map", haciendo que este mapa mapee una cadena de vectores pares, donde cada par contiene un sello del tiempo y el valor, asi como cree
// una clase set que toma una clave, un valor, y un sellor del tiempo, y este lo añada al par del tiempo valor, del vector asociado con esa clave y asi. Luego pues cree otro metodo get que toma una clave y un sello
// del tiempo y devuelve el valor asociado con el tiempo dado, y si en un caso no hay un valor exacto para el tiempo, pues devuelve el valor mas reciente antes de ese tiempo, tambien pues finalmente cree un destructor 
// el cual libera la memoria y lo hice con busqueda binaria todo.  