#pragma once
#include <string>
#include <vector>
#include "Produit.h"

class Client{
public:
    
    Client();
    Client(std::string prenom, std::string nom, std::vector<Product> panier);
    Client(std::string prenom, std::string nom) ; 

    
    Client(Client& client);

  
    std::string getNom() const;
    std::string getPrenom() const;
    int getId() const;
    std::vector<Product> getPanier() const;

    
    void addProduct(Product produit , int quantite = 1);

    void updateQuantity(Product produit,int quantite);
    void updateQuantity(std::string titre, int quantite);

    void viderPanier();

    void deleteProduct(Product product);
    void deleteProduct(std::string titre);

 
    friend std::ostream& operator<< (std::ostream& output, Client& client);

private:
    std::string m_prenom;
    std::string m_nom;
    int m_id;
    std::vector<Product> m_panier;

    //méthode pour fournir un identifiant unique
    int identifiant_auto_int();

};