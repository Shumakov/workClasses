#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::to_string;


class A {
    int a{};

public:
    class B {
        int b{};
        friend class  A;

    public:
        void print() {
            cout << "Class B " << b << endl;
        }

        void setB(int b);
    };
    B clB{};

public:
    void print() {
        cout << "Class A " << a << endl;
        clB.print();
    }

};

void A::B::setB(int b) {
    this->b = b;
}

int G{};

void printt() {
    int G = 100;
    cout << G << endl;
    ::G = 1000;
    cout << ::G << endl;
}


class Image {

    class Coordinat;
    Coordinat* cor_ptr;
    //Coordinat cor_value; // - ошибка

    class Pixel {

        friend class Image;
        int r;
        int g;
        int b;
        //int calculate() const;

    public:
        Pixel(int r, int g, int b) : r{ r }, g{ g }, b{ b } {}
        string getInfo() {
            return "Pixel: r = " + to_string(r) + " g = " + to_string(g) + " b = " + to_string(b);
        }

    };

    static const int pixel_count = 6;

    Pixel pixels[pixel_count]{
        Pixel(0,4,64),
        Pixel(11 ,4,64),
        Pixel(34,4,64),
        Pixel(55,4,64),
        Pixel(66,4,64),
        Pixel(99,4,64),
    };

public:
    void getImageInfo() {
        for (int i{ 0 }; i < pixel_count; ++i) {

            cout << pixels[i].r;
            cout << "#" << i << " " << pixels[i].getInfo() << endl;
        }
    }
};


class Image::Coordinat {


};


class Cap {
    string color;
    int size;

public:
    string getColor() const { return color; }
    int getSize() const { return size; }
    Cap(string c = "Red", int s = 54) : color{ c }, size{ s } {}
};


class Brain {

public:
    string Think() {
        return "Я думаю!";
    }
};

/*
Агрегирование  — методика создания нового класса из уже существующих классов путём их включения.
*/

/*
Композиция (агрегирование по значению) — более строгий вариант агрегирования,
когда включаемый объект может существовать только как часть контейнера.
Если контейнер будет уничтожен, то и включённый объект тоже будет уничтожен.
*/
class Human1 {

    Cap* myCap{}; // Агрегирование  
    Brain* brain{}; //Композиция

public:

    // Агрегирование кепки и композиция мозга
    Human1():brain{ new Brain{} } {}
    Human1(Cap* cap) :myCap{ cap }, brain{ new Brain{} } {}
    ~Human1() {
        delete myCap;
        delete brain;
    }


    void inspectMyCap() {
        cout << "Моя кепка " << myCap->getColor() << " цвета и " << myCap->getSize() << " размера" << endl;
    }
    string Think() {
        return brain->Think();
    }

};

class F {

    int f{2};
public:
    void print() const {
        cout << "Class F " << f << endl;       
    }

    int getF() const { return f; };

};

class G1 :public F {

    int g{1};
public:
    //G() : F{} {};
    void print() const {
        cout << "Class G " << g << endl;
        F::print();
    }

    double div() {
        return (double)g / getF();
    }

};

 // Наследование студента и профессора
class Human{
public:
    string name;
    int age{};
    string color_hair;
public:
    string getName() const { return name; }
    int  getAge() const { return age; }
    string getColorHair() const { return color_hair; }
    Human() = default;
    Human(string name, string c, int age) : name{ name }, age{ age }, color_hair{c} {
        cout << "Create Human" << endl;
    
    }
    ~Human() {
        cout << "Delete Human" << endl;
    }
};

class Student : public Human
{
public:
    string group;
public:

    Student(string name, int age, string c, string group):Human(name,c, age), group{group}{
        cout << "Create Student" << endl;
    }

    ~Student() {
        cout << "Delete Student" << endl;
    }

    string getGroup() const { return group; }
    void Learn() {
        std::cout <<"Меня зовут" << name << ",я  учусь в группе " << group << std::endl;
    }
};

class ExtraStudent : public Student
{

    string time;

public:
    ExtraStudent(string name, int age, string c, string group, string time):
        Student(name, age, c, group), time{time} {
        cout << "Create ExtraStudent" << endl;
    }
    void Learn() {
        std::cout << "Я учусь заочно!" << std::endl;
        Student::Learn();
    }
};

class Professor : public Human
{
    string subject;

public:
    //Professor(string name, int age) :Human(name, age) {}
    void work() {
        std::cout << "Я учу "<< subject << std::endl;
    }
};


class Test {
public:
    string st_public{ "Публичная строка" };
private:
    string st_private{ "Приватная строка" };
protected:
    string st_protected{ "Защищенная строка" };
};

class  Test1 : private Test {
public:
    void print() {
        cout << st_public << endl;
        //cout << st_private << endl;
        cout << st_protected << endl;
    }
};


int main()
{

    setlocale(LC_ALL, "Rus");

    /*Test1 test;

    test.print();


    cout << test.st_public << endl;
    cout << test.st_private << endl;
    cout << test.st_protected << endl;*/

   //return 0;

    ExtraStudent st{ "Student" ,25,"Red", "Group1", "TIME"};
    //st.name = "Student";
    //st.age = 25;
    //st.color_hair = "red";
    //st.group = "group1";

    st.Learn();

    return 0;
   // F f{};
    G1 g;
    g.print();
    cout << g.div() << endl;

    cout << g.getF() << endl;
    return 0;


    Cap *c = new Cap{};
    Human1 h{ c };

    Brain brain;
    cout << brain.Think() << endl << endl;

    h.inspectMyCap();
    cout << h.Think()<< endl;

    Image im;

   // Image::Pixel pixel;

    im.getImageInfo();

    return 0;

    A a{};
    a.print();

    A::B b;
    b.print();

    b.setB(99);
    b.print();

    //B b{};

    return 0;
    
}

