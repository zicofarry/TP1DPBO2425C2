#include <bits/stdc++.h>
using namespace std;

// Class Electronic Shop
class Electronic{
    private:
        int id;
        string name;
        string category;
        int price;
    
    public:
        // Constructor (initializer)
        Electronic(){
            id = 0;
            name = "";
            category = "";
            price = 0;
        };

        // Contructor with parameter
        Electronic(int id, string name, string category, int price){            this->id = id;
            this->name = name;
            this->category = category;
            this->price = price;
        }

        // Setter and Getter for id
        void setId(int id){this->id = id;}
        int getId(){return id;}

        // Setter and Getter for name
        void setName(string name){this->name = name;}
        string getName(){return name;}

        // Setter and Getter for category
        void setCategory(string category){this->category = category;}
        string getCategory(){return category;}

        // Setter and Getter for price
        void setPrice(int price){this->price = price;}
        int getPrice(){return price;}

        // Desctructor
        ~Electronic(){}
};