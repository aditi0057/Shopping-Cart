#include<iostream>
#include<vector>
#include"shopping_cart.h"
using namespace std;
vector<Product> allProducts =  //list initialisation
{
    Product(1,"apple",26),
    Product(2,"guava",36),
    Product(3,"mango",16),
    Product(4,"strawberry",29),
    Product(5,"banana",56),
    Product(6,"pineapple",20),
};
Product* chooseProduct()
{
    //Display the list of Products
    string productList;
    cout<<"Avaliable Products "<<endl;

    for(auto product: allProducts)
    {
        productList.append(product.getDisplayName());
    }
    cout<<productList<<endl;
    cout<<"------------"<<endl;
    string choice;
    cin>>choice;
    for(int i=0;i<allProducts.size();i++)
    {
        if(allProducts[i].getShortName()==choice)
        {
            return &allProducts[i];
        }
    }
    cout<<"Product not found!!"<<endl;
    return NULL;

}
bool checkout(Cart &cart)
{
    if(cart.isEmpty())
    {
        return false;
    }
    int total = cart.getTotal();
    cout<<"PAY IN CASH";

    int paid;
    cin>>paid;
    if(paid>=total)
    {
        cout<<"CHANGE "<<paid-total<<endl;
        cout<<"THANKYOU FOR SHOPPING WITH US!!"<<endl<<"HAVE A NICE DAY"<<endl;
        return true;
    }
}
int main()
{
  char action;
  Cart cart;
  while(true)
  {
    cout<<"Select an action-(a)dd item , (v)iew cart, (c)heckout"<<endl;
    cin>>action;
    if(action=='a')
    {
        //todo: Add to cart
        //view all products + choose products + add to the cart
        Product * product =chooseProduct();
        if(product!=NULL)
        {
            cout<<"Added to the cart "<<product->getDisplayName()<<endl;
            cart.addProduct(*product);

        }
    }
    else if(action=='v')
    {
        //view the cart
        cout<<"-------------"<<endl;
        cout<<cart.viewCart();
        cout<<"-------------"<<endl;

    }

    else
    {
        //checkout
        cart.viewCart();
        if(checkout(cart))
        {
            break;
        }
    }
  }
  return 0;
}