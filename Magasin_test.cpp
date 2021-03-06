#include "Magasin.h"
#include <iostream>

int main(){

    std::vector<Product> produits;

    produits.emplace_back("PS3","Console de jeu Sony",2,300);
    produits.emplace_back("MacBook Pro", "PC portable", 3, 999);
    produits.emplace_back("Xbox One", "Console de jeu Microsoft", 5, 349.95);


    Magasin magasin(produits);
    std::cout << "Affichage des produits du magasin : \n";
    magasin.displayProducts();
    std::cout << std::endl; 

    std::cout << "Affichage du produit MacBook Pro grâce à la méthode qui prend en paramètre le nom du produit :\n";
    magasin.displayProduct("MacBook Pro");

    std::cout << std::endl ;
    std::cout << std::endl ;


    std::cout << "Exécution du script figurant sur la question 3\n";
    Magasin my_easystore;

    
    my_easystore.addProductToStore("PS4","Console de jeu Sony", 249.99,10);
    my_easystore.addProductToStore("Switch", "Console de jeu Nintendo", 299.99,30);
    my_easystore.addProductToStore("Xbox One", "Console de jeu Microsoft", 179.99,15);

    // Display all the products
    my_easystore.displayProducts();

    // Update quantity of a product
    my_easystore.updateQuantite("Switch", 20);

    // Display the updated product
    my_easystore.displayProduct("Switch");


    std::cout << "Voudriez-vous insérer des produits à un nouveau magasin ?\n";
    std::cout<< "Si oui, veuillez taper (O/o). Sinon, veuillez taper n'importe quel caractère.\n";
    char aide;
    std::cin >> aide;

    if(aide == 'O' || aide == 'o'){
        Magasin easy_store;
        
        std::cout << "Le nombre de produits que vous voulez saisir : ";
        int help;
        std::cin >> help;

        if(help > 0) {
            for(int i = 0; i < help ; i++){
                std::cout << "Produit " << i+1 << " : \n" ;
                std::cout << "\tLe titre du produit : ";
                std::string titre;
                std::cin >> titre;
            
                std::cout << "\tLa description du produit : ";
                std::string description;
                std::cin >> description ;

                std::cout << "\tLa quantité du produit  : ";
                int quantite;
                std::cin >> quantite;

                std::cout << "\tLe prix du produit : ";
                int prix;
                std::cin >> prix;

                easy_store.addProductToStore(titre, description, quantite, prix);
            }
        }
    std::cout<<"\nAffichage des produits du magasin : \n";
    easy_store.displayProducts();
    std::cout << std::endl;
    }



    return 0;
}