#pragma once
#include <iostream>

namespace chaminji2693305
{
    class book
    {
    private: 
        int id;//id: 1~1000
        int price;//price: 0~50000won

        void testID()
        {
            if(id<1 || id>1000)
           {
                std::cout << "Invalid book id\n";
                std::exit(1);
           }

        }
        void testPrice()
        {  
            if(price <0 || price >50000)
            {
                std::cout << "Invalid book id\n";
                std::exit(1);
            }
        }

    public:
        book(int d = 1, int p = 0):id{d}, price{p}
        {
            testID(); testPrice();
        }
        void input()
        {
            std::cout <<"Enter book id: ";
            std::cin>>id; testID();
            std::cout <<"Enter book price: ";
            std::cin >>price ; testPrice();
        }
        friend std::istream& operator>>(std::istream& is, book& b)
        {
            is>>b.id>>b.price; b.testID(); b.testPrice();

            return is;
        }
        void setID(int d){id=d; testID();}
        void setPrice(int p){price=p; testPrice();}
        void print() const
        {
            std::cout << id << ", " << price << "won\n";
        }
        friend std::ostream& operator<<(std::ostream& os, const book& b)
        {
            os<<b.id<<", "<<b.price<<"won\n";
            return os;
        }

        int getID() const {return id;}
        int getPrice() const {return price;}
        book operator++(){return book(id, ++price);}
        book operator++(int){return book(id, price++);}
        // {
        //    book temp{id, price};
        //    price++;
        //    return temp;
        // //return book{id, price++};
        // }
        friend bool operator == (const book& b1, const book& b2)
        {
            return b1.id == b2.id && b1.price == b2.price;
        }
        friend int operator+ (const book& b1, const book& b2)
        {
            return b1.price + b2.price;
        }
    
    };
}