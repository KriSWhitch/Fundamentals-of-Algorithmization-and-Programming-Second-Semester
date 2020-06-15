#include <iostream>
#include <conio.h>
//N человек  располагаются  по кругу.  
//Начав отсчет от первого, удаляют каждого k-го, смыкая круг после удаления.
//Определить порядок удаления людей из круга. Использовать линейный список.
struct sLogo
{
    sLogo()
    {
        std::cout << "\nЗадание \"Числа Флавиуса\"----------------------начало:\n";
    }
};

///----------------------------------------------------------------------------|
/// Описание понятия "Круг из skrug::n людей".
///----------------------------------------------------------------------------:
struct skrug
{
    int* x;
    int  amount;
    int  n;

    skrug()
    {
        while (true)
        {
            std::cout << "Количество людей:\n";
            std::cin >> n;

            if (n < 6) std::cout << "Error: (n < 6)\n\n";
            else break;
        }

        x = new int[n];
        amount = n;

        for (int i = 0; i < n; ++i)
        {
            x[i] = i;
        }
    }
    ~skrug()
    {
        delete[] x;
    }

    void del(int _i)
    {
        for (int i = _i; i < amount - 1; ++i)
        {
            x[i] = x[i + 1];
        }
        amount--;
    }
};

///----------------------------------------------------------------------------|
/// Считалка на убывание.
///----------------------------------------------------------------------------:
struct s_Josephus_Flavius
{
    s_Josephus_Flavius()
    {
        std::cout << "Число Флавиуса: ";
        std::cin >> m;

        std::cout << "Начинаем отсчет с человека под номером: 0"; // начинаем с первого человека по условию задания
        t = 0;

        for (int i = 0; i < 5; ++i)
        {
            t = count_man(m);
            s[i] = krug.x[t];
            krug.del(t);

            //std::cout << "Out t    = " << t    << "\n";
            //std::cout << "Out s[i] = " << s[i] << "\n";
            //_getch();
        }

        while (!check_win())
        {
            t = count_man(m);
            krug.del(t);
        }

        show_result();
    }

    ///---------------------------------|
    /// Создаем круг из skrug::n людей. |
    ///---------------------------------:
    sLogo Logo;
    skrug krug;

    int m, t;
    int s[5];

    int count_man(int _m)
    {
        return (_m + t) % krug.amount;
    }

    bool check_win()
    {
        if (krug.amount == 1) return true;
        return false;
    }

    void show_result()
    {
        std::cout << "\nПервые 5 выбывших:\n";
        for (int i = 0; i < 5; ++i)
        {
            std::cout << s[i] << "\n";
        }

        std::cout << "\nПобедитель:\n" << krug.x[0] << "\n\n";
    }
};

///----------------------------------------------------------------------------|
/// Start.
///----------------------------------------------------------------------------:
int main()
{
    setlocale(LC_ALL, "Rus");
    while (true)
        s_Josephus_Flavius task;

    return 0;
}