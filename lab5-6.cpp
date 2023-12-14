#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class Zoo
{
private:

    char *name;
    char *country;
    char **animals_list;
    char **work_time;
    double price;
    size_t count_animals;
    double kof; 
    
public:

    Zoo ()                  //контруктор по умолчанию
    {
        name = nullptr;
        country = nullptr;
        animals_list = nullptr;
        work_time = nullptr;
        price = 0;
        count_animals = 0;
        kof = 0;
        
    }

    Zoo (char* name_zoo, char* zoo_country, char **animals, char** time, double ticket_price, size_t count_an)
    {   
        name = new char[strlen(name_zoo)+1];
        strcpy(name, name_zoo);

        country = new char[strlen(zoo_country)+1];
        strcpy(country, zoo_country);

        animals_list = new char*[count_an];
        for (int i = 0; i < count_an; ++i)
        {
            animals_list[i] = new char[strlen(animals[i])+1];
            strcpy(animals_list[i], animals[i]);
        }
        if (time != nullptr)
        {
            work_time = new char*[2];
            for (int i = 0; i < 2; ++i)
            {
                work_time[i] = new char[strlen(time[i])+1];
                strcpy(work_time[i], time[i]);
            }
        }
        else
            work_time = nullptr;


        price = ticket_price;
        count_animals = count_an;
        if (count_animals != 0)
            kof = price / count_animals;
        else
            kof = 0;
        
    }

    Zoo (const Zoo &other)  //конструктор копирования
    {
        this->name = new char[strlen(other.name)+1];
        strcpy(this->name, other.name);

        this->country = new char[strlen(other.country)+1];
        strcpy(this->country, other.country);

        this->animals_list = new char*[other.count_animals];
        for (int i = 0; i < other.count_animals; ++i)
        {
            this->animals_list[i] = new char[strlen(other.animals_list[i])+1];
            strcpy(this->animals_list[i], other.animals_list[i]);
        }

        this->work_time = new char*[2];
        for (int i = 0; i < 2; ++i)
        {
            this->work_time[i] = new char[strlen(other.work_time[i])+1];
            strcpy(this->work_time[i], other.work_time[i]);
        }


        this->price = other.price;
        this->count_animals = other.count_animals;
        this->kof = other.kof;
        
    }

    ~Zoo ()                 //деструтор
    {
        delete[] name;
        delete[] country;
        if (work_time != nullptr)
        {
            for (int j = 0; j < 2; ++j)
            {
                delete[] work_time[j];}
        }
        delete[] work_time;
        for (int i = 0; i < count_animals; ++i)
        {
            delete[] animals_list[i];
        }
        delete[] animals_list;
        
    }

    //сеттеры
    void Set_name(const char* name_zoo)
    {
        name = new char[strlen(name_zoo)+1];
        strcpy(name, name_zoo);
    }
    void Set_country(const char* zoo_country)
    {
        country = new char[strlen(zoo_country)+1];
        strcpy(country, zoo_country);
    }
    void Set_animals_list(char **mass_animals, int size_of_array )
    {
        count_animals = size_of_array;
        animals_list = new char*[count_animals];
        for (int i = 0; i < count_animals; ++i)
        {
            animals_list[i] = new char[strlen(mass_animals[i])+1];
            strcpy(animals_list[i],mass_animals[i]);
        }
    }
    void Set_work_time(const char* time_op, const char* time_cl)
    {
        
        work_time = new char*[2];
        work_time[0] = new char[strlen(time_op)+1];
        strcpy(work_time[0], time_op);
        work_time[1] = new char[strlen(time_cl)+1];
        strcpy(work_time[1], time_cl);
        
    }
    void Set_price(double ticket_price)
    {
        price = ticket_price;
        if (count_animals != 0)
            kof = price / count_animals;
    }
    void Set_count_animals(size_t count_an)
    {
        count_animals = count_an;
        if (price != 0)
            kof = price / count_animals;
    }

    //геттеры
    char* Get_name() const
    {
        return name;
    }
    char* Get_country() const
    {
        return country;
    }
    char* Get_animals(int index = 0) const
    {
        if (index == 0)
            return *animals_list;
        if (index > 0 && index <= count_animals)
            return animals_list[index-1];
        else
            cerr << "Incorrect index";
    }
    char* Get_worktime() const
    {
        return *work_time;
    }
    int Get_worktime_min() const
    {
        char **work_time_new = new char*[2];
        work_time_new[0] = new char[strlen(work_time[0])+1];
        strcpy(work_time_new[0], work_time[0]);
        work_time_new[1] = new char[strlen(work_time[1])+1];
        strcpy(work_time_new[1], work_time[1]);
        
        int hours1, hours2, minutes1, minutes2, sum;
        
        char* token1 = std::strtok(work_time_new[0], ":");
        if (token1 != nullptr) {
            hours1 = std::stoi(token1); // Преобразование строки в int
            token1 = std::strtok(nullptr, ":");
            if(token1 != nullptr) {
                minutes1 = std::stoi(token1); // Преобразование строки в int
            }
        }
        char* token2 = std::strtok(work_time_new[1], ":");
        if (token2 != nullptr) {
            hours2 = std::stoi(token2); // Преобразование строки в int
            token2 = std::strtok(nullptr, ":");
            if(token2 != nullptr) {
                minutes2 = std::stoi(token2); // Преобразование строки в int
            }
        }
        sum = (hours2*60 + minutes2) - (hours1*60 + minutes1);
        return sum;    
    }
    double Get_price() const
    {
        return price;
    }
    size_t Get_count_animals() const
    {
        return count_animals;
    }

    //принтеры?
    void Print_name()
    {
        cout << "Name : " << name << endl;
    }
    void Print_country()
    {
        cout << "Country : " << country << endl;
    }
    void Print_animals()
    {
        for (int i = 0; i < count_animals; ++i)
        {
            cout << "Animal [" << i+1 << "] : " << animals_list[i] << endl;
        }
    }
    void Print_worktime()
    {
        cout << "Work time : " << work_time[0] << " - " << work_time[1] << endl;
    }
    void Print_price()
    {
        cout << "Ticket price : " << price << endl;
    }
    void Print_count_animals()
    {
        cout << "Count animals : " << count_animals << endl;
    } 
    void Print_zoo()
    {
        Print_name();
        Print_country();
        Print_count_animals();
        Print_animals();
        Print_worktime();
        Print_price();
        cout << endl;
    }
    
    int Possible_count_animal(int rabota,int c_minut)
    {
        int a;
        a = rabota / c_minut;
        return a;
    }
    bool operator < (const Zoo& other) const
    {
        return this->kof < other.kof;
    }
    void operator = (const Zoo& other)
    {
        this->name = new char[strlen(other.name)+1];
        strcpy(this->name, other.name);

        this->country = new char[strlen(other.country)+1];
        strcpy(this->country, other.country);

        this->animals_list = new char*[other.count_animals];
        for (int i = 0; i < other.count_animals; ++i)
        {
            this->animals_list[i] = new char[strlen(other.animals_list[i])+1];
            strcpy(this->animals_list[i], other.animals_list[i]);
        }
        this->work_time = new char*[2];
        for (int i = 0; i < 2; ++i)
        {
            this->work_time[i] = new char[strlen(other.work_time[i])+1];
            strcpy(this->work_time[i], other.work_time[i]);
        }


        this->price = other.price;
        this->count_animals = other.count_animals;
        this->kof = other.kof;
    }
};

void swap(Zoo& a, Zoo& b) {
    Zoo temp = a;
    a = b;
    b = temp;
}
void bubbleSort(Zoo arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
void Sort_by_country(const Zoo *arr, const char* country, int n)
{
    cout << "Names of zoos in " << country << ": ";
    for (int i = 0; i < n;  ++i)
    {
        
        if (strcmp(arr[i].Get_country(), country) == 0)
            cout << arr[i].Get_name() << "  ";
    }

}

int main()
{
    Zoo a;
    
    int m;
    cin >> m;
    //запись животных с консоли
    char **list = new char*[m]; 
    cin.ignore(); // игнорирование символа новой строки
    for (int i = 0; i < m; i++)
    {
        cout << "Введите животное " << i+1 << ": ";
        string str;
        getline(std::cin, str);
        list[i] = new char[str.length() + 1]; 
        strcpy(list[i], str.c_str());
    }
    
    a.Set_animals_list(list,m);
    a.Set_name("A");
    a.Set_country("France");
    a.Set_work_time("12:00","17:00");
    a.Set_count_animals(m);
    a.Set_price(1200.00);
    
    a.Print_name();
    a.Print_country();
    a.Print_count_animals();
    a.Print_animals();
    a.Print_worktime();
    a.Print_price();
    a.Print_zoo();

    //установка времени с консоли
    char timeStr1[6];
    cout << "Введите время в формате '00:00': ";
    cin >> timeStr1;
    char timeStr2[6];
    cout << "Введите время в формате '00:00': ";
    cin >> timeStr2;
    char **vremya = new char* []{timeStr1, timeStr2}; //считывание и запись времени
    
    Zoo b("B", "Canada", list, vremya, 120, m);
    
    int t = b.Get_worktime_min();
    cout << "За время работы можно обойти "<< b.Possible_count_animal(t,3) << " животных." << endl;

    
    //ввод массива животных зоопарка С с консоли
    int n = 3;
    char **list_c = new char *[n];
    cin.ignore();
    for (int j = 0; j < n; j++)
    {
        cout << "Введите животное " << j+1 << ": ";
        string str1;
        getline(cin, str1);
        list_c[j] = new char[str1.length() + 1]; 
        strcpy(list_c[j], str1.c_str());
    }

    
    Zoo c("C", "Italy", list_c, nullptr, 1000, n);
    c.Set_work_time("11:00","19:00");
    

    Zoo arr[] = {a, b, c};
    int x = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, x);
    cout << "Отсортированные по коэфициенту N зоопарки: ";
    for (int q = 0; q < x; q++) {
        cout << arr[q].Get_name() << " ";
    }
    cout << endl;
    Sort_by_country(arr, "Canada", x);
    cout << endl;

    return 0;
}