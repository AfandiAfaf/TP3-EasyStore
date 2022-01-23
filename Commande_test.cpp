#include <iostream>
#include "Commande.h"

int main(){
    Product airpods("AIRPODS","Accessoirs", 1 , 299);
    Product keyboard("KEYBOARD","Accessoirs", 5 , 999);
    Product mac("MacBook Pro","PC portable", 1 , 8979);
    
    
    Client client("Afaf","Afandi");
    client.addProduct(airpods); 
    client.addProduct(mac , 2 ); 
    
    client.updateQuantity("AIRPODS",2);
    client.deleteProduct("MacBook Pro");

    Commande commande(client);      
    std::cout<<commande << std::endl;
    
    return 0;
}