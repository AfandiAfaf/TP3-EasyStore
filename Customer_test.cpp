#include <iostream>
#include "Client.h" // la bibliothèque Produit.h est incluse dans Client.h

int main(){

    Product airpods("AIRPODS","Accessoirs", 1 , 299);
    Product keyboard("KEYBOARD","Accessoirs", 5 , 999);
    Product mac("MacBook Pro","PC portable", 1 , 8979);
    

    std::vector<Product> panierA = {airpods};

    Client clientA("Afaf","Afandi",panierA);
    clientA.addProduct(airpods);
    clientA.updateQuantity(airpods,3);
    clientA.updateQuantity(mac,2);

    std::vector<Product> panierB = {mac,keyboard};

    Client clientB("Abderrahman","Sabiri",panierB);
    clientB.updateQuantity(keyboard,2);
    clientB.updateQuantity(mac,3);


    std::cout << clientA << clientB ;

    //vider le panier du client B
    std::cout << "\nVider le panier du client B\n";
    clientB.viderPanier();
    std::cout << clientB;

    //delete ps3 
    std::cout << "\nSupprimer le produit ps3 du panier du client A\n";
    clientA.deleteProduct(ps3);
    std::cout << clientA;

    return 0;
}