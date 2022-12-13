//

#include <iostream>
using namespace std;

class Pet
{
public:
    Pet(int hunger = 0, int boredom = 0, bool Die = false);
    bool m_Die;
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
    void Run(int fun = 8);
    void List();
    void Die();
private:
    int m_Hunger;
    int m_Boredom;
    int GetMood() const;
    void PassTime(int time = 1);
};


Pet::Pet(int hunger, int boredom, bool Die) :
    m_Hunger(hunger),
    m_Boredom(boredom),
    m_Die(Die)
{}

inline int Pet::GetMood() const
{
    return (m_Hunger + m_Boredom);
}

void Pet::PassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
}

void Pet::Talk()
{
    cout << "\n Humano estoy: ";
    
    int mood = GetMood();

    if (m_Boredom > 5)
    {
        cout << " Estoy aburrido!! Divierteme esclavo \n";
    }
    if (m_Hunger > 5)
    {
        cout << "\n Tengo hambre alv alimentame o se te acabo el dinero... pto pobre \n";
    }
    else
    {
        cout << " Mira sigo vivo o no??";
    }

    
    PassTime();
}

void Pet::Eat(int food)
{
    cout << "    ,    /-.\n";
    cout << "   ((___/ __> \n";
    cout << "   /      } \n";
    cout << "   | .--. /    ___ \n";
    cout << "   ||   ||    /___| \n";
    m_Hunger -= food;

    if (m_Hunger < 0)
    {
        m_Die = true;
    }

    PassTime();
}

void Pet::Play(int fun)
{
    cout << "          __ \n";
    cout << " | ______/ V`-, \n";
    cout << "  }        /~~ \n";
    cout << " /_)^ --,r' \n";
    cout << "|b      |b \n";
    m_Boredom -= fun;

    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }

    PassTime();
}

void Pet::Run(int fun)
{
    cout << "    |       __\n";
    cout << "    |______/ V`-, \n";
    cout << "    }        /~~ \n";
    cout << "   /_)^ --,r' \n";
    cout << "  |b      |b\n";
    m_Boredom -= fun;

    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }
}

void Pet::List()
{
    cout << "\n Nivel de aburrido: " << m_Boredom << "\n";
    cout << "\n Nivel de Hambre: " << m_Hunger << "\n";
}

void Pet::Die()
{
    if (m_Boredom > 20 && m_Hunger > 20)
    {
        cout << "\n si ni te cuidas a ti que me ibas a cuidar a mi...\n";
        m_Die = false;
    }
}



int main()
{

    Pet pet;
    pet.Talk();
    int choice;

    do {
        cout << "\n Mascotas Virtuales\n\n";
        cout << "0 -  Salir\n";
        cout << "1 -  Escucha a tu macota\n";
        cout << "2 -  Alimentar\n";
        cout << "3 -  Jugar con mascota\n";
        cout << "4 -  Sacar a pasear y que cague\n";
        cout << "5 -  Mostrar listado de atributos\n";
        cout << "Elige una opción: \n";

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Vuelve pronto!. \n";
            break;
        case 1:
            pet.Talk();
            break;
        case 2:
            pet.Eat();
            break;
        case 3:
            pet.Play();
            break;
        case 4:
            pet.Run();
            break;
        case 5:
            pet.List();
            break;
        default:
            cout << "\nTu elección se inválida. \n";
        }

        pet.Die();
        if (pet.m_Die)
        {
            break;
        }

    } while (choice != 0);
}