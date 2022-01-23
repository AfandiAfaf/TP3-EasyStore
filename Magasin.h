#pragma once
#include <vector>
#include "Produit.h"
#include "Customer.h"
#include "Commande.h"

class Magasin {
public:
	
	Magasin();
	Magasin(std::vector <Product>& products, std::vector <Client>& clients, std::vector <Commande>& orders);

	Magasin(std::vector <Product>& products);

	std::vector <Product* > getProducts() const ;
	std::vector <Client* > getClients() const ;
	std::vector <Commande* > getOrders() const;

	
	
	void addProduct(Product& produit);
	void addClient(Client& client);
	void addOrder(Commande& order);
    void addProductToStore(std::string nom, std::string description, float prix, int quantite);
    void addProductToShoppingCart(std::string titre, std::string prenom, std::string nom);
	void addProductToShoppingCart(std::string titre, int id );
	void addClient(std::string prenom, std::string nom);

	void displayProducts();
	void displayProduct(std::string nom_produit);
    void displayClients();
	void displayClient(std::string prenom, std::string nom);
	void displayClient(int id);

	void updateQuantite(std::string nom_produit,int quantite);
    void updateProductQuantityClient(std::string titre, int quantite, int id);
	void updateProductQuantityClient(std::string titre, int quantite, std::string prenom, std::string nom);
	bool updateCommandeStatus(int id, bool status);
	
	
	void deleteProductClient(std::string titre, std::string prenom, std::string nom);
	void deleteProductClient(std::string titre, int id);
	
	bool validationCommande(Client& client);
	bool validationCommande(std::string prenom, std::string nom);
	bool validationCommande(int id);
	

	
	void affichageCommandePassees();
	void affichageCommandesClient(int id);
	void affichageCommandesClient(std::string prenom, std::string nom);

	bool productExist(std::string titre);
	Product* productFind(std::string titre);

	bool clientExist(std::string prenom, std::string nom);
	bool clientExist(int id);
	Client* clientFind(std::string prenom , std::string nom);


private:
	std::vector <Product* > m_products;
	std::vector <Client* > m_clients;
	std::vector <Commande* > m_orders;

};