#pragma once
#include <string>
#include <iostream>

class Product{
public:

    Product();
    Product(std::string titre, std::string description, int quantite,double prix);


    std::string getTitre() const;
    std::string getDescription()const ;
    int getQuantite() const ;
    double getPrix() const ;


    void setTitre(std::string& titre);
    void setDescription(std::string& description);
    void setQuantite(int quantite);
    void setPrix(double prix);
    
    
    friend std::ostream& operator<< (std::ostream &output, Product& product);

private:
    std::string m_titre;
    std::string m_description;
    int m_quantite;
    double m_prix;
};

//fonction qui permet d'avoir N "espace" pour afficher les informations des produits allignées
void nEspace(std::ostream& output, int taille_chaine_caractere, int taille_champ);